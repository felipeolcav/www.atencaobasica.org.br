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

  // Exported field_instance: 'node-experiencia-field_endereco'
  $field_instances['node-experiencia-field_endereco'] = array(
    'bundle' => 'experiencia',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'addressfield',
        'settings' => array(
          'format_handlers' => array(
            0 => 'address',
          ),
          'use_widget_handlers' => 1,
        ),
        'type' => 'addressfield_default',
        'weight' => 46,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'extra_description' => array(
      'multiple' => 0,
      'over_description' => '',
    ),
    'field_name' => 'field_endereco',
    'label' => 'Onde ocorre a experiência?',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'addressfield',
      'settings' => array(
        'available_countries' => array(
          'BR' => 'BR',
        ),
        'format_handlers' => array(
          'address' => 'address',
          'addressfield-dab-relatos' => 'addressfield-dab-relatos',
          'address-hide-country' => 'address-hide-country',
          'organisation' => 0,
          'name-full' => 0,
          'name-oneline' => 0,
        ),
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
      ),
      'type' => 'addressfield_standard',
      'weight' => 62,
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
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
      ),
      'type' => 'options_buttons',
      'weight' => 67,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_experiencia_anexo'
  $field_instances['node-experiencia-field_experiencia_anexo'] = array(
    'bundle' => 'experiencia',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 34,
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
    'extra_description' => array(
      'multiple' => 0,
      'over_description' => 'Anexe aqui termos de autorização de uso de imagem ou termo de consentimento de entrevista (clique aqui para mais informações)',
    ),
    'field_name' => 'field_experiencia_anexo',
    'label' => 'Arquivos anexados',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
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
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 63,
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
        'weight' => 38,
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
    'extra_description' => array(
      'multiple' => 0,
      'over_description' => '',
    ),
    'field_name' => 'field_experiencia_ator_categoria',
    'label' => 'Categoria',
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
      'weight' => 58,
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
        'weight' => 37,
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
    'extra_description' => array(
      'multiple' => 0,
      'over_description' => '',
    ),
    'field_name' => 'field_experiencia_ator_nome',
    'label' => 'Nome',
    'required' => 0,
    'settings' => array(
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
      'weight' => 57,
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
        'weight' => 36,
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
    'extra_description' => array(
      'multiple' => 0,
      'over_description' => '',
    ),
    'field_name' => 'field_experiencia_autorcat',
    'label' => 'Categoria',
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
      'weight' => 56,
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
        'weight' => 35,
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
    'extra_description' => array(
      'multiple' => 0,
      'over_description' => '',
    ),
    'field_name' => 'field_experiencia_autornome',
    'label' => 'Nome',
    'required' => 0,
    'settings' => array(
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
      'weight' => 55,
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
    'label' => 'Categorias Específicas',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 0,
      ),
      'type' => 'options_select',
      'weight' => 68,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_experiencia_desafios'
  $field_instances['node-experiencia-field_experiencia_desafios'] = array(
    'bundle' => 'experiencia',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Durante o desenvolvimento da experiência surgiram desafios que demandaram improvisos? De quais conhecimentos, e/ou articulações lançaram mão para responder aos desafios? (máximo de 4000 caracteres com espaços)',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 27,
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
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 91,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_experiencia_descricao'
  $field_instances['node-experiencia-field_experiencia_descricao'] = array(
    'bundle' => 'experiencia',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'As informações desse campo serão utilizadas para divulgação da experiência! Por isso, "venda seu peixe!", diga em poucas palavras sobre o que é a experiência e porque é interessante que outras pessoas a conheçam. (máximo de 500 caracteres)',
    'display' => array(
      'default' => array(
        'label' => 'above',
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
    'display_in_partial_form' => 0,
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'extra_description' => array(
      'multiple' => 0,
      'over_description' => '',
    ),
    'field_name' => 'field_experiencia_descricao',
    'label' => 'Venda seu peixe!',
    'required' => 1,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 65,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_experiencia_desenvolvida'
  $field_instances['node-experiencia-field_experiencia_desenvolvida'] = array(
    'bundle' => 'experiencia',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Fale em termos gerais sobre o que é a experiência, detalhando mais as informações colocadas no campo "venda seu peixe". (máximo de 4000 caracteres com espaços)',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 25,
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
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 89,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_experiencia_funcionamento'
  $field_instances['node-experiencia-field_experiencia_funcionamento'] = array(
    'bundle' => 'experiencia',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Como o município ou estado se organizou para realizar a experiência? (caso se aplique) Como a equipe se organizou para para realizar a experiência? (caso se aplique) Trata-se de uma experiência planejada? Quais foram as etapas do trabalho realizado? Houve apoio de outros níveis de gestão – distrital, município, região, estado? Houve apoio local? De quem foi a iniciativa para o início da experiência? Houve adesão de outros membros da equipe? (caso se aplique) Como a proposta foi acolhida? De quem foi a iniciativa para o início da experiência? (máximo de 4000 caracteres com espaços)',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 26,
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
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 90,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_experiencia_novidades'
  $field_instances['node-experiencia-field_experiencia_novidades'] = array(
    'bundle' => 'experiencia',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Quais estratégias de ação foram sendo formuladas/produzidas durante o percurso da experiência? O que foi novo e desafiador? A experiência favoreceu uma mudança no processo de trabalho? Ajudou a pensar estratégias para outras ações? (máximo de 4000 caracteres com espaços)',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 28,
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
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 92,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_experiencia_observacoes'
  $field_instances['node-experiencia-field_experiencia_observacoes'] = array(
    'bundle' => 'experiencia',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '(máximo de 4000 caracteres com espaços)',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 29,
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
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 93,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_experiencia_pontosequipes'
  $field_instances['node-experiencia-field_experiencia_pontosequipes'] = array(
    'bundle' => 'experiencia',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 33,
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
    'extra_description' => array(
      'multiple' => 0,
      'over_description' => '',
    ),
    'field_name' => 'field_experiencia_pontosequipes',
    'label' => ' Envolve quais pontos / equipes da rede?',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
      ),
      'type' => 'options_buttons',
      'weight' => 61,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_imagem'
  $field_instances['node-experiencia-field_imagem'] = array(
    'bundle' => 'experiencia',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => 'file',
          'image_style' => 'large',
        ),
        'type' => 'image',
        'weight' => 32,
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
      'focus' => 0,
      'focus_lock_ratio' => 0,
      'focus_min_size' => '',
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
        'maxlength_js_label' => '',
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 96,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_imagem_de_destaque'
  $field_instances['node-experiencia-field_imagem_de_destaque'] = array(
    'bundle' => 'experiencia',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => 'file',
          'image_style' => 'medium',
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
      'focus' => 0,
      'focus_lock_ratio' => 0,
      'focus_min_size' => '',
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
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 66,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_info_1'
  $field_instances['node-experiencia-field_info_1'] = array(
    'bundle' => 'experiencia',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 39,
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
    'extra_description' => array(
      'multiple' => 0,
      'over_description' => '',
    ),
    'field_name' => 'field_info_1',
    'label' => 'Info 1',
    'required' => 0,
    'settings' => array(
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

  // Exported field_instance: 'node-experiencia-field_info_2'
  $field_instances['node-experiencia-field_info_2'] = array(
    'bundle' => 'experiencia',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 43,
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
    'extra_description' => array(
      'multiple' => 0,
      'over_description' => '',
    ),
    'field_name' => 'field_info_2',
    'label' => 'Info 2',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'markup',
      'settings' => array(
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
      ),
      'type' => 'markup',
      'weight' => 88,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_label_group_1'
  $field_instances['node-experiencia-field_label_group_1'] = array(
    'bundle' => 'experiencia',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 44,
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
    'extra_description' => array(
      'multiple' => 0,
      'over_description' => '',
    ),
    'field_name' => 'field_label_group_1',
    'label' => 'Label group 1',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'markup',
      'settings' => array(
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
      ),
      'type' => 'markup',
      'weight' => 57,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_label_group_2'
  $field_instances['node-experiencia-field_label_group_2'] = array(
    'bundle' => 'experiencia',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 45,
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
    'extra_description' => array(
      'multiple' => 0,
      'over_description' => '',
    ),
    'field_name' => 'field_label_group_2',
    'label' => 'Label group 2',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'markup',
      'settings' => array(
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
      ),
      'type' => 'markup',
      'weight' => 59,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_video'
  $field_instances['node-experiencia-field_video'] = array(
    'bundle' => 'experiencia',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'video_embed_field',
        'settings' => array(
          'description' => 1,
          'video_style' => 'normal',
        ),
        'type' => 'video_embed_field',
        'weight' => 31,
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
    'extra_description' => array(
      'multiple' => 0,
      'over_description' => 'Insira o link do(s) vídeo(s)',
    ),
    'field_name' => 'field_video',
    'label' => 'Galeria de Vídeos',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'video_embed_field',
      'settings' => array(
        'maxlength_js_label' => '',
      ),
      'type' => 'video_embed_field_video',
      'weight' => 95,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t(' Envolve quais pontos / equipes da rede?');
  t('(máximo de 4000 caracteres com espaços)');
  t('Arquivos anexados');
  t('As informações desse campo serão utilizadas para divulgação da experiência! Por isso, "venda seu peixe!", diga em poucas palavras sobre o que é a experiência e porque é interessante que outras pessoas a conheçam. (máximo de 500 caracteres)');
  t('Categoria');
  t('Categorias Específicas');
  t('Como funciona(ou) a experiência?');
  t('Como o município ou estado se organizou para realizar a experiência? (caso se aplique) Como a equipe se organizou para para realizar a experiência? (caso se aplique) Trata-se de uma experiência planejada? Quais foram as etapas do trabalho realizado? Houve apoio de outros níveis de gestão – distrital, município, região, estado? Houve apoio local? De quem foi a iniciativa para o início da experiência? Houve adesão de outros membros da equipe? (caso se aplique) Como a proposta foi acolhida? De quem foi a iniciativa para o início da experiência? (máximo de 4000 caracteres com espaços)');
  t('Desafios para o desenvolvimento');
  t('Durante o desenvolvimento da experiência surgiram desafios que demandaram improvisos? De quais conhecimentos, e/ou articulações lançaram mão para responder aos desafios? (máximo de 4000 caracteres com espaços)');
  t('Fale em termos gerais sobre o que é a experiência, detalhando mais as informações colocadas no campo "venda seu peixe". (máximo de 4000 caracteres com espaços)');
  t('Galeria de Vídeos');
  t('Galeria de imagens');
  t('Info 1');
  t('Info 2');
  t('Label group 1');
  t('Label group 2');
  t('Nome');
  t('Onde ocorre a experiência?');
  t('Outras observações/campo livre');
  t('Para começar, uma imagem');
  t('Quais as novidades?');
  t('Quais estratégias de ação foram sendo formuladas/produzidas durante o percurso da experiência? O que foi novo e desafiador? A experiência favoreceu uma mudança no processo de trabalho? Ajudou a pensar estratégias para outras ações? (máximo de 4000 caracteres com espaços)');
  t('Qual foi a experiência desenvolvida? Sobre o que foi?');
  t('Venda seu peixe!');
  t('Âmbito da experiência');

  return $field_instances;
}
