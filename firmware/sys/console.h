#ifndef CONSOLE_H
#define CONSOLE_H

#include "etc/byte.h"
#include "lib/delay/delay.h"
#include "etc/config.h"
#include "dev/uart/uart.h"

void console_init();
void console_interp();

#endif

