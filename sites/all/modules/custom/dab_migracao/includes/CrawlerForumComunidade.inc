<?php

class CrawlerForumComunidade {

  const ARQUIVO_XML_OUTPUT = "./sites/all/modules/custom/dab_migracao/xml/forum-comunidade.xml";
  const URL_BASE = "http://www.atencaobasica.org.br";
  const USER_AGENT = "Mozilla/5.0 (Windows NT 6.1; rv:8.0) Gecko/20100101 Firefox/8.0";
  const URL_COMUNIDADES = "http://www.atencaobasica.org.br/comunidades";

  private $username;
  private $password;
  private $count_item;
  private $count_pagina;
  private $doc;
  private $root;
  private $caminho_arquivo_output;

  public function __construct($username, $password) {
    $this->username = $username;
    $this->password = $password;
    $this->caminho_arquivo_output = self::ARQUIVO_XML_OUTPUT;
    if (file_exists($this->caminho_arquivo_output)) {
      unlink($this->caminho_arquivo_output);
    }
  }

  public function executar() {
//LEMBRAR DE LIMPAR O CONTEÚDO DA PASTA '../files' ANTES DE EXECUTAR ESSE SCRIPT

    $this->doc = new DOMDocument('1.0', 'utf-8');
    $this->root = $this->doc->createElement('root');
    $this->doc->appendChild($this->root);

    $pagina_comunidades = $this->fazerRequisicaoWeb(self::URL_COMUNIDADES);

    foreach (@qp($pagina_comunidades, '.cop_listing_item', array('ignore_parser_warnings' => TRUE)) as $div_comunidade) {
      $link_comunidade = htmlqp($div_comunidade, '.cop_listing_text a');
      $url_comunidade = $link_comunidade->attr("href");

      $pagina_foruns_comunidade = $this->fazerRequisicaoWeb($url_comunidade . '/forum');
      $id_comunidade = end(split("/", $url_comunidade));

      foreach (@qp($pagina_foruns_comunidade, '#listing-table tbody tr', array('ignore_parser_warnings' => TRUE)) as $linha_forum) {
        $dados_forum = array('id_comunidade' => $id_comunidade);

        foreach (@qp($linha_forum, 'td', array('ignore_parser_warnings' => TRUE)) as $ind_col_forum => $col_forum) {
          switch ($ind_col_forum) {
            case 2:
              $link_pagina_forum = htmlqp($col_forum, 'a');
              $dados_forum['url'] = self::URL_BASE . $link_pagina_forum->attr("href");
              $dados_forum['nome'] = $link_pagina_forum->text();
              break;
            case 4:
              $dados_forum['data_modificacao'] = $col_forum->text();
              break;
            case 5:
              $dados_forum['visibilidade'] = htmlqp($col_forum, 'span')->text();
              break;

            default:
              break;
          }
        }
        $url_forum = split('/', $dados_forum['url']);
        $dados_forum['id_forum'] = $url_forum[count($url_forum) - 2];

        $pagina_topicos_forum = $this->fazerRequisicaoWeb($dados_forum['url']);
        $div_descricao_forum = @qp($pagina_topicos_forum, 'div.ploneboardForumDescription', array('ignore_parser_warnings' => TRUE));
        $dados_forum['descricao'] = $div_descricao_forum->text();

        foreach (@qp($pagina_topicos_forum, 'table.listing tbody tr', array('ignore_parser_warnings' => TRUE)) as $linha_topico) {
          $dados_topico = array('id_comunidade' => $id_comunidade, 'id_forum' => $dados_forum['id_forum']);

          foreach (@qp($linha_topico, 'td', array('ignore_parser_warnings' => TRUE)) as $ind_col_topico => $col_topico) {
            if ($ind_col_topico == 0) {
              $link_pagina_topico = htmlqp($col_topico, 'a');

              $dados_topico['url'] = $link_pagina_topico->attr("href");
              $dados_topico['nome'] = preg_replace('/por .*/', '', $link_pagina_topico->text());
              $dados_topico['visibilidade'] = $link_pagina_topico->attr("class");
              $dados_topico['autor'] = str_replace('por ', '', htmlqp($link_pagina_topico, 'span')->text());
              break;
            }
          }

          $pagina_comentarios_topico = $this->fazerRequisicaoWeb($dados_topico['url']);
          $ul_top_level = @qp($pagina_comentarios_topico, 'div.boardConversation ul.topLevelComment', array('ignore_parser_warnings' => TRUE));

          $comentarios = array();
          foreach (@qp($ul_top_level, 'li', array('ignore_parser_warnings' => TRUE)) as $li_top_level) {
            $comentarios[] = $this->processarLI($li_top_level, $dados_topico);
          }
        }
      }
    }
  }

  private function processarLI($li, $dados_topico) {
    $comentario = array('id_comunidade' => $dados_topico['id_comunidade']
      , 'id_forum' => $dados_topico['id_forum']
      , 'topico' => $dados_topico['nome']);

    $div_comment = @qp($li, 'div.boardComment', array('ignore_parser_warnings' => TRUE));
    $comentario['id_comentario'] = @qp($div_comment, '>a', array('ignore_parser_warnings' => TRUE))->attr('id');

    $div_header = htmlqp($div_comment->html(), 'div.boardCommentDetails > div.boardCommentHeaderTitleBlock');

    $exploded_texto = explode("\n", $div_header->text());
    $data_str = $exploded_texto[count($exploded_texto) - 2];
    $comentario['data'] = $data_str;

    $link_autor = @qp($div_header->html(), 'a[href*="@"]', array('ignore_parser_warnings' => TRUE));
    $comentario['autor_email'] = end(split('/', $link_autor->attr('href')));
    $comentario['autor_nome'] = $link_autor->text();

    $div_comment_content = @qp($div_comment, 'div.boardCommentBody > div.boardCommentContent', array('ignore_parser_warnings' => TRUE));
    $comentario['conteudo'] = $div_comment_content->html();
    $comentario['conteudo'] = str_replace('<div class="boardCommentContent">', '', $comentario['conteudo']);
    $comentario['conteudo'] = preg_replace('/<\/div>$/', '', $comentario['conteudo']);

    $div_attachments = @qp($div_comment, 'fieldset.commentAttachments', array('ignore_parser_warnings' => TRUE));
    if (count($div_attachments->html()) > 0) {
      $anexos = array();
      foreach (@qp($div_attachments->html(), 'li > a', array('ignore_parser_warnings' => TRUE)) as $link_attachment) {
        $anexos[] = $this->salvarArquivo($link_attachment->attr('href'));
      }
      if (!empty($anexos)) {
        $comentario['anexos'] = $anexos;
      }
    }
    return $comentario;
  }

  private function inserirElementoNoXML($elemento) {
    print_r("\n\n--------------------------------------------------------------\n");
    print_r("\nElementos processados: " . $this->count_item . "\n");
    print_r($elemento);

    $xml_item = $this->doc->createElement('item');
    foreach ($elemento as $key => $value) {
      $xml_element = $this->doc->createElement($key);
      $xml_element->nodeValue = $value;
      $xml_item->appendChild($xml_element);
    }
    $this->root->appendChild($xml_item);

    $this->doc->formatOutput = TRUE;
    $this->doc->save($this->caminho_arquivo_output);
  }

  private function salvarArquivo($url) {

    $nome_arquivo = preg_replace('/.*\/comunidades\//', '', $url);
    $nome_arquivo .= '.' . end(explode('-', $nome_arquivo));

    $caminho_completo_arq = $this->getCaminhoPastaAnexosComentarios() . $nome_arquivo;

    $dirname = dirname($caminho_completo_arq);
    if (!is_dir($dirname)) {
      mkdir($dirname, 0755, true);
    }

    $this->fazerRequisicaoDownloadArquivo($url, $caminho_completo_arq);


    return $caminho_completo_arq;
  }

  private function getCaminhoPastaAnexosComentarios() {
    return realpath(__DIR__ . '/..') . '/comment-attachments/';
  }

//  private function processarNomeArquivo($caminho_completo_original) {
//    if (!file_exists($caminho_completo_original)) {
//      $extensao = strrchr($caminho_completo_original, '.');
//      $arquivo_sem_extensao = str_replace($extensao, '', $caminho_completo_original);
//      $tamanho_final = 255 - strlen($extensao);
//      $caminho_arquivo = substr($arquivo_sem_extensao, 0, $tamanho_final) . $extensao;
//
//      print_r("\n>>>>>>>>>>>>>>>>>>>>>> Alteração no nome do arquivo por causa do tamanho. Novo nome: " . $caminho_arquivo);
//
//      return $caminho_arquivo;
//    }
//
//    $caminho_arquivo = $caminho_completo_original;
//    $contador = 1;
//    do {
//      $contador++;
//      $regex_sufixo = '(_[0-9]+)?\.'; //Exemplo: '/caminho/do/arquivo/nome.txt' => '.' ou '/caminho/do/arquivo/nome_2.txt' => '_2.'
//      $sufixo = "_$contador.";
//      $caminho_arquivo = preg_replace("/$regex_sufixo(?!.*$regex_sufixo)/", $sufixo, $caminho_arquivo);
//
//      if (strlen($caminho_arquivo) > 255) {//correção no nome do arquivo por causa do tamanho
//        $extensao = substr(strrchr($caminho_arquivo, '.'), 1);
//
//        if (strpos($caminho_arquivo, $sufixo)) {
//          $caminho_arquivo = preg_replace("/$regex_sufixo(?!.*$regex_sufixo)/", ".", $caminho_arquivo);
//        }
//        else {
//          $sufixo = '.';
//        }
//        $caminho_arquivo = preg_replace("/\.$extensao/", "", $caminho_arquivo);
//        $tamanho_final = 255 - strlen($sufixo) - strlen($extensao);
//        $caminho_arquivo = substr($caminho_arquivo, 0, $tamanho_final) . $sufixo . $extensao;
//
//        print_r("\n>>>>>>>>>>>>>>>>>>>>>> Alteração no nome do arquivo por causa do tamanho. Novo nome: " . $caminho_arquivo);
//      }
//    } while (file_exists($caminho_arquivo));
//
//    return $caminho_arquivo;
//  }

  private function fazerRequisicaoDownloadArquivo($url, $caminho_arquivo) {
    $username = urlencode($this->username);
    $password = urlencode($this->password);
    $post_data = "__ac_name=$username&__ac_password=$password";


    set_time_limit(0);
    $fp = fopen($caminho_arquivo, 'w+'); //This is the file where we save the    information


    $ch = curl_init(str_replace(" ", "%20", $url)); //Here is the file we are downloading, replace spaces with %20

    curl_setopt($ch, CURLOPT_USERAGENT, self::USER_AGENT);
    curl_setopt($ch, CURLOPT_POST, 1);
    curl_setopt($ch, CURLOPT_POSTFIELDS, $post_data);
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
    curl_setopt($ch, CURLOPT_FOLLOWLOCATION, 1);
    curl_setopt($ch, CURLOPT_TIMEOUT, 50);
    curl_setopt($ch, CURLOPT_FILE, $fp); // write curl response to file

    curl_exec($ch);
    curl_close($ch);
    fclose($fp);
  }

  private function fazerRequisicaoWeb($url) {

    $username = urlencode($this->username);
    $password = urlencode($this->password);
    $post_data = "__ac_name=$username&__ac_password=$password";

    $url_processada = preg_replace(array('/&__ac_name=[^&]*/', '/&__ac_password=[^&]*/'), array('', ''), $url);

    $ch = curl_init();
    curl_setopt($ch, CURLOPT_USERAGENT, self::USER_AGENT);
    curl_setopt($ch, CURLOPT_URL, $url_processada);
    curl_setopt($ch, CURLOPT_POST, 1);
    curl_setopt($ch, CURLOPT_POSTFIELDS, $post_data);
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
    curl_setopt($ch, CURLOPT_FOLLOWLOCATION, 1);
    $resultado = curl_exec($ch);
    $final_url = curl_getinfo($ch, CURLINFO_EFFECTIVE_URL);
    curl_close($ch);

    print_r("\n [pag " . $this->count_pagina . "]: ");
    print_r($final_url);

    return $resultado;
//    return mb_convert_encoding($resultado, 'UTF-8', mb_detect_encoding($resultado, 'UTF-8, ISO-8859-1', true));
  }

}