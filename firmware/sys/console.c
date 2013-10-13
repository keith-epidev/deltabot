#include "console.h"
#include "math.h"


#define B 3950

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

	double avg_temp = 0;
	double volt = 0;
	double therm = 0;
	double t = 0;
	double logs = 0;
	double b_val = 0;

	uart_write(">");
	while(!uart_new_line());
	uart_write("Got stuff\r\n");

	for(int i = 0; i < 1000; i++)
	avg_temp += temp[i];
	avg_temp /= 1000;


	volt = (avg_temp)*5/1024;

	therm = (4700*volt)/(5-volt);


	t = 1 / 298.15;

	logs =  1/log(therm / 100000 );
	
	b_val = B * logs ;


	t += 1/b_val;
 
	t = 1/t;
	t -= 273.15;


//	for(char i = 0; i < 5; i++)
//	test += temp;
	//test=test>>10;

	printf("vout: %f\n",volt);
	printf("therm: %f\n",therm);
	printf("log: %f\n",logs);
	printf("b: %f\n",b_val);
	printf("temp: %fC°\n",t);
	uart_get();

}
