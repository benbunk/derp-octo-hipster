<?php
/**
 * @file
 * petitions_petition.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function petitions_petition_default_rules_configuration() {
  $items = array();
  $items['rules_first_threshold'] = entity_import('rules_config', '{ "rules_first_threshold" : {
      "LABEL" : "First threshold",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "petitions" ],
      "REQUIRES" : [ "rules", "comment" ],
      "ON" : [ "comment_insert" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "comment:node" ],
            "type" : { "value" : { "petition" : "petition" } }
          }
        },
        { "data_is" : { "data" : [ "comment:node:comment-count" ], "value" : "150" } }
      ],
      "DO" : [
        { "data_set" : { "data" : [ "comment:node:field-status" ], "value" : "2" } }
      ]
    }
  }');
  $items['rules_second_threshold'] = entity_import('rules_config', '{ "rules_second_threshold" : {
      "LABEL" : "Second threshold",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "petitions" ],
      "REQUIRES" : [ "rules", "comment" ],
      "ON" : [ "comment_insert" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "comment:node" ],
            "type" : { "value" : { "petition" : "petition" } }
          }
        },
        { "data_is" : { "data" : [ "comment:node:comment-count" ], "value" : "25000" } }
      ],
      "DO" : [
        { "data_set" : { "data" : [ "comment:node:field-status" ], "value" : "4" } }
      ]
    }
  }');
  $items['rules_time_limit'] = entity_import('rules_config', '{ "rules_time_limit" : {
      "LABEL" : "Time limit",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "-1",
      "TAGS" : [ "petitions" ],
      "REQUIRES" : [ "rules", "comment" ],
      "ON" : [ "comment_insert" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "comment:node" ],
            "type" : { "value" : { "petition" : "petition" } }
          }
        },
        { "data_is" : { "data" : [ "comment:node:created" ], "value" : "+30 days" } }
      ],
      "DO" : [
        { "data_set" : { "data" : [ "comment:node:field-status" ], "value" : "3" } }
      ]
    }
  }');
  return $items;
}
