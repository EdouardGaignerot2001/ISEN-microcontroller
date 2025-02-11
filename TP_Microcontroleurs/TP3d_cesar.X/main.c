#include "configbits.h"
#include "usart.h"
#include "adc.h"
#include "cesar.h"

State s;

void __interrupt() ISR(void);

void __interrupt() ISR(void)
{
    if (PIR1bits.RCIF)
    {
        handle_char_received(&s);
    }
    if (INTF)
    {
        handle_button_clicked(&s);
    }
}

void main(void) {
    config_USART();
    config_USART_RX();
    
    SPI_InitializePins();
    LCD_InitializePins();
    SPI_Initialize();
    LCD_Initialize();
    
    button_init();
    
    init_adc();
        
    s.crypting = true;
    s.offset = 1;
    
    update_lcd(s);
    
    char result;
    
    while (1) {
        result = ad_read_max_36();
        if (result != s.offset)
        {
            s.offset = result;
            update_lcd(s);
        }
    }
}