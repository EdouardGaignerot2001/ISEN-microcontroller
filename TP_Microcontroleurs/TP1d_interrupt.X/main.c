#include <xc.h>
#include "timer.h"
#include "caterpillar.h"

void __interrupt() ISR(void);

// Routine d'interruption
void __interrupt() ISR(void) {
    if (PIR1bits.TMR2IF) {    // V�rifier si l'interruption vient de Timer 2
        PIR1bits.TMR2IF = 0;  // R�initialiser le drapeau d'interruption
        char state = get_state();
        next_state(&state);
        LATD = get_D_from_state(state);
        LATB = get_B_from_state(state);
    }
}

// Fonction principale
void main(void) {
    // Initialisation
    timer2_init();
    TRISD = 0x00;              // On met tout le port D en sortie
    TRISB = 0x00;              // On met tout le port B en sortie
    char state = 0x01;         // repr�sente l'�t� du chenillar
    LATD = get_D_from_state(state);        
    LATB = get_B_from_state(state);

    // Boucle principale
    while (1) {
        // Rien � faire ici, la gestion est assur�e par l'interruption
    }
}