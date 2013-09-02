<?php

class MigracaoComunidadeXML extends XMLMigration {

  public function __construct($arguments) {

    parent::__construct();
    $this->description = 'Migraçao de Comunidades baseadas no xml gerado a partir do processamento de um outro xml vindo do Plone.';

    $this->machineName = $arguments['machine_name'];

    // TIP: Regular dependencies, besides enforcing (in the absence of --force)
    // the run order of migrations, affect the sorting of migrations on display.
    // You can use soft dependencies to affect just the display order when the
    // migrations aren't technically required to run in a certain order. In this
    // case, we want the role migration to appear after the file migration.
    //$this->softDependencies = array('WineFileCopy');
    // There isn't a consistent way to automatically identify appropriate "fields"
    // from an XML feed, so we pass an explicit list of source fields
    $source_fields = array(
      'id' => 'id',
      'nome' => 'nome',
      'dono' => 'dono',
    );

    // The source ID here is the one retrieved from each data item in the XML file, and
    // used to identify specific items
    $this->map = new MigrateSQLMap($this->machineName,
        array('id_group' => array(// this field is used to connect user und profile2
            'type' => 'varchar',
            'length' => 255,
            'not null' => TRUE,
          )
        ),
        MigrateDestinationNode::getKeySchema()
    );

    $xml_folder = DRUPAL_ROOT . '/' . drupal_get_path('module', 'dab_migracao') . '/xml/';
    $items_url = $xml_folder . 'comunidades-processadas.xml';
    $item_xpath = '/root/comunidade';  // relative to document
    $item_ID_xpath = 'id';         // relative to item_xpath and gets assembled

    $items_class = new MigrateItemsXML($items_url, $item_xpath, $item_ID_xpath);
    $this->source = new MigrateSourceMultiItems($items_class, $source_fields);

    $this->destination = new MigrateDestinationNode('group');

    // Mapped fields
    $this->addFieldMapping('id_group', 'id')
      ->xpath('id');

    $this->addFieldMapping('title', 'nome')
      ->xpath('nome');
    $this->addFieldMapping('title_field', 'nome')
      ->xpath('nome');

    $this->addFieldMapping('uid', 'Email')
      ->sourceMigration('ConsolidadoDeUsuariosDoPlone')
      ->xpath('dono')
      ->defaultValue(1);
    //$this->addFieldMapping('uid')->defaultValue(1);
      
    $this->addFieldMapping('status')->defaultValue(1);

    // Organic Groups
    $this->addFieldMapping('group_group')->defaultValue(1);
    $this->addFieldMapping('og_roles_permissions')->defaultValue(0);
  }

}