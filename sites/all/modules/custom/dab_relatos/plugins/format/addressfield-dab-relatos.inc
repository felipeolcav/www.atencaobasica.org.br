<?php

/**
 * @file
 * A specific handler for CH.
 */

$plugin = array(
  'title' => t('DAB - Relatos'),
  'format callback' => 'addressfield_format_address_dab_relatos',
  'type' => 'address',
  'weight' => -80,
);

function addressfield_format_address_dab_relatos(&$format, $address, $context = array()) {
  $format['street_block']['#access'] = false;
  $format['locality_block']['postal_code']['#access'] = false;
  $format['locality_block']['locality']['#weight'] = 10;
}