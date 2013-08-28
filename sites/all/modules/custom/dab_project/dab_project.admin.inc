<?php
/**
 * @file
 * Configurações do modulo do projeto da rede DAB.
 */


/**
 * Formulário de configuração do modulo
 *
 * @ingroup forms
 * @see system_settings_form().
 */
function dab_project_admin_settings() {
  $form = array();

   $form['cometchat'] = array(
    '#type' => 'fieldset',
    '#title' => t('Configurações do Cometchat'),
    '#weight' => 5,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['cometchat']['dab_cometchat_js'] = array(
    '#type' => 'textfield',
    '#title' => 'Url do javascript do cometchat',
    '#default_value' => variable_get('dab_cometchat_js', '/cometchat/cometchatjs.php'),
    '#maxlength' => 1000,
    '#description' => "Exemplo: /cometchat/cometchatjs.php",
    '#required' => FALSE,
  );

  $form['cometchat']['dab_cometchat_css'] = array(
    '#type' => 'textfield',
    '#title' => 'Url do css do cometchat',
    '#default_value' => variable_get('dab_cometchat_css', '/cometchat/cometchatcss.php'),
    '#maxlength' => 1000,
    '#description' => "Exemplo: /cometchat/cometchatcss.php",
    '#required' => FALSE,
  );

  return system_settings_form($form);
}
