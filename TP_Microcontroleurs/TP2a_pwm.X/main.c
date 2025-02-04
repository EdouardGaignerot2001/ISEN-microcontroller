#include "configbits.h"
#include "button.h"
#include "pwm.h"

void main(void) {
    button_init();
    PWM4_init();

    while (1) {
        if (button_pressed())
        {
            set_duty_cycle_to_100();
        }
        else
        {
            set_duty_cycle_to_10();
        }
    }
}