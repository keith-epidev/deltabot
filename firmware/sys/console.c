#include "console.h"
#include "math.h"
#include <string.h>
#include "lib/utils/array_length.h"

static FILE mystdout = FDEV_SETUP_STREAM(uart_put_printf, NULL, _FDEV_SETUP_WRITE);


void disp_temp();
void echo();
void control_heat();
void position();

Program programs[] = {
{"temp",disp_temp},
{"echo",echo},
{"heat",control_heat},
{"G",position}
};

void console_init(){
	stdout = &mystdout;

	uart_write("-= deltabot v0.1 =-\r\n");
	uart_write("Console Started.\r\n");

}



	static char args[5][32];
void console_parse(){

	//clean array
	for(int i = 0; i < ARRAY_LENGTH(args); i++)
		for(int j = 0; j < ARRAY_LENGTH(args[0]); j++)
			args[i][j] = 0;

	int i = 0;
	int arg = 0;
	char temp;

	while(1){
		temp = uart_get();
		if(temp == 0){
			break;
		}else
		if(temp == ' '){
			arg++;
			i=0;
		}else{
			args[arg][i] = temp;
			i++;
		}
	}
	
	for(int i = 0; i < ARRAY_LENGTH(programs); i++){
		if( strcmp (programs[i].name, args[0]) == 0 ){
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
	printf("echo [%s] [%s]\n",args[0],args[1]);
}

void control_heat(){
	if(args[1][0] == 0)
	printf("heat requires one argument\n");
	else if( strcmp(args[1],"on") == 0)
	pin_high(e_heat);
	else if( strcmp(args[1],"off") == 0)
	pin_low(e_heat);
	else
	printf("error!\n");
}

void position(){
	x = atof(args[1]);
	y = atof(args[2]);
	z = atof(args[3]);

	calc_position();

}
