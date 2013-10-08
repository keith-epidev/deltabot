#include "etc/byte.h"
#include "etc/config.h"
#include "sys/port.h"
#include "sys/console.h"
#include "dev/uart/uart.h"
#include <util/delay.h>



int main(void){

	Uart *uart = uart_init();
	pin_config_out(heat);
	pin_low(heat);

	console_init();
	while(1);

	return 1;
}
