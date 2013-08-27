<?php

class CrawlerConteudoComunidade {

  const URL_BASE = "http://www.atencaobasica.org.br/";
  const USER_AGENT = "Mozilla/5.0 (Windows NT 6.1; rv:8.0) Gecko/20100101 Firefox/8.0";
  const COOKIE_FILE = "cookie.txt";
  const URL_PESQUISA = "http://www.atencaobasica.org.br/@@search?advanced_search=False&sort_on=Date&SearchableText=&portal_type%3Alist=CoPDocument&portal_type%3Alist=CoPFile&portal_type%3Alist=CoPImage&portal_type%3Alist=CoPLink&created.query%3Arecord%3Alist%3Adate=1970-01-02&created.range%3Arecord=min";

//const URL_PESQUISA = "http://www.atencaobasica.org.br/@@search?SearchableText=&sort_on=Date&b_start:int=0&advanced_search=False&sort_order=reverse&created.range:record=min&created.query:date:list:record=1970/01/02%2000%3A00%3A00%20GMT%2B0&portal_type:list=CoPDocument&portal_type:list=CoPFile&portal_type:list=CoPImage&portal_type:list=CoPLink";

  private $username;
  private $password;

  public function __construct($username, $password) {
    $this->username = $username;
    $this->password = $password;
  }

  public function executar() {
    //LEMBRAR DE LIMPAR O CONTEÚDO DA PASTA '../files' ANTES DE EXECUTAR ESSE SCRIPT

    $url_pagina_corrente = self::URL_PESQUISA;
    $count = 0;
    $pagina = 0;

    while (!empty($url_pagina_corrente)) {
      $pagina++;

      print_r("\n===============================================================");
      print_r("\n==================== TROCANDO DE PÁGINA =======================");
      print_r("\n===============================================================");
      print_r("\n [pag " . $pagina . "]: ");

      $pagina_pesquisa = $this->fazerRequisicaoWeb($url_pagina_corrente);

      $div_search_results = htmlqp($pagina_pesquisa, '#search-results-wrapper')->html();
      $link_proxima_pagina = htmlqp($pagina_pesquisa, 'div.listingBar span.next a');
      
      if (count($link_proxima_pagina->html()) > 0) {
        $url_pagina_corrente = $link_proxima_pagina->attr("href");
      }
      else {
        $url_pagina_corrente = NULL;
      }

      if (count($div_search_results) > 0) {
        $elemento_corrente = NULL;
        foreach (htmlqp($div_search_results, 'dl.searchResults > *') as $item) {
          $item_html = $item->html();

          if (preg_match('/\<dt.*\>/', $item_html)) {
            if (isset($elemento_corrente)) {
              $count++;
              print_r("\nCOUNT: " . $count);
              $this->inserirElementoNoXML($elemento_corrente);
              $elemento_corrente = NULL;
            }

            $link = htmlqp($item_html, 'a');
            $link_href = $link->attr("href");

            $img_icone_arquivo = htmlqp($item_html, 'img');
            $tipo_arquivo = $this->extrairTipo($img_icone_arquivo);
            $nome_arquivo = $this->salvarArquivo($link_href, $tipo_arquivo);

            $elemento_corrente = array(
              'link_href' => $link_href,
              'link_texto' => $link->text(),
              'privacidade' => $link->attr("class"),
              'nome_arquivo' => $nome_arquivo,
              'tipo_arquivo' => $tipo_arquivo,
            );
          }
          elseif (preg_match('/\<dd.*\>/', $item_html)) {
            $div_descricao = htmlqp($item_html, 'div');
            if (count($div_descricao->html()) > 0) {
              $elemento_corrente['descricao'] = $div_descricao->text();
            }
            
            $link_autor = htmlqp($item_html, 'span.discreet span.documentAuthor a');
            if (count($link_autor->html()) > 0) {
              $elemento_corrente['autor_email'] = $link_autor->attr("href");
              $elemento_corrente['autor_nome'] = $link_autor->text();
            }
          }
        }
        if (isset($elemento_corrente)) {
          $count++;
          print_r("\nCOUNT: " . $count);
          $this->inserirElementoNoXML($elemento_corrente);
          $elemento_corrente = NULL;
        }
      }
      else {
        print_r("\n\n######################################################\n");
        print_r("nao achou!!");
        print_r($div_search_results);
      }
    }
  }

  private function inserirElementoNoXML($elemento) {
    print_r("\n\n--------------------------------------------------------------\n");
    print_r($elemento);
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

  private function salvarArquivo($url, $tipo) {

    $nome_arquivo = preg_replace('/.*\/comunidades\//', '', $url);
    if (!preg_match('/.+\.[a-z]{3,4}/', $nome_arquivo)) {

      if (strlen($tipo) == 3 || strlen($tipo) == 4) {
        $nome_arquivo .= '.' . $tipo;
      }
      else {
        if ($tipo == 'link_icon' || $tipo == 'document_icon') {
          $nome_arquivo .= '.' . 'html';
        }
      }
    }

    $caminho_arquivo = realpath(__DIR__ . '/..');
    $caminho_arquivo .= '/files/' . $nome_arquivo;

    $contador = 1;
    while (file_exists($caminho_arquivo)) {
      $contador++;
      $regex_sufixo = '(_[0-9]+)?\.'; //Exemplo: '/caminho/do/arquivo/nome.txt' => '.' ou '/caminho/do/arquivo/nome_2.txt' => '_2.'
      $caminho_arquivo = preg_replace("/$regex_sufixo(?!.*$regex_sufixo)/", "_$contador.", $caminho_arquivo);
    }

    $dirname = dirname($caminho_arquivo);
    if (!is_dir($dirname)) {
      mkdir($dirname, 0755, true);
    }

    $this->fazerRequisicaoDownloadArquivo($url, $caminho_arquivo);


    return $caminho_arquivo;
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
    curl_setopt($ch, CURLOPT_ENCODING, "");
    $resultado = curl_exec($ch);
    $final_url = curl_getinfo($ch, CURLINFO_EFFECTIVE_URL);
    print_r($final_url);
    curl_close($ch);

    return $resultado;
//    return mb_convert_encoding($content, 'UTF-8', mb_detect_encoding($content, 'UTF-8, ISO-8859-1', true));
  }

}