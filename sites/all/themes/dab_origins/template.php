<?php

/**
 * Melhorias de usabilidade nos formulários de Node em geral
 */
function dab_origins_form_node_form_alter(&$form, &$form_state, &$form_id) {

  if (isset($_GET['og_group_ref'])) {
    $comunidade = node_load($_GET['og_group_ref']);
    $titulo_original = drupal_get_title();
    drupal_set_title($comunidade->title . ' / ' . $titulo_original);
  }

}