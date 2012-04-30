<?php
/**
 * @file
 * petitions_response.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function petitions_response_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function petitions_response_node_info() {
  $items = array(
    'response' => array(
      'name' => t('Response'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
