#include "led.h" // Bits de configuration

// définitino des groupes de led
#define GROUP_1 MASK_LED1 | MASK_LED2 | MASK_LED3 | MASK_LED4
#define GROUP_2 MASK_LED5 | MASK_LED6 | MASK_LED7 | MASK_LED8

void main(void) {      
    output_D(GROUP_1);
    output_B(GROUP_2);

    while(1){        
        enable_D(GROUP_1);
        disable_B(GROUP_2);
        __delay_ms(500);
        disable_D(GROUP_1);
        enable_B(GROUP_2);
        __delay_ms(500);
    }
}