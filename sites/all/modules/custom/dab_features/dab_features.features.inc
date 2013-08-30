<?php
/**
 * @file
 * dab_features.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dab_features_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
