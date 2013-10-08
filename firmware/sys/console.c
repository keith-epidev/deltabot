#include "console.h"

void console_init(){

	uart_write("-= deltabot v0.1 =-\r\n");
	uart_write("Console Started.\r\n");

	while(1)
	console_interp();

}


void console_interp(){
	uart_write(">");
	while(!uart_new_line());
	uart_write("Got stuff\r\n");
	uart_get();

}
