#include "configbits.h"
#include "pwm.h"
#include "timer.h"

int count = 0;
signed char step = 1;

void __interrupt() ISR(void) {
    if (PIR2bits.TMR4IF) {    // Vérifier si l'interruption vient de Timer 4
        PIR2bits.TMR4IF = 0;  // Réinitialiser le drapeau d'interruption
        set_duty_cycle(count);
        count += step;
        
        if (count == 1023) {
            step = -1;
        }
        else if (count == 0) {
            step = 1;
        }
    }
}

void main(void) {
    PWM4_init();
    timer4_init();
    
    while (1) {
    }
}