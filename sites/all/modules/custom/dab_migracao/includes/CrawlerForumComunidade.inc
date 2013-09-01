<?php

class CrawlerForumComunidade {

  const URL_BASE = "http://www.atencaobasica.org.br";
  const USER_AGENT = "Mozilla/5.0 (Windows NT 6.1; rv:8.0) Gecko/20100101 Firefox/8.0";
  const URL_COMUNIDADES = "http://www.atencaobasica.org.br/comunidades";

  private $username;
  private $password;
  private $count_comunidades;
  private $count_foruns;
  private $count_topicos;
  private $count_comentarios;
  private $count_anexos;
  private $count_pagina;
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

    $pagina_comunidades = $this->fazerRequisicaoWeb(self::URL_COMUNIDADES);

    foreach (@qp($pagina_comunidades, '.cop_listing_item', array('ignore_parser_warnings' => TRUE)) as $div_comunidade) {
      $this->count_comunidades++;
      print_r("\n\n\tÍndice Comunidades: " . $this->count_comunidades);
      
      $dados_comunidade = array();

      $link_comunidade = htmlqp($div_comunidade, '.cop_listing_text > a');
      $dados_comunidade['url'] = $link_comunidade->attr("href");
      $dados_comunidade['id'] = end(split("/", $dados_comunidade['url']));
      $dados_comunidade['url'] .= '/forum';

      $pagina_foruns_comunidade = $this->fazerRequisicaoWeb($dados_comunidade['url']);

      foreach (@qp($pagina_foruns_comunidade, '#listing-table tbody tr', array('ignore_parser_warnings' => TRUE)) as $linha_forum) {
        $this->count_foruns++;

        $dados_forum = array();

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
        $dados_forum['id'] = $url_forum[count($url_forum) - 2];

        $pagina_topicos_forum = $this->fazerRequisicaoWeb($dados_forum['url']);
        $div_descricao_forum = @qp($pagina_topicos_forum, 'div.ploneboardForumDescription', array('ignore_parser_warnings' => TRUE));
        $dados_forum['descricao'] = $div_descricao_forum->text();

        $this->inserirForumNoXML($dados_comunidade, $dados_forum);
        
        foreach (@qp($pagina_topicos_forum, 'table.listing tbody tr', array('ignore_parser_warnings' => TRUE)) as $linha_topico) {
          $this->count_topicos++;

          $dados_topico = array();

          foreach (@qp($linha_topico, 'td', array('ignore_parser_warnings' => TRUE)) as $ind_col_topico => $col_topico) {
            if ($ind_col_topico == 0) {
              $link_pagina_topico = htmlqp($col_topico, 'a');

              $url_topico = $link_pagina_topico->attr("href");
              $dados_topico['id'] = end(explode('/',$url_topico));
              $dados_topico['url'] = $url_topico;
              $dados_topico['nome'] = preg_replace('/por .*/', '', $link_pagina_topico->text());
              $dados_topico['visibilidade'] = $link_pagina_topico->attr("class");
              $dados_topico['autor'] = str_replace('por ', '', htmlqp($link_pagina_topico, 'span')->text());
              break;
            }
          }
          
          $this->inserirTopicoNoXML($dados_comunidade, $dados_forum, $dados_topico);

          $pagina_comentarios_topico = $this->fazerRequisicaoWeb($dados_topico['url']);
          $ul_top_level = @qp($pagina_comentarios_topico, 'div.boardConversation ul.topLevelComment', array('ignore_parser_warnings' => TRUE));

          $comentarios = array();
          foreach (@qp($ul_top_level, '>li', array('ignore_parser_warnings' => TRUE)) as $li_top_level) {
            $comentario = $this->processarLI($li_top_level, $dados_comunidade, $dados_forum, $dados_topico, NULL);
            $comentarios[] = $comentario;
          }
        }
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
    print_r("\n\n\t\tÍndice Fóruns: " . $this->count_foruns);

    $forum = $this->doc_foruns->createElement('forum');
    foreach ($dados_forum as $key_forum => $value_forum) {
      $xml_element = $this->doc_foruns->createElement('forum_' . $key_forum);
      $xml_element->nodeValue = $value_forum;
      $forum->appendChild($xml_element);
    }
    foreach ($dados_comunidade as $key_comunidade => $value_comunidade) {
      $xml_element = $this->doc_foruns->createElement('comunidade_' . $key_comunidade);
      $xml_element->nodeValue = $value_comunidade;
      $forum->appendChild($xml_element);
    }
    
    $xml_element = $this->doc_foruns->createElement('num_comunidade');
    $xml_element->nodeValue = $this->count_comunidades;
    $forum->appendChild($xml_element);
    
    $xml_element = $this->doc_foruns->createElement('num_forum');
    $xml_element->nodeValue = $this->count_foruns;
    $forum->appendChild($xml_element);
    
    $this->root_foruns->appendChild($forum);

    $this->doc_foruns->formatOutput = TRUE;
    $this->doc_foruns->save($this->arquivo_foruns);
  }
  private function inserirTopicoNoXML($dados_comunidade, $dados_forum, $dados_topico) {
    print_r("\n\n\t\t\tÍndice Tópicos: " . $this->count_topicos);

    $topico = $this->doc_topicos->createElement('topico');
    foreach ($dados_topico as $key_topico => $value_topico) {
      $xml_element = $this->doc_topicos->createElement('topico_' . $key_topico);
      $xml_element->nodeValue = $value_topico;
      $topico->appendChild($xml_element);
    }
    foreach ($dados_forum as $key_forum => $value_forum) {
      $xml_element = $this->doc_topicos->createElement('forum_' . $key_forum);
      $xml_element->nodeValue = $value_forum;
      $topico->appendChild($xml_element);
    }
    foreach ($dados_comunidade as $key_comunidade => $value_comunidade) {
      $xml_element = $this->doc_topicos->createElement('comunidade_' . $key_comunidade);
      $xml_element->nodeValue = $value_comunidade;
      $topico->appendChild($xml_element);
    }
    
    $xml_element = $this->doc_topicos->createElement('num_comunidade');
    $xml_element->nodeValue = $this->count_comunidades;
    $topico->appendChild($xml_element);
    
    $xml_element = $this->doc_topicos->createElement('num_forum');
    $xml_element->nodeValue = $this->count_foruns;
    $topico->appendChild($xml_element);
    
    $xml_element = $this->doc_topicos->createElement('num_topico');
    $xml_element->nodeValue = $this->count_topicos;
    $topico->appendChild($xml_element);
    
    $this->root_topicos->appendChild($topico);

    $this->doc_topicos->formatOutput = TRUE;
    $this->doc_topicos->save($this->arquivo_topicos);
  }

  private function processarLI($li, $dados_comunidade, $dados_forum, $dados_topico, $comentario_pai) {
    $this->count_comentarios++;

    $comentario = array(
      'comunidade_id' => $dados_comunidade['id']
      , 'comunidade_url' => $dados_comunidade['url']
      , 'forum_id' => $dados_forum['id']
      , 'forum_url' => $dados_forum['url']
      , 'topico_url' => $dados_topico['url']
      , 'comentario_pai' => $comentario_pai['comentario_id']
    );

    $div_comment = @qp($li, '>div.boardComment', array('ignore_parser_warnings' => TRUE));
    $div_details = @qp($div_comment, '>div.boardCommentDetails', array('ignore_parser_warnings' => TRUE));
    $comentario['comentario_id'] = $div_details->attr('name');


    $div_header = htmlqp($div_comment->html(), 'div.boardCommentDetails > div.boardCommentHeaderTitleBlock');
    $link = htmlqp($div_header, '> a');
    $link_href = $link->attr('href');
    $comentario['comentario_id'] = end(explode('/', $link_href));

    $exploded_texto = explode("\n", $div_header->text());
    $data_str = $exploded_texto[count($exploded_texto) - 2];
    $comentario['data'] = $data_str;

    $link_autor = htmlqp($div_header->html(), 'a[href*="@"]');
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
        $this->count_anexos++;

        $anexos[] = $this->salvarArquivo($link_attachment->attr('href'));
      }
      if (!empty($anexos)) {
        $comentario['anexos'] = $anexos;
      }
    }

    if (empty($comentario['comentario_id'])) {
      print_r($comentario);
      throw new Exception("\n\n#### Comentario sem ID");
    }

    $sub_comentarios = array();
    foreach (@qp($li, '> ul > li', array('ignore_parser_warnings' => TRUE)) as $li_sub_comentario) {
      $sub_comentarios[] = $this->processarLI($li_sub_comentario, $dados_comunidade, $dados_forum, $dados_topico, $comentario);
    }

    if (!empty($sub_comentarios)) {
      $comentario['sub_comentarios'] = $sub_comentarios;
    }
    return $comentario;
  }

  private function inserirElementoNoXML($elemento) {
    print_r("\n\n--------------------------------------------------------------\n");
    print_r("\nElementos processados: " . $this->count_foruns . "\n");
    print_r($elemento);

    $xml_item = $this->doc_foruns->createElement('item');
    foreach ($elemento as $key => $value) {
      $xml_element = $this->doc_foruns->createElement($key);
      $xml_element->nodeValue = $value;
      $xml_item->appendChild($xml_element);
    }
    $this->root_foruns->appendChild($xml_item);

    $this->doc_foruns->formatOutput = TRUE;
    $this->doc_foruns->save($this->arquivo_foruns);
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

    print_r("\n[pag " . $this->count_pagina . "]: ");
    print_r($final_url);

    return $resultado;
//    return mb_convert_encoding($resultado, 'UTF-8', mb_detect_encoding($resultado, 'UTF-8, ISO-8859-1', true));
  }

}