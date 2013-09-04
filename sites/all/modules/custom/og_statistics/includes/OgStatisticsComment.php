<?php

class OgStatisticsComment {

  static public function hook_comment_insert($comment) {

    // Update statistics only for content that is a group content type.
    $node = node_load($comment->nid);
    if (og_is_group_content_type('node', $node->type)) {
      $groups = og_get_entity_groups('node', $node);

      if ($groups > 0) {
        foreach ($groups as $gid) {
          db_merge('og_statistics')
            ->key(array('gid' => $gid))
            ->fields(array(
              'last_activity' => time(),
              'last_comment_timestamp' => $comment->created,
              'last_comment_uid' => $comment->uid,
              'last_comment_nid' => $comment->nid,
              'last_comment_cid' => $comment->cid,
            ))
            ->expression('comments_count', 'comments_count + :inc', array(':inc' => 1))
            ->execute();
        }
      }
    }
  }

  static public function hook_comment_update($comment) {

    // Update statistics only for content that is a group content type.
    $node = node_load($comment->nid);
    if (og_is_group_content_type('node', $node->type)) {
      $groups = og_get_entity_groups('node', $node);

      if ($groups > 0) {
        foreach ($groups as $gid) {
          db_update('og_statistics')
            ->fields(array(
              'last_activity' => time(),
              'last_comment_timestamp' => time(),
              'last_comment_uid' => $comment->uid,
            ))
            ->condition('gid', $gid)
            ->execute();
        }
      }
    }
  }

  static public function hook_comment_delete($comment) {

    // Update statistics only for content that is a group content type.
    $node = node_load($comment->nid);
    if (og_is_group_content_type('node', $node->type)) {
      $groups = og_get_entity_groups('node', $node);

      if ($groups > 0) {
        foreach ($groups as $gid) {
          db_merge('og_statistics')
            ->key(array('gid' => $gid))
            ->fields(array(
              'nid' => $node->nid,
              'last_activity' => time(),
            ))
            ->expression('comments_count', 'comments_count - :inc', array(':inc' => 1))
            ->execute();
        }
      }
    }
  }

}