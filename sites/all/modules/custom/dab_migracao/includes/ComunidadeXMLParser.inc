<?php

class ComunidadeXMLParser {

  private $file_handle;
  private $caminho_completo_arquivo;
  private $pilha_tags;
  private $count_linhas;
  private $count_comunidades;
  private $linha_corrente;
  private $linha_anterior;

  public function __construct($caminho_completo_arquivo) {
    $this->caminho_completo_arquivo = $caminho_completo_arquivo;
  }

  public function executar() {
    $this->pilha_tags = array();
    $this->count_linhas = 0;
    $this->count_comunidades = 0;

    $this->file_handle = fopen($this->caminho_completo_arquivo, "r");

    try {

      while ($this->file_handle && !feof($this->file_handle)) {
        do {
          $linha = $this->avancarAteItem('global', NULL, 'module="communities.practice.content.CoP"'); //esse global já é dentro de um pickle
          $linha_anterior_pickle = $this->contemString($this->linha_anterior, '<pickle>');
          //print_r("[" . $this->count_linhas . "] Linha Comunidade " . $this->count_comunidades . ": " . $linha);
        } while (!feof($this->file_handle) && !$linha_anterior_pickle);

        $linha = $this->avancarAteItem('pickle', TRUE); //aqui já é o segundo pickle
        $this->processarDadosComunidade($linha);
      }
    } catch (Exception $e) {
      print_r($e);
    }
    if ($this->file_handle) {
      fclose($this->file_handle);
    }
  }

  private function processarDadosComunidade($linha) {
    if (!isset($linha)) {
      return;
    }

    if (!($this->isTagTipo('pickle', $linha) && $this->isTagAbertura($linha))) {//é esperado o segundo pickle do record que possua global com 'module="communities.practice.content.CoP"'
      throw new Exception('Era esperada uma tag de abertura do tipo pickle. Linha: ' . $linha);
    }

    $dados_comunidade = array();
    $linha = $this->avancarAteItem('dictionary', TRUE);

    //TODO:processar esses atributos quando for necessário
    //modification_date -> value > object > state > dictionary > *item (key/value)
    //subject VAZIO
    //twitter
    //_owner -> list(...)|string(karensathie@atencaobasica.org.br)
    //youtube
    //facebook
    //creation_date -> value > object > state > dictionary > *item (key/value)

    $linha = $this->getProximaLinha();
    while ((!$this->isTagTipo('dictionary', $linha))
    || ($this->isTagAbertura($linha))) {

      $linha = $this->avancarAteItem('key', NULL);
      $key_dictionary = $this->extrairConteudoString($linha);

      if ($key_dictionary == '__ac_local_roles__') {
        $dados_comunidade['participacoes'] = $this->extrairEmailsComPapeis();
      }
      elseif ($this->contemString($linha, "_date")) {
        $linha = $this->avancarAteItem('object', FALSE);
      }
      elseif ($key_dictionary == 'id') {
        $linha = $this->avancarAteItem('value', NULL);
        $dados_comunidade['id'] = $this->extrairConteudoString($linha);
      }
      elseif ($key_dictionary == 'title') {
        $linha = $this->avancarAteItem('value', NULL);
        $dados_comunidade['nome'] = $this->extrairConteudoString($linha);
      }
      elseif ($this->contemString($key_dictionary, "_Permission")) {
        $permissao_papeis = $this->extrairPermissaoEPapeis($key_dictionary);
        $dados_comunidade['permissoes'][$permissao_papeis['permissao']] = $permissao_papeis['papeis'];
      }

      $linha = $this->avancarAteItem('item', FALSE);
      $linha = $this->getProximaLinha();
    }

    $this->count_comunidades++;
//    print_r("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
//    print_r("\nTotal de Comunidades: " . $this->count_comunidades . "\n");
    print_r($dados_comunidade['id']);
    //TODO: agora que tem o objeto $dados_comunidade em mãos, nesse ponto deveremos escrever no xml
    print_r("\n");
  }

  private function extrairPermissaoEPapeis($permissao) {
    $papeis = array();

    $linha = $this->avancarAteItem('tuple', TRUE);
    $linha = $this->getProximaLinha();
    while (!($this->isTagTipo('tuple', $linha) && !$this->isTagAbertura($linha))) {
      $papeis[] = $this->extrairConteudoString($linha);
      $linha = $this->getProximaLinha();
    }

    return array('permissao' => $permissao, 'papeis' => $papeis);
  }

  private function extrairEmailsComPapeis() {
    $linha = $this->avancarAteItem('dictionary', TRUE);

    if (!$this->isTagTipo('dictionary', $linha) || !$this->isTagAbertura($linha)) {
      throw new Exception('Era esperada uma tag de abertura do tipo dictionary. Linha: ' . $linha);
    }
    $linha = $this->getProximaLinha();

    $emails_papeis = array();
    while (($this->isTagTipo('item', $linha) && $this->isTagAbertura($linha))) {
      $linha = $this->avancarAteItem('key');
      $email = $this->extrairConteudoString($linha);

      if (!empty($email)) {//pode ser vazio quando é um elemento do tipo 'reference' em vez de 'string'  
        $papeis = array();

        $linha = $this->avancarAteItem('list', TRUE);
        $linha = $this->getProximaLinha();
        while (!($this->isTagTipo('list', $linha) && !$this->isTagAbertura($linha))) {//</list>
          $papel = $this->extrairConteudoString($linha);
          if (!empty($papel)) {
            $papeis[] = $papel;
          }
          else {
            //TODO: tratar aquele caso de ser a tag 'reference' em vez de 'string' 
          }
          $linha = $this->getProximaLinha();
        }

        $emails_papeis[$email] = $papeis;
      }

      $linha = $this->avancarAteItem('item', FALSE);
      $linha = $this->getProximaLinha();
    }
    return $emails_papeis;
  }

  private function avancarAteItem($tipo_tag_procurado, $tagAbertura = NULL, $contendo = NULL, $print = FALSE) {

    while ($this->file_handle && !feof($this->file_handle)) {
      $linha = $this->getProximaLinha();
      if ($print) {
        print_r($linha);
      }
      
      $is_abertura = $this->isTagAbertura($linha);

      if ($this->isTagTipo($tipo_tag_procurado, $linha)) {
        if (!isset($tagAbertura)) {
          if (empty($contendo) || $this->contemString($linha, $contendo)) {
            return $linha;
          }
        }
        elseif ($tagAbertura) {
          if ($is_abertura
            && (empty($contendo) || $this->contemString($linha, $contendo))) {
            return $linha;
          }
        }
        else {
          if (isset($tagAbertura) && !$is_abertura) {

//            $tipo_tag_real = $this->extrairTipoTag($linha);
//            $ocorrencias = count(array_keys($this->pilha_tags, $tipo_tag_real));
//            if ($ocorrencias == 1) {
            return $linha;
//            }
          }
        }
      }
    }
    return NULL;
  }

  private function getProximaLinha() {
    $this->linha_anterior = $this->linha_corrente;
    $this->linha_corrente = fgets($this->file_handle);
    $this->count_linhas++;

    $tipo_tag = $this->extrairTipoTag($this->linha_corrente);
    if (!empty($tipo_tag)) {

      $is_tag_abertura = $this->isTagAbertura($this->linha_corrente);
      if ($is_tag_abertura) {
        array_push($this->pilha_tags, $tipo_tag);
      }
      else {
        if (isset($is_tag_abertura)) {
          array_pop($this->pilha_tags);
        }
      }
    }
    if ($this->count_linhas % 10000 == 0) {
      //print_r("[" . $this->count_linhas . "]");
    }
    return $this->linha_corrente;
  }

  private function extrairConteudoString($linha) {
    preg_match('/\<string.*\>(.+)\<\/string\>/', $linha, $matches);
    $resultado = $matches[1];
    if (empty($resultado)) {
      preg_match('/\<unicode.*\>(.+)\<\/unicode>/', $linha, $matches);
      $resultado = $matches[1];
    }
    return $resultado;
  }

  private function isTagAbertura($tag) {
    $reg_abre = '/\<([a-z]+)\>|\<([a-z]+)[^\/]+\>/';
    $is_abre = preg_match($reg_abre, $tag);

    $reg_fecha = '/\<\/([a-z]+)\>|\<\/([a-z]+)[^\/]+\>/';
    $is_fecha = preg_match($reg_fecha, $tag);

    if (($is_abre && $is_fecha) || (!$is_abre && !$is_fecha)) {
      return NULL;
    }
    return $is_abre;
  }

  private function contemString($texto, $valor_procurado) {
    return strpos($texto, $valor_procurado) !== false;
  }

  private function isTagTipo($tipo_elemento, $linha) {
    return preg_match('/\<\/?' . $tipo_elemento . '(.*)\>/', $linha);
  }

  private function extrairTipoTag($tag) {
    $reg_duas_tags = '/\<[a-z]+.*\>.*\<\/[a-z]+\>/';
    $possui_duas_tags = preg_match($reg_duas_tags, $tag);
    if ($possui_duas_tags) {
      return NULL;
    }

    $reg_abre = '(\<([a-z]*)\>|\<([a-z]*)[^\/]+\>)';
    $reg_fecha = '\<\/([a-z]+)\>|\<\/([a-z]+)[^\/]+\>';
    $reg_abre_fecha = '\<([a-z]*).*\/\>';

    $regex = "/" . $reg_abre_fecha . "|" . $reg_abre . "|" . $reg_fecha . "/";

    preg_match($regex, $tag, $output_array);
    return end($output_array);
  }

}