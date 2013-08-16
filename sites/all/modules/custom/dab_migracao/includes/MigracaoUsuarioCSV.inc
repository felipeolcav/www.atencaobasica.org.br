<?php

class UsuarioMigration extends Migration {

  public static $mapa_estado_uf;

  public function __construct($arguments) {
    parent::__construct();

    self::popularMapaEstadoUF();

    $this->machineName = $arguments['machine_name'];

    $this->description = t('Import an CSV-file (only "Account"-fields)');
    //Nome,Email,Estado,Municipio,Populacao
    $columns = array(
      // "Source": ('Fieldname', 'Description')
      0 => array('Nome', 'Nome do usuário'),
      1 => array('Email', 'Email do usuário'),
      2 => array('Estado', 'Estado do usuário'),
      3 => array('Municipio', 'Municipio do usuário'),
      4 => array('Populacao', 'Populacao: campo não utilizado')
    );
    $this->source = new MigrateSourceCSV(DRUPAL_ROOT . '/'
        . drupal_get_path('module', 'dab_migracao')
        . '/csv/' . $arguments['file_name'] . '.csv', $columns, array('header_rows' => 1));
    $this->destination = new MigrateDestinationUser();
    $this->map = new MigrateSQLMap($this->machineName,
        array('Email' => array(
            'type' => 'varchar',
            'length' => 255,
            'not null' => TRUE,
          )
        ),
        MigrateDestinationUser::getKeySchema()
    );

    //Nome,Email,Estado,Municipio,Populacao
    // Mapped fields
    $this->addFieldMapping('field_name_first', 'Nome');
    $this->addFieldMapping('name', 'Email');
    $this->addFieldMapping('mail', 'Email');
    $this->addFieldMapping('field_estado', 'Estado');
    $this->addFieldMapping('field_cidade', 'Municipio');

    $this->addFieldMapping('init')
      ->defaultValue('')
      ->description(t('Email address used for initial account creation'));

    $this->addFieldMapping('is_new')
      ->defaultValue(TRUE)
      ->description(t('Build the new user (0|1)'));

    $this->addFieldMapping('pass')
      ->defaultValue('asdf')
      ->description(t("User's password (plain text)"));

    $this->addFieldMapping('roles')
      ->defaultValue(array(DRUPAL_AUTHENTICATED_RID))
      ->description(DRUPAL_AUTHENTICATED_RID . t(' = "authenticated user"'));

    $this->addFieldMapping('role_names')
      ->defaultValue('authenticated user');
    $this->addFieldMapping('theme')
      ->defaultValue('')
      ->description(t("User's default theme"));

    $this->addFieldMapping('signature')
      ->defaultValue('')
      ->description(t("User's signature"));

    $this->addFieldMapping('data')
      ->defaultValue('');

    $this->addFieldMapping('signature_format')
      ->defaultValue('filtered_html')
      ->description(t('Which filter applies to this signature'));

    $this->addFieldMapping('created')
      ->defaultValue(time())
      ->description(t('UNIX timestamp of user creation date'));

    $this->addFieldMapping('access')
      ->defaultValue(0)
      ->description(t('UNIX timestamp for previous time user accessed the site'));

    $this->addFieldMapping('login')
      ->defaultValue(0)
      ->description(t('UNIX timestamp for user\'s last login'));

    $this->addFieldMapping('status')
      ->defaultValue(1)
      ->description(t('Whether the user is active(1) or blocked(0)'));

    $this->addFieldMapping('timezone')
      ->defaultValue(t('America/Sao_Paulo')) // 'America/Los_Angeles', 'Europe/Berlin', 'UTC', ... from drupal.org/node/714214
      ->description(t("User's time zone"));

    $this->addFieldMapping('language')
      ->defaultValue(t('pt-BR')) // e.g.: 'en', 'fr', 'de', ...
      ->description(t("User's default language"));

    $this->addFieldMapping('picture')
      ->defaultValue(0)
      ->description(t('Avatar of the user'));
  }

  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    $row->field_estado = self::$mapa_estado_uf[$row->Estado];
    $row->field_cidade = $row->Municipio . ' (' . $row->field_estado . ')';

    return TRUE;
  }

  public function prepare($user, stdClass $row) {
    $user->field_estado['und'][0]['value'] = $row->field_estado;
    $user->field_cidade['und'][0]['value'] = $row->field_cidade;
  }

  public static function popularMapaEstadoUF() {
    //field_estado: [RJ] => Rio de Janeiro
    //mapa_estado : Rio de Janeiro => RJ

    if (empty(self::$mapa_estado_uf)) {
      self::$mapa_estado_uf = array();

      $info_field_estado = field_info_field('field_estado');
      $tupla_field_estado = $info_field_estado['settings']['allowed_values'];

      foreach ($tupla_field_estado as $uf => $estado) {
        self::$mapa_estado_uf[$estado] = $uf;
      }
    }
  }

}