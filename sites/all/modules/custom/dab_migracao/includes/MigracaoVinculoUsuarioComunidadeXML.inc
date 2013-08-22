<?php

class MigracaoVinculoUsuarioComunidadeXML extends XMLMigration {

  public function __construct($arguments) {

    parent::__construct();
    $this->description = 'Migraçao do vínculo dos Usuários às Comunidades baseadas no xml gerado a partir do processamento de um outro xml vindo do Plone.';

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
      'id_vinculo' => 'id_vinculo',
      'id_comunidade' => 'id_comunidade',
      'email' => 'email',
      'papeis' => 'papeis',
    );

    // The source ID here is the one retrieved from each data item in the XML file, and
    // used to identify specific items
    $this->map = new MigrateSQLMap($this->machineName,
        array(
          'vinculo_concat_key' => array(
            'type' => 'varchar',
            'length' => 255,
            'not null' => TRUE,
          ),
        ),
        MigrateDestinationOGMembership::getKeySchema()
    );

    $xml_folder = DRUPAL_ROOT . '/' . drupal_get_path('module', 'dab_migracao') . '/xml/';
    $items_url = $xml_folder . 'vinculos-usuarios-comunidades.xml';
    $item_xpath = '/root/vinculo';  // relative to document
    $item_ID_xpath = 'id_vinculo'; // relative to item_xpath and gets assembled

    $items_class = new MigrateItemsXML($items_url, $item_xpath, $item_ID_xpath);
    $this->source = new MigrateSourceMultiItems($items_class, $source_fields);
    $this->destination = new MigrateDestinationOGMembership();


    // Group reference
    $this->addFieldMapping('group_type')->defaultValue('node');
    $this->addFieldMapping('gid', 'id_group')//id_group: usado no MigrateSQLMap desse sourceMigration 'Comunidades'
      ->sourceMigration('Comunidades')
      ->xpath('id_comunidade');

    // User reference
    $this->addFieldMapping('entity_type')->defaultValue('user');
    $this->addFieldMapping('etid', 'Email')//Email: usado no MigrateSQLMap desse sourceMigration
      ->sourceMigration($this->getUserMigrations())
      ->xpath('email');

    // Other membership properties
    $this->addFieldMapping('state')->defaultValue(OG_STATE_ACTIVE);
    $this->addFieldMapping('is_admin')->defaultValue(0);

    // Array of roles names or ids.
    $this->addFieldMapping('group_roles', 'papeis')
      ->xpath('papeis');
    ;
  }

  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
    
    if (!empty($row->xml->papeis)) {
      if(strpos($row->xml->papeis, 'Owner') !== false){
        //Papeis: Participante, Moderador, Aguardando, Owner, Bloqueado (regex para buscar no xml: <papeis>(?!Participante|Moderador|Aguardando|Bloqueado).*</papeis>)
        return FALSE;//pular o Owner porque ele já veio na carga de Comunidade
      }
      
      $row->xml->papeis = str_replace(array('Participante','Moderador'), array(OG_AUTHENTICATED_ROLE,OG_ADMINISTRATOR_ROLE), $row->xml->papeis);
      $group_roles = explode(',', $row->xml->papeis);
      
      //$og_roles = og_roles('node', 'group', $row->xml->gid, TRUE, TRUE);
      $og_roles = og_roles('node', 'group');
      
      
      foreach ($group_roles as $role) {
        if (!in_array($role, $og_roles)) {
          //$new_role = og_role_create($role, 'node', $row->xml->gid, 'group');
          $new_role = og_role_create($role, 'node', 0, 'group');//gid como zero para não ser de uma comunidade espcífica
          
          og_role_save($new_role);
        }
      }
    }
  }

  public function prepare($membership, stdClass $row) {
    if (!empty($row->xml->papeis)) {
      $membership->group_roles = explode(',', $row->xml->papeis);
    }elseif (!is_array($row->xml->papeis)) {
      $membership->group_roles = array();
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