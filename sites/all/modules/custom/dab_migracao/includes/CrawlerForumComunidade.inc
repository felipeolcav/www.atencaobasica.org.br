<?php

class CrawlerForumComunidade {

  const URL_BASE = "http://www.atencaobasica.org.br";
  const USER_AGENT = "Mozilla/5.0 (Windows NT 6.1; rv:8.0) Gecko/20100101 Firefox/8.0";
  const URL_COMUNIDADES = "http://www.atencaobasica.org.br/comunidades";

  private $username;
  private $password;
  private $count_paginas;
  private $count_comunidades;
  private $count_foruns;
  private $count_topicos;
  private $count_comentarios;
  private $count_anexos;
  private $count_foruns_inseridos;
  private $count_topicos_inseridos;
  private $count_comentarios_inseridos;
  private $count_anexos_inseridos;
  private $doc_foruns;
  private $root_foruns;
  private $arquivo_foruns = "./sites/all/modules/custom/dab_migracao/xml/foruns-comunidade.xml";
  private $doc_topicos;
  private $root_topicos;
  private $arquivo_topicos = "./sites/all/modules/custom/dab_migracao/xml/topicos-forum.xml";
  private $doc_comentarios;
  private $root_comentarios;
  private $arquivo_comentarios = "./sites/all/modules/custom/dab_migracao/xml/comentarios-topico.xml";
  private $doc_anexos;
  private $root_anexos;
  private $arquivo_anexos = "./sites/all/modules/custom/dab_migracao/xml/anexos-comentario.xml";

  public function __construct($username, $password) {
    $this->username = $username;
    $this->password = $password;

    if (file_exists($this->arquivo_foruns)) {
      unlink($this->arquivo_foruns);
    }
    if (file_exists($this->arquivo_topicos)) {
      unlink($this->arquivo_topicos);
    }
    if (file_exists($this->arquivo_comentarios)) {
      unlink($this->arquivo_comentarios);
    }
    if (file_exists($this->arquivo_anexos)) {
      unlink($this->arquivo_anexos);
    }
  }

  public function executar() {
    $this->incializarArquivosXML();
    $this->count_comunidades = 0;
    $this->count_foruns = 0;
    $this->count_topicos = 0;
    $this->count_comentarios = 0;
    $this->count_anexos = 0;
    $this->count_foruns_inseridos = 0;
    $this->count_topicos_inseridos = 0;
    $this->count_comentarios_inseridos = 0;
    $this->count_anexos_inseridos = 0;

    $pagina_comunidades = $this->fazerRequisicaoWeb(self::URL_COMUNIDADES);

    //foreach (@qp($pagina_comunidades, 'div.cop_listing_item', array('ignore_parser_warnings' => TRUE)) as $div_comunidade) {//total de 1831 itens
    foreach (@qp($pagina_comunidades, 'div#cop_todas div.cop_listing_item', array('ignore_parser_warnings' => TRUE)) as $div_comunidade) {//total de 1831 itens

      $dados_comunidade = array();

      $link_comunidade = htmlqp($div_comunidade, '>div.cop_listing_text > a');
      $dados_comunidade['url'] = $link_comunidade->attr("href");
      $dados_comunidade['id'] = end(split("/", $dados_comunidade['url']));
      $dados_comunidade['url'] .= '/forum';

      
      $this->count_comunidades++;
      print_r("\n\n\t--Índice Comunidade : " . $this->count_comunidades);


      $pagina_foruns_comunidade = $this->fazerRequisicaoWeb($dados_comunidade['url']);

      foreach (@qp($pagina_foruns_comunidade, '#listing-table tbody tr', array('ignore_parser_warnings' => TRUE)) as $linha_forum) {
        $this->count_foruns++;
        print_r("\n\n\t\t>>>Fóruns Visitados : " . $this->count_foruns);

        $dados_forum = array();

        foreach (@qp($linha_forum, 'td', array('ignore_parser_warnings' => TRUE)) as $ind_col_forum => $col_forum) {
          switch ($ind_col_forum) {
            case 2:
              $link_pagina_forum = htmlqp($col_forum, 'a');
              $dados_forum['url'] = self::URL_BASE . $link_pagina_forum->attr("href");
              $dados_forum['nome'] = str_replace("\n", '', $link_pagina_forum->text());
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
        $dados_forum['id'] = $url_forum[count($url_forum) - 2];

        $pagina_topicos_forum = $this->fazerRequisicaoWeb($dados_forum['url']);
        $div_descricao_forum = @qp($pagina_topicos_forum, 'div.ploneboardForumDescription', array('ignore_parser_warnings' => TRUE));
        $dados_forum['descricao'] = $div_descricao_forum->text();

        try {
          foreach (@qp($pagina_topicos_forum, 'table.listing tbody tr', array('ignore_parser_warnings' => TRUE)) as $linha_topico) {
            $this->count_topicos++;
            print_r("\n\n\t\t\t>>>Tópicos Visitados : " . $this->count_topicos);

            try {
              $dados_topico = array();

              foreach (@qp($linha_topico, 'td', array('ignore_parser_warnings' => TRUE)) as $ind_col_topico => $col_topico) {
                if ($ind_col_topico == 0) {
                  $link_pagina_topico = htmlqp($col_topico, 'a');

                  $url_topico = $link_pagina_topico->attr("href");
                  $dados_topico['id'] = end(explode('/', $url_topico));
                  $dados_topico['url'] = $url_topico;
                  $dados_topico['nome'] = str_replace("\n", '', preg_replace('/por .*/', '', $link_pagina_topico->text()));
                  $dados_topico['visibilidade'] = $link_pagina_topico->attr("class");
                  $dados_topico['autor'] = str_replace('por ', '', htmlqp($link_pagina_topico, 'span')->text());
                  break;
                }
              }

              $pagina_comentarios_topico = $this->fazerRequisicaoWeb($dados_topico['url']);
              $ul_top_level = @qp($pagina_comentarios_topico, 'div.boardConversation ul.topLevelComment', array('ignore_parser_warnings' => TRUE));

              $comentarios = array();
              foreach (@qp($ul_top_level, '>li', array('ignore_parser_warnings' => TRUE)) as $li_top_level) {
                $comentario = $this->processarLI($li_top_level, $dados_comunidade, $dados_forum, $dados_topico, NULL);
                $comentarios[] = $comentario;
              }
            } catch (Exception $e_topico) {
              print_r("\n#############" . $e_topico);
            }
            $this->inserirTopicoNoXML($dados_comunidade, $dados_forum, $dados_topico, $comentarios);
          }
        } catch (Exception $e_forum) {
          print_r("\n#############" . $e_forum);
        }

        $this->inserirForumNoXML($dados_comunidade, $dados_forum);
      }
    }
  }

  private function incializarArquivosXML() {
    $this->doc_foruns = new DOMDocument('1.0', 'utf-8');
    $this->doc_topicos = new DOMDocument('1.0', 'utf-8');
    $this->doc_comentarios = new DOMDocument('1.0', 'utf-8');
    $this->doc_anexos = new DOMDocument('1.0', 'utf-8');

    $this->root_foruns = $this->doc_foruns->createElement('root');
    $this->root_topicos = $this->doc_topicos->createElement('root');
    $this->root_comentarios = $this->doc_comentarios->createElement('root');
    $this->root_anexos = $this->doc_anexos->createElement('root');

    $this->doc_foruns->appendChild($this->root_foruns);
    $this->doc_topicos->appendChild($this->root_topicos);
    $this->doc_comentarios->appendChild($this->root_comentarios);
    $this->doc_anexos->appendChild($this->root_anexos);
  }

  private function inserirForumNoXML($dados_comunidade, $dados_forum) {
    $forum = $this->doc_foruns->createElement('forum');
    foreach ($dados_forum as $key_forum => $value_forum) {
      $xml_element = $this->doc_foruns->createElement('forum_' . $key_forum);
      $xml_element->nodeValue = $value_forum;
      $forum->appendChild($xml_element);
    }

    //comunidade ---------------------------------------------------------------
    $xml_element = $this->doc_foruns->createElement('comunidade_id');
    $xml_element->nodeValue = $dados_comunidade['id'];
    $forum->appendChild($xml_element);
    $xml_element = $this->doc_foruns->createElement('comunidade_url');
    $xml_element->nodeValue = $dados_comunidade['url'];
    $forum->appendChild($xml_element);
    //--------------------------------------------------------------------------

    $this->root_foruns->appendChild($forum);

    $this->doc_foruns->formatOutput = TRUE;
    $this->doc_foruns->save($this->arquivo_foruns);
    print_r("\n\n\t\t<<<Fóruns Inseridos : " . ++$this->count_foruns_inseridos);
  }

  private function inserirTopicoNoXML($dados_comunidade, $dados_forum, $dados_topico, $comentarios) {

    $topico = $this->doc_topicos->createElement('topico');
    foreach ($dados_topico as $key_topico => $value_topico) {
      $xml_element = $this->doc_topicos->createElement('topico_' . $key_topico);
      $xml_element->nodeValue = $value_topico;
      $topico->appendChild($xml_element);
    }
    if (!empty($comentarios)) {

      $xml_element = $this->doc_topicos->createElement('primeiro_comentario_email');
      $xml_element->nodeValue = $comentarios[0]['autor_email'];
      $topico->appendChild($xml_element);

      $xml_element = $this->doc_topicos->createElement('primeiro_comentario_nome');
      $xml_element->nodeValue = $comentarios[0]['autor_nome'];
      $topico->appendChild($xml_element);

      $xml_element = $this->doc_topicos->createElement('primeiro_comentario_data');
      $xml_element->nodeValue = $comentarios[0]['data'];
      $topico->appendChild($xml_element);

      $xml_element = $this->doc_topicos->createElement('primeiro_comentario_conteudo');
      $xml_element->nodeValue = $comentarios[0]['data'];
      $topico->appendChild($xml_element);

      $xml_element = $this->doc_topicos->createElement('ultimo_comentario_data');
      $xml_element->nodeValue = $comentarios[count($comentarios) - 1]['data'];
      $topico->appendChild($xml_element);
    }

    //forum --------------------------------------------------------------------
    $xml_element = $this->doc_topicos->createElement('forum_id');
    $xml_element->nodeValue = $dados_forum['id'];
    $topico->appendChild($xml_element);
    $xml_element = $this->doc_topicos->createElement('forum_nome');
    $xml_element->nodeValue = $dados_forum['nome'];
    $topico->appendChild($xml_element);
    $xml_element = $this->doc_topicos->createElement('forum_url');
    $xml_element->nodeValue = $dados_forum['url'];
    $topico->appendChild($xml_element);
    //--------------------------------------------------------------------------
    //comunidade ---------------------------------------------------------------
    $xml_element = $this->doc_topicos->createElement('comunidade_id');
    $xml_element->nodeValue = $dados_comunidade['id'];
    $topico->appendChild($xml_element);
    $xml_element = $this->doc_topicos->createElement('comunidade_url');
    $xml_element->nodeValue = $dados_comunidade['url'];
    $topico->appendChild($xml_element);
    //--------------------------------------------------------------------------

    $this->root_topicos->appendChild($topico);

    $this->doc_topicos->formatOutput = TRUE;
    $this->doc_topicos->save($this->arquivo_topicos);

    print_r("\n\n\t\t\t<<<Tópicos Inseridos : " . ++$this->count_topicos_inseridos);
  }

  private function inserirComentarioNoXML($dados_comunidade, $dados_forum, $dados_topico, $dados_comentario) {
    //comentario ---------------------------------------------------------------
    $comentario = $this->doc_comentarios->createElement('comentario');
    foreach ($dados_comentario as $key_comentario => $value_comentario) {
      $xml_element = $this->doc_comentarios->createElement('comentario_' . $key_comentario);
      $xml_element->nodeValue = $value_comentario;
      $comentario->appendChild($xml_element);
    }
    //--------------------------------------------------------------------------
    //topico -------------------------------------------------------------------
    $xml_element = $this->doc_comentarios->createElement('topico_id');
    $xml_element->nodeValue = $dados_topico['id'];
    $comentario->appendChild($xml_element);
    $xml_element = $this->doc_comentarios->createElement('topico_url');
    $xml_element->nodeValue = $dados_topico['url'];
    $comentario->appendChild($xml_element);
    //--------------------------------------------------------------------------
    //forum --------------------------------------------------------------------
    $xml_element = $this->doc_comentarios->createElement('forum_id');
    $xml_element->nodeValue = $dados_forum['id'];
    $comentario->appendChild($xml_element);
    $xml_element = $this->doc_comentarios->createElement('forum_url');
    $xml_element->nodeValue = $dados_forum['url'];
    $comentario->appendChild($xml_element);
    $xml_element = $this->doc_comentarios->createElement('forum_nome');
    $xml_element->nodeValue = $dados_forum['nome'];
    $comentario->appendChild($xml_element);
    //--------------------------------------------------------------------------
    //comunidade ---------------------------------------------------------------
    $xml_element = $this->doc_comentarios->createElement('comunidade_id');
    $xml_element->nodeValue = $dados_comunidade['id'];
    $comentario->appendChild($xml_element);
    $xml_element = $this->doc_comentarios->createElement('comunidade_url');
    $xml_element->nodeValue = $dados_comunidade['url'];
    $comentario->appendChild($xml_element);
    //--------------------------------------------------------------------------

    $this->root_comentarios->appendChild($comentario);

    $this->doc_comentarios->formatOutput = TRUE;
    $this->doc_comentarios->save($this->arquivo_comentarios);

    print_r("\n\n\t\t\t\t<<<Comentários Inseridos : " . ++$this->count_comentarios_inseridos);
  }

  private function processarLI($li, $dados_comunidade, $dados_forum, $dados_topico, $comentario_pai) {
    $this->count_comentarios++;
    print_r("\n\n\t\t\t\t>>>Comentários Visitados : " . $this->count_comentarios);

    $dados_comentario = array();
    $dados_comentario['pai_id'] = $comentario_pai['id'];



    $div_comment = @qp($li, '>div.boardComment', array('ignore_parser_warnings' => TRUE));
    $div_details = @qp($div_comment, '>div.boardCommentDetails', array('ignore_parser_warnings' => TRUE));
    $dados_comentario['id'] = $div_details->attr('name');



    $div_header = htmlqp($div_comment->html(), 'div.boardCommentDetails > div.boardCommentHeaderTitleBlock');
    $link = htmlqp($div_header, '> a');
    $link_href = $link->attr('href');
    $dados_comentario['id'] = end(explode('/', $link_href));

    $exploded_texto = explode("\n", $div_header->text());
    $data_str = $exploded_texto[count($exploded_texto) - 2];
    $dados_comentario['data'] = $this->converterData($data_str);

    $link_autor = htmlqp($div_header->html(), 'a[href*="@"]');
    $dados_comentario['autor_email'] = end(split('/', $link_autor->attr('href')));
    $dados_comentario['autor_nome'] = $link_autor->text();

    $div_comment_content = @qp($div_comment, 'div.boardCommentBody > div.boardCommentContent', array('ignore_parser_warnings' => TRUE));
    $dados_comentario['conteudo'] = $div_comment_content->html();
    $dados_comentario['conteudo'] = str_replace('<div class="boardCommentContent">', '', $dados_comentario['conteudo']);
    $dados_comentario['conteudo'] = preg_replace('/<\/div>$/', '', $dados_comentario['conteudo']);

    try {
      $div_attachments = @qp($div_comment, 'fieldset.commentAttachments', array('ignore_parser_warnings' => TRUE));
      if (count($div_attachments->html()) > 0) {
        $anexos = array();
        foreach (@qp($div_attachments->html(), 'li > a', array('ignore_parser_warnings' => TRUE)) as $link_attachment) {
          $this->count_anexos++;
          print_r("\n\n\t\t\t\t\t>>>Anexos Visitados : " . $this->count_anexos);
          $anexos[] = $this->salvarArquivo($link_attachment->attr('href'));
          print_r("\n\n\t\t\t\t\t<<<Anexos Inseridos : " . ++$this->count_anexos_inseridos);
        }
        if (!empty($anexos)) {
          $dados_comentario['anexos'] = $anexos;
        }
      }

      if (empty($dados_comentario['id'])) {
        print_r($dados_comentario);
        throw new Exception("Comentario sem ID");
      }
    } catch (Exception $e_comentario) {
      print_r("\n#############" . $e_comentario);
    }
    $this->inserirComentarioNoXML($dados_comunidade, $dados_forum, $dados_topico, $dados_comentario);

    $sub_comentarios = array();
    foreach (@qp($li, '> ul > li', array('ignore_parser_warnings' => TRUE)) as $li_sub_comentario) {
      $sub_comentarios[] = $this->processarLI($li_sub_comentario, $dados_comunidade, $dados_forum, $dados_topico, $dados_comentario);
    }

    if (!empty($sub_comentarios)) {
      $dados_comentario['sub_comentarios'] = $sub_comentarios;
    }
    return $dados_comentario;
  }

  private function converterData($str_data) {
    $traducao_mes = array(
      'Janeiro' => '1'
      , 'Fevereiro' => '2'
      , 'Março' => '3'
      , 'Abril' => '4'
      , 'Maio' => '5'
      , 'Junho' => '6'
      , 'Julho' => '7'
      , 'Agosto' => '8'
      , 'Setembro' => '9'
      , 'Outubro' => '10'
      , 'Novembro' => '11'
      , 'Dezembro' => '12'
    );
    $separated_values = preg_split("/ (de|às) /", $str_data);
    if (count($separated_values) != 4) {
      return NULL;
    }
    $composed_value = $separated_values[0] . '-' . $traducao_mes[$separated_values[1]] . '-' . $separated_values[2] . ' ' . $separated_values[3];

    return $composed_value;
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

    print_r("\n[pag " . ++$this->count_paginas . "]: " . $final_url);

    return $resultado;
//    return mb_convert_encoding($resultado, 'UTF-8', mb_detect_encoding($resultado, 'UTF-8, ISO-8859-1', true));
  }

}