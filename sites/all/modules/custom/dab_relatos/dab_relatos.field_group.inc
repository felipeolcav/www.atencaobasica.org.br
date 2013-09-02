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
  $field_group->data = '';
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
  $field_group->data = '';
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
  $field_group->data = '';
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
  $field_group->data = '';
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
  $field_group->data = '';
  $export['group_terceira_etapa|node|experiencia|form'] = $field_group;

  return $export;
}
