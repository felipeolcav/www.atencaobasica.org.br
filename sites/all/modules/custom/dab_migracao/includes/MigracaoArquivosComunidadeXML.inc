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

    $this->addFieldMapping('title', 'link_texto')//modificar no prepare
      ->xpath('link_texto');

    $this->addFieldMapping('body', 'descricao')
      ->xpath('descricao');

    $this->addFieldMapping('uid', 'Email')
      ->sourceMigration($this->getUserMigrations())
      ->xpath('autor_email')
      ->defaultValue(1);

    $this->addFieldMapping('og_group_ref', 'id_group')
      ->sourceMigration('Comunidades')
      ->xpath('comunidade');

    $this->addFieldMapping('created', 'data_atualizacao')
      ->xpath('data_atualizacao');
    $this->addFieldMapping('changed', 'data_atualizacao')
      ->xpath('data_atualizacao');

    $this->addFieldMapping('status', 'privacidade')->defaultValue(0); //fazer a tradução no prepare
  }

  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
    $row->xml->data_atualizacao = strtotime($row->xml->data_atualizacao);

    if (empty($row->xml->link_texto)) {
      $row->xml->link_texto = $row->xml->arquivo_id;
    }
    if ($row->xml->privacidade == 'state-publico') {
      $row->xml->privacidade = TRUE;
    }
    else {
      $row->xml->privacidade = FALSE;
    }
    $i++;
  }

  public function prepare($node, stdClass $row) {
    if (strlen($node->uri) > 255) {
      $extensao = strrchr($node->uri, '.');
      $arquivo_sem_extensao = str_replace($extensao, '', $node->uri);
      $tamanho_final = 255 - strlen('public://') - strlen($extensao);
      $node->uri = substr($arquivo_sem_extensao, 0, $tamanho_final) . $extensao;
    }
  }

  private function getUserMigrations() {
    return array(
      'APSSESMG',
      'AcademiaDaSaude',
      'AlimentaNutricaoSUS',
      'AssistenciaReabilitacaoComunidade',
      'AtividadeFisicaSaude',
      'BoasVindas',
      'CaminhosCuidadoApoioPedagogico',
      'CaminhosCuidadoCoordenacaoNacional',
      'CaminhosCuidadoEquipeComunicacao',
      'ConscienciaEmDia',
      'ConversacaoCoordenadoresCuradoresABSF',
      'CoordenacaoCuradoriaMostraNacionalABSF',
      'CursoColaborativoDoencasCronicas',
      'DesignComunidadePraticas',
      'EvolucaoParticipacaoDentistasSUS',
      'GTIF',
      'GrupoFacilitadoresComunidadePraticas',
      'HistoriasCcotidianoAtencaoBasica',
      'MostraEixoTematico1',
      'MostraEixoTematico10',
      'MostraEixoTematico11',
      'MostraEixoTematico12',
      'MostraEixoTematico13',
      'MostraEixoTematico14',
      'MostraEixoTematico15',
      'MostraEixoTematico16',
      'MostraEixoTematico17',
      'MostraEixoTematico18',
      'MostraEixoTematico19',
      'MostraEixoTematico2',
      'MostraEixoTematico20',
      'MostraEixoTematico3',
      'MostraEixoTematico4',
      'MostraEixoTematico5',
      'MostraEixoTematico6',
      'MostraEixoTematico7',
      'MostraEixoTematico8',
      'MostraEixoTematico9',
      'MelhorEmCasa',
      'MedicosNoro',
      'NASF',
      'UsuarioNosso',
      'OncoDiscussoes',
      'PMAQAcessoQualidadeAtencaoBasica',
      'PMAQ1',
      'PraticasIntegrativasComplementares',
      'SaudeNaEscola',
      'ESUS',
      'EmDesenvolvimento',
      'PMAQ'
      )
    ;
  }

}

/*
Title                       title_field           Texto	Campo de texto	editar	apagar	
 
Body                        body                  Texto longo e sumário	Área de texto com resumo	editar	apagar	
 
File                        field_document_file   Arquivo	Arquivo	editar	apagar	
 
Radioactivity               field_radioactivity   Radioactivity	Default text field	editar	apagar	
 
Groups                      og_group_ref          Entity Reference	OG reference	editar	apagar	
 
Topics                      field_topics          Referência de termo	Widget de autocompletar de termo	editar	apagar	
 
Group content visibility    group_content_access	Listagem (inteiro)	Lista de seleção	editar	apagar	
 
Redirecionamento de URLs    redirect              Redirect module form elements			
 
Configurações de endereço   path                  Elementos de formulário do módulo Path
 */