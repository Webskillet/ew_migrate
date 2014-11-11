<?php

function ew_migrate_migrate_api() {
	$api = array(
		'api' => 2,
		'groups' => array(
			'ew_children' => array(
				'title' => t('Relationship Migrations'),
			),
		),
		'migrations' => array(
			'MigrateEWChildrenMigration' => array(
				'class_name' => 'MigrateEWChildrenMigration',
				'group_name' => 'ew_children',
			),
			'MigrateEWRelationshipMigration' => array(
				'class_name' => 'MigrateEWRelationshipMigration',
				'group_name' => 'ew_children',
			),
			'MigrateEWHouseholdMigration' => array(
				'class_name' => 'MigrateEWHouseholdMigration',
				'group_name' => 'ew_children',
			),
		),
	);
	return $api;
}


