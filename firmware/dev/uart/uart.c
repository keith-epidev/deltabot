#include "uart.h"

#define   TPB      13
#define   TPH      (TPB - TPB/2)
#define RED_LED	b7
#define GRN_LED	b1

char bitcnt = 0;
char bitcnt_rx = 0;
int TXWord;
int RXByte;

Uart *target;

static char buffer[64];


void prep_tx(char c);
void prep_rx( void );

Uart* uart_init(Pin *tx, Pin *rx){

	Uart *uart = (Uart * ) malloc( sizeof( Uart ) );

	buffer[0] = 'a';

	uart->tx = tx;
	uart->rx = rx;
	uart->in = circular_buffer_new(2);
	uart->out = circular_buffer_new(16);

	//Uart temp = {tx,rx,circular_buffer_new(16),circular_buffer_new(16)};
	pin_config_out(tx);
	pin_config_alt(rx);
	pin_config_in(rx);

	/* set up the clocks for 1 Mhz */
	BCSCTL1 = CALBC1_1MHZ;
	DCOCTL = CALDCO_1MHZ;
	BCSCTL2 &= ~(DIVS_3);
	/* Set timer A to use count up mode 4 Mhz / 8 = 500 Khz. */
	TACTL = TASSEL_2 + MC_2 + ID_3 + TACLR;
	/* Set ticks-per-bit to specify communication speed */
	TACCR0 = TPB;

	target = uart;

	//prep_rx();

	return uart;//temp;
}


////////////// send stuff


void prep_tx(char c){

	/* load the byte */
	TXWord = c;
	/* add stop bit */
	TXWord |= 0x100;
	/* add start bit */
	TXWord <<= 1;    

	bitcnt = 10;

	/* clear the counter, clear interrupt flag, and tell Timer A0 to
	*      * start triggering interrupts
	*           */
	TACTL |= TACLR;
	TACCTL0 &= ~CCIFG;
	TACCTL0 |= CCIE;

   /* Set ticks-per-bit to specify communication speed */
    TACCR0 = TPB;
   
    /* clear interrupt flag, and tell Timer A0 capture control to
     * start triggering interrupts
     */
    TACCTL0 &= ~CCIFG;
    TACCTL0 |= CCIE;


	/* sleep until message sent */
	while( TACCTL0 & CCIE ) {
	__bis_SR_register( LPM0_bits + GIE );
	}

}



void uart_put(Uart *uart, char c){
	if(bitcnt == 0)
		prep_tx(c);
	else
	circular_buffer_put(uart->out,c);

}

void uart_putstr(Uart *uart, char *str){
	/*
	if(bitcnt == 0){
		prep_tx(str[0]);
		circular_buffer_putstr(uart->out,&str[1]);
	}else
		circular_buffer_putstr(uart->out,str);
*/
	circular_buffer_putstr(uart->out,str);
	if(bitcnt == 0)
		prep_tx(circular_buffer_get(uart->out));
		
}





void TimerA0 (void) __attribute__((interrupt(TIMER0_A0_VECTOR)));
void TimerA0(void) {
 CCR0 += TPB;


	if( ! bitcnt  && circular_buffer_isempty(target->out)  ) {
		/* no bits left, turn off interrupts and wake up */
		TACCTL0 &= ~ CCIE;
		__bic_SR_register_on_exit( LPM0_bits );
		return;
	}else 
	if( ! bitcnt && !circular_buffer_isempty(target->out) ){
		TACCTL0 &= ~ CCIE;
		__bic_SR_register_on_exit( LPM0_bits );
		prep_tx(circular_buffer_get(target->out));
		return;
	}
	else {
		/* send least significant bit */
		if( TXWord & 0x01 ) {
			pin_high(target->tx);
	} else {
			pin_low(target->tx);
	}

	/* shift word to remove one bit */
	TXWord >>= 1;
	bitcnt --;
	TACCTL0 &= ~CCIFG;
	}
}


/////////////// recieve part

void prep_rx(void){
  bitcnt_rx = 8;
    CCTL1 = SCS + OUTMOD0 + CM_2 + CAP + CCIE;
    CCTL1 &= ~CCIFG;

}

/**
 * Receives a single character.
 */
char uart_receive() {
     
    prep_rx();
   
    while (TACCTL1 & CCIE) {
      /* go to sleep and wait for data */
      __bis_SR_register( LPM0_bits + GIE );
    }
   
    return RXByte;
}







void TimerA1 (void) __attribute__((interrupt(TIMER0_A1_VECTOR)));
void TimerA1(void) {

      /* add ticks per bit to trigger again on next bit in stream */
    CCR1 += TPB;
     
    /* If we just caught the 0 start bit, then turn off capture
     * mode (it'll be all compares from here forward) and add
     * ticks-per-half so we'll catch signals in the middle of
     * each bit.
     */
    if( CCTL1 & CAP ) {
        /* 8 bits pending */
        bitcnt_rx = 8;
 
        /* next interrupt in 1.5 bits (i.e. in middle of next bit) */
        CCR1 += TPH;
 
        /* reset capture mode and interrupt flag */
        CCTL1 &= ~ ( CAP + CCIFG );      
    } else {
          /* Otherwise we need to catch another bit.  We'll shift right
           * the currently received data, and add new bits on the left.
           */
          RXByte >>= 1;
          if( CCTL1 & SCCI ) {
              RXByte |= 0x80;
          }
          bitcnt_rx --;
     
          /* last bit received */
          if( ! bitcnt_rx ) {       
            //  P1OUT &= ~(LED);     // for testing
              TACCTL1 &= ~CCIE;
              __bic_SR_register_on_exit( LPM0_bits );
            }
    }  
 
    /* reset the interrupt flag */
    CCTL1 &= ~CCIFG;



}
