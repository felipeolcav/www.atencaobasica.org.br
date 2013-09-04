<?php

// $Id: $

/**
 * @file
 *   Views Integration of og_statitics.
 */

/**
 * Implements hook_views_data().
 */
function og_statistics_views_data() {
  $data['og_statistics']['table']['group'] = t('Groups Statistics');

  $data['og_statistics']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',
    ),
  );
  $data['og_statistics']['members_count'] = array(
    'title' => t('Members Count'),
    'help' => t('A count of users subscribed to the group'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['og_statistics']['content_count'] = array(
    'title' => t('Content Count'),
    'help' => t('A count of pieces of content (nodes) in the group'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['og_statistics']['comments_count'] = array(
    'title' => t('Comments Count'),
    'help' => t('A count of the total number of comments on pieces of content in the group'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['og_statistics']['last_activity'] = array(
    'title' => t('Last activity'),
    'help' => t('Time the latest activity on the group'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
  );
  $data['og_statistics']['last_node_timestamp'] = array(
    'title' => t('Last inserted/updated Node-time'),
    'help' => t('Time the latest piece of content was added to the group'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
  );
  $data['og_statistics']['last_comment_timestamp'] = array(
    'title' => t('Last Comment-time'),
    'help' => t('Time the latest comment was added to the group'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
  );
  $data['og_statistics']['last_member_timestamp'] = array(
    'title' => t('Last Member subscription'),
    'help' => t('Time the latest member was subscribed to the group'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
  );

  // Add relationship to node table for last node posted.
  $data['og_statistics']['last_node_nid'] = array(
    'title' => 'Last Node posted',
    'help' => 'Create a relationship to for the last node posted',
    'relationship' => array(
      'handler' => 'views_handler_relationship',
      'base' => 'node',
      'field' => 'nid',
      'label' => t('node'),
    ),
  );
  // Add relationship to user table for last node posted.
  $data['og_statistics']['last_node_uid'] = array(
    'title' => 'User that created the last node posted',
    'help' => 'Create a relationship to the user that last posted a node.',
    'relationship' => array(
      'handler' => 'views_handler_relationship',
      'base' => 'users',
      'field' => 'uid',
      'label' => t('user'),
    ),
  );

  // Add relationship to node table for last comment posted.
  $data['og_statistics']['last_comment_nid'] = array(
    'title' => 'Node the last comment was posted to',
    'help' => 'Create a relationship to the last comment posted',
    'relationship' => array(
      'handler' => 'views_handler_relationship',
      'base' => 'node',
      'field' => 'nid',
      'label' => t('node'),
    ),
  );
  // Add relationship to user table for last comment posted.
  $data['og_statistics']['last_comment_uid'] = array(
    'title' => 'User that posted the last comment',
    'help' => 'Create a relationship to the user that last posted a comment.',
    'relationship' => array(
      'handler' => 'views_handler_relationship',
      'base' => 'users',
      'field' => 'uid',
      'label' => t('user'),
    ),
  );
  // Add relationship to the comment table for the last comment posted.
  $data['og_statistics']['last_comment_cid'] = array(
    'title' => 'Comment last posted',
    'help' => 'Create a relationship to the last comment posted',
    'relationship' => array(
      'handler' => 'views_handler_relationship',
      'base' => 'comments',
      'field' => 'cid',
      'label' => t('comment'),
    ),
  );

  // Add relationship to the users table for the last member.
  $data['og_statistics']['last_member_uid'] = array(
    'title' => 'Last member to join',
    'help' => 'Create a relationship to the last user to join',
    'relationship' => array(
      'handler' => 'views_handler_relationship',
      'base' => 'users',
      'field' => 'uid',
      'label' => t('user'),
    ),
  );

  return $data;
}

