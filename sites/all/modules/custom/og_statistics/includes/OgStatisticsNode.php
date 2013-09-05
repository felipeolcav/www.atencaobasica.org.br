<?php

class OgStatisticsNode {

  static public function hook_node_insert($node) {

    // Update statistics only for content that is a group content type.
    global $user;
    if (og_is_group_content_type('node', $node->type)) {
      $groups = og_get_entity_groups('node', $node);

      if ($groups > 0) {
        foreach ($groups as $gid) {
          db_merge('og_statistics')
            ->key(array('gid' => $gid))
            ->fields(array(
              'last_activity' => time(),
              'last_node_timestamp' => $node->created,
              'last_node_uid' => $node->uid,
            ))
            ->expression('content_count', 'content_count + :inc', array(':inc' => 1))
            ->execute();
        }
      }
    }
    elseif (og_is_group_type('node', $node->type)) {
      $group = og_get_group('node', $node->nid);
      $default_record = array(
        'nid' => $node->nid,
        'gid' => $group->gid,
        'members_count' => 1,
        'content_count' => 0,
        'comments_count' => 0,
        'last_activity' => time(),
        'last_node_timestamp' => 0,
        'last_comment_timestamp' => 0,
        'last_member_timestamp' => 0,
        'last_comment_uid' => 0,
        'last_comment_nid' => 0,
        'last_comment_cid' => 0,
        'last_node_nid' => 0,
        'last_node_uid' => 0,
        'last_member_uid' => $user->uid,
      );
      db_insert('og_statistics')
        ->fields($default_record)
        ->execute();
    }
  }

  static public function hook_node_update($node) {

    global $user;
    if (og_is_group_content_type('node', $node->type)) {
      $groups = og_get_entity_groups('node', $node);

      if ($groups > 0) {
        foreach ($groups as $gid) {
          db_update('og_statistics')
            ->fields(array(
              'last_activity' => time(),
              'last_node_timestamp' => time(),
              'last_node_uid' => $node->uid,
            ))
            ->condition('gid', $gid)
            ->execute();
        }
      }
    }
  }

  static public function hook_node_delete($node) {

    // Switch for whether this is a group or group content.
    // Update statistics only for content that is a group content type.
    if (og_is_group_content_type('node', $node->type)) {
      $groups = og_get_entity_groups('node', $node);

      if ($groups > 0) {
        foreach ($groups as $gid) {
          db_merge('og_statistics')
            ->key(array('gid' => $gid))
            ->fields(array(
              'last_activity' => time(),
              'last_node_timestamp' => NULL,
              'last_node_uid' => $node->uid,
            ))
            ->expression('content_count', 'content_count - :inc', array(':inc' => 1))
            ->execute();
        }
      }
    }
    elseif (og_is_group_type('node', $node->type)) {
      $num_deleted = db_delete('og_statistics')
        ->condition('nid', $node->nid)
        ->execute();
    }
  }
}