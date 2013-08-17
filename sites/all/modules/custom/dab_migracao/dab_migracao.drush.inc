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

  return $commands;
}

/**
 * Callback for command l10n-update-refresh.
 */
function drush_dab_migracao_papel_comunidade() {

  $caminho_completo_arquivo = $_SERVER['argv'][3]; //arquivo xml gerado pelo plone/zope
  $parser = new ComunidadeXMLParser($caminho_completo_arquivo);
  $parser->executar();
}

