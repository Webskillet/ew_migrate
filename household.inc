<?php

class MigrateEWHouseholdMigration extends Migration {

  /**
   * Constructor.
   *
   * @param $field_type Field type machine name.
   */
  public function __construct($arguments) {
	$this->arguments = $arguments;
    parent::__construct();
    $this->source = new MigrateSourceCSV(__DIR__.'/households.csv', array(), array('header_rows' => 1));
    $this->destination = new MigrateDestinationRelation('lives_in');
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'status' => array(
          'type' => 'varchar',
          'length' => 128,
          'not null' => TRUE,
        ),
        'contact_id' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
        ),
        'household_id' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
        ),
      ),
      MigrateDestinationRelation::getKeySchema()
    );
	$this->addFieldMapping('field_resident_status','status');
    
  }

  public function prepare(stdClass $relation, stdClass $source_row) {
    $relation->endpoints[LANGUAGE_NONE] = array(
      array('entity_type' => 'redhen_contact', 'entity_id' => $source_row->contact_id),
      array('entity_type' => 'redhen_org', 'entity_id' => $source_row->household_id),
    );
  }
}
