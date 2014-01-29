<?php
/**
 * @file
 * os2web_rules_actions_and_triggers.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function os2web_rules_actions_and_triggers_default_rules_configuration() {
  $items = array();
  $items['rules_os2web_set_taxonomy_from_roles'] = entity_import('rules_config', '{ "rules_os2web_set_taxonomy_from_roles" : {
      "LABEL" : "OS2web set taxonomy from roles",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "os2web_rules" ],
      "ON" : [ "user_login" ],
      "IF" : [
        { "user_has_role" : { "account" : [ "account" ], "roles" : { "value" : { "2" : "2" } } } }
      ],
      "DO" : [
        { "os2web_rules_rules_action_drupal_message" : { "account" : [ "account" ] } }
      ]
    }
  }');
  return $items;
}
