#include "console.h"
#include "math.h"
#include <string.h>
#include "lib/utils/array_length.h"

static FILE mystdout = FDEV_SETUP_STREAM(uart_put_printf, NULL, _FDEV_SETUP_WRITE);


void disp_temp();
void echo();

Program programs[] = {
{"temp",disp_temp},
{"echo",echo}
};

void console_init(){
	stdout = &mystdout;

	uart_write("-= deltabot v0.1 =-\r\n");
	uart_write("Console Started.\r\n");

}



	static char buffer[64];
void console_parse(){
	int i = 0;
	while((buffer[i++] = uart_get())!=0);
//	printf("rec:[%s]\n",buffer);
	
	for(int i = 0; i < ARRAY_LENGTH(programs); i++){
		if( strcmp (programs[i].name, buffer) == 0 ){
			programs[i].function();
			return;
		}
	}
	
	printf("Command not found!\n");
}

void console_prompt(){
	while(1)
	console_interp();
}

void console_interp(){


	uart_write(">");
	while(!uart_new_line());
	console_parse();

//	uart_write("Got stuff\r\n");


	//uart_get();
}


void disp_temp(){
	printf("temp=%0.2f\n",thermistor_get_c());
}

void echo(){
	printf("echo\n");
}
