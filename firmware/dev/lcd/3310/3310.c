//lcd.c
#include "dev/lcd/3310/3310.h"
#include "lib/display/ascii.h"
#include <util/delay.h>
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


LCD* lcd_new(Pin *mode, Pin *reset, Pin *enable){
        LCD *lcd = (LCD * ) malloc( sizeof( LCD ) );

	lcd->spi = spi_init();
	lcd->mode = mode;
	lcd->rst = reset;
	lcd->enb = enable;
	lcd->col = 14;
	lcd->row = 6;

	pin_config_out(mode);
	pin_config_out(reset);
	pin_config_out(enable);

	pin_low(enable);

	//active low reset pulse
	pin_high(reset);
	pin_pulse(reset);

	//enter config mode
	pin_low(mode);

	//config lcd driver
	_delay_us(100);
	spi_put(0x21);
	_delay_us(100);
	spi_put(0xA0);
	_delay_us(100);
	spi_put(0x04);
	_delay_us(100);
	spi_put(0x14);
	_delay_us(100);
	spi_put(0x20);
	_delay_us(100);
	spi_put(0x0C);
	_delay_us(100);

	pin_high(mode);
	clear_screen(lcd);
	
	//ready to accept data
	gotoXY(lcd,0,0);

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
		spi_put(ASCII[(int)c][i]);
	_delay_us(100);
	}
	spi_put(0x00);
	_delay_us(100);
}

void clear_screen(LCD *lcd){
	for(int i = 0; i < 14*7; i++)
	write_character(lcd,' ');
}



void gotoXY(LCD *lcd, char x, char y){
	pin_low(lcd->enb);
	pin_low(lcd->mode);

	spi_put( 0x80 | x );
	_delay_us(100);
	spi_put( 0x40 | y );
	_delay_us(100);


	pin_high(lcd->enb);
	pin_high(lcd->mode);
}

