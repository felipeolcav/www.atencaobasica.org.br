<?php

function dab_migracao_migrate_api() {
  $api = array(
    'api' => 2,
    'migrations' => array(
      'ConsolidadoDeUsuariosDoPlone' => array(
        'class_name' => 'UsuarioMigration',
        'file_name' => 'unificado',
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
      'ComentariosTopicos' => array(
        'class_name' => 'MigracaoComentariosTopicosXML',
        'dependencies' => array(
          'grupoUsuario',
          'Comunidades',
        ),
      ),
    ),
  );
  return $api;
}
