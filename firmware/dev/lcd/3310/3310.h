#ifndef LCD3310_H
#define LCD3310_H

#include "sys/port.h"
#include "lib/serial/serial.h"
#include "lib/delay/delay.h"
#include "dev/lcd/lcd.h"



LCD* lcd_new(Pin *clk, Pin *data, Pin *mode, Pin *reset, Pin *enable);
void write_string(LCD *lcd,char *s);
void write_character(LCD *lcd,char c);
void gotoXY(LCD *lcd, char x, char y);
void clear_screen(LCD *lcd);
//void shift_register_latch_output(Shift_register *shift_register);


#endif
