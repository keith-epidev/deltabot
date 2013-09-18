//lcd.c
#include "lcd.h"
//#include "lib/display/ascii.h"



/*
 Pins | LCD
------|------------------
 P1.2 | SCLK - Clock?
 P1.3 | MOSI - Data?
 P1.4 | D/C - Mode select
 P1.5 | RST - Reset

*/

/*
LCD lcd_new(Pin *clk, Pin *data, Pin *mode, Pin *reset){
	LCD lcd = {{clk,data},mode,reset};
	pin_config_out(clk);
	pin_config_out(data);
	pin_config_out(mode);
	pin_config_out(reset);

	//active low reset pulse
	
	pin_high(reset);
	pin_pulse(reset);

	//enter config mode
	pin_low(mode);

	//config lcd driver
	serial_out(&lcd.serial,0x21);
	serial_out(&lcd.serial,0xBf);
	serial_out(&lcd.serial,0x04);
	serial_out(&lcd.serial,0x14);
	serial_out(&lcd.serial,0x20);
	serial_out(&lcd.serial,0x0C);
	
	//ready to accept data
	pin_high(mode);
	write_string(&lcd,"              - [ EPIDEV ] -");

	return lcd;
}

void write_string(LCD *lcd,char *s){
	int i = 0;
	while(s[i] != 0){
		write_character(lcd,s[i]);
		i++;
	}
}


void write_character(LCD *lcd,char c){
	c = c-32; //offset char map

	for(int i = 0; i < 5; i++){
		serial_out(&lcd->serial,ASCII[(int)c][i]);
	}
	serial_out(&lcd->serial,0x00);
}
*/
