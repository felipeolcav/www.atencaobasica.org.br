<?php

class OgStatistics {

  static public function getStatisticsForGroupsList(array $gids) {

    $query = db_select('og_statistics')->fields('og_statistics');
    
    if (!empty($gids)) {
      $gids_arr = array();
      foreach ($gids as $gid) {
        if (is_object($gid)) {
          $gids_arr[] = $gid->entity_id;
        }
        else {
          $gids_arr[] = $gid;
        }
      }
      $query->condition('gid', $gids_arr);
    }

    return $query->execute()->fetchAll();
  }

  static public function getTotalAmountOfGroups() {
    return count(self::getListOfGroupIds());
  }

  static public function getListOfGroupIds() {
    $query = "SELECT entity_id
              FROM {field_data_group_group}
              WHERE bundle = 'group' AND group_group_value = 1";
    return db_query($query)->fetchAll(); 
  }

  static public function getMemberCount($gid) {
    return (int) db_query('SELECT COUNT(*) 
      FROM {og_membership} f 
      INNER JOIN {users} u ON u.uid = f.etid 
      WHERE f.gid = :gid AND f.entity_type = :type AND u.status = 1',
      array(':gid' => $gid, ':type' => 'user')
    )->fetchField();
  }

  static public function getCommentsCount($gid) {
    return (int) db_query('SELECT SUM(comment_count) 
      FROM {node} n 
      INNER JOIN {og_membership} f ON n.nid = f.etid 
      LEFT JOIN {node_comment_statistics} ncs ON n.nid = ncs.nid 
      WHERE f.gid = :gid',
      array(':gid' => $gid)
    )->fetchField();
  }

  static public function getLastNode($gid) {
    return (object) db_query('SELECT * 
      FROM {og_membership} f 
      INNER JOIN {node} n ON n.nid = f.etid 
      WHERE f.entity_type = :type AND f.gid = :gid 
      ORDER BY f.created 
      DESC LIMIT 1', 
      array(':gid' => $gid, ':type' => 'node')
    )->fetchObject();
  }

  static public function getLastMember($gid) {
    return (object) db_query('SELECT * 
      FROM {og_membership} f 
      INNER JOIN {users} u ON u.uid = f.etid 
      WHERE f.entity_type = :type AND f.gid = :gid 
      ORDER BY f.created 
      DESC LIMIT 1', 
      array(':gid' => $group->entity_id, ':type' => 'user')
    )->fetchObject();
  }

  static public function getLastComment($gid) {
    return (object) db_query('SELECT * 
      FROM {og_membership} f 
      INNER JOIN {node_comment_statistics} ncs ON ncs.nid = f.etid 
      WHERE f.gid = :gid 
      ORDER BY f.created 
      DESC LIMIT 1', 
      array(':gid' => $group->entity_id)
    )->fetchObject();
  }

}