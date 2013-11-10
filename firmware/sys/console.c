#include "console.h"
#include "math.h"
#include <string.h>
#include "lib/utils/array_length.h"
#include "lib/position/position.h"
#include "dev/stepper/stepper.h"
#include <util/delay.h>

static FILE mystdout = FDEV_SETUP_STREAM(uart_put_printf, NULL, _FDEV_SETUP_WRITE);


void disp_temp();
void echo();
void control_heat();
void position();
void drop();
void rise();
void get_sense();
//void test();
void aprox();
void home();
void sound();

Program programs[] = {
{"temp",disp_temp},
{"echo",echo},
{"heat",control_heat},
{"G",position},
{"drop",drop},
{"rise",rise},
{"get_sense",get_sense},
//{"test",test},
{"aprox",aprox},
{"home",home},
{"sound",sound}
};

void console_init(){
	stdout = &mystdout;

	printf("-= deltabot v0.1 =-\n");
	printf("Console Started.\n");

}



	static char args[5][16];
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

/*
void rise(){

hold_on = 1;
a1_step = 1;
a2_step = 1;
a3_step = 1;
pin_low(x_dir);
pin_low(y_dir);
pin_low(z_dir);
displacement = 0;
steppers_enable();
printf("rising..");
while(1){
if(pin_get(x_stop) == 0)
	a1_step = -1;
if(pin_get(y_stop) == 0)
	a2_step = -1;
if(pin_get(z_stop) == 0)
	a3_step = -1;

if(pin_get(x_stop)==0 && pin_get(y_stop)==0 && pin_get(z_stop)==0)
	break;
}

//printf("d: %g\n",displacement);

hold_on = 0;

}

void drop(){
int s = 10;
uart_disable();
hold_on = 1;
a1_step = 0;
a2_step = 0;
a3_step = 0;
pin_high(x_dir);
pin_high(y_dir);
pin_high(z_dir);
displacement = 0;
steppers_enable();

while(1){
set_speed(s+=2);
if(pin_get(sense_rx)==1)
	break;
}
//printf("%g!!!\n",displacement);

hold_on = 0;

uart_enable();

}
*/

void get_sense(){

printf("sense_rx=%i",pin_get(sense_rx));

}

void aprox(){

	long double dist = atof(args[1]);
	double a1 = atof(args[2]);
	double a2 = atof(args[3]);
	double a3 = atof(args[4]);



	pin_low(motor_enb);



	if(a1 > 0)
		pin_low(steppers[0]->direction);
	else
		pin_high(steppers[0]->direction);

	if(a2 > 0)
		pin_low(steppers[1]->direction);
	else
		pin_high(steppers[1]->direction);

	if(a3 > 0)
		pin_low(steppers[2]->direction);
	else
		pin_high(steppers[2]->direction);


	a1 = fabs(a1);
	a2 = fabs(a2);
	a3 = fabs(a3);

	a1_cycle = 0;
	a2_cycle = 0;
	a3_cycle = 0;


	int d_cycle = 0;
	int d = 0;

	//find largest
	/*
	if(a1 >= a2 && a1 >= a3)
	d = a1;
	else
	if(a2 >= a1 && a2 >= a3)
	d = a2;
	else
	if(a3 >= a1 && a3 >= a2)
	d = a3;
	*/

/*
	printf("a1=%g\n",a1);
	_delay_ms(10);
	printf("a2=%g\n",a2);
	_delay_ms(10);
	printf("a3=%g\n",a3);
	_delay_ms(1);
*/

	while(1){
	if( (int)(a1_cycle + a1) != (int)(a1_cycle)   ){
		pin_toggle(steppers[0]->step);
	}

	if( (int)(a2_cycle + a2) != (int)(a2_cycle)   ){
		pin_toggle(steppers[1]->step);
	}

	if( (int)(a3_cycle + a3) != (int)(a3_cycle)   ){
		pin_toggle(steppers[2]->step);
	}
/*
	if( floor(a1_cycle + a1) != floor(a1_cycle)   ){
		pin_toggle(steppers[0]->step);
	}

	if( floor(a2_cycle + a2) != floor(a2_cycle)   ){
		pin_toggle(steppers[1]->step);
	}

	if( floor(a3_cycle + a3) != floor(a3_cycle)   ){
		pin_toggle(steppers[2]->step);
	}
*/
		a1_cycle += a1;
		a2_cycle += a2;
		a3_cycle += a3;


		dist--;
		if(dist <= 0)
			break;

//		_delay_us(1);

	}
	pin_high(motor_enb);
}


void sound(){

for(unsigned int i = 0; i < 60000; i++){
	pin_toggle(buzzer);
	_delay_us(1);
}

	_delay_ms(500);
for(unsigned int i = 0; i < 60000; i++){
	pin_toggle(buzzer);
	_delay_us(1);
}
	_delay_ms(500);

for(unsigned int i = 0; i < 60000; i++){
	pin_toggle(buzzer);
	_delay_us(1);
}
	_delay_ms(500);

}


/*
void test(){
	if(args[1][0] == 0){
		printf("test requires one argument\n");
		return;
	}

	long long dist = atof(args[1]);
	int a1 = atof(args[2]);
	int a2 = atof(args[3]);
	int a3 = atof(args[4]);



	pin_low(motor_enb);



	if(a1 > 0)
		pin_low(steppers[0]->direction);
	else
		pin_high(steppers[0]->direction);

	if(a2 > 0)
		pin_low(steppers[1]->direction);
	else
		pin_high(steppers[1]->direction);

	if(a3 > 0)
		pin_low(steppers[2]->direction);
	else
		pin_high(steppers[2]->direction);


	a1 = abs(a1);
	a2 = abs(a2);
	a3 = abs(a3);

	int d_cycle = 0;
	int d = 0;

	//find largest
	if(a1 >= a2 && a1 >= a3)
	d = a1;
	else
	if(a2 >= a1 && a2 >= a3)
	d = a2;
	else
	if(a3 >= a1 && a3 >= a2)
	d = a3;



	while(1){
		a1_cycle++;
		a2_cycle++;
		a3_cycle++;
		d_cycle++;


	if(a1_cycle >= a1 && a1 != -1){
		pin_toggle(steppers[0]->step);
		a1_cycle = 0;
	}
	if(a2_cycle >= a2 && a2 != -1){
		pin_toggle(steppers[1]->step);
		a2_cycle = 0;
	}
	if(a3_cycle >= a3 && a3 != -1){
		pin_toggle(steppers[2]->step);
		a3_cycle = 0;
	}

	if(d_cycle >= d){
		dist--;
		if(dist <= 0)
			break;
		else
		d_cycle = 0;
	}


		_delay_us(1);




	}
	pin_high(motor_enb);
}
*/


void rise(){
int a1 = 1,a2 = 1,a3 = 1;

pin_low(x_dir);
pin_low(y_dir);
pin_low(z_dir);
pin_low(motor_enb);

displacement = 0;
printf("rising..\n");
while(1){
displacement++;

if(a1 == 1)
	pin_toggle(steppers[0]->step);
if(a2 == 1)
	pin_toggle(steppers[1]->step);
if(a3 == 1)
	pin_toggle(steppers[2]->step);



if(pin_get(x_stop) == 0)
	a1 = -1;
if(pin_get(y_stop) == 0)
	a2 = -1;
if(pin_get(z_stop) == 0)
	a3 = -1;

if(a1==-1 && a2==-1 && a3==-1)
	break;

_delay_us(6);

}

printf("disp: %g\n",displacement);

pin_high(motor_enb);

}

void drop(){

pin_high(x_dir);
pin_high(y_dir);
pin_high(z_dir);
pin_low(motor_enb);

displacement = 0;
printf("dropping..\n");
while(1){
	displacement++;

	pin_toggle(steppers[0]->step);
	pin_toggle(steppers[1]->step);
	pin_toggle(steppers[2]->step);

if(pin_get(sense_rx)==1)
	break;


_delay_us(6);

}

printf("disp: %g\n",displacement);

pin_high(motor_enb);
}



void home(){
	rise();
	drop();
}



