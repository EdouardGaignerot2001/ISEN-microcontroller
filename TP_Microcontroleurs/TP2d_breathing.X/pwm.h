#ifndef __PWM__
#define	__PWM__

#include <xc.h> 

void timer2_init(void);

void set_duty_cycle(int i);

void PWM4_init();

#endif

