#include "unity.h"
#include "power_select_power_supply_task.h"

void run_cycle(int c) {

}

TASK(master_task, TASK_STACK_512) {
  fsm_run_cycle(power_supply);
  vTaskDelay(pdMS_TO_TICKS(1000));
  gpio_set_state(&g_power_select_valid_pin, GPIO_STATE_LOW);
  fsm_run_cycle(power_supply);
  vTaskDelay(pdMS_TO_TICKS(1000));
  fsm_run_cycle(power_supply);
  vTaskDelay(pdMS_TO_TICKS(1000));
  vTaskEndScheduler();
}

void setup_test(void) {
  tasks_init();
  log_init();
  init_power_supply();
  tasks_init_task(master_task, TASK_PRIORITY(3), NULL);
}

void teardown_test(void) {}

void test_power_select_power_supply_task(void) {
  gpio_init_pin(&g_power_select_valid_pin, GPIO_OUTPUT_PUSH_PULL, GPIO_STATE_HIGH);
  tasks_start();
  TEST_ASSERT_EQUAL(get_adc_reading_voltage(), 0);
}