#include "configbits.h"
#include "pwm.h"
#include "adc.h"

void main(void) {
    PWM4_init();
    init_adc();
    char result;
    while (1) {
        result = ad_read();
        set_duty_cycle(result * 0.395);
    }
}