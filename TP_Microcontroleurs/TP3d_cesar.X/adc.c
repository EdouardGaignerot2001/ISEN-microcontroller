/*
 * File:   adc.c
 * Author: gilda
 *
 * Created on 7 février 2025, 13:31
 */

#include "adc.h"

char ad_read(){
    ADCON0 |= 0x02; // indique le debut de la conversion
    while(ADCON0bits.GO){} // tant que la conversion est en cours
    return ADRESH; // retourne le resultat de la conversion
}

char ad_read_max_36()
{
    return ad_read() / 7;
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



