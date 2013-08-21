<?php
/**
 * @file
 * dab_relatos.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dab_relatos_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'relatos_de_experi_ncia';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Relatos de experiência';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Relatos de experiência';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mais';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Aplicar';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Restaurar';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordenar por';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Crescente';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Itens por página';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Todos -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Deslocamento';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« início';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ anterior';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'próximo ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'fim »';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Campo: Conteúdo: Título */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Campo: Conteúdo: Data de publicação */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd/m - h:i';
  /* Campo: Conteúdo: Confirme o eixo temático */
  $handler->display->display_options['fields']['field_experiencia_catespecificas']['id'] = 'field_experiencia_catespecificas';
  $handler->display->display_options['fields']['field_experiencia_catespecificas']['table'] = 'field_data_field_experiencia_catespecificas';
  $handler->display->display_options['fields']['field_experiencia_catespecificas']['field'] = 'field_experiencia_catespecificas';
  $handler->display->display_options['fields']['field_experiencia_catespecificas']['label'] = 'Cat. Específicas';
  $handler->display->display_options['fields']['field_experiencia_catespecificas']['type'] = 'taxonomy_term_reference_plain';
  /* Campo: Handler quebrado ou não encontrado */
  $handler->display->display_options['fields']['field_experiencia_catgerais']['id'] = 'field_experiencia_catgerais';
  $handler->display->display_options['fields']['field_experiencia_catgerais']['table'] = 'field_data_field_experiencia_catgerais';
  $handler->display->display_options['fields']['field_experiencia_catgerais']['field'] = 'field_experiencia_catgerais';
  $handler->display->display_options['fields']['field_experiencia_catgerais']['label'] = 'Cat. gerais';
  /* Campo: Conteúdo: Âmbito da experiência */
  $handler->display->display_options['fields']['field_experiencia_ambito']['id'] = 'field_experiencia_ambito';
  $handler->display->display_options['fields']['field_experiencia_ambito']['table'] = 'field_data_field_experiencia_ambito';
  $handler->display->display_options['fields']['field_experiencia_ambito']['field'] = 'field_experiencia_ambito';
  $handler->display->display_options['fields']['field_experiencia_ambito']['type'] = 'taxonomy_term_reference_plain';
  /* Critério de ordenação: Conteúdo: Data de publicação */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Critério de filtragem: Conteúdo: Publicado */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Critério de filtragem: Conteúdo: Tipo */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'experiencia' => 'experiencia',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Critério de filtragem: Conteúdo: Título */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Título';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'titulo';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
  );
  /* Critério de filtragem: Conteúdo: Confirme o eixo temático (field_experiencia_catespecificas) */
  $handler->display->display_options['filters']['field_experiencia_catespecificas_tid']['id'] = 'field_experiencia_catespecificas_tid';
  $handler->display->display_options['filters']['field_experiencia_catespecificas_tid']['table'] = 'field_data_field_experiencia_catespecificas';
  $handler->display->display_options['filters']['field_experiencia_catespecificas_tid']['field'] = 'field_experiencia_catespecificas_tid';
  $handler->display->display_options['filters']['field_experiencia_catespecificas_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_experiencia_catespecificas_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_experiencia_catespecificas_tid']['expose']['operator_id'] = 'field_experiencia_catespecificas_tid_op';
  $handler->display->display_options['filters']['field_experiencia_catespecificas_tid']['expose']['label'] = 'Categorias Específicas';
  $handler->display->display_options['filters']['field_experiencia_catespecificas_tid']['expose']['operator'] = 'field_experiencia_catespecificas_tid_op';
  $handler->display->display_options['filters']['field_experiencia_catespecificas_tid']['expose']['identifier'] = 'cat_esp';
  $handler->display->display_options['filters']['field_experiencia_catespecificas_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_experiencia_catespecificas_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_experiencia_catespecificas_tid']['vocabulary'] = 'experiencia_eixos';
  $handler->display->display_options['filters']['field_experiencia_catespecificas_tid']['hierarchy'] = 1;
  /* Critério de filtragem: Handler quebrado ou não encontrado */
  $handler->display->display_options['filters']['field_experiencia_catgerais_tid']['id'] = 'field_experiencia_catgerais_tid';
  $handler->display->display_options['filters']['field_experiencia_catgerais_tid']['table'] = 'field_data_field_experiencia_catgerais';
  $handler->display->display_options['filters']['field_experiencia_catgerais_tid']['field'] = 'field_experiencia_catgerais_tid';
  $handler->display->display_options['filters']['field_experiencia_catgerais_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_experiencia_catgerais_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_experiencia_catgerais_tid']['expose']['operator_id'] = 'field_experiencia_catgerais_tid_op';
  $handler->display->display_options['filters']['field_experiencia_catgerais_tid']['expose']['label'] = 'Categorias gerais';
  $handler->display->display_options['filters']['field_experiencia_catgerais_tid']['expose']['operator'] = 'field_experiencia_catgerais_tid_op';
  $handler->display->display_options['filters']['field_experiencia_catgerais_tid']['expose']['identifier'] = 'cat_gerais';
  $handler->display->display_options['filters']['field_experiencia_catgerais_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
  );
  /* Critério de filtragem: Conteúdo: Âmbito da experiência (field_experiencia_ambito) */
  $handler->display->display_options['filters']['field_experiencia_ambito_tid']['id'] = 'field_experiencia_ambito_tid';
  $handler->display->display_options['filters']['field_experiencia_ambito_tid']['table'] = 'field_data_field_experiencia_ambito';
  $handler->display->display_options['filters']['field_experiencia_ambito_tid']['field'] = 'field_experiencia_ambito_tid';
  $handler->display->display_options['filters']['field_experiencia_ambito_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_experiencia_ambito_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_experiencia_ambito_tid']['expose']['operator_id'] = 'field_experiencia_ambito_tid_op';
  $handler->display->display_options['filters']['field_experiencia_ambito_tid']['expose']['label'] = 'Âmbito da experiência';
  $handler->display->display_options['filters']['field_experiencia_ambito_tid']['expose']['operator'] = 'field_experiencia_ambito_tid_op';
  $handler->display->display_options['filters']['field_experiencia_ambito_tid']['expose']['identifier'] = 'ambito';
  $handler->display->display_options['filters']['field_experiencia_ambito_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_experiencia_ambito_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_experiencia_ambito_tid']['vocabulary'] = 'experiencia_cat';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'relatos-de-experiencia';
  $translatables['relatos_de_experi_ncia'] = array(
    t('Master'),
    t('Relatos de experiência'),
    t('mais'),
    t('Aplicar'),
    t('Restaurar'),
    t('Ordenar por'),
    t('Crescente'),
    t('Desc'),
    t('Itens por página'),
    t('- Todos -'),
    t('Deslocamento'),
    t('« início'),
    t('‹ anterior'),
    t('próximo ›'),
    t('fim »'),
    t('Título'),
    t('Data de publicação'),
    t('Cat. Específicas'),
    t('Cat. gerais'),
    t('Âmbito da experiência'),
    t('Categorias Específicas'),
    t('Categorias gerais'),
    t('Page'),
  );
  $export['relatos_de_experi_ncia'] = $view;

  return $export;
}
