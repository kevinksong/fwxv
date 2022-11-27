#include "unity.h"
#include "power_select_power_supply_task.h"

void setup_test(void) {
  tasks_init();
  log_init();
  tasks_init_task(master_task, TASK_PRIORITY(2), NULL);
  tasks_start();
}

void teardown_test(void) {}

void test_power_select_power_supply_task(void) {
  TEST_ASSERT_EQUAL(5, 5);
}