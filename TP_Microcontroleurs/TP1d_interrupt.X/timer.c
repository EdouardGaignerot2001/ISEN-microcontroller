#include "timer.h"

void timer2_init(void) {
    T2CONbits.T2CKPS = 0b11;  // Prédiviseur 1:64
    T2CONbits.T2OUTPS = 0b1111; // Postdiviseur 1:16
    PR2 = 255;               // Régler la période (256 counts)

    TMR2 = 0;                 // Initialiser le compteur à 0
    PIR1bits.TMR2IF = 0;      // Réinitialiser le drapeau d'interruption
    PIE1bits.TMR2IE = 1;      // Activer les interruptions du Timer 2
    INTCONbits.PEIE = 1;      // Activer les interruptions périphériques
    INTCONbits.GIE = 1;       // Activer les interruptions globales

    T2CONbits.TMR2ON = 1;     // Activer le Timer 2
}

void wait_timer2_periods() {
    // Attendre que le drapeau TMR2IF soit levé
    while (!PIR1bits.TMR2IF);  // Scrutation
    PIR1bits.TMR2IF = 0;      // Réinitialiser le drapeau
}