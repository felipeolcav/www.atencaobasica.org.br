<?php

// $Id: og_statistics.admin.inc $
/**
 * @file
 *   Admin settings for og_statistics module.
 */
function og_statistics_settings() {
  $form['rebuild'] = array(
    '#type' => 'submit',
    '#value' => t('Rebuild Organic Groups Statistics')
  );
  return $form;
}

function og_statistics_settings_recalc(&$context) {

  //variable_set('og_statistics_include_unapproved_members', $form_state['values']['include_unapproved_members']);
  if (empty($context['sandbox'])) {
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['current_group'] = 0;
    $context['sandbox']['max'] = OgStatistics::getTotalAmountOfGroups();
  }
  
  $result = db_select('field_data_group_group', 'g')
    ->fields('g', array('entity_id'))
    ->condition('g.bundle', 'group')
    ->condition('g.group_group_value', 1)
    ->condition('g.entity_id', $context['sandbox']['current_group'], '>')
    ->orderBy('g.entity_id')
    ->range(0, 10)
    ->execute()->fetchAll();

  $field_og_group_ref = field_info_field('og_group_ref');
  $node_types_totals = array();

  // Write a new record with calculated numbers for each one
  foreach ($result as $group) {

    foreach ($field_og_group_ref['bundles']['node'] as $bundle) {
      
      $count = (int) db_query('SELECT COUNT(*) 
        FROM {node} n 
        INNER JOIN {og_membership} f ON n.nid = f.etid 
        WHERE f.gid = :gid AND f.entity_type = :type AND n.type = :bundle AND n.status = 1',
        array(':gid' => $group->entity_id, ':type' => 'node', ':bundle' => $bundle)
      )->fetchField();

      $node_types_totals[$bundle] = $count;
    }

    $content_count = array_sum($node_types_totals);
    $member_count = OgStatistics::getMemberCount($group->entity_id);
    if (module_exists('comment')) {
      $comments_count = OgStatistics::getCommentsCount($group->entity_id);
    }
    $last_node = OgStatistics::getLastNode($group->entity_id);
    $last_member = OgStatistics::getLastMember($group->entity_id);
    $last_comment = OgStatistics::getLastComment($group->entity_id);

    $last_activity = max($last_node->created, $last_member->created, $last_comment->last_comment_timestamp);

    $fields_to_update = array(
        'nid' => $group->entity_id,
        'gid' => $group->entity_id,
        'members_count' => $member_count,
        'content_count' => $content_count,
        'comments_count' => $comments_count,
        'last_activity' => $last_activity,
        'last_node_timestamp' => $last_node->group_audience_created,
        'last_comment_timestamp' => $last_comment->last_comment_timestamp,
        'last_member_timestamp' => $last_member->group_audience_created,
        'last_comment_uid' => $last_comment->last_comment_uid,
        'last_comment_nid' => $last_comment->nid,
        'last_comment_cid' => $last_comment->cid,
        'last_node_nid' => $last_node->nid,
        'last_node_uid' => $last_node->uid,
        'last_member_uid' => $last_member->uid,
    );
    foreach ($node_types_totals as $bundle => $count) {
      $fields_to_update[$bundle . '_count'] = $count;
    }
    
    $query = db_insert('og_statistics')->fields($fields_to_update)->execute();

    $context['results'][] = $group->entity_id;
    $context['sandbox']['progress']++;
    $context['sandbox']['current_group'] = $group->entity_id;
    $context['message'] = t('Group @id processed.', array('@id' => $group->entity_id));
  }

  if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }
}

function og_statistics_settings_submit() {
  
  db_truncate('og_statistics')->execute();
  
  $batch = array(
    'title' => t('Generating statistics'),
    'operations' => array(
      array('og_statistics_settings_recalc', array()),
    ),
    'init_message' => 'Loading group nodes',
    'progress_message' => t('Calculated statistics for @current out of @total groups'),
    'error_message' => 'An unrecoverable error has occurred. You can find the error message below. It is advised to copy it to the clipboard for reference.',
    'finished' => 'og_statistics_settings_finished',
    'file' => drupal_get_path('module', 'og_statistics') . '/og_statistics.admin.inc',
  );
  batch_set($batch);
}

function og_statistics_settings_finished($success, $results, $operations) {
  if ($success) {
    $message = format_plural(count($results), 'One group processed.', '@count groups processed.');
  } else {
    $message = t('Finished with an error.');
  }
  drupal_set_message($message);
  // Providing data for the redirected page is done through $_SESSION.
  foreach ($results as $result) {
    $items[] = t('Loaded node %title.', array('%title' => $result));
  }
  $_SESSION['my_batch_results'] = $items;
}