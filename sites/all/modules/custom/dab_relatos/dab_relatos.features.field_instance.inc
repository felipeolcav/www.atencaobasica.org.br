<?php
/**
 * @file
 * dab_relatos.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function dab_relatos_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'comment-comment_node_experiencia-comment_body'
  $field_instances['comment-comment_node_experiencia-comment_body'] = array(
    'bundle' => 'comment_node_experiencia',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'comment',
    'field_name' => 'comment_body',
    'label' => 'Comment',
    'required' => TRUE,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_cidade'
  $field_instances['node-experiencia-field_cidade'] = array(
    'bundle' => 'experiencia',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Clique e digite o nome de sua cidade (com acentos) para buscar',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 16,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'display_in_partial_form' => 0,
    'entity_type' => 'node',
    'field_name' => 'field_cidade',
    'label' => 'd. Onde ocorre a experiência?',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
      ),
      'type' => 'options_select',
      'weight' => 27,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_descricao'
  $field_instances['node-experiencia-field_descricao'] = array(
    'bundle' => 'experiencia',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'As informações desse campo serão utilizadas para divulgação da experiência! Por isso, "venda seu peixe!", diga em poucas palavras sobre o que é a experiência e porque é interessante que outras pessoas a conheçam. (máximo de 500 caracteres)',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'display_in_partial_form' => 1,
    'entity_type' => 'node',
    'field_name' => 'field_descricao',
    'label' => 'Venda seu peixe!',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => 500,
        'maxlength_js_enforce' => 0,
        'maxlength_js_label' => 'Conteúdo limitado a @limit caracteres. Restando: <strong>@remaining</strong>',
        'maxlength_js_truncate_html' => 0,
        'rows' => 3,
      ),
      'type' => 'text_textarea',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_envolve_quais_pontos_equip'
  $field_instances['node-experiencia-field_envolve_quais_pontos_equip'] = array(
    'bundle' => 'experiencia',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Digite 1 ou 2 letras e veja os <b>pontos da rede</b> já existentes. Caso não encontre um que contemple, termine de digitar para adicionar um novo.

Para inserir mais de um, separe-os entre vírgulas.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 24,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'display_in_partial_form' => 0,
    'entity_type' => 'node',
    'field_name' => 'field_envolve_quais_pontos_equip',
    'label' => 'Envolve quais pontos / equipes da rede?',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => 25,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_estado'
  $field_instances['node-experiencia-field_estado'] = array(
    'bundle' => 'experiencia',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 21,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'display_in_partial_form' => 0,
    'entity_type' => 'node',
    'field_name' => 'field_estado',
    'label' => 'Estado',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
      ),
      'type' => 'options_select',
      'weight' => 28,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_exp_info_a'
  $field_instances['node-experiencia-field_exp_info_a'] = array(
    'bundle' => 'experiencia',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 22,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'display_in_partial_form' => 0,
    'entity_type' => 'node',
    'exclude_cv' => 0,
    'field_name' => 'field_exp_info_a',
    'label' => 'exp_info_a',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'markup',
      'settings' => array(
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
      ),
      'type' => 'markup',
      'weight' => 63,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_exp_info_ab'
  $field_instances['node-experiencia-field_exp_info_ab'] = array(
    'bundle' => 'experiencia',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 20,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_exp_info_ab',
    'label' => 'field_exp_info_a',
    'required' => FALSE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'markup',
      'settings' => array(),
      'type' => 'markup',
      'weight' => 21,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_experiencia_ambito'
  $field_instances['node-experiencia-field_experiencia_ambito'] = array(
    'bundle' => 'experiencia',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_experiencia_ambito',
    'label' => 'Âmbito da experiência',
    'required' => 1,
    'settings' => array(
      'exclude_cv' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
      ),
      'type' => 'options_buttons',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_experiencia_anexo'
  $field_instances['node-experiencia-field_experiencia_anexo'] = array(
    'bundle' => 'experiencia',
    'deleted' => 0,
    'description' => 'Anexe aqui termos de autorização de uso de imagem ou termo de consentimento de entrevista (clique aqui para mais informações).',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 17,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'display_in_partial_form' => 0,
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'extra_description' => array(
      'multiple' => 0,
      'over_description' => 'Anexe aqui termos de autorização de uso de imagem ou termo de consentimento de entrevista (clique aqui para mais informações)',
    ),
    'field_name' => 'field_experiencia_anexo',
    'label' => 'Arquivos anexados',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'exclude_cv' => FALSE,
      'file_directory' => '',
      'file_extensions' => 'doc docx odf pdf zip',
      'filefield_paths' => array(
        'active_updating' => 0,
        'file_name' => array(
          'options' => array(
            'pathauto' => 0,
            'transliterate' => 0,
          ),
          'value' => '[file:ffp-name-only-original].[file:ffp-extension-original]',
        ),
        'file_path' => array(
          'options' => array(
            'pathauto' => 0,
            'transliterate' => 0,
          ),
          'value' => 'uploads/[node:content-type:machine-name]/[node:nid]',
        ),
        'retroactive_update' => 0,
      ),
      'filefield_paths_enabled' => 1,
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'filefield_sources' => array(
          'filefield_sources' => array(),
          'source_attach' => array(
            'absolute' => 0,
            'attach_mode' => 'move',
            'path' => 'file_attach',
          ),
          'source_imce' => array(
            'imce_mode' => 0,
          ),
          'source_reference' => array(
            'autocomplete' => 0,
          ),
        ),
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 29,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_experiencia_ator_categoria'
  $field_instances['node-experiencia-field_experiencia_ator_categoria'] = array(
    'bundle' => 'experiencia',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 14,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'display_in_partial_form' => 0,
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'exclude_cv' => 0,
    'extra_description' => array(
      'multiple' => 0,
      'over_description' => '',
    ),
    'field_name' => 'field_experiencia_ator_categoria',
    'label' => 'Categoria',
    'required' => 1,
    'settings' => array(
      'exclude_cv' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
      ),
      'type' => 'options_select',
      'weight' => 26,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_experiencia_ator_nome'
  $field_instances['node-experiencia-field_experiencia_ator_nome'] = array(
    'bundle' => 'experiencia',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 13,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'display_in_partial_form' => 0,
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'exclude_cv' => 0,
    'extra_description' => array(
      'multiple' => 0,
      'over_description' => '',
    ),
    'field_name' => 'field_experiencia_ator_nome',
    'label' => 'Nome',
    'required' => 1,
    'settings' => array(
      'exclude_cv' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 25,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_experiencia_autorcat'
  $field_instances['node-experiencia-field_experiencia_autorcat'] = array(
    'bundle' => 'experiencia',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 12,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'display_in_partial_form' => 0,
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'extra_description' => array(
      'multiple' => 0,
      'over_description' => '',
    ),
    'field_name' => 'field_experiencia_autorcat',
    'label' => 'Categoria',
    'required' => 1,
    'settings' => array(
      'exclude_cv' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
      ),
      'type' => 'options_select',
      'weight' => 23,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_experiencia_autornome'
  $field_instances['node-experiencia-field_experiencia_autornome'] = array(
    'bundle' => 'experiencia',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 11,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'display_in_partial_form' => 0,
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'extra_description' => array(
      'multiple' => 0,
      'over_description' => '',
    ),
    'field_name' => 'field_experiencia_autornome',
    'label' => 'Nome',
    'required' => 1,
    'settings' => array(
      'exclude_cv' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 22,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_experiencia_catespecificas'
  $field_instances['node-experiencia-field_experiencia_catespecificas'] = array(
    'bundle' => 'experiencia',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'display_in_partial_form' => 0,
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_experiencia_catespecificas',
    'label' => 'Confirme o eixo temático',
    'required' => 1,
    'settings' => array(
      'exclude_cv' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 0,
      ),
      'type' => 'options_select',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_experiencia_desafios'
  $field_instances['node-experiencia-field_experiencia_desafios'] = array(
    'bundle' => 'experiencia',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'display_in_partial_form' => 0,
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'extra_description' => array(
      'multiple' => 0,
      'over_description' => '',
    ),
    'field_name' => 'field_experiencia_desafios',
    'label' => 'Desafios para o desenvolvimento',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'label_help_description' => 'Durante o desenvolvimento da experiência surgiram desafios que demandaram improvisos? De quais conhecimentos, e/ou articulações lançaram mão para responder aos desafios? (máximo de 4000 caracteres com espaços)',
        'maxlength_js' => '',
        'maxlength_js_enforce' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'maxlength_js_truncate_html' => 0,
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 13,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_experiencia_desenvolvida'
  $field_instances['node-experiencia-field_experiencia_desenvolvida'] = array(
    'bundle' => 'experiencia',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'display_in_partial_form' => 0,
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'extra_description' => array(
      'multiple' => 0,
      'over_description' => '',
    ),
    'field_name' => 'field_experiencia_desenvolvida',
    'label' => 'Qual foi a experiência desenvolvida? Sobre o que foi?',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'label_help_description' => 'Fale em termos gerais sobre o que é a experiência, detalhando mais as informações colocadas no campo "venda seu peixe". (máximo de 4000 caracteres com espaços)',
        'maxlength_js' => '',
        'maxlength_js_enforce' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'maxlength_js_truncate_html' => 0,
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_experiencia_funcionamento'
  $field_instances['node-experiencia-field_experiencia_funcionamento'] = array(
    'bundle' => 'experiencia',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'display_in_partial_form' => 0,
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'extra_description' => array(
      'multiple' => 0,
      'over_description' => '',
    ),
    'field_name' => 'field_experiencia_funcionamento',
    'label' => 'Como funciona(ou) a experiência?',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'label_help_description' => 'Como o município ou estado se organizou para realizar a experiência? (caso se aplique) Como a equipe se organizou para para realizar a experiência? (caso se aplique) Trata-se de uma experiência planejada? Quais foram as etapas do trabalho realizado? Houve apoio de outros níveis de gestão – distrital, município, região, estado? Houve apoio local? De quem foi a iniciativa para o início da experiência? Houve adesão de outros membros da equipe? (caso se aplique) Como a proposta foi acolhida? De quem foi a iniciativa para o início da experiência? (máximo de 4000 caracteres com espaços)',
        'maxlength_js' => '',
        'maxlength_js_enforce' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'maxlength_js_truncate_html' => 0,
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_experiencia_novidades'
  $field_instances['node-experiencia-field_experiencia_novidades'] = array(
    'bundle' => 'experiencia',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 7,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'display_in_partial_form' => 0,
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'extra_description' => array(
      'multiple' => 0,
      'over_description' => '',
    ),
    'field_name' => 'field_experiencia_novidades',
    'label' => 'Quais as novidades?',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'label_help_description' => 'Quais estratégias de ação foram sendo formuladas/produzidas durante o percurso da experiência? O que foi novo e desafiador? A experiência favoreceu uma mudança no processo de trabalho? Ajudou a pensar estratégias para outras ações? (máximo de 4000 caracteres com espaços)',
        'maxlength_js' => '',
        'maxlength_js_enforce' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'maxlength_js_truncate_html' => 0,
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 14,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_experiencia_observacoes'
  $field_instances['node-experiencia-field_experiencia_observacoes'] = array(
    'bundle' => 'experiencia',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 8,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'display_in_partial_form' => 0,
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'extra_description' => array(
      'multiple' => 0,
      'over_description' => '',
    ),
    'field_name' => 'field_experiencia_observacoes',
    'label' => 'Outras observações/campo livre',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'label_help_description' => '(máximo de 4000 caracteres com espaços)',
        'maxlength_js' => '',
        'maxlength_js_enforce' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'maxlength_js_truncate_html' => 0,
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 15,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_field_exp_info_b'
  $field_instances['node-experiencia-field_field_exp_info_b'] = array(
    'bundle' => 'experiencia',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 18,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'display_in_partial_form' => 0,
    'entity_type' => 'node',
    'exclude_cv' => 0,
    'field_name' => 'field_field_exp_info_b',
    'label' => 'field_exp_info_b',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'markup',
      'settings' => array(
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
      ),
      'type' => 'markup',
      'weight' => 23,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_imagem'
  $field_instances['node-experiencia-field_imagem'] = array(
    'bundle' => 'experiencia',
    'deleted' => 0,
    'description' => 'Clique em upload e o sistema permitirá adicionar mais uma imagem',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => 'file',
          'image_style' => 'large',
        ),
        'type' => 'image',
        'weight' => 10,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'display_in_partial_form' => 0,
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'extra_description' => array(
      'multiple' => 0,
      'over_description' => '',
    ),
    'field_name' => 'field_imagem',
    'label' => 'Galeria de imagens',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'filefield_paths' => array(
        'active_updating' => 0,
        'file_name' => array(
          'options' => array(
            'pathauto' => 1,
            'transliterate' => 1,
          ),
          'value' => '[file:ffp-name-only-original].[file:ffp-extension-original]',
        ),
        'file_path' => array(
          'options' => array(
            'pathauto' => 0,
            'transliterate' => 0,
          ),
          'value' => 'uploads/[node:content-type:machine-name]/[node:nid]',
        ),
        'retroactive_update' => 0,
      ),
      'filefield_paths_enabled' => 1,
      'max_filesize' => '',
      'max_resolution' => '1280x780',
      'min_resolution' => '',
      'title_field' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'filefield_sources' => array(
          'filefield_sources' => array(),
          'source_attach' => array(
            'absolute' => 0,
            'attach_mode' => 'move',
            'path' => 'file_attach',
          ),
          'source_imce' => array(
            'imce_mode' => 0,
          ),
          'source_reference' => array(
            'autocomplete' => 0,
          ),
        ),
        'maxlength_js_label' => '',
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 17,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_imagem_de_destaque'
  $field_instances['node-experiencia-field_imagem_de_destaque'] = array(
    'bundle' => 'experiencia',
    'deleted' => 0,
    'description' => 'Insira uma imagem que ajude a simbolizar a experiência (pode ser uma imagem de unidades, das equipes, do mapa do território, etc).',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => 'file',
          'image_style' => 'large',
        ),
        'type' => 'image',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'display_in_partial_form' => 0,
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'extra_description' => array(
      'multiple' => 0,
      'over_description' => 'Insira uma imagem que ajude a simbolizar a experiência (pode ser uma imagem de unidades, das equipes, do mapa do território, etc.).',
    ),
    'field_name' => 'field_imagem_de_destaque',
    'label' => 'Para começar, uma imagem',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'exclude_cv' => FALSE,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'filefield_paths' => array(
        'active_updating' => 0,
        'file_name' => array(
          'options' => array(
            'pathauto' => 0,
            'transliterate' => 0,
          ),
          'value' => 'imagem-de-destaque.[file:ffp-extension-original]',
        ),
        'file_path' => array(
          'options' => array(
            'pathauto' => 0,
            'transliterate' => 0,
          ),
          'value' => 'uploads/[node:content-type:machine-name]/[node:nid]',
        ),
        'retroactive_update' => 0,
      ),
      'filefield_paths_enabled' => 1,
      'max_filesize' => '',
      'max_resolution' => '1280x780',
      'min_resolution' => '',
      'title_field' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'filefield_sources' => array(
          'filefield_sources' => array(),
          'source_attach' => array(
            'absolute' => 0,
            'attach_mode' => 'move',
            'path' => 'file_attach',
          ),
          'source_imce' => array(
            'imce_mode' => 0,
          ),
          'source_reference' => array(
            'autocomplete' => 0,
          ),
        ),
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_topics'
  $field_instances['node-experiencia-field_topics'] = array(
    'bundle' => 'experiencia',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Digite 1 ou 2 letras e veja os <b>temas</b> já existentes. Caso não encontre um tema que contemple, termine de digitar para adicionar um novo.
<br><br>
Para inserir mais de um tema, separe-os entre vírgulas.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 19,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'display_in_partial_form' => 0,
    'entity_type' => 'node',
    'field_name' => 'field_topics',
    'label' => 'Temas',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_video'
  $field_instances['node-experiencia-field_video'] = array(
    'bundle' => 'experiencia',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Insira o link do(s) vídeo(s) (instruções sobre como enviar um vídeo <a href="http://www.atencaobasica.org.br/mostra/instrucoes/inserir-video" target="_blank">clique aqui</a>)',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'video_embed_field',
        'settings' => array(
          'description' => 1,
          'video_style' => 'normal',
        ),
        'type' => 'video_embed_field',
        'weight' => 9,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'display_in_partial_form' => 0,
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'extra_description' => array(
      'multiple' => 0,
      'over_description' => 'Insira o link do(s) vídeo(s)',
    ),
    'field_name' => 'field_video',
    'label' => 'Galeria de Vídeos',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'exclude_cv' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'video_embed_field',
      'settings' => array(
        'maxlength_js_label' => '',
      ),
      'type' => 'video_embed_field_video',
      'weight' => 16,
    ),
  );

  // Exported field_instance: 'node-experiencia-og_group_ref'
  $field_instances['node-experiencia-og_group_ref'] = array(
    'bundle' => 'experiencia',
    'default_value' => NULL,
    'default_value_function' => 'entityreference_prepopulate_field_default_value',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 22,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'display_in_partial_form' => 0,
    'entity_type' => 'node',
    'field_name' => 'og_group_ref',
    'label' => 'Groups audience',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'og_widget' => array(
          'admin' => array(
            'widget_type' => 'entityreference_autocomplete',
          ),
          'default' => array(
            'widget_type' => 'options_select',
          ),
          'status' => TRUE,
        ),
        'prepopulate' => array(
          'action' => 'hide',
          'action_on_edit' => 1,
          'fallback' => 'none',
          'og_context' => 0,
          'skip_perm' => 0,
          'status' => 1,
        ),
      ),
      'exclude_cv' => FALSE,
      'user_register_form' => FALSE,
    ),
    'view modes' => array(
      'full' => array(
        'custom settings' => FALSE,
        'label' => 'Completo',
        'type' => 'og_list_default',
      ),
      'teaser' => array(
        'custom settings' => FALSE,
        'label' => 'Chamada',
        'type' => 'og_list_default',
      ),
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'og',
      'settings' => array(
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
      ),
      'type' => 'og_complex',
      'weight' => 4,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Anexe aqui termos de autorização de uso de imagem ou termo de consentimento de entrevista (clique aqui para mais informações).');
  t('Arquivos anexados');
  t('As informações desse campo serão utilizadas para divulgação da experiência! Por isso, "venda seu peixe!", diga em poucas palavras sobre o que é a experiência e porque é interessante que outras pessoas a conheçam. (máximo de 500 caracteres)');
  t('Categoria');
  t('Clique e digite o nome de sua cidade (com acentos) para buscar');
  t('Clique em upload e o sistema permitirá adicionar mais uma imagem');
  t('Comment');
  t('Como funciona(ou) a experiência?');
  t('Confirme o eixo temático');
  t('Desafios para o desenvolvimento');
  t('Digite 1 ou 2 letras e veja os <b>pontos da rede</b> já existentes. Caso não encontre um que contemple, termine de digitar para adicionar um novo.

Para inserir mais de um, separe-os entre vírgulas.');
  t('Digite 1 ou 2 letras e veja os <b>temas</b> já existentes. Caso não encontre um tema que contemple, termine de digitar para adicionar um novo.
<br><br>
Para inserir mais de um tema, separe-os entre vírgulas.');
  t('Envolve quais pontos / equipes da rede?');
  t('Estado');
  t('Galeria de Vídeos');
  t('Galeria de imagens');
  t('Groups audience');
  t('Insira o link do(s) vídeo(s) (instruções sobre como enviar um vídeo <a href="http://www.atencaobasica.org.br/mostra/instrucoes/inserir-video" target="_blank">clique aqui</a>)');
  t('Insira uma imagem que ajude a simbolizar a experiência (pode ser uma imagem de unidades, das equipes, do mapa do território, etc).');
  t('Nome');
  t('Outras observações/campo livre');
  t('Para começar, uma imagem');
  t('Quais as novidades?');
  t('Qual foi a experiência desenvolvida? Sobre o que foi?');
  t('Temas');
  t('Venda seu peixe!');
  t('d. Onde ocorre a experiência?');
  t('exp_info_a');
  t('field_exp_info_a');
  t('field_exp_info_b');
  t('Âmbito da experiência');

  return $field_instances;
}
