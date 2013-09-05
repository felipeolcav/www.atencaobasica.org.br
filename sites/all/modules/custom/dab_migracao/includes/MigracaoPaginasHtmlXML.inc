<?php

class MigracaoPaginasHtmlXML extends XMLMigration {

  public function __construct($arguments) {

    parent::__construct();
    $this->description = 'Migraçao das páginas HTML das Comunidades.';

    $this->machineName = $arguments['machine_name'];
    $source_fields = array(
      'id_link_hash' => 'id_link_hash',
      'titulo' => 'titulo',
      'autor_email' => 'autor_email',
      'data_modificacao' => 'data_modificacao',
      'conteudo' => 'conteudo',
      'comunidade' => 'comunidade',
      'link_href' => 'link_href',
      'link_texto' => 'link_texto',
      'privacidade' => 'privacidade',
    );

    $this->map = new MigrateSQLMap($this->machineName,
        array('post_id' => array(
            'type' => 'varchar',
            'length' => 255,
            'not null' => TRUE,
          )
        ),
        MigrateDestinationNode::getKeySchema()
    );

    $xml_folder = DRUPAL_ROOT . '/' . drupal_get_path('module', 'dab_migracao') . '/xml/';
    $items_url = $xml_folder . 'paginas-html-comunidade.xml';
    $item_xpath = '/root/pagina_html';
    $item_ID_xpath = 'id_link_hash';

    $items_class = new MigrateItemsXML($items_url, $item_xpath, $item_ID_xpath);
    $this->source = new MigrateSourceMultiItems($items_class, $source_fields);

    $this->destination = new MigrateDestinationNode('post');


    // Mapped fields
    $this->addFieldMapping('title_field', 'titulo')
      ->xpath('titulo');
    $this->addFieldMapping('title', 'titulo')
      ->xpath('titulo');

    $this->addFieldMapping('uid', 'Email')
      ->sourceMigration('ConsolidadoDeUsuariosDoPlone')
      ->xpath('autor_email')
      ->defaultValue(1);

    $this->addFieldMapping('og_group_ref', 'id_group')
      ->sourceMigration('Comunidades')
      ->xpath('comunidade');

    $this->addFieldMapping('status', 'topico_visibilidade'); //fazer a tradução no prepare

    $this->addFieldMapping('created', 'data_modificacao')
      ->xpath('data_modificacao');

    $this->addFieldMapping('changed', 'data_modificacao')
      ->xpath('data_modificacao');
    
    $this->addFieldMapping('body', 'conteudo')
      ->xpath('conteudo');

    $this->addFieldMapping('body:format')
      ->defaultValue('filtered_html');
  }

  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    if (!empty($row->xml->data_modificacao)) {
      
      $date = DateTime::createFromFormat('d/m/Y H:i', $row->xml->data_modificacao);
      $row->xml->data_modificacao = $date->getTimestamp();
    }
  }

  public function prepare($node, stdClass $row) {
    $node->status = ($row->xml->topico_visibilidade == 'state-publico');
    $node->title = substr($node->title, 0, 255);
  }

}
