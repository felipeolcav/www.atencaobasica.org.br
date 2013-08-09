<?php
/**
 * @file
 * commons_notify.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function commons_notify_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_message_type().
 */
function commons_notify_default_message_type() {
  $items = array();
  $items['commons_notify_comment_created'] = entity_import('message_type', '{
    "name" : "commons_notify_comment_created",
    "description" : "Commons Notify: Comment created",
    "argument_keys" : [],
    "argument" : [],
    "category" : "commons_notify",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "pt-br",
    "arguments" : null,
    "message_text" : {
      "und" : [
        {
          "value" : "New comment on [message:field-target-nodes:0:title] in [message:field-target-nodes:0:og-group-ref:0:title]: [message:field-target-nodes:0:title]",
          "format" : "plain_text",
          "safe_value" : "\\u003Cp\\u003ENew comment on [message:field-target-nodes:0:title] in [message:field-target-nodes:0:og-group-ref:0:title]: [message:field-target-nodes:0:title]\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "Hi [message:user:name],\\r\\n\\r\\n[message:field-target-comments:0:author] commented on [message:field-target-nodes:0:title] [commons-groups:in-groups-text]:\\r\\n\\r\\n[message:field-target-comments:0:body]\\r\\n\\r\\nRead \\u0026 respond: [message:field-target-comments:0:url]\\r\\nUpdate your notification settings: [site:url]\\/notification-settings",
          "format" : "plain_text",
          "safe_value" : "\\u003Cp\\u003EHi [message:user:name],\\u003C\\/p\\u003E\\n\\u003Cp\\u003E[message:field-target-comments:0:author] commented on [message:field-target-nodes:0:title] [commons-groups:in-groups-text]:\\u003C\\/p\\u003E\\n\\u003Cp\\u003E[message:field-target-comments:0:body]\\u003C\\/p\\u003E\\n\\u003Cp\\u003ERead \\u0026amp; respond: [message:field-target-comments:0:url]\\u003Cbr \\/\\u003E\\nUpdate your notification settings: [site:url]\\/notification-settings\\u003C\\/p\\u003E\\n"
        }
      ],
      "pt-br" : [
        {
          "value" : "Novo comentário em [message:field-target-nodes:0:title] no [message:field-target-nodes:0:og-group-ref:0:title]: [message:field-target-nodes:0:title]",
          "format" : "plain_text",
          "safe_value" : "Novo comentário em [message:field-target-nodes:0:title] no [message:field-target-nodes:0:og-group-ref:0:title]: [message:field-target-nodes:0:title]"
        },
        {
          "value" : "Oi [message:user:name], \\r\\n\\r\\n[message:field-target-comments:0:author] comentou no [message:field-target-nodes:0:title] [commons-groups:in-groups-text]:\\r\\n\\r\\n[message:field-target-comments:0:body]\\r\\n\\r\\nLeia \\u0026 responda: [message:field-target-comments:0:url]\\r\\nPara alterar as configurações de notificação acesse:  [site:url]\\/notification-settings",
          "format" : "plain_text",
          "safe_value" : "\\u003Cp\\u003EOi [message:user:name],\\u003C\\/p\\u003E\\n\\u003Cp\\u003E[message:field-target-comments:0:author] comentou no [message:field-target-nodes:0:title] [commons-groups:in-groups-text]:\\u003C\\/p\\u003E\\n\\u003Cp\\u003E[message:field-target-comments:0:body]\\u003C\\/p\\u003E\\n\\u003Cp\\u003ELeia \\u0026amp; comente: [message:field-target-comments:0:url]\\u003Cbr \\/\\u003E\\nAltere suas configurações de notificação em: [site:url]\\/notification-settings\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['commons_notify_node_created'] = entity_import('message_type', '{
    "name" : "commons_notify_node_created",
    "description" : "The notification sent when a user creates a node.",
    "argument_keys" : [],
    "argument" : [],
    "category" : "commons_notify",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "pt-br",
    "arguments" : null,
    "message_text" : {
      "und" : [
        {
          "value" : "New [message:field-target-nodes:0:content-type] in [message:field-target-nodes:0:og-group-ref:0:title]: [message:field-target-nodes:0:title]",
          "format" : "plain_text",
          "safe_value" : "\\u003Cp\\u003ENew [message:field-target-nodes:0:content-type] in [message:field-target-nodes:0:og-group-ref:0:title]: [message:field-target-nodes:0:title]\\u003C\\/p\\u003E\\n"
        },
        {
          "value" : "Hi [message:user:name],\\r\\n\\r\\n[message:field-target-nodes:0:author] created the [message:field-target-nodes:0:content-type] \\u201c[message:field-target-nodes:0:title]\\u201d on [site:name] [commons-groups:in-groups-text] on [message:field-target-nodes:0:created]:\\r\\n\\r\\n[message:field-target-nodes:0:body]\\r\\n\\r\\n\\r\\nPermalink: [message:field-target-nodes:0:url]\\r\\nAdd a comment at [message:field-target-nodes:0:url]#comment-form\\r\\n\\r\\nChange email notifications at [site:url]user\\/[message:user:uid]\\/notification-settings",
          "format" : "plain_text",
          "safe_value" : "\\u003Cp\\u003EHi [message:user:name],\\u003C\\/p\\u003E\\n\\u003Cp\\u003E[message:field-target-nodes:0:author] created the [message:field-target-nodes:0:content-type] \\u201c[message:field-target-nodes:0:title]\\u201d on [site:name] [commons-groups:in-groups-text] on [message:field-target-nodes:0:created]:\\u003C\\/p\\u003E\\n\\u003Cp\\u003E[message:field-target-nodes:0:body]\\u003C\\/p\\u003E\\n\\u003Cp\\u003EPermalink: [message:field-target-nodes:0:url]\\u003Cbr \\/\\u003E\\nAdd a comment at [message:field-target-nodes:0:url]#comment-form\\u003C\\/p\\u003E\\n\\u003Cp\\u003EChange email notifications at [site:url]user\\/[message:user:uid]\\/notification-settings\\u003C\\/p\\u003E\\n"
        }
      ],
      "pt-br" : [
        {
          "value" : "Novo [message:field-target-nodes:0:content-type] no [message:field-target-nodes:0:og-group-ref:0:title]: [message:field-target-nodes:0:title]",
          "format" : "filtered_html",
          "safe_value" : "Novo [message:field-target-nodes:0:content-type] no [message:field-target-nodes:0:og-group-ref:0:title]: [message:field-target-nodes:0:title]"
        },
        {
          "value" : "\\u003Cp\\u003EOi [message:user:name],\\r\\n\\r\\n[message:field-target-nodes:0:author] criou o [message:field-target-nodes:0:content-type] \\u201c[message:field-target-nodes:0:title]\\u201d no [site:name] [commons-groups:in-groups-text] em [message:field-target-nodes:0:created]:\\r\\n\\r\\n[message:field-target-nodes:0:body]\\r\\n\\r\\n\\r\\nLink permanente: [message:field-target-nodes:0:url]\\r\\nAdicione um comentário em: [message:field-target-nodes:0:url]#comment-form\\r\\n\\r\\nPara mudar as configurações de notificações acesse: [site:url]user\\/[message:user:uid]\\/notification-settings\\u003C\\/p\\u003E\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003EOi [message:user:name],\\r\\n\\r\\n[message:field-target-nodes:0:author] criou o [message:field-target-nodes:0:content-type] \\u201c[message:field-target-nodes:0:title]\\u201d no [site:name] [commons-groups:in-groups-text] em [message:field-target-nodes:0:created]:\\r\\n\\r\\n[message:field-target-nodes:0:body]\\r\\n\\r\\n\\r\\nLink permanente: [message:field-target-nodes:0:url]\\r\\nAdicione um comentário em: [message:field-target-nodes:0:url]#comment-form\\r\\n\\r\\nPara mudar as configurações de notificações acesse: [site:url]user\\/[message:user:uid]\\/notification-settings\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['commons_notify_node_created_no_groups'] = entity_import('message_type', '{
    "name" : "commons_notify_node_created_no_groups",
    "description" : "The notification sent when a user creates a node that is not in any groups",
    "argument_keys" : [],
    "argument" : [],
    "category" : "commons_notify",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "pt-br",
    "arguments" : null,
    "message_text" : {
      "pt-br" : [
        {
          "value" : "Novo [message:field-target-nodes:0:content-type] no [site:name]: [message:field-target-nodes:0:title]\\r\\n",
          "format" : "plain_text",
          "safe_value" : "Novo [message:field-target-nodes:0:content-type] no [site:name]: [message:field-target-nodes:0:title]\\n"
        },
        {
          "value" : "Oi [message:user:name], \\r\\n\\r\\n[message:field-target-nodes:0:author] criou o [message:field-target-nodes:0:content-type] \\u201c[message:field-target-nodes:0:title]\\u201d no [site:name] [commons-groups:in-groups-text] em [message:field-target-nodes:0:created]:\\r\\n\\r\\n[message:field-target-nodes:0:body]\\r\\n\\r\\n\\r\\nLink permanente: [message:field-target-nodes:0:url]\\r\\nAdicione um comentario em: [message:field-target-nodes:0:url]#comment-form\\r\\n\\r\\nPara mudar as configurações de notificação acesse: [site:url]user\\/[message:user:uid]\\/notification-settings",
          "format" : "filtered_html",
          "safe_value" : "Oi [message:user:name], \\r\\n\\r\\n[message:field-target-nodes:0:author] criou o [message:field-target-nodes:0:content-type] \\u201c[message:field-target-nodes:0:title]\\u201d no [site:name] [commons-groups:in-groups-text] em [message:field-target-nodes:0:created]:\\r\\n\\r\\n[message:field-target-nodes:0:body]\\r\\n\\r\\n\\r\\nLink permanente: [message:field-target-nodes:0:url]\\r\\nAdicione um comentario em: [message:field-target-nodes:0:url]#comment-form\\r\\n\\r\\nPara mudar as configurações de notificação acesse: [site:url]user\\/[message:user:uid]\\/notification-settings",
          "format" : "filtered_html"
        }
      ],
      "und" : [
        {
          "value" : "New [message:field-target-nodes:0:content-type] on [site:name]: [message:field-target-nodes:0:title]",
          "format" : "plain_text",
          "safe_value" : "New [message:field-target-nodes:0:content-type] on [site:name]: [message:field-target-nodes:0:title]\\n"
        },
        {
          "value" : "Hi [message:user:name],\\r\\n\\r\\n[message:field-target-nodes:0:author] created the [message:field-target-nodes:0:content-type] \\u201c[message:field-target-nodes:0:title]\\u201d on [site:name] [commons-groups:in-groups-text] on [message:field-target-nodes:0:created]:\\r\\n\\r\\n[message:field-target-nodes:0:body]\\r\\n\\r\\n\\r\\nPermalink: [message:field-target-nodes:0:url]\\r\\nAdd a comment at [message:field-target-nodes:0:url]#comment-form\\r\\n\\r\\nChange email notifications at [site:url]user\\/[message:user:uid]\\/notification-settings",
          "format" : "plain_text",
          "safe_value" : "\\u003Cp\\u003EHi [message:user:name],\\u003C\\/p\\u003E\\n\\u003Cp\\u003E[message:field-target-nodes:0:author] created the [message:field-target-nodes:0:content-type] \\u201c[message:field-target-nodes:0:title]\\u201d on [site:name] [commons-groups:in-groups-text] on [message:field-target-nodes:0:created]:\\u003C\\/p\\u003E\\n\\u003Cp\\u003E[message:field-target-nodes:0:body]\\u003C\\/p\\u003E\\n\\u003Cp\\u003EPermalink: [message:field-target-nodes:0:url]\\u003Cbr \\/\\u003E\\nAdd a comment at [message:field-target-nodes:0:url]#comment-form\\u003C\\/p\\u003E\\n\\u003Cp\\u003EChange email notifications at [site:url]user\\/[message:user:uid]\\/notification-settings\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_message_type_category().
 */
function commons_notify_default_message_type_category() {
  $items = array();
  $items['commons_notify'] = entity_import('message_type_category', '{
    "category" : "commons_notify",
    "description" : "Commons Notify",
    "language" : "und",
    "rdf_mapping" : []
  }');
  return $items;
}
