/*
 * File:   button.c
 * Author: gilda
 *
 * Created on 4 février 2025, 12:13
 */
#include "button.h"

void button_init()
{
    TRISB |= 0x10; // RB0 en entrée
    ANSELB = 0; // RB0 en numérique
}

int button_pressed()
{
    return RB0 == 0;
}
