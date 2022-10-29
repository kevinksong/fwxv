#include "log.h"

// Allocating memory for extern variables in .h files
char g_log_buffer[MAX_LOG_SIZE];
Mutex s_log_mutex;

UartSettings log_settings = {
  .alt_fn = GPIO_ALTFN_0,
  .baudrate = 115200,
  .tx = {GPIO_PORT_B, 6},
  .rx = {GPIO_PORT_B, 7}
};

void log_init(void) {
  mutex_init(&s_log_mutex);  
  uart_init(UARTPORT, &log_settings);
}