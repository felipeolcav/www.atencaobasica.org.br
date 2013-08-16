<?php

function dab_migracao_migrate_api() {


  $api = array(
    'api' => 2,
    'migrations' => array(
      'APSSESMG' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_APS SES-MG- Nível Central e Regional'
      ),
      'AcademiaDaSaude' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_Academia da Saúde'
      ),
      'AlimentaNutricaoSUS' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_Alimentação e Nutrição no SUS- Saberes e práticas'
      ),
      'AssistenciaReabilitacaoComunidade' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_Assistência em Reabilitação na Comunidade'
      ),
      'AtividadeFisicaSaude' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_Atividade Física e Saúde'
      ),
      'BoasVindas' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_Boas vindas'
      ),
      'CaminhosCuidadoApoioPedagogico' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_Caminhos do Cuidado - Apoio Pedagógico'
      ),
      'CaminhosCuidadoCoordenacaoNacional' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_Caminhos do Cuidado - Coordenação Nacional'
      ),
      'CaminhosCuidadoEquipeComunicacao' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_Caminhos do Cuidado - Equipe de Comunicação'
      ),
      'ConscienciaEmDia' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_Consciência em dia'
      ),
      'ConversacaoCoordenadoresCuradoresABSF' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_Conversação de Coordenadores e Curadores da IV Mostra AB-SF'
      ),
      'CoordenacaoCuradoriaMostraNacionalABSF' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_Coordenação de Curadoria da IV Mostra Nacional de Atenção Básica Saúde da Família '
      ),
      'CursoColaborativoDoencasCronicas' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_Curso Colaborativo sobre Doenças Crônicas'
      ),
      'DesignComunidadePraticas' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_Design da Comunidade de Práticas'
      ),
      'EvolucaoParticipacaoDentistasSUS' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_Evolução da participação dos dentistas no SUS'
      ),
      'GTIF' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_GTIF - Grupo de Trabalho Intersetorial Federal'
      ),
      'GrupoFacilitadoresComunidadePraticas' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_Grupo de Facilitadores da Comunidade de Práticas'
      ),
      'HistoriasCcotidianoAtencaoBasica' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_Histórias do cotidiano na Atenção Básica'
      ),
      'MostraEixoTematico1' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_IV Mostra - Eixo Temático 1'
      ),
      'MostraEixoTematico10' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_IV Mostra - Eixo Temático 10'
      ),
      'MostraEixoTematico11' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_IV Mostra - Eixo Temático 11'
      ),
      'MostraEixoTematico12' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_IV Mostra - Eixo Temático 12'
      ),
      'MostraEixoTematico13' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_IV Mostra - Eixo Temático 13'
      ),
      'MostraEixoTematico14' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_IV Mostra - Eixo Temático 14'
      ),
      'MostraEixoTematico15' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_IV Mostra - Eixo Temático 15'
      ),
      'MostraEixoTematico16' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_IV Mostra - Eixo Temático 16'
      ),
      'MostraEixoTematico17' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_IV Mostra - Eixo Temático 17'
      ),
      'MostraEixoTematico18' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_IV Mostra - Eixo Temático 18'
      ),
      'MostraEixoTematico19' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_IV Mostra - Eixo Temático 19'
      ),
      'MostraEixoTematico2' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_IV Mostra - Eixo Temático 2'
      ),
      'MostraEixoTematico20' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_IV Mostra - Eixo Temático 20'
      ),
      'MostraEixoTematico3' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_IV Mostra - Eixo Temático 3'
      ),
      'MostraEixoTematico4' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_IV Mostra - Eixo Temático 4'
      ),
      'MostraEixoTematico5' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_IV Mostra - Eixo Temático 5'
      ),
      'MostraEixoTematico6' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_IV Mostra - Eixo Temático 6'
      ),
      'MostraEixoTematico7' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_IV Mostra - Eixo Temático 7'
      ),
      'MostraEixoTematico8' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_IV Mostra - Eixo Temático 8'
      ),
      'MostraEixoTematico9' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_IV Mostra - Eixo Temático 9'
      ),
      'MelhorEmCasa' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_Melhor em Casa'
      ),
      'MedicosNoro' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_Médicos Norô'
      ),
      'NASF' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_NASF - Núcleo de Apoio à Saúde da Família'
      ),
      'UsuarioNosso' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_O Usuário é Nosso'
      ),
      'PrescricaoTratamentoAdesao' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_O que existe entre a prescrição de um tratamento e a sua adesão.csv'
      ),
      'OncoDiscussoes' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_Onco discussões'
      ),
      'PMAQAcessoQualidadeAtencaoBasica' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_PMAQ - Acesso e Qualidade na Atenção Básica'
      ),
      'PMAQ1' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_PMAQ1'
      ),
      'PraticasIntegrativasComplementares' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_Práticas Integrativas e Complementares'
      ),
      'SaudeNaEscola' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_Saúde na Escola'
      ),
      'ESUS' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_e-SUS'
      ),
      'EmDesenvolvimento' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_em desenvolvimento'
      ),
      'PMAQ' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'participantes_pmaq'
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