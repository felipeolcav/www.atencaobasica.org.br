<?php

/**
 * @file
 * Migração de dados complementares ao Benfeitoria.
 */

/**
 * Implements hook_drush_command().
 */
function dab_migracao_drush_command() {
  $commands = array();
  $commands['dab-migracao-papel-comunidade'] = array(
    'description' => 'Migração dos papeis dos usuários nas Comunidades',
    'aliases' => array('dab-mpc'),
  );
  $commands['dab-migracao-crawler-conteudo-comunidade'] = array(
    'description' => 'Crawler para buscar os arquivos das Comunidades',
    'aliases' => array('dab-ccc'),
  );
  $commands['dab-migracao-crawler-paginas-html-comunidade'] = array(
    'description' => 'Crawler para buscar o conteúdo das páginas html das Comunidades',
    'aliases' => array('dab-chtml'),
  );
  $commands['dab-migracao-crawler-forum-comunidade'] = array(
    'description' => 'Migração dos Fóruns das Comunidades',
    'aliases' => array('dab-cfc'),
  );

  return $commands;
}

/**
 * Callback for command l10n-update-refresh.
 */
function drush_dab_migracao_papel_comunidade() {

  $caminho_completo_arquivo = DRUPAL_ROOT . '/'
    . drupal_get_path('module', 'dab_migracao')
    . '/xml/comunidades.xml'; //arquivo xml gerado pelo plone/zope
  $parser = new ComunidadeXMLParser($caminho_completo_arquivo);
  $parser->executar();
}

function drush_dab_migracao_crawler_conteudo_comunidade() {
  $username = $_SERVER['argv'][3];
  $password = $_SERVER['argv'][4];

  $crawler = new CrawlerConteudoComunidade($username, $password);
  $crawler->executar();
}
function drush_dab_migracao_crawler_paginas_html_comunidade() {
  $username = $_SERVER['argv'][3];
  $password = $_SERVER['argv'][4];

  $crawler = new CrawlerPaginasHTML($username, $password);
  $crawler->executar();
}
function drush_dab_migracao_crawler_forum_comunidade() {
  $username = $_SERVER['argv'][3];
  $password = $_SERVER['argv'][4];

  $crawler = new CrawlerForumComunidade($username, $password);
  $crawler->executar();
}

