#include "configbits.h"
#include "usart.h"

#define _XTAL_FREQ 8000000



void main(void) {
    config_USART();

    while (1) {
        __delay_ms(1000);
        
        send_char('b');
    }
}