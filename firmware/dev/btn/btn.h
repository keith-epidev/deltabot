#ifndef BTN_H
#define BTN_H

#include "sys/port.h"

typedef const struct Btn{
	byte mode;
	Pin *pin;
}Btn;

Btn btn_new(Pin *pin, byte mode);
byte btn_get(Btn *btn);

#endif
