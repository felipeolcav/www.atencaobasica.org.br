<?php

class CrawlerPaginasHTML {

  const CAMINHO_ARQ_XML_PAGINAS_HTML = "./sites/all/modules/custom/dab_migracao/xml/paginas-html-comunidade.xml";
  const CAMINHO_ARQ_XML_COMENTARIOS = "./sites/all/modules/custom/dab_migracao/xml/comentarios-paginas-html-comunidade.xml";
  const URL_BASE = "http://www.atencaobasica.org.br/";
  const USER_AGENT = "Mozilla/5.0 (Windows NT 6.1; rv:8.0) Gecko/20100101 Firefox/8.0";
  const URL_PESQUISA = "http://www.atencaobasica.org.br/@@search?created.query:date:list:record=1970/01/02%2000%3A00%3A00%20GMT%2B0&created.range:record=min&advanced_search=False&sort_order=reverse&portal_type:list=CoPDocument&sort_on=Date&SearchableText=&b_start:int=0";

  private $username;
  private $password;
  private $count_itens_processados;
  private $count_pagina;
  private $doc_html;
  private $doc_comentarios;
  private $root_html;
  private $root_comentarios;

  public function __construct($username, $password) {
    $this->username = $username;
    $this->password = $password;
    if (file_exists(self::CAMINHO_ARQ_XML_PAGINAS_HTML)) {
      unlink(self::CAMINHO_ARQ_XML_PAGINAS_HTML);
    }
    if (file_exists(self::CAMINHO_ARQ_XML_COMENTARIOS)) {
      unlink(self::CAMINHO_ARQ_XML_COMENTARIOS);
    }
  }

  public function executar() {
    $this->doc_html = new DOMDocument('1.0', 'utf-8');
    $this->root_html = $this->doc_html->createElement('root');
    $this->doc_html->appendChild($this->root_html);

    $this->doc_comentarios = new DOMDocument('1.0', 'utf-8');
    $this->root_comentarios = $this->doc_comentarios->createElement('root');
    $this->doc_comentarios->appendChild($this->root_comentarios);

    $url_pagina_corrente = self::URL_PESQUISA;
    $this->count_itens_processados = 0;
    $this->count_pagina = 0;

    while (!empty($url_pagina_corrente)) {
      $this->count_pagina++;

      print_r("\n===============================================================");
      print_r("\n==================== TROCANDO DE PÁGINA =======================");
      print_r("\n===============================================================");

      $pagina_pesquisa = $this->fazerRequisicaoWeb($url_pagina_corrente);

      $div_search_results = @qp($pagina_pesquisa, '#search-results-wrapper', array('ignore_parser_warnings' => TRUE))->html();
      $link_proxima_pagina = htmlqp($pagina_pesquisa, 'div.listingBar span.next a');

      if (count($link_proxima_pagina->html()) > 0) {
        $url_pagina_corrente = $link_proxima_pagina->attr("href");
      }
      else {
        $url_pagina_corrente = NULL;
      }

      if (count($div_search_results) > 0) {
        $elemento_corrente = NULL;
        foreach (htmlqp($div_search_results, 'dl.searchResults > dt') as $item) {
          $item_html = $item->html();

          $link = htmlqp($item_html, 'a');
          $link_href = $link->attr("href");

          $img_icone_arquivo = htmlqp($item_html, 'img');
          $tipo_arquivo = $this->extrairTipo($img_icone_arquivo);

          preg_match('/.*\/comunidades\/([^\/]*)\/.*/', $link_href, $match);
          $comunidade = end($match);

          $elemento_corrente = $this->processarURL($link_href, $tipo_arquivo);

          if (isset($elemento_corrente)) {

            $elemento_corrente['id_link_hash'] = hash('md5', $link_href);
            $elemento_corrente['comunidade'] = $comunidade;
            $elemento_corrente['link_href'] = $link_href;
            $elemento_corrente['link_texto'] = $link->text();
            $elemento_corrente['privacidade'] = $link->attr("class");

            $this->count_itens_processados++;
            $this->inserirElementoNoXML($elemento_corrente);
          }
        }
      }
    }
  }

  private function inserirElementoNoXML($elemento) {
    print_r("\n\n--------------------------------------------------------------\n");
    print_r("\nElementos processados: " . $this->count_itens_processados . "\n");
    print_r($elemento);

    //página HTML --------------------------------------------------------------
    $item_pagina_html = $this->doc_html->createElement('pagina_html');
    foreach ($elemento as $key => $value) {
      if ($key != 'comentarios') {
        $xml_element = $this->doc_html->createElement($key);
        $xml_element->nodeValue = $value;
        $item_pagina_html->appendChild($xml_element);
      }
    }
    $this->root_html->appendChild($item_pagina_html);

    $this->doc_html->formatOutput = TRUE;
    $this->doc_html->save(self::CAMINHO_ARQ_XML_PAGINAS_HTML);
    //--------------------------------------------------------------------------


    /*
     * $elemento_corrente['comunidade'] = $comunidade;
      $elemento_corrente['link_href'] = $link_href;
      $elemento_corrente['link_texto'] = $link->text();
     */

    /*
      $elemento['comentarios'][$id] = array(
      'autor_email' => $autor_email
      , 'data' => $data
      , 'conteudo' => $conteudo
      , 'comentario_pai_id' => $id_pai
      , 'visibilidade' => $visibilidade
      );

     */

    //comentários das páginas HTML ---------------------------------------------
    if (!empty($elemento['comentarios'])) {
      foreach ($elemento['comentarios'] as $id_comentario => $dados_comentario) {
        $item_comentario = $this->doc_comentarios->createElement('comentario_pagina');

        $prop_comentario = $this->doc_comentarios->createElement('comentario_id');
        $prop_comentario->nodeValue = $id_comentario;
        $item_comentario->appendChild($prop_comentario);
        

        foreach ($dados_comentario as $key_comentario => $value_comentario) {
          $prop_comentario = $this->doc_comentarios->createElement($key_comentario);
          $prop_comentario->nodeValue = $value_comentario;
          $item_comentario->appendChild($prop_comentario);
        }
        
        $prop_comunidade = $this->doc_comentarios->createElement('comunidade');
        $prop_comunidade->nodeValue = $elemento['comunidade'];
        $item_comentario->appendChild($prop_comunidade);
        
        $prop_link_href = $this->doc_comentarios->createElement('pagina_link_href');
        $prop_link_href->nodeValue = $elemento['link_href'];
        $item_comentario->appendChild($prop_link_href);
        
        $prop_link_texto = $this->doc_comentarios->createElement('pagina_link_texto');
        $prop_link_texto->nodeValue = $elemento['link_texto'];
        $item_comentario->appendChild($prop_link_texto);
        
        $this->root_comentarios->appendChild($item_comentario);
      }

      $this->doc_comentarios->formatOutput = TRUE;
      $this->doc_comentarios->save(self::CAMINHO_ARQ_XML_COMENTARIOS);
    }
    //--------------------------------------------------------------------------
  }

  private function extrairTipo($img_icone_arquivo) {
    /*
     * <img width="16" 
     * height="16" 
     * src="http://www.atencaobasica.org.br/link_icon.png.pagespeed.ce.kyJMGuOEqv.png" 
     * alt="Link" 
     * pagespeed_url_hash="1271360551">
     */

    $src = $img_icone_arquivo->attr("src");
    $regex_tipo = "/http:\/\/www\.atencaobasica\.org\.br\/(.+)\.png.+/";
    preg_match($regex_tipo, $src, $matches);

    if (count($matches) == 2) {
      return $matches[1];
    }
    return NULL;
  }

  private function processarURL($url, $tipo) {

    if ($tipo != 'document_icon') {
      print_r("\n\n######## Pulando arquivos não html: " . $url);
      return NULL;
    }

    $elemento = array();

    $pagina_conteudo_html = $this->fazerRequisicaoWeb($url);
    $div_cop_container = @qp($pagina_conteudo_html, 'div.cop_container', array('ignore_parser_warnings' => TRUE));

    $elemento['titulo'] = htmlqp($div_cop_container, '>h1')->text();

    $div_info_pag = htmlqp($div_cop_container, '> div#viewlet-below-content-title > div#plone-document-byline');

    $link_autor = htmlqp($div_info_pag, '> span.documentAuthor > a');
    $elemento['autor_email'] = end(explode('/', $link_autor->attr('href')));

    $span_data = htmlqp($div_info_pag, '> span.documentModified');
    $elemento['data_modificacao'] = str_replace(array('última modificação', "\n"), array('', ''), $span_data->text());

    $div_conteudo = @qp($div_cop_container, '> div#content', array('ignore_parser_warnings' => TRUE));
    $elemento['conteudo'] = $div_conteudo->html();
    

    $elemento['comentarios'] = array();
    $div_discussao = @qp($pagina_conteudo_html, 'div.discussion', array('ignore_parser_warnings' => TRUE));

    $ultimos_ids_por_nivel = array();
    foreach (htmlqp($div_discussao, '> div.comment') as $div_comment) {
      $id = $div_comment->attr('id');

      $classes = $div_comment->attr('class');
      preg_match('/replyTreeLevel([0-9]+)/', $classes, $match);
      $nivel = end($match);
      $id_pai = $ultimos_ids_por_nivel[$nivel - 1];

      preg_match('/state\-(.+)/', $classes, $match);
      $visibilidade = end($match);

      $link_autor = htmlqp($div_comment, '> div.documentByLine > a');
      $autor_email = end(explode('/', $link_autor->attr('href')));
      $data = htmlqp($div_comment, '> div.documentByLine > div.commentDate')->text();
      $conteudo = htmlqp($div_comment, '> div.commentBody > p')->text();

      $elemento['comentarios'][$id] = array(
        'autor_email' => $autor_email
        , 'data' => $data
        , 'conteudo' => $conteudo
        , 'comentario_pai_id' => $id_pai
        , 'visibilidade' => $visibilidade
      );

      $ultimos_ids_por_nivel[$nivel] = $id;
    }

    return $elemento;
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

    print_r("\n [pag " . $this->count_pagina . "]: ");
    print_r($final_url);

    return $resultado;
//    return mb_convert_encoding($resultado, 'UTF-8', mb_detect_encoding($resultado, 'UTF-8, ISO-8859-1', true));
  }

}