//lcd.c
#include "winstar.h"

void write_ctrl(LCD *lcd, char c);


LCD lcd_new(Port *data, Pin *RS, Pin *RW, Pin *E){
	LCD lcd = {data,RS,RW,E,16,16};
	port_config_out(data);
	pin_config_out(RS);
	pin_config_out(RW);
	pin_config_out(E);

	//defaults
	port_low(data);
	pin_low(RS);
	pin_low(RW);
	pin_low(E);

	//config lcd driver
	write_ctrl(&lcd, 0x30 );	
	write_ctrl(&lcd, 0x30 );	
	write_ctrl(&lcd, 0x30 );	
	write_ctrl(&lcd, 0x30 );	

	write_ctrl(&lcd, 0x38 );	
	write_ctrl(&lcd, 0x0F );	
	write_ctrl(&lcd, 0x01 );	
	write_ctrl(&lcd, 0x06 );	

	//test write
//	write_string(&lcd,"test?");
	delay(1000);
	delay(1000);
	delay(1000);
	delay(1000);
	delay(1000);
	delay(1000);
	delay(1000);
	delay(1000);
	delay(1000);

	write_character(&lcd,'z');
	write_character(&lcd,'x');
	write_string(&lcd,"test?");
	write_string(&lcd,"test?");

	while(1){
	write_character(&lcd,'z');
	write_character(&lcd,'x');
	write_string(&lcd,"test?");
	write_string(&lcd,"test?");
		
	};

	return lcd;
}

void write_string(LCD *lcd, char *s){
	int i = 0;
	while(s[i] != 0){
		write_character(lcd,s[i]);
		i++;
	}
}

void wait(LCD *lcd){
	Pin D0 = pin_new(lcd->data,0);
	Pin D1 = pin_new(lcd->data,1);
	pin_config_in(&D0);
	pin_config_in(&D1);


	while(pin_get(&D0) && pin_get(&D1));


	pin_config_out(&D0);
	pin_config_out(&D1);
}

void write_character(LCD *lcd, char c){
//	wait(lcd);
	*lcd->data->out = c;
	pin_high(lcd->RS);
	pin_low(lcd->RW);
	delay(1000);
	delay(1000);
	delay(1000);
	pin_pulse(lcd->E);
	delay(1000);
	delay(1000);
	delay(1000);
	delay(1000);
}

void write_ctrl(LCD *lcd, char c){
//	wait(lcd);
	*lcd->data->out = c;
	pin_low(lcd->RS);
	pin_low(lcd->RW);
	pin_pulse(lcd->E);
	delay(1000);
}
