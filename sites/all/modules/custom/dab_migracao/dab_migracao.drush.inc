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
    'description' => 'Migração dos papeis dos usuários nas comunidades',
    'aliases' => array('dab-mpc'),
  );
  $commands['dab-migracao-crawler-conteudo-comunidade'] = array(
    'description' => 'Migração dos papeis dos usuários nas comunidades',
    'aliases' => array('dab-ccc'),
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

