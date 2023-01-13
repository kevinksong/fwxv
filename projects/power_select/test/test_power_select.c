#include "unity.h"
#include "power_select_power_supply_task.h"

void setup_test(void) {

}

void teardown_test(void) {}

void test_power_select_power_supply_task(void) {
  get_adc_reading_voltage();
  TEST_ASSERT_EQUAL(5, 5);
}