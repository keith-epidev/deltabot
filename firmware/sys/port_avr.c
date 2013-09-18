//port.c
#include "sys/port.h"

#ifdef __MSP430_HAS_PORT1_R__
 Port P1 = {(byte *)P1IN_,(byte *)P1OUT_,(byte *)P1DIR_,(byte *)P1IFG_,(byte *)P1IES_,(byte *)P1IE_,(byte *)P1SEL_,(byte *)P1REN_};
#endif


/*

#ifdef __MSP430_HAS_PORT1_R__
 Port P1 = {(byte *)P1IN_,(byte *)P1OUT_,(byte *)P1DIR_,(byte *)P1IFG_,(byte *)P1IES_,(byte *)P1IE_,(byte *)P1SEL_,(byte *)P1REN_};
#endif

#ifdef __MSP430_HAS_PORT2_R__
 Port P2 = {(byte *)P2IN_,(byte *)P2OUT_,(byte *)P2DIR_,(byte *)P2IFG_,(byte *)P2IES_,(byte *)P2IE_,(byte *)P2SEL_,(byte *)P2REN_};
#endif
*/
//PORT UTILS

void port_config_out( Port *port){
	*port->dir = 0xff;
	*port->out = 0x00;
//	*obj.adr = 0x01;
//	*obj.ctl = 0x00;//output
//	*obj.adr = 0x00;
}

void port_low(Port *port){
	*port->out = 0x00;
}

void port_out_toggle( Port *port){
	*port->out = *port->out ^ 0xff;

}

void port_set( Port *port, byte var){
	*port->out = var;
}


/*
void port_config_in(port obj){
	*(obj.out) = 0x00;
	*(obj.adr) = 0x01;
	*(obj.ctl) = 0xFF;//input
	*(obj.adr) = 0x00;
}


void port_config_alt(port obj){
	*(obj.out) = 0x00;
	*(obj.adr) = 0x02;
	*(obj.ctl) = 0xFF;//output
	*(obj.adr) = 0x00;
}


byte port_get(port obj){
	return *(obj.in);
}

*/


//PIN UTILS
Pin pin_new(  Port *port_ptr, byte id){
	Pin pin = {id,port_ptr, (0x01<<id)};
/*	pin.id = id;
	pin.port_ptr = port_ptr;
	pin.mask = (0x01<<id);
*/	return pin;
}

byte pin_get(Pin *pin){
	byte in;
	in = *pin->port_ptr->in;
	in = in >> pin->id;
	in &= 0x01;
	return in;
}


void pin_set(Pin *pin, byte var){
	if(var)
	pin_high(pin);
	else
	pin_low(pin);
}

void pin_high(Pin *pin){
		*pin->port_ptr->out |= pin->mask;
}

void pin_low(Pin *pin){
		*pin->port_ptr->out &= ~pin->mask;
}


void pin_pulse(Pin *pin){
	delay(1000);
	pin_toggle(pin);
	delay(1000);
	pin_toggle(pin);
	delay(1000);
}

void pin_toggle( Pin *pin){
		*pin->port_ptr->out ^= pin->mask;
}


void pin_config_out(Pin *pin){
	pin_low(pin);
	*pin->port_ptr->dir |= pin->mask;
}

void pin_config_in(Pin *pin){
	pin_low(pin);
	*pin->port_ptr->dir &= ~pin->mask;
}


void pin_config_alt(Pin *pin){
	pin_low(pin);
	*pin->port_ptr->sel |= pin->mask;
}

