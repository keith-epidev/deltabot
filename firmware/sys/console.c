#include "console.h"
#include "math.h"

static FILE mystdout = FDEV_SETUP_STREAM(uart_put_printf, NULL, _FDEV_SETUP_WRITE);


void console_init(){
	stdout = &mystdout;

	uart_write("-= deltabot v0.1 =-\r\n");
	uart_write("Console Started.\r\n");

}



void console_prompt(){
	while(1)
	console_interp();
}

void console_interp(){


	uart_write(">");
	while(!uart_new_line());
	uart_write("Got stuff\r\n");

	//uart_get();
}
