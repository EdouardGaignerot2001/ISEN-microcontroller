#include "timer.h"

void timer2_init(void) {
    T2CONbits.T2CKPS = 0b11;  // Pr�diviseur 1:64
    T2CONbits.T2OUTPS = 0b1111; // Postdiviseur 1:16
    PR2 = 255;               // R�gler la p�riode (256 counts)

    TMR2 = 0;                 // Initialiser le compteur � 0
    T2CONbits.TMR2ON = 1;     // Activer le Timer 2
}

void wait_timer2_periods() {
    while (!PIR1bits.TMR2IF);
    PIR1bits.TMR2IF = 0;
}