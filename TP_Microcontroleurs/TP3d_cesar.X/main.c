#include "configbits.h"
#include "usart.h"

#define _XTAL_FREQ 8000000

void __interrupt() ISR(void);

void __interrupt() ISR(void)
{
    if (PIR1bits.RCIF)
    {
        if (RC1STAbits.OERR)
        {
            RC1STAbits.CREN = 0;
            RC1STAbits.CREN = 1;
        }
        else
        {
            // send_char(RC1REG);
            TX1REG = RC1REG;
            // display value on leds
            LATD = RC1REG & 0xf;
            LATB = RC1REG >> 4;
        }
        PIR1bits.RCIF = 0;
    }
}

void main(void) {
    config_USART();
    config_USART_RX();
    TRISD = 0;
    TRISB = 0;

    while (1) {
    }
}