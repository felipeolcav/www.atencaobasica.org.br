<?php

class MigracaoTopicosXML extends XMLMigration {

  public function __construct($arguments) {

    parent::__construct();
    $this->description = 'Migraçao dos tópicos de cada fórum das Comunidades.';

    $this->machineName = $arguments['machine_name'];
    $source_fields = array(
      'topico_id' => 'topico_id',
      'topico_url' => 'topico_url',
      'topico_nome' => 'topico_nome',
      'topico_visibilidade' => 'topico_visibilidade',
      'topico_autor' => 'topico_autor',
      'primeiro_comentario_email' => 'primeiro_comentario_email',
      'primeiro_comentario_data' => 'primeiro_comentario_data',
      'ultimo_comentario_data' => 'ultimo_comentario_data',
      'forum_id' => 'forum_id',
      'forum_nome' => 'forum_nome',
      'forum_url' => 'forum_url',
      'comunidade_id' => 'comunidade_id',
      'comunidade_url' => 'comunidade_url',
    );

    $this->map = new MigrateSQLMap($this->machineName,
        array('topico_id' => array(
            'type' => 'int',
            'not null' => TRUE,
          )
        ),
        MigrateDestinationNode::getKeySchema()
    );

    $xml_folder = DRUPAL_ROOT . '/' . drupal_get_path('module', 'dab_migracao') . '/xml/';
    $items_url = $xml_folder . 'topicos-forum.xml';
    $item_xpath = '/root/topico';
    $item_ID_xpath = 'topico_id';

    $items_class = new MigrateItemsXML($items_url, $item_xpath, $item_ID_xpath);
    $this->source = new MigrateSourceMultiItems($items_class, $source_fields);

    $this->destination = new MigrateDestinationNode('post');


    // Mapped fields
    $this->addFieldMapping('title_field', 'topico_nome')
      ->xpath('topico_nome');
    $this->addFieldMapping('title', 'topico_nome')
      ->xpath('topico_nome');

    $this->addFieldMapping('uid', 'Email')
      ->sourceMigration($this->getUserMigrations())
      ->xpath('primeiro_comentario_email')
      ->defaultValue(1);

    $this->addFieldMapping('og_group_ref', 'id_group')
      ->sourceMigration('Comunidades')
      ->xpath('comunidade_id');

    $this->addFieldMapping('status', 'topico_visibilidade'); //fazer a tradução no prepare

    $this->addFieldMapping('created', 'primeiro_comentario_data')
      ->xpath('primeiro_comentario_data');

    $this->addFieldMapping('changed', 'ultimo_comentario_data')
      ->xpath('ultimo_comentario_data');

    $this->addFieldMapping('field_topics', 'forum_nome')
      ->xpath('forum_nome');

    $this->addFieldMapping('field_topics:create_term')
      ->defaultValue(1);

    $this->addFieldMapping('field_topics:ignore_case')
      ->defaultValue(1);
  }

  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
    if (empty($row->xml->link_texto)) {
      $row->xml->link_texto = $row->xml->arquivo_id;
    }

    //data gerada no xml: 19 de Agosto de 2013 às 21:05

    if (!empty($row->xml->primeiro_comentario_data)) {
      
      $date = DateTime::createFromFormat('d-m-Y H:i', $row->xml->primeiro_comentario_data);
      $row->xml->primeiro_comentario_data = $date->getTimestamp();
    }
    if (!empty($row->xml->ultimo_comentario_data)) {
      $date = DateTime::createFromFormat('d-m-Y H:i', $row->xml->ultimo_comentario_data);
      $row->xml->ultimo_comentario_data = $date->getTimestamp();
    }
  }

  public function prepare($node, stdClass $row) {
    $node->status = ($row->xml->topico_visibilidade == 'state-publico');
    $node->title = substr($node->title, 0, 255);
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