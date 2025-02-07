/*
 * File:   pwm.c
 * Author: gilda
 *
 * Created on 4 février 2025, 12:11
 */

#include "pwm.h"

void timer2_init(void) {
    // voir les choix dans hyperparameter.ipynb
    PIR1bits.TMR2IF = 0;      // Réinitialiser le drapeau d'interruption
    
    T2CONbits.T2CKPS = 0b11;  // Prédiviseur 1:64
    
    TMR2 = 0;                 // Initialiser le compteur à 0

    T2CONbits.TMR2ON = 1;     // Activer le Timer 2
}

void set_duty_cycle(int i)
{
    // voir notebook à la racine du projet    
    int DCHDCL = i * 4.08;
    
    PWM4DCH = DCHDCL >> 2;
    PWM4DCL = DCHDCL & 0x3;
}

// Fonction d'initialisation du PWM4 avec PPS et PWM4
// Les commentaires suivent précisemment ce qui est décrit page 181 de la documentation
void PWM4_init()
{
    TRISD |= 0x01; // Disable the PWMx pin output driver(s) by setting the associated TRIS bit(s).
    
    PWM4CON = 0; // Clear the PWMxCON register. 
    
    PR2 = 0x65; // Load the PR2 register with the PWM period value.
    
    // Load the PWMxDCH register and bits <7:6> of the PWMxDCL register with the PWM duty cycle value
    set_duty_cycle(0);
   
    // Configure and start Timer2
    timer2_init();
    
    // Enable PWM output pin and wait until Timer2 overflows, TMR2IF bit of the PIR1 register is set
    PWM4CONbits.PWM4OUT = 1; 
    while (!PIR1bits.TMR2IF); 
    PIR1bits.TMR2IF = 0;
    
    TRISD &= 0xFE; // Enable the PWMx pin output driver(s) by clearing the associated TRIS bit(s) and setting the desired pin PPS control bits
    RD0PPS = 0x0F;  // Assign PWM4 output to RD0
    
    PWM4CONbits.PWM4EN = 1; // Configure the PWM module by loading the PWMxCON register with the appropriate values
}