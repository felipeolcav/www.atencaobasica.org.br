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
  $file_handle = fopen($caminho_completo_arquivo, "r");

  while ($file_handle && !feof($file_handle)) {
    //o global a seguir já está dentro de um pickle (que é o primeiro)
    $linha = avancarAteItem($file_handle, 'global', TRUE, 'module="communities.practice.content.CoP"');
    print_r($linha);

    $linha = avancarAteItem($file_handle, 'pickle', TRUE); //aqui já é o segundo pickle

    for ($i = 0; $i < 45; $i++) {
      $linha = avancarAteItem($file_handle, 'item', TRUE);
    }
    $linha = avancarAteItem($file_handle, 'key', NULL, '__ac_local_roles__');
    $linha = avancarAteItem($file_handle, 'dictionary', TRUE);
    $linha = processarDictionaryMailRole($file_handle, $linha);

    print_r("\n\n-----------------------------------------------------------------");
  }
  if ($file_handle) {
    fclose($file_handle);
  }
}

function avancarAteItem(&$file_handle, $tipo_tag, $tagAbertura = NULL, $contendo = NULL, $print = FALSE) {

  while ($file_handle && !feof($file_handle)) {
    $linha = fgets($file_handle);
    if ($print) {
      print_r($linha);
    }

    if (isTagTipo($tipo_tag, $linha)) {
      if ($tagAbertura == NULL) {
        if (empty($contendo) || contemString($linha, $contendo)) {
          return $linha;
        }
      }
      elseif ($tagAbertura) {
        if (isTagAbertura($linha)
          && (empty($contendo) || contemString($linha, $contendo))) {
          return $linha;
        }
      }
      else {
        if (!isTagAbertura($linha)) {
          return $linha;
        }
      }
    }
  }
  return NULL;
}

function processarDictionaryMailRole(&$file_handle, $linha) {
  if (!isTagTipo('dictionary', $linha) || !isTagAbertura($linha)) {
    throw new Exception('Era esperada uma tag de abertura do tipo dictionary. Linha: ' . $linha);
  }
  $linha = fgets($file_handle);

  while ((isTagTipo('item', $linha) && isTagAbertura($linha))) {
    $linha = avancarAteItem($file_handle, 'key');

    $email = extrairConteudoString($linha);
    print_r("\n" . $email . " => ");

    $papeis = array();

    //tem um <value> como pai do <list>
    $linha = avancarAteItem($file_handle, 'list', TRUE);
    $linha = fgets($file_handle);
    while (!(isTagTipo('list', $linha) && !isTagAbertura($linha))) {//</list>
      $papel = extrairConteudoString($linha);
      if (!empty($papel)) {
        $papeis[] = $papel;
      }else{
        //TODO: tratar aquele caso de ser a tag 'reference' em vez de 'string' 
      }
      $linha = fgets($file_handle);
    }

    print_r(implode(',', $papeis));

    $linha = avancarAteItem($file_handle, 'item', FALSE);
    $linha = fgets($file_handle);
  }
}

function extrairConteudoString($linha) {
  preg_match('/\<string.*\>(.+)\<\/string\>/', $linha, $matches);
  return $matches[1];
}

function isTagAbertura($tag) {
  return !contemString($tag, '</');
}

function contemString($texto, $valor_procurado) {
  return strpos($texto, $valor_procurado) !== false;
}

function isTagTipo($tipo_elemento, $linha) {
  return preg_match('/\<\/?' . $tipo_elemento . '(.*)\>/', $linha);
}