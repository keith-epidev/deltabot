#include <msp430.h>

/* Demo UART application.  Receives bytes from the computer
 * at 2400 bps, and blinks the red LED for 1s and the green
 * LED for 0s.
 */

#define   RED_LED   BIT7
#define   GRN_LED   BIT6

#define   RXD       BIT2

/* Ticks per bit, and ticks per half.  Use the following values based on speed:
 * 9600 bps ->  13
 * 2400 bps ->  52
 * 1200 bps -> 104
 * I did not have success with slower speeds, like 300 bps.
 */
#define   TPB      13
#define   TPH      (TPB - TPB/2)

int RXByte;
unsigned char bitcnt = 0;

/* function prototypes */
void initUart( void );
void RX_Ready( void );

void main(void) {
    /* stop the watchdog timer */
    WDTCTL = WDTPW + WDTHOLD;

    /* LEDs off, but we'll blink them as we send or receive bits */
    P1DIR |= RED_LED+GRN_LED;
    P1OUT &= ~ (RED_LED + GRN_LED );

    initUart();

    for( ; ; ) {
        RX_Ready();
        /* go to sleep and wait for data */
        __bis_SR_register( LPM0_bits + GIE );
    }
}

void initUart( void ) {
    /* set up the clocks for 1 mhz */
    BCSCTL1 = CALBC1_1MHZ;
    DCOCTL = CALDCO_1MHZ;
    BCSCTL2 &= ~(DIVS_3);

    /* Set timer A to use continuous mode 1 mhz / 8 = 125 khz. */
    TACTL = TASSEL_2 + MC_2 + ID_3;

    /* RXD set for timer function as a receive pin */
    P1SEL |= RXD;
    P1DIR &= ~ RXD;
}

void RX_Ready( void ) {
    /* Make ready to receive character.  Syncronize, negative edge
     * capture, enable interrupts.
     */
    bitcnt = 8;
    CCTL1 = SCS + OUTMOD0 + CM1 + CAP + CCIE;
}

void TimerA1 (void) __attribute__((interrupt(TIMER0_A1_VECTOR)));
void TimerA1(void) {
    /* reset the interrupt flag */
    CCTL1 &= ~CCIFG;

    /* add ticks per bit to trigger again on next bit in stream */
    CCR1 += TPB;

    /* If we just caught the 0 start bit, then turn off capture
     * mode (it'll be all compares from here forward) and add
     * tick-per-half so we'll catch signals in the middle of
     * each bit.
     */
    if( CCTL1 & CAP ) {
        CCTL1 &= ~ CAP;
        CCR1 += TPH;
    }
    /* Otherwise we need to catch another bit.  We'll shift right
     * the currently received data, and add new bits on the left.
     */
    else {
        RXByte >>= 1;

        if( CCTL1 & SCCI ) {
            RXByte |= 0x80;
            P1OUT |= RED_LED;           // for testing
            P1OUT &= ~ GRN_LED;         // for testing
        } else {
            P1OUT |= GRN_LED;           // for testing
            P1OUT &= ~ RED_LED;         // for testing
        }
        bitcnt --;

        if( ! bitcnt ) {
            /* Go back to capture mode and wait for next start bit */
            CCTL1 |= CAP;
            bitcnt = 8;
		if(RXByte == 0x31){
            P1OUT |= GRN_LED;           // for testing
            P1OUT &= ~ RED_LED;         // for testing
		}
		else if(RXByte == 0x32){
            P1OUT |= RED_LED;           // for testing
            P1OUT &= ~ GRN_LED;         // for testing
		}

		

//            P1OUT &= ~ (RED_LED + GRN_LED);     // for testing

            __bic_SR_register_on_exit( LPM0_bits );
        }
    }
}
