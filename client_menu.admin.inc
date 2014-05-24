<?php

/**
 * @file
 * Administrative page callbacks for the client_menu module.
 */

/**
 * client_menu administration form.
 */


function client_menu_admin_settings($form, &$form_state) {

  drupal_set_title('Client Menu configuration');
  // List roles
  $liste_roles = user_roles();

  $form['roles'] = array(
    '#type' => 'fieldset',
    '#title' => t('Roles'),
    '#weight' => 0,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['roles']['client_menu_roles'] = array(
    '#type' => 'checkboxes',
    '#title' => t('List of roles can see the menu'),
    '#options' => drupal_map_assoc($liste_roles),
    '#default_value' => variable_get('client_menu_roles', array()),
    '#description' => t('List of roles can see the menu.'),
  );

  $contenttypes_array = array();
  foreach (node_type_get_types() as $key => $value) {
    $contenttypes_array[] = $value->type;
  }

  $form['cts'] = array(
    '#type' => 'fieldset',
    '#title' => t('Content types'),
    '#weight' => 0,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['cts']['client_menu_cts'] = array(
    '#type' => 'checkboxes',
    '#title' => t('List of creatable content types to display'),
    '#options' => drupal_map_assoc($contenttypes_array),
    '#default_value' => variable_get('client_menu_cts', array()),
    '#description' => t('List of creatable content types to display.'),
  );

  function get_list_taxos_vocabularies() {
    $vocabulary = taxonomy_get_vocabularies();
    $checklist_vocab_array = array();
    foreach ($vocabulary as $item) {
      $checklist_vocab_array[] = $item->machine_name;
    }
    return $checklist_vocab_array;
  }

  $form['taxos'] = array(
    '#type' => 'fieldset',
    '#title' => t('Taxonomies'),
    '#weight' => 1,
    '#collapsible' => TRUE, 
    '#collapsed' => TRUE,
  );
  $form['taxos']['client_menu_taxos'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Display a list of taxonomies'),
    '#options' => drupal_map_assoc(get_list_taxos_vocabularies()),
    '#default_value' => variable_get('client_menu_taxos', array()),
    '#description' => t('Display a list of taxonomies.'),
  );

  $form['menus'] = array(
    '#type' => 'fieldset',
    '#title' => t('List menus'),
    '#weight' => 2,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['menus']['client_menu_menus'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Display a list of menu'),
    '#options' => drupal_map_assoc(menu_get_names()),
    '#default_value' => variable_get('client_menu_menus', array()),
    '#description' => t('Display a list of menu.'),
  );

  $form['menu1_links'] = array(
    '#markup' => l(
      t('Go to the first menu'), 
      'admin/structure/menu/manage/client-menu-menu1' ,
      array(
        'attributes' => array(
          'class' => 'client-menu-link',
        ),
        'absolute' => TRUE,
      )
    ),
    '#weight' => 5,
  );

  $form['menu2_links'] = array(
    '#markup' => l(
      t('Go to the second menu'), 
      'admin/structure/menu/manage/client-menu-menu2' ,
      array(
        'attributes' => array(
          'class' => 'client-menu-link',
        ),
        'absolute' => TRUE,
      )
    ),
    '#weight' => 6,
  );

  return system_settings_form($form);
}