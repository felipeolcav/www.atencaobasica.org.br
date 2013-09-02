<?php

class MigracaoArquivosComunidadeXML extends XMLMigration {

  public function __construct($arguments) {

    parent::__construct();
    $this->description = 'Migraçao dos arquivos das Comunidades.';

    $this->machineName = $arguments['machine_name'];

    $source_fields = array(
      'arquivo_id' => 'arquivo_id',
      'arq_caminho_completo' => 'arq_caminho_completo',
      'source_dir' => 'source_dir',
      'filename' => 'filename',
      'comunidade' => 'comunidade',
      'link_href' => 'link_href',
      'link_texto' => 'link_texto',
      'privacidade' => 'privacidade',
      'tipo_arquivo' => 'tipo_arquivo',
      'descricao' => 'descricao',
      'autor_email' => 'autor_email',
      'autor_nome' => 'autor_nome',
      'data_atualizacao' => 'data_atualizacao',
    );

    $this->map = new MigrateSQLMap($this->machineName,
        array('arquivo_id' => array(
            'type' => 'varchar',
            'length' => 255,
            'not null' => TRUE,
          )
        ),
        MigrateDestinationNode::getKeySchema()
    );

    $xml_folder = DRUPAL_ROOT . '/' . drupal_get_path('module', 'dab_migracao') . '/xml/';
    $items_url = $xml_folder . 'arquivos-conteudo-comunidade.xml';
    $item_xpath = '/root/item';
    $item_ID_xpath = 'arquivo_id';

    $items_class = new MigrateItemsXML($items_url, $item_xpath, $item_ID_xpath);
    $this->source = new MigrateSourceMultiItems($items_class, $source_fields);

    $this->destination = new MigrateDestinationNode('document');



    // Mapped fields
    $this->addFieldMapping('arquivo_id', 'arquivo_id')
      ->xpath('arquivo_id');

    $this->addFieldMapping('field_document_file', 'arq_caminho_completo')
      ->xpath('arq_caminho_completo');
    $this->addFieldMapping('field_document_file:source_dir', 'field_document_file:source_dir')
      ->xpath('field_document_file:source_dir');
    $this->addFieldMapping('field_document_file:destination_file', 'filename')
      ->xpath('filename');
    $this->addFieldMapping('field_document_file:preserve_files')
      ->defaultValue(0);
    $this->addFieldMapping('field_document_file:file_replace')
      ->defaultValue(MigrateFile::FILE_EXISTS_REUSE);

    $this->addFieldMapping('title_field', 'link_texto')
      ->xpath('link_texto');
    $this->addFieldMapping('title', 'link_texto')
      ->xpath('link_texto');

    $this->addFieldMapping('body', 'descricao')
      ->xpath('descricao');

    $this->addFieldMapping('uid', 'Email')
      ->sourceMigration('ConsolidadoDeUsuariosDoPlone')
      ->xpath('autor_email')
      ->defaultValue(1);

    $this->addFieldMapping('og_group_ref', 'id_group')
      ->sourceMigration('Comunidades')
      ->xpath('comunidade');

    $this->addFieldMapping('status', 'privacidade'); //fazer a tradução no prepare

    $this->addFieldMapping('created', 'data_atualizacao')
      ->xpath('data_atualizacao');
    $this->addFieldMapping('changed', 'data_atualizacao')
      ->xpath('data_atualizacao');
  }

  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
    if (empty($row->xml->link_texto)) {
      $row->xml->link_texto = $row->xml->arquivo_id;
    }

    if (strlen('public://' . $row->xml->filename) > 255) {
      $extensao = strrchr($row->xml->filename, '.');
      $arquivo_sem_extensao = str_replace($extensao, '', $row->xml->filename);
      $tamanho_final = 255 - strlen('public://') - strlen($extensao);
      $row->xml->filename = substr($arquivo_sem_extensao, 0, $tamanho_final) . $extensao;
    }

    if (!empty($row->xml->data_atualizacao)) {
      $date = DateTime::createFromFormat('d/m/Y H:i', $row->xml->data_atualizacao);
      $row->xml->data_atualizacao = $date->getTimestamp();
    }
  }

  public function prepare($node, stdClass $row) {
    $node->status = ($row->xml->privacidade == 'state-publico');
  }
}
