<?php

/**
 * @file
 *   Administrative pages for the CMS CDN module.
 */

/**
 * Admin settings form.
 */
function cmscdn_settings() {
  // Clear the javascript cache when the setting is updated and check version of jquery file.
  $form['#submit'][] = 'drupal_clear_js_cache';
  $form['#submit'][] = 'jquery_update_flush_caches';

  $form['cmscdn_server_status'] = array(
    '#type'  => 'fieldset',
    '#title' => t('Server Status'),
  );
  $form['cmscdn_server_status']['cmscdn_status'] = array(
    '#type' => 'radios',
    '#title' => t('CMS CDN Status'),
    '#options' => array(
      'active' => t('Active'),
      'down' => t('Down'),
    ),
    '#default_value' => variable_get('cmscdn_status', 'active'),
    '#description' => t('If there are ever any problems with the system you can change this value to point to your own CDN. Check here for server status: %domain%version/CHANGELOG.txt.', array('%domain' => CMSCDN_DOMAIN, '%version' => VERSION)),
  );

  $form['cmscdn_domain_override'] = array(
    '#type'  => 'fieldset',
    '#title' => t('Domain Override'),
    '#collapsible'  => TRUE,
    '#collapsed'    => TRUE,
  );
  $form['cmscdn_domain_override']['cmscdn_domain'] = array(
    '#type' => 'textfield',
    '#title' => t('CMS CDN Domain'),
    '#default_value' => variable_get('cmscdn_domain_js', CMSCDN_DEFAULT_DOMAIN),
    '#description' => t('If there is ever a problem with %domain you can point this to wherever you want, simply \'/\' would be for local.', array('%domain' => CMSCDN_DOMAIN)),
  );

  $form['cmscdn_aggregation'] = array(
    '#type'  => 'fieldset',
    '#title' => t('Aggregation Settings'),
  );
  $form['cmscdn_aggregation']['cmscdn_aggregate_css'] = array(
    '#type' => 'radios',
    '#title' => t('Aggregate CMS CDN CSS Files'),
    '#options' => array(t('Disabled'), t('Enabled')),
    '#default_value' => intval(variable_get('cmscdn_aggregate_css', TRUE)),
    '#description' => t('Core aggregation is often not enabled due to caching issues. It is recommended to leave CMS CDN aggregation enabled.'),
  );
  $form['cmscdn_aggregation']['cmscdn_aggregate_js'] = array(
    '#type' => 'radios',
    '#title' => t('Aggregate CMS CDN JavaScript Files'),
    '#options' => array(t('Disabled'), t('Enabled')),
    '#default_value' => intval(variable_get('cmscdn_aggregate_js', TRUE)),
    '#description' => t('Core aggregation is often not enabled due to caching issues. It is recommended to leave CMS CDN aggregation enabled.'),
  );

  return system_settings_form($form);
}

