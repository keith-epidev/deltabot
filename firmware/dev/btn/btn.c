//btn.c
#include "btn.h"


Btn btn_new(Pin *pin, byte mode){
	Btn btn = {mode,pin};
	pin_config_in(pin);
	return btn;
}

byte btn_get(Btn *btn){
	if(btn->mode)
	return pin_get(btn->pin);
	else
	return !pin_get(btn->pin);
}
