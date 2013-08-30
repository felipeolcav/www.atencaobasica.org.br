<?php
/**
 * @file
 * dab_features.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function dab_features_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'dab_activity_streams_activity_site_wide';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'message';
  $view->human_name = 'DAB Activity Streams - Activity (Site-wide)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Atividades recentes';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mais';
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Aplicar';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Restaurar';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordenar por';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Crescente';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Itens por página';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Todos -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Deslocamento';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« início';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ anterior';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'próximo ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'fim »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Comportamento quando sem resultados: Global: Área de texto */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No activity matched the filters you selected.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relação: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_target_nodes_target_id']['id'] = 'field_target_nodes_target_id';
  $handler->display->display_options['relationships']['field_target_nodes_target_id']['table'] = 'field_data_field_target_nodes';
  $handler->display->display_options['relationships']['field_target_nodes_target_id']['field'] = 'field_target_nodes_target_id';
  /* Campo: Mensagem: Timestamp */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'message';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'time_ago_dynamic';
  /* Campo: Mensagem: @entity-tipe renderizado(a) */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_message';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['label'] = '';
  $handler->display->display_options['fields']['rendered_entity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['display'] = 'view';
  $handler->display->display_options['fields']['rendered_entity']['view_mode'] = 'full';
  $handler->display->display_options['fields']['rendered_entity']['bypass_access'] = 0;
  /* Critério de ordenação: Mensagem: Timestamp */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'message';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  /* Filtro contextual: Mensagem: Mensagem ID */
  $handler->display->display_options['arguments']['mid']['id'] = 'mid';
  $handler->display->display_options['arguments']['mid']['table'] = 'message';
  $handler->display->display_options['arguments']['mid']['field'] = 'mid';
  $handler->display->display_options['arguments']['mid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['mid']['exception']['title'] = 'Tudo';
  $handler->display->display_options['arguments']['mid']['default_argument_type'] = 'commons_follow_message';
  $handler->display->display_options['arguments']['mid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['mid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['mid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['mid']['break_phrase'] = TRUE;
  /* Critério de filtragem: Acesso ao conteúdo: Acesso */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node_access';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['relationship'] = 'field_target_nodes_target_id';
  /* Critério de filtragem: Conteúdo: Publicado ou admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['relationship'] = 'field_target_nodes_target_id';
  /* Critério de filtragem: Mensagem: User Follow */
  $handler->display->display_options['filters']['cf_user_follow_message']['id'] = 'cf_user_follow_message';
  $handler->display->display_options['filters']['cf_user_follow_message']['table'] = 'message';
  $handler->display->display_options['filters']['cf_user_follow_message']['field'] = 'cf_user_follow_message';
  $handler->display->display_options['filters']['cf_user_follow_message']['value'] = '0';
  $handler->display->display_options['filters']['cf_user_follow_message']['exposed'] = TRUE;
  $handler->display->display_options['filters']['cf_user_follow_message']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['cf_user_follow_message']['expose']['label'] = 'Exibir';
  $handler->display->display_options['filters']['cf_user_follow_message']['expose']['operator'] = 'cf_user_follow_message_op';
  $handler->display->display_options['filters']['cf_user_follow_message']['expose']['identifier'] = 'following';
  $handler->display->display_options['filters']['cf_user_follow_message']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['cf_user_follow_message']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['cf_user_follow_message']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Critério de filtragem: Mensagem: Message category */
  $handler->display->display_options['filters']['type_category']['id'] = 'type_category';
  $handler->display->display_options['filters']['type_category']['table'] = 'message';
  $handler->display->display_options['filters']['type_category']['field'] = 'type_category';
  $handler->display->display_options['filters']['type_category']['value'] = array(
    'message_type' => 'message_type',
  );

  /* Display: Activity (Sidebar) */
  $handler = $view->new_display('panel_pane', 'Activity (Sidebar)', 'panel_pane_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mais';
  $handler->display->display_options['link_url'] = 'activity';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relação: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_target_nodes_target_id']['id'] = 'field_target_nodes_target_id';
  $handler->display->display_options['relationships']['field_target_nodes_target_id']['table'] = 'field_data_field_target_nodes';
  $handler->display->display_options['relationships']['field_target_nodes_target_id']['field'] = 'field_target_nodes_target_id';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Critério de filtragem: Mensagem: Message category */
  $handler->display->display_options['filters']['type_category']['id'] = 'type_category';
  $handler->display->display_options['filters']['type_category']['table'] = 'message';
  $handler->display->display_options['filters']['type_category']['field'] = 'type_category';
  $handler->display->display_options['filters']['type_category']['value'] = array(
    'message_type' => 'message_type',
  );
  /* Critério de filtragem: Conteúdo: Publicado ou admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['relationship'] = 'field_target_nodes_target_id';
  /* Critério de filtragem: Acesso ao conteúdo: Acesso */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node_access';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['relationship'] = 'field_target_nodes_target_id';
  $handler->display->display_options['pane_category']['name'] = 'Commons';
  $handler->display->display_options['pane_category']['weight'] = '0';

  /* Display: Activity - Full view */
  $handler = $view->new_display('panel_pane', 'Activity - Full view', 'panel_pane_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pane_category']['name'] = 'Commons';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['inherit_panels_path'] = '1';
  $translatables['dab_activity_streams_activity_site_wide'] = array(
    t('Master'),
    t('Atividades recentes'),
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
    t('No activity matched the filters you selected.'),
    t('Conteúdo entity referenced from field_target_nodes'),
    t('Tudo'),
    t('Exibir'),
    t('Activity (Sidebar)'),
    t('Commons'),
    t('Activity - Full view'),
  );
  $export['dab_activity_streams_activity_site_wide'] = $view;

  return $export;
}
