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
void write_buffer(LCD *lcd);


LCD* lcd_new(Pin *mode, Pin *reset, Pin *enable){
        LCD *lcd = (LCD * ) malloc( sizeof( LCD ) );

	lcd->spi = spi_init();
	lcd->mode = mode;
	lcd->rst = reset;
	lcd->enb = enable;
	lcd->col = 14;
	lcd->row = 6;
	lcd->cursor = 0;
	lcd->buffer = circular_buffer_new(128);

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
	write_buffer(lcd);
	pin_high(lcd->enb);
}


void write_stringf(LCD *lcd,const char* format, ...){
	static char buffer[16] = {0};

	va_list args;
	va_start (args, format);
	vsnprintf (buffer, 15, format, args);

	write_string(lcd,buffer);
}


void write_character(LCD *lcd, char c){
	switch(c){
	case '\n':
		if(lcd->cursor > 5*14)
			lcd->cursor = 6*14;
		else
			if(lcd->cursor%14 != 0) //dont force new lines on new empty ones
				lcd->cursor += 14-lcd->cursor%14;
		break;
	case '\r':
		lcd->cursor -= lcd->cursor%14;

		break;
	default:

		if(lcd->cursor == 6*14){ 
			lcd->cursor -= 14;
			circular_buffer_shift(lcd->buffer,14);
			for(int i = 0; i < 14; i++)
				circular_buffer_put_index(lcd->buffer,lcd->cursor+i,' '); //clear line
		}
		circular_buffer_put_index(lcd->buffer,lcd->cursor++,c);
	}


}

void clear_screen(LCD *lcd){
	for(int i = 0; i < 14*6*6; i++){
		spi_put(0x00);
		_delay_us(100);
	}

}


void write_buffer(LCD *lcd){
	gotoXY(lcd,0,0);//ensure at starting point
	for(int i = 0; i < 14*6; i++){
		int c = (int)circular_buffer_get_index(lcd->buffer,i);
		if(c < 32) c = ' ';
		c-=32;
		for(int i = 0; i < 5; i++){
			spi_put(ASCII[c][i]);
			_delay_us(100);
		}
		spi_put(0x00);
		_delay_us(100);
	}	
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

