<?php

function dab_migracao_migrate_api() {


  $api = array(
    'api' => 2,
    'migrations' => array(
      'APSSESMG' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_APS SES-MG- Nível Central e Regional',
        'group_name' => 'grupoUsuario',
      ),
      'AcademiaDaSaude' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_Academia da Saúde',
        'group_name' => 'grupoUsuario',
      ),
      'AlimentaNutricaoSUS' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_Alimentação e Nutrição no SUS- Saberes e práticas',
        'group_name' => 'grupoUsuario',
      ),
      'AssistenciaReabilitacaoComunidade' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_Assistência em Reabilitação na Comunidade',
        'group_name' => 'grupoUsuario',
      ),
      'AtividadeFisicaSaude' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_Atividade Física e Saúde',
        'group_name' => 'grupoUsuario',
      ),
      'BoasVindas' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_Boas vindas',
        'group_name' => 'grupoUsuario',
      ),
      'CaminhosCuidadoApoioPedagogico' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_Caminhos do Cuidado - Apoio Pedagógico',
        'group_name' => 'grupoUsuario',
      ),
      'CaminhosCuidadoCoordenacaoNacional' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_Caminhos do Cuidado - Coordenação Nacional',
        'group_name' => 'grupoUsuario',
      ),
      'CaminhosCuidadoEquipeComunicacao' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_Caminhos do Cuidado - Equipe de Comunicação',
        'group_name' => 'grupoUsuario',
      ),
      'ConscienciaEmDia' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_Consciência em dia',
        'group_name' => 'grupoUsuario',
      ),
      'ConversacaoCoordenadoresCuradoresABSF' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_Conversação de Coordenadores e Curadores da IV Mostra AB-SF',
        'group_name' => 'grupoUsuario',
      ),
      'CoordenacaoCuradoriaMostraNacionalABSF' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_Coordenação de Curadoria da IV Mostra Nacional de Atenção Básica Saúde da Família',
        'group_name' => 'grupoUsuario',
      ),
      'CursoColaborativoDoencasCronicas' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_Curso Colaborativo sobre Doenças Crônicas',
        'group_name' => 'grupoUsuario',
      ),
      'DesignComunidadePraticas' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_Design da Comunidade de Práticas',
        'group_name' => 'grupoUsuario',
      ),
      'EvolucaoParticipacaoDentistasSUS' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_Evolução da participação dos dentistas no SUS',
        'group_name' => 'grupoUsuario',
      ),
      'GTIF' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_GTIF - Grupo de Trabalho Intersetorial Federal',
        'group_name' => 'grupoUsuario',
      ),
      'GrupoFacilitadoresComunidadePraticas' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_Grupo de Facilitadores da Comunidade de Práticas',
        'group_name' => 'grupoUsuario',
      ),
      'HistoriasCcotidianoAtencaoBasica' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_Histórias do cotidiano na Atenção Básica',
        'group_name' => 'grupoUsuario',
      ),
      'MostraEixoTematico1' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_IV Mostra - Eixo Temático 1',
        'group_name' => 'grupoUsuario',
      ),
      'MostraEixoTematico10' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_IV Mostra - Eixo Temático 10',
        'group_name' => 'grupoUsuario',
      ),
      'MostraEixoTematico11' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_IV Mostra - Eixo Temático 11',
        'group_name' => 'grupoUsuario',
      ),
      'MostraEixoTematico12' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_IV Mostra - Eixo Temático 12',
        'group_name' => 'grupoUsuario',
      ),
      'MostraEixoTematico13' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_IV Mostra - Eixo Temático 13',
        'group_name' => 'grupoUsuario',
      ),
      'MostraEixoTematico14' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_IV Mostra - Eixo Temático 14',
        'group_name' => 'grupoUsuario',
      ),
      'MostraEixoTematico15' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_IV Mostra - Eixo Temático 15',
        'group_name' => 'grupoUsuario',
      ),
      'MostraEixoTematico16' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_IV Mostra - Eixo Temático 16',
        'group_name' => 'grupoUsuario',
      ),
      'MostraEixoTematico17' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_IV Mostra - Eixo Temático 17',
        'group_name' => 'grupoUsuario',
      ),
      'MostraEixoTematico18' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_IV Mostra - Eixo Temático 18',
        'group_name' => 'grupoUsuario',
      ),
      'MostraEixoTematico19' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_IV Mostra - Eixo Temático 19',
        'group_name' => 'grupoUsuario',
      ),
      'MostraEixoTematico2' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_IV Mostra - Eixo Temático 2',
        'group_name' => 'grupoUsuario',
      ),
      'MostraEixoTematico20' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_IV Mostra - Eixo Temático 20',
        'group_name' => 'grupoUsuario',
      ),
      'MostraEixoTematico3' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_IV Mostra - Eixo Temático 3',
        'group_name' => 'grupoUsuario',
      ),
      'MostraEixoTematico4' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_IV Mostra - Eixo Temático 4',
        'group_name' => 'grupoUsuario',
      ),
      'MostraEixoTematico5' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_IV Mostra - Eixo Temático 5',
        'group_name' => 'grupoUsuario',
      ),
      'MostraEixoTematico6' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_IV Mostra - Eixo Temático 6',
        'group_name' => 'grupoUsuario',
      ),
      'MostraEixoTematico7' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_IV Mostra - Eixo Temático 7',
        'group_name' => 'grupoUsuario',
      ),
      'MostraEixoTematico8' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_IV Mostra - Eixo Temático 8',
        'group_name' => 'grupoUsuario',
      ),
      'MostraEixoTematico9' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_IV Mostra - Eixo Temático 9',
        'group_name' => 'grupoUsuario',
      ),
      'MelhorEmCasa' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_Melhor em Casa',
        'group_name' => 'grupoUsuario',
      ),
      'MedicosNoro' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_Médicos Norô',
        'group_name' => 'grupoUsuario',
      ),
      'NASF' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_NASF - Núcleo de Apoio à Saúde da Família',
        'group_name' => 'grupoUsuario',
      ),
      'UsuarioNosso' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_O Usuário é Nosso',
        'group_name' => 'grupoUsuario',
      ),
      'PrescricaoTratamentoAdesao' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_O que existe entre a prescrição de um tratamento e a sua adesão',
        'group_name' => 'grupoUsuario',
      ),
      'OncoDiscussoes' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_Onco discussões',
        'group_name' => 'grupoUsuario',
      ),
      'PMAQAcessoQualidadeAtencaoBasica' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_PMAQ - Acesso e Qualidade na Atenção Básica',
        'group_name' => 'grupoUsuario',
      ),
      'PMAQ1' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_PMAQ1',
        'group_name' => 'grupoUsuario',
      ),
      'PraticasIntegrativasComplementares' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_Práticas Integrativas e Complementares',
        'group_name' => 'grupoUsuario',
      ),
      'SaudeNaEscola' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_Saúde na Escola',
        'group_name' => 'grupoUsuario',
      ),
      'ESUS' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_e-SUS',
        'group_name' => 'grupoUsuario',
      ),
      'EmDesenvolvimento' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_em desenvolvimento',
        'group_name' => 'grupoUsuario',
      ),
      'PMAQ' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_pmaq',
        'group_name' => 'grupoUsuario',
      ),
      'Comunidades' => array(
        'class_name' => 'MigracaoComunidadeXML',
        'dependencies' => array(
          'grupoUsuario',
        ),
      ),
      'VinculoUsuarioComunidade' => array(
        'class_name' => 'MigracaoVinculoUsuarioComunidadeXML',
        'dependencies' => array(
          'grupoUsuario',
          'Comunidades',
        ),
      ),
      'ArquivosComunidade' => array(
        'class_name' => 'MigracaoArquivosComunidadeXML',
        'dependencies' => array(
          'grupoUsuario',
          'Comunidades',
        ),
      ),
      'TopicosForum' => array(
        'class_name' => 'MigracaoTopicosXML',
        'dependencies' => array(
          'grupoUsuario',
          'Comunidades',
        ),
      ),
      
      
    ),
  );
  return $api;
}

/*
 * participantes_APS SES-MG- Nível Central e Regional.csv participantes_Academia da Saúde.csv participantes_Alimentação e Nutrição no SUS- Saberes e práticas..csv, participantes_Assistência em Reabilitação na Comunidade... Relato de Experiências.... Terapia Ocupacional, Fisioterapia, Psicologia, Assistência Social, Nutricionista, Enfermagem e demais profissionais.csv, participantes_Atividade Física e Saúde.csv, participantes_Boas vindas!.csv, participantes_Caminhos do Cuidado - Apoio Pedagógico.csv, participantes_Caminhos do Cuidado - Coordenação Nacional.csv, participantes_Caminhos do Cuidado - Equipe de Comunicação.csv, participantes_Consciência em dia .csv, participantes_Conversação de Coordenadores e Curadores da IV Mostra AB-SF.csv, participantes_Coordenação de Curadoria da IV Mostra Nacional de Atenção Básica Saúde da Família .csv, participantes_Curso Colaborativo sobre Doenças Crônicas.csv, participantes_Design da Comunidade de Práticas.csv, participantes_Evolução da participação dos dentistas no SUS.csv, participantes_GTIF - Grupo de Trabalho Intersetorial Federal.csv, participantes_Grupo de Facilitadores da Comunidade de Práticas.csv, participantes_Histórias do cotidiano na Atenção Básica.csv, participantes_IV Mostra - Eixo Temático 1.csv, participantes_IV Mostra - Eixo Temático 10.csv, participantes_IV Mostra - Eixo Temático 11.csv, participantes_IV Mostra - Eixo Temático 12.csv, participantes_IV Mostra - Eixo Temático 13.csv, participantes_IV Mostra - Eixo Temático 14.csv, participantes_IV Mostra - Eixo Temático 15.csv, participantes_IV Mostra - Eixo Temático 16.csv, participantes_IV Mostra - Eixo Temático 17.csv, participantes_IV Mostra - Eixo Temático 18.csv, participantes_IV Mostra - Eixo Temático 19.csv, participantes_IV Mostra - Eixo Temático 2.csv, participantes_IV Mostra - Eixo Temático 20.csv, participantes_IV Mostra - Eixo Temático 3.csv, participantes_IV Mostra - Eixo Temático 4.csv, participantes_IV Mostra - Eixo Temático 5.csv, participantes_IV Mostra - Eixo Temático 6.csv, participantes_IV Mostra - Eixo Temático 7.csv, participantes_IV Mostra - Eixo Temático 8.csv, participantes_IV Mostra - Eixo Temático 9.csv, participantes_Melhor em Casa.csv, participantes_Médicos Norô.csv, participantes_NASF - Núcleo de Apoio à Saúde da Família .csv, participantes_O Usuário é Nosso.csv, participantes_O que existe entre a prescrição de um tratamento e a sua adesão- .csv, participantes_Onco discussões.csv, participantes_PMAQ - Acesso e Qualidade na Atenção Básica.csv, participantes_PMAQ1.csv, participantes_Práticas Integrativas e Complementares.csv, participantes_Saúde na Escola.csv, participantes_e-SUS.csv, participantes_em desenvolvimento ....csv, participantes_pmaq.csv
 * 
 participantes_APS SES-MG- Nível Central e Regional.csv
 participantes_Academia da Saúde.csv
 participantes_Alimentação e Nutrição no SUS- Saberes e práticas..csv
 participantes_Assistência em Reabilitação na Comunidade... Relato de Experiências.... Terapia Ocupacional, Fisioterapia, Psicologia, Assistência Social, Nutricionista, Enfermagem e demais profissionais.csv
 participantes_Atividade Física e Saúde.csv
 participantes_Boas vindas!.csv
 participantes_Caminhos do Cuidado - Apoio Pedagógico.csv
 participantes_Caminhos do Cuidado - Coordenação Nacional.csv
 participantes_Caminhos do Cuidado - Equipe de Comunicação.csv
 participantes_Consciência em dia .csv
 participantes_Conversação de Coordenadores e Curadores da IV Mostra AB-SF.csv
 participantes_Coordenação de Curadoria da IV Mostra Nacional de Atenção Básica Saúde da Família .csv
 participantes_Curso Colaborativo sobre Doenças Crônicas.csv
 participantes_Design da Comunidade de Práticas.csv
 participantes_Evolução da participação dos dentistas no SUS.csv
 participantes_GTIF - Grupo de Trabalho Intersetorial Federal.csv
 participantes_Grupo de Facilitadores da Comunidade de Práticas.csv
 participantes_Histórias do cotidiano na Atenção Básica.csv
 participantes_IV Mostra - Eixo Temático 1.csv
 participantes_IV Mostra - Eixo Temático 10.csv
 participantes_IV Mostra - Eixo Temático 11.csv
 participantes_IV Mostra - Eixo Temático 12.csv
 participantes_IV Mostra - Eixo Temático 13.csv
 participantes_IV Mostra - Eixo Temático 14.csv
 participantes_IV Mostra - Eixo Temático 15.csv
 participantes_IV Mostra - Eixo Temático 16.csv
 participantes_IV Mostra - Eixo Temático 17.csv
 participantes_IV Mostra - Eixo Temático 18.csv
 participantes_IV Mostra - Eixo Temático 19.csv
 participantes_IV Mostra - Eixo Temático 2.csv
 participantes_IV Mostra - Eixo Temático 20.csv
 participantes_IV Mostra - Eixo Temático 3.csv
 participantes_IV Mostra - Eixo Temático 4.csv
 participantes_IV Mostra - Eixo Temático 5.csv
 participantes_IV Mostra - Eixo Temático 6.csv
 participantes_IV Mostra - Eixo Temático 7.csv
 participantes_IV Mostra - Eixo Temático 8.csv
 participantes_IV Mostra - Eixo Temático 9.csv
 participantes_Melhor em Casa.csv
 participantes_Médicos Norô.csv
 participantes_NASF - Núcleo de Apoio à Saúde da Família .csv
 participantes_O Usuário é Nosso.csv
 participantes_O que existe entre a prescrição de um tratamento e a sua adesão- .csv
 participantes_Onco discussões.csv
 participantes_PMAQ - Acesso e Qualidade na Atenção Básica.csv
 participantes_PMAQ1.csv
 participantes_Práticas Integrativas e Complementares.csv
 participantes_Saúde na Escola.csv
 participantes_e-SUS.csv
 participantes_em desenvolvimento ....csv
 participantes_pmaq.csv
 * 
 *  
 */