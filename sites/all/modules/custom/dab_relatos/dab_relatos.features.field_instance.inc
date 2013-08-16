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
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
      ),
      'type' => 'options_select',
      'weight' => 68,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_experiencia_catgerais'
  $field_instances['node-experiencia-field_experiencia_catgerais'] = array(
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
        'weight' => 24,
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
    'field_name' => 'field_experiencia_catgerais',
    'label' => 'Categorias gerais',
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
      'weight' => 90,
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
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => '',
        'maxlength_js_enforce' => 0,
        'maxlength_js_label' => '<strong>@remaining</strong> caracteres restantes',
        'maxlength_js_truncate_html' => 0,
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
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => 500,
        'maxlength_js_enforce' => 0,
        'maxlength_js_label' => '<strong>@remaining</strong> caracteres restantes',
        'maxlength_js_truncate_html' => 0,
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
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => 4000,
        'maxlength_js_enforce' => 0,
        'maxlength_js_label' => '<strong>@remaining</strong> restantes',
        'maxlength_js_truncate_html' => 0,
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
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => 4000,
        'maxlength_js_enforce' => 0,
        'maxlength_js_label' => '<strong>@remaining</strong> caracteres restantes',
        'maxlength_js_truncate_html' => 0,
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
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => 4000,
        'maxlength_js_enforce' => 0,
        'maxlength_js_label' => '<strong>@remaining</strong> caracteres restantes',
        'maxlength_js_truncate_html' => 0,
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
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => 4000,
        'maxlength_js_enforce' => 0,
        'maxlength_js_label' => '<strong>@remaining</strong> caracteres restantes',
        'maxlength_js_truncate_html' => 0,
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

  // Exported field_instance: 'node-experiencia-field_experiencia_tipomidia'
  $field_instances['node-experiencia-field_experiencia_tipomidia'] = array(
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
        'weight' => 30,
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
    'field_name' => 'field_experiencia_tipomidia',
    'label' => 'Além de descrição textual, seu relato possui',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'maxlength_js_label' => '',
      ),
      'type' => 'options_buttons',
      'weight' => 94,
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

  // Exported field_instance: 'node-experiencia-field_sub_eixo_1'
  $field_instances['node-experiencia-field_sub_eixo_1'] = array(
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
        'weight' => 4,
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
    'field_name' => 'field_sub_eixo_1',
    'label' => 'Sub-eixo 1',
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
      'weight' => 70,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_sub_eixo_10'
  $field_instances['node-experiencia-field_sub_eixo_10'] = array(
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
        'weight' => 13,
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
    'field_name' => 'field_sub_eixo_10',
    'label' => 'Sub-eixo 10',
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
      'weight' => 79,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_sub_eixo_11'
  $field_instances['node-experiencia-field_sub_eixo_11'] = array(
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
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_sub_eixo_11',
    'label' => 'Sub-eixo 11',
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
      'weight' => 80,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_sub_eixo_12'
  $field_instances['node-experiencia-field_sub_eixo_12'] = array(
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
        'weight' => 15,
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
    'field_name' => 'field_sub_eixo_12',
    'label' => 'Sub-eixo 12',
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
      'weight' => 81,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_sub_eixo_13'
  $field_instances['node-experiencia-field_sub_eixo_13'] = array(
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
        'weight' => 16,
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
    'field_name' => 'field_sub_eixo_13',
    'label' => 'Sub-eixo 13',
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
      'weight' => 82,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_sub_eixo_14'
  $field_instances['node-experiencia-field_sub_eixo_14'] = array(
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
        'weight' => 17,
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
    'field_name' => 'field_sub_eixo_14',
    'label' => 'Sub-eixo 14',
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
      'weight' => 83,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_sub_eixo_15'
  $field_instances['node-experiencia-field_sub_eixo_15'] = array(
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
        'weight' => 18,
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
    'field_name' => 'field_sub_eixo_15',
    'label' => 'Sub-eixo 15',
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
      'weight' => 84,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_sub_eixo_16'
  $field_instances['node-experiencia-field_sub_eixo_16'] = array(
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
        'weight' => 19,
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
    'field_name' => 'field_sub_eixo_16',
    'label' => 'Sub-eixo 16',
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
      'weight' => 85,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_sub_eixo_17'
  $field_instances['node-experiencia-field_sub_eixo_17'] = array(
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
        'weight' => 20,
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
    'field_name' => 'field_sub_eixo_17',
    'label' => 'Sub-eixo 17',
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
      'weight' => 86,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_sub_eixo_18'
  $field_instances['node-experiencia-field_sub_eixo_18'] = array(
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
        'weight' => 21,
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
    'field_name' => 'field_sub_eixo_18',
    'label' => 'Sub-eixo 18',
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
      'weight' => 87,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_sub_eixo_19'
  $field_instances['node-experiencia-field_sub_eixo_19'] = array(
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
        'weight' => 22,
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
    'field_name' => 'field_sub_eixo_19',
    'label' => 'Sub-eixo 19',
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
      'weight' => 88,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_sub_eixo_2'
  $field_instances['node-experiencia-field_sub_eixo_2'] = array(
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
        'weight' => 5,
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
    'field_name' => 'field_sub_eixo_2',
    'label' => 'Sub-eixo 2',
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
      'weight' => 71,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_sub_eixo_20'
  $field_instances['node-experiencia-field_sub_eixo_20'] = array(
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
        'weight' => 23,
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
    'field_name' => 'field_sub_eixo_20',
    'label' => 'Sub-eixo 20',
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
      'weight' => 89,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_sub_eixo_3'
  $field_instances['node-experiencia-field_sub_eixo_3'] = array(
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
        'weight' => 6,
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
    'field_name' => 'field_sub_eixo_3',
    'label' => 'Sub-eixo 3',
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
      'weight' => 72,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_sub_eixo_4'
  $field_instances['node-experiencia-field_sub_eixo_4'] = array(
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
        'weight' => 7,
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
    'field_name' => 'field_sub_eixo_4',
    'label' => 'Sub-eixo 4',
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
      'weight' => 73,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_sub_eixo_5'
  $field_instances['node-experiencia-field_sub_eixo_5'] = array(
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
        'weight' => 8,
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
    'field_name' => 'field_sub_eixo_5',
    'label' => 'Sub-eixo 5',
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
      'weight' => 74,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_sub_eixo_6'
  $field_instances['node-experiencia-field_sub_eixo_6'] = array(
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
        'weight' => 9,
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
    'field_name' => 'field_sub_eixo_6',
    'label' => 'Sub-eixo 6',
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
      'weight' => 75,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_sub_eixo_7'
  $field_instances['node-experiencia-field_sub_eixo_7'] = array(
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
        'weight' => 10,
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
    'field_name' => 'field_sub_eixo_7',
    'label' => 'Sub-eixo 7',
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
      'weight' => 76,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_sub_eixo_8'
  $field_instances['node-experiencia-field_sub_eixo_8'] = array(
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
        'weight' => 11,
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
    'field_name' => 'field_sub_eixo_8',
    'label' => 'Sub-eixo 8',
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
      'weight' => 77,
    ),
  );

  // Exported field_instance: 'node-experiencia-field_sub_eixo_9'
  $field_instances['node-experiencia-field_sub_eixo_9'] = array(
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
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_sub_eixo_9',
    'label' => 'Sub-eixo 9',
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
      'weight' => 78,
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
  t('Além de descrição textual, seu relato possui');
  t('Arquivos anexados');
  t('As informações desse campo serão utilizadas para divulgação da experiência! Por isso, "venda seu peixe!", diga em poucas palavras sobre o que é a experiência e porque é interessante que outras pessoas a conheçam. (máximo de 500 caracteres)');
  t('Categoria');
  t('Categorias Específicas');
  t('Categorias gerais');
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
  t('Sub-eixo 1');
  t('Sub-eixo 10');
  t('Sub-eixo 11');
  t('Sub-eixo 12');
  t('Sub-eixo 13');
  t('Sub-eixo 14');
  t('Sub-eixo 15');
  t('Sub-eixo 16');
  t('Sub-eixo 17');
  t('Sub-eixo 18');
  t('Sub-eixo 19');
  t('Sub-eixo 2');
  t('Sub-eixo 20');
  t('Sub-eixo 3');
  t('Sub-eixo 4');
  t('Sub-eixo 5');
  t('Sub-eixo 6');
  t('Sub-eixo 7');
  t('Sub-eixo 8');
  t('Sub-eixo 9');
  t('Venda seu peixe!');
  t('Âmbito da experiência');

  return $field_instances;
}
