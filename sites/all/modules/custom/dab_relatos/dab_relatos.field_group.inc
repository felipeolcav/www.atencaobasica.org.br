<?php
/**
 * @file
 * dab_relatos.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dab_relatos_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_etapas|node|experiencia|form';
  $field_group->group_name = 'group_etapas';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'experiencia';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Etapas',
    'weight' => '0',
    'children' => array(
      0 => 'group_primeira_etapa',
      1 => 'group_segunda_etapa',
      2 => 'group_terceira_etapa',
    ),
    'format_type' => 'accordion',
    'format_settings' => array(
      'label' => 'Etapas',
      'instance_settings' => array(
        'classes' => '',
        'effect' => 'bounceslide',
      ),
    ),
  );
  $export['group_etapas|node|experiencia|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_experiencia_atores|node|experiencia|form';
  $field_group->group_name = 'group_experiencia_atores';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'experiencia';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_terceira_etapa';
  $field_group->data = array(
    'label' => '',
    'weight' => '24',
    'children' => array(
      0 => 'field_experiencia_ator_categoria',
      1 => 'field_experiencia_ator_nome',
    ),
    'format_type' => 'field_group_multiple_table',
  );
  $export['group_experiencia_atores|node|experiencia|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_experiencia_autores|node|experiencia|form';
  $field_group->group_name = 'group_experiencia_autores';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'experiencia';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_terceira_etapa';
  $field_group->data = array(
    'label' => 'a. Autores do relato: quem inscreve e apresenta o relato de experiência',
    'weight' => '22',
    'children' => array(
      0 => 'field_experiencia_autorcat',
      1 => 'field_experiencia_autornome',
    ),
    'format_type' => 'field_group_multiple_table',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'parent_format_type' => 'div',
        'classes' => '',
        'required_fields' => 1,
        'row_titles' => '',
      ),
    ),
  );
  $export['group_experiencia_autores|node|experiencia|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_primeira_etapa|node|experiencia|form';
  $field_group->group_name = 'group_primeira_etapa';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'experiencia';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Primeira Etapa',
    'weight' => '0',
    'children' => array(
      0 => 'field_experiencia_ambito',
      1 => 'field_experiencia_catespecificas',
      2 => 'field_imagem_de_destaque',
      3 => 'field_topics',
      4 => 'og_group_ref',
      5 => 'title_field',
      6 => 'field_descricao',
      7 => 'path',
      8 => 'redirect',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Primeira Etapa',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_primeira_etapa|node|experiencia|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_segunda_etapa|node|experiencia|form';
  $field_group->group_name = 'group_segunda_etapa';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'experiencia';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Segunda Etapa',
    'weight' => '10',
    'children' => array(
      0 => 'field_experiencia_desafios',
      1 => 'field_experiencia_desenvolvida',
      2 => 'field_experiencia_funcionamento',
      3 => 'field_experiencia_novidades',
      4 => 'field_experiencia_observacoes',
      5 => 'field_imagem',
      6 => 'field_video',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Segunda Etapa',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_segunda_etapa|node|experiencia|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_terceira_etapa|node|experiencia|form';
  $field_group->group_name = 'group_terceira_etapa';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'experiencia';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Terceira Etapa',
    'weight' => '18',
    'children' => array(
      0 => 'field_experiencia_anexo',
      1 => 'field_field_exp_info_b',
      2 => 'field_exp_info_ab',
      3 => 'field_cidade',
      4 => 'field_estado',
      5 => 'field_envolve_quais_pontos_equip',
      6 => 'field_experiencia_pontosequipes',
      7 => 'group_experiencia_atores',
      8 => 'group_experiencia_autores',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Terceira Etapa',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_terceira_etapa|node|experiencia|form'] = $field_group;

  return $export;
}
