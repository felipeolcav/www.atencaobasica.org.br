<?php

class MigracaoComentariosTopicosXML extends XMLMigration {

  public function __construct($arguments) {

    parent::__construct();
    $this->description = 'Migraçao dos comentários dos tópicos de cada fórum das Comunidades.';

    $this->machineName = $arguments['machine_name'];
    $source_fields = array(
      'comentario_pai_id' => 'comentario_pai_id',
      'comentario_id' => 'comentario_id',
      'comentario_data' => 'comentario_data',
      'comentario_autor_email' => 'comentario_autor_email',
      'comentario_conteudo' => 'comentario_conteudo',
      'topico_id' => 'topico_id',
      'forum_nome' => 'forum_nome',
      'comunidade_id' => 'comunidade_id',
    );

    $this->map = new MigrateSQLMap($this->machineName,
        array('map_comentario_id' => array(
            'type' => 'int',
            'not null' => TRUE,
          )
        ),
        MigrateDestinationNode::getKeySchema()
    );

    $xml_folder = DRUPAL_ROOT . '/' . drupal_get_path('module', 'dab_migracao') . '/xml/';
    $items_url = $xml_folder . 'comentarios-topico.xml';
    $item_xpath = '/root/comentario';
    $item_ID_xpath = 'comentario_id';

    $items_class = new MigrateItemsXML($items_url, $item_xpath, $item_ID_xpath);
    $this->source = new MigrateSourceMultiItems($items_class, $source_fields);

    $this->destination = new MigrateDestinationComment('comment_node_post');


    // Mapped fields
    $this->addFieldMapping('map_comentario_id', 'comentario_id')
      ->xpath('comentario_id');

    $this->addFieldMapping('nid', 'topico_id')
      ->sourceMigration('TopicosForum')
      ->xpath('topico_id');

    $this->addFieldMapping('pid', 'comentario_pai_id')
      ->sourceMigration($this->machineName)
      ->xpath('comentario_pai_id');

    $this->addFieldMapping('uid', 'Email')
      ->sourceMigration($this->getUserMigrations())
      ->xpath('comentario_autor_email')
      ->defaultValue(1);

    $this->addFieldMapping('comment_body', 'comentario_conteudo')
      ->xpath('comentario_conteudo');

    $this->addFieldMapping('comment_body:format')
      ->defaultValue('filtered_html');

    $this->addFieldMapping('status')
      ->defaultValue(1);

    $this->addFieldMapping('created', 'comentario_data')
      ->xpath('comentario_data');

    $this->addFieldMapping('changed', 'comentario_data')
      ->xpath('comentario_data');
  }

  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    if (!empty($row->xml->comentario_data)) {
      $date = DateTime::createFromFormat('d-m-Y H:i', $row->xml->comentario_data);
      $row->xml->comentario_data = $date->getTimestamp();
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