<?php

class OgStatisticsUser {

  static public function insertIntoGroup($account) {

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

  // static public function hook_user_update(&$edit, $account, $category) {

  //   $groups = og_get_entity_groups('user', $account);
    
  //   $gids_old = array();
  //   foreach ($account->original->group_audience as $lang_audiences) {
  //     if (!empty($lang_audiences)) {
  //       foreach ($lang_audiences as $audience) {
  //         $gids_old[$audience['gid']] = $audience['state'];
  //       }
  //     }
  //   }
  //   $gids_new = array();
  //   foreach ($account->group_audience as $lang_audiences) {
  //     if (!empty($lang_audiences)) {
  //       foreach ($lang_audiences as $audience) {
  //         $gids_new[$audience['gid']] = $audience['state'];
  //       }
  //     }
  //   }
    
  //   foreach ($gids_old as $key=>$gid_old) {
  //     if (empty($gids_new[$key]) || !$gids_new[$key]) {
  //       // audience was removed.
  //       $this->stat2db(array('gid'=>$key, 'uid'=>$account->uid), false);
  //     }
  //   }

  //   foreach ($gids_new as $key=>$gid_new) {
  //     if (empty($gids_old[$key]) || !$gids_old[$key]) {
  //       // new audience appeared.
  //       $this->stat2db(array('gid'=>$key, 'uid'=>$account->uid), true);
  //     }
  //   }
  // }

  // static public function hook_user_delete($account) {

  //   foreach ($account->group_audience as $lang_key => $lang_audiences) {
  //     foreach ($lang_audiences as $key => $audience) {
  //       // new audience appeared.
  //       db_merge('og_statistics')
  //         ->key(array('gid' => $audience['gid']))
  //         ->fields(array(
  //           'last_member_uid' => $account->uid,
  //           'last_activity' => time(),
  //         ))
  //         ->expression('members_count', 'members_count - :inc', array(':inc' => 1))
  //         ->execute();
  //     }
  //   }
  // }

  // /**
  //  * Helper function for updating user in statistics.
  //  */
  // private function stat2db($record, $insert = true) {
  //   $group = og_get_group('group', $record['gid']);

  //   $expression = $insert ? 'members_count + :inc' : 'members_count - :inc';
  //   db_merge('og_statistics')
  //     ->key(array('gid' => $record['gid']))
  //     ->fields(array(
  //       'last_member_uid' => $record['uid'],
  //       'last_activity' => time(),
  //       'nid' => $group->etid
  //     ))
  //     ->expression('members_count', $expression, array(':inc' => 1))
  //     ->execute();  
  // }

}