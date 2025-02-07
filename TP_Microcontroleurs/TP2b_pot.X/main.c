#include <xc.h>
#include "configbits.h"
#include "led.h"

// #definitions
/*--------+------+----------
 Elément | Port | # de bit
 --------+------+----------
 POT     | A    | 0
--------+------+----------*/
#define MASK_POT 0x01

char ad_read(){
    ADCON0 |= 0x02; // indique le debut de la conversion
    while(ADCON0 & 0x02){} // tant que la conversion est en cours
    return ADRESH; // retourne le resultat de la conversion
}

void init_adc()
{
    // pot en entree analogique
    TRISA |= 0x01;  // Configure RA0 comme entrée
    ANSELA |= 0x01; // Active le mode analogique pour RA0
    
    // registre ADCON1: 
    // 0 110 0 0 00
    // \   \    \  \_ Vdd
    //  \   \    \___ Vss
    //   \   \_______ Fosc/64
    //    \__________ justifie a gauche
    ADCON1 = 0x60;
    
    // registre ADCON0: 
    // - connecte au pot
    // - mode adc
    // 0 00000 0 1
    //  \   \   \ \_ ADON
    //   \   \   \__ GO/DONE
    //    \   \_____ AN0
    //     \________ unimplemented
    ADCON0 = 0x01;
}

void main(void) {
    // Code d'initialisation
    init_adc();
    output_all();

    while(1){
        char result = ad_read();
        disable_all();
        //enable_D(result & 0x0f);
        //enable_B((result >> 4) & 0x0f);
        char nbLed = (result >> 5) + 1;
        
        switch(nbLed)
        {
            case 1: 
                enable_D(MASK_LED1);
                break;
            case 2:
                enable_D(MASK_LED2);
                break;
            case 3:
                enable_D(MASK_LED3);
                break;
            case 4: 
                enable_D(MASK_LED4);
                break;
            case 5:
                enable_B(MASK_LED5);
                break;
            case 6:
                enable_B(MASK_LED6);
                break;
            case 7: 
                enable_B(MASK_LED7);
                break;
            case 8:
                enable_B(MASK_LED8);
                break;
            default: 
                disable_all();
        }
    }
}