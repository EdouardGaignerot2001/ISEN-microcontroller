#include "timer.h"

void timer4_init(void) {
    // voir les choix dans hyperparameter.ipynb
    T4CONbits.T4CKPS = 0b00;  // Pr�diviseur 1:64
    T4CONbits.T4OUTPS = 0b0111; // Postdiviseur 1:16
    PR4 = 243;               // R�gler la p�riode (256 counts)

    TMR4 = 0;                 // Initialiser le compteur � 0
    PIR2bits.TMR4IF = 0;      // R�initialiser le drapeau d'interruption
    PIE2bits.TMR4IE = 1;      // Activer les interruptions du Timer 2
    INTCONbits.PEIE = 1;      // Activer les interruptions p�riph�riques
    INTCONbits.GIE = 1;       // Activer les interruptions globales

    T4CONbits.TMR4ON = 1;     // Activer le Timer 2
}

void wait_timer4_periods() {
    // Attendre que le drapeau TMR2IF soit lev�
    while (!PIR2bits.TMR4IF);  // Scrutation
    PIR1bits.TMR2IF = 0;      // R�initialiser le drapeau
}