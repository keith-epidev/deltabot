//lcd.c
#include "dev/lcd/3310/3310.h"
#include "lib/display/ascii.h"

/*
 Pins | LCD
------|------------------
      | VCC
      | GND
      | SCE 
      | RST
      | D/C
      | MOSI
      | SCLK
      | LED

*/


LCD* lcd_new(Pin *clk, Pin *data, Pin *mode, Pin *reset, Pin *enable){
        LCD *lcd = (LCD * ) malloc( sizeof( LCD ) );

	lcd->serial = (Serial){clk,data};
	lcd->mode = mode;
	lcd->rst = reset;
	lcd->enb = enable;
	lcd->col = 14;
	lcd->row = 6;

	pin_config_out(clk);
	pin_config_out(data);
	pin_config_out(mode);
	pin_config_out(reset);
	pin_config_out(enable);

	//active low reset pulse
	pin_low(enable);
	
	pin_high(reset);
	pin_pulse(reset);

	//enter config mode
	pin_low(mode);

	//config lcd driver
	serial_out(&lcd->serial,0x21);
	serial_out(&lcd->serial,0xA0);
	serial_out(&lcd->serial,0x04);
	serial_out(&lcd->serial,0x14);
	serial_out(&lcd->serial,0x20);
	serial_out(&lcd->serial,0x0C);

	pin_high(mode);
	clear_screen(lcd);
	
	//ready to accept data
	gotoXY(lcd,0,0);


	//write_string(lcd,"123456789ABCDE123456789ABCDE123456789ABCDE123456789ABCDE123456789ABCDE123456789ABCDE");
//	write_string(lcd,"123");

	pin_high(enable);
	return lcd;
}

void write_string(LCD *lcd,char *s){
	int i = 0;
	pin_low(lcd->enb);
	pin_high(lcd->mode);
	while(s[i] != 0){
		write_character(lcd,s[i]);
		i++;
	}
	pin_high(lcd->enb);
}


void write_character(LCD *lcd,char c){
	c = c-32; //offset char map

	for(int i = 0; i < 5; i++){
		serial_out(&lcd->serial,ASCII[(int)c][i]);
	}
	serial_out(&lcd->serial,0x00);
}

void clear_screen(LCD *lcd){
	for(int i = 0; i < 14*7; i++)
	write_character(lcd,' ');
}



void gotoXY(LCD *lcd, char x, char y){
	pin_low(lcd->enb);
	pin_low(lcd->mode);

	serial_out(&lcd->serial, 0x80 | x );
	serial_out(&lcd->serial, 0x40 | y );

	pin_high(lcd->enb);
	pin_high(lcd->mode);
}

