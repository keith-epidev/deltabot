#include "thermistor.h"
#include "math.h"

#define B 3950
volatile int temp[1000] = {0};
int k = 0;


void thermistor_init(){

        ADMUX |= b6 + 5; //b6 is AREF with cap, 5 is ADC5 selection 
        ADCSRA = 0xAF; // enable adc, auto trigger enb, interupt enb, 32 div prescaler
        ADCSRB &= b6; // adc disable multiplexer
        ADCSRA |= b6;//start adc

}



ISR(ADC_vect) { 
        //copy value over to temp
       temp[k] =  ADC;//ADCH << 8 | ADCL;
	k++;
	if(k == 1000)
	k = 0;
}

double thermistor_get_c(){

	double avg_temp = 0;
	double volt = 0;
	double therm = 0;
	double t = 0;
	double logs = 0;
	double b_val = 0;


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

return t;
}
