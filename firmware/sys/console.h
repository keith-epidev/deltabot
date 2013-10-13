#ifndef CONSOLE_H
#define CONSOLE_H

#include "etc/byte.h"
#include "lib/delay/delay.h"
#include "etc/config.h"
#include "dev/uart/uart.h"
#include <stdio.h>
#include "dev/thermistor/thermistor.h"


static FILE mystdout = FDEV_SETUP_STREAM(uart_put_printf, NULL, _FDEV_SETUP_WRITE);

void console_init();
void console_interp();
void console_prompt();

#endif

