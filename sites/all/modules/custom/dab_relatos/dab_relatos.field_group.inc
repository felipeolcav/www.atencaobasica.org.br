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
    'label' => '',
    'weight' => '0',
    'children' => array(
      0 => 'group_primeira_etapa',
      1 => 'group_segunda_etapa',
      2 => 'group_terceira_etapa',
    ),
    'format_type' => 'multipage-group',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'classes' => '',
        'page_header' => '0',
        'page_counter' => '0',
        'move_button' => '1',
        'move_additional' => '1',
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
    'label' => 'Atores: quem participa(ou) da experiência?',
    'weight' => '60',
    'children' => array(
      0 => 'field_experiencia_ator_nome',
      1 => 'field_experiencia_ator_categoria',
    ),
    'format_type' => 'field_group_multiple_table',
    'format_settings' => array(
      'label' => 'Atores: quem participa(ou) da experiência?',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
        'parent_format_type' => 'fieldset',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'row_titles' => '',
      ),
      'formatter' => 'open',
    ),
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
    'label' => ' Autores do relato: quem inscreve e apresenta o relato de experiência',
    'weight' => '58',
    'children' => array(
      0 => 'field_experiencia_autornome',
      1 => 'field_experiencia_autorcat',
    ),
    'format_type' => 'field_group_multiple_table',
    'format_settings' => array(
      'label' => ' Autores do relato: quem inscreve e apresenta o relato de experiência',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
        'parent_format_type' => 'fieldset',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'row_titles' => '',
      ),
      'formatter' => 'collapsible',
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
  $field_group->parent_name = 'group_etapas';
  $field_group->data = array(
    'label' => 'Primeira etapa',
    'weight' => '1',
    'children' => array(
      0 => 'field_imagem_de_destaque',
      1 => 'field_experiencia_ambito',
      2 => 'field_experiencia_catespecificas',
      3 => 'field_sub_eixo_1',
      4 => 'field_sub_eixo_2',
      5 => 'field_sub_eixo_3',
      6 => 'field_sub_eixo_4',
      7 => 'field_sub_eixo_5',
      8 => 'field_sub_eixo_6',
      9 => 'field_sub_eixo_7',
      10 => 'field_sub_eixo_8',
      11 => 'field_sub_eixo_9',
      12 => 'field_sub_eixo_10',
      13 => 'field_sub_eixo_11',
      14 => 'field_sub_eixo_12',
      15 => 'field_sub_eixo_13',
      16 => 'field_sub_eixo_14',
      17 => 'field_sub_eixo_15',
      18 => 'field_sub_eixo_16',
      19 => 'field_sub_eixo_17',
      20 => 'field_sub_eixo_18',
      21 => 'field_sub_eixo_19',
      22 => 'field_sub_eixo_20',
      23 => 'field_experiencia_catgerais',
      24 => 'field_experiencia_descricao',
      25 => 'field_info_1',
      26 => 'title',
      27 => 'path',
    ),
    'format_type' => 'multipage',
    'format_settings' => array(
      'formatter' => 'no-start',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
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
  $field_group->parent_name = 'group_etapas';
  $field_group->data = array(
    'label' => 'Segunda Etapa',
    'weight' => '2',
    'children' => array(
      0 => 'field_experiencia_desenvolvida',
      1 => 'field_experiencia_funcionamento',
      2 => 'field_experiencia_desafios',
      3 => 'field_experiencia_novidades',
      4 => 'field_experiencia_observacoes',
      5 => 'field_experiencia_tipomidia',
      6 => 'field_video',
      7 => 'field_imagem',
      8 => 'field_info_2',
    ),
    'format_type' => 'multipage',
    'format_settings' => array(
      'formatter' => 'no-start',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
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
  $field_group->parent_name = 'group_etapas';
  $field_group->data = array(
    'label' => 'Terceira etapa',
    'weight' => '3',
    'children' => array(
      0 => 'field_experiencia_pontosequipes',
      1 => 'field_experiencia_anexo',
      2 => 'field_label_group_1',
      3 => 'field_label_group_2',
      4 => 'field_endereco',
      5 => 'group_experiencia_atores',
      6 => 'group_experiencia_autores',
    ),
    'format_type' => 'multipage',
    'format_settings' => array(
      'formatter' => 'no-start',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_terceira_etapa|node|experiencia|form'] = $field_group;

  return $export;
}
