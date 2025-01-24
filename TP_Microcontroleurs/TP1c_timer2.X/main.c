#include "configbits.h"
#include "caterpillar.h"
#include "timer.h"

#define _XTAL_FREQ 8000000

void main(void) {
    timer2_init();
    TRISD = 0x00;              // On met tout le port D en sortie
    TRISB = 0x00;              // On met tout le port B en sortie
    char state = 0x01;         // représente l'été du chenillar
    LATD = get_D_from_state(state);        
    LATB = get_B_from_state(state);

    while (1) {
        wait_timer2_periods(); // Attendre une période du Timer 2
        state = get_state();
        next_state(&state);
        LATD = get_D_from_state(state);
        LATB = get_B_from_state(state);
    }
}

/*
#include "led.h"

// Prototypes
void Timer2_Init(void);
void __interrupt() ISR(void);

// Fonction pour initialiser Timer 2
void Timer2_Init(void) {
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

// Routine d'interruption
void __interrupt() ISR(void) {
    if (PIR1bits.TMR2IF) {    // Vérifier si l'interruption vient de Timer 2
        PIR1bits.TMR2IF = 0;  // Réinitialiser le drapeau d'interruption
        LATD ^= 0x01;         // Inverser l'état de LED1 (bit 0 de LATD)
    }
}

// Fonction principale
void main(void) {
    // Initialisation
    Timer2_Init();
    output_D(MASK_LED1);  // Configurer la LED1 sur PORTD

    // Boucle principale
    while (1) {
        // Rien à faire ici, la gestion est assurée par l'interruption
    }
}
*/
