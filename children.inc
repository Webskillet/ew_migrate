<?php

class MigrateEWChildrenMigration extends Migration {

  /**
   * Constructor.
   */
  public function __construct($arguments) {
	$this->arguments = $arguments;
    parent::__construct();
    $this->source = new MigrateSourceCSV(__DIR__.'/child_guardian_test.csv', array(), array('header_rows' => 1));
    $this->destination = new MigrateDestinationRelation('child_minor');
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'nature' => array(
          'type' => 'varchar',
          'length' => 128,
          'not null' => TRUE,
        ),
        'child_id' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
        ),
        'guardian_id' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
        ),
      ),
      MigrateDestinationRelation::getKeySchema()
    );
	$this->addFieldMapping('field_nature_of_relation','nature');
    
  }

  public function prepare(stdClass $relation, stdClass $source_row) {
    $relation->endpoints[LANGUAGE_NONE] = array(
      array('entity_type' => 'redhen_contact', 'entity_id' => $source_row->child_id),
      array('entity_type' => 'redhen_contact', 'entity_id' => $source_row->guardian_id),
    );
  }
}
