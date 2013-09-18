//btn.c
#include "shift_register.h"
#define speed1 1

Shift_register* shift_register_new(unsigned int size, Pin *serial, Pin *clk, Pin *latch){
	Shift_register* shift_register = (Shift_register *) malloc( sizeof(Shift_register));
	shift_register->size = size;
	shift_register->data = (char *)malloc(size * sizeof(char) );
	shift_register->serial = serial;
	shift_register->clk = clk;
	shift_register->latch = latch;

	pin_config_out(serial);
	pin_config_out(clk);
	pin_config_out(latch);
	return shift_register;
}

void shift_register_data(Shift_register *shift_register,char *data){
	memcpy(shift_register->data,data,shift_register->size);
}


void shift_register_latch_output(Shift_register *shift_register){
	for(int j = 0; j < shift_register->size; j++){ 
		char data = shift_register->data[j];

	for(int i = 0; i < 8; i++){
		if(  data & 0x01 )
		pin_high(shift_register->serial);
		else
		pin_low(shift_register->serial);
		//delay(speed1);
		
		pin_high(shift_register->clk);
		//delay(speed1);
		pin_low(shift_register->clk);
		//delay(speed1);
		data = data>>1;
		}
	}

	//latch data
	pin_high(shift_register->latch);
	//delay(speed1);
	pin_low(shift_register->latch);
	//delay(speed1);



}



