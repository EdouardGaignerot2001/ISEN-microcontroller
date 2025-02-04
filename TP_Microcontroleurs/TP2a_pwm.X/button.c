/*
 * File:   button.c
 * Author: gilda
 *
 * Created on 4 f�vrier 2025, 12:13
 */
#include "button.h"

void button_init()
{
    TRISB |= 0x10; // RB0 en entr�e
    ANSELB = 0; // RB0 en num�rique
}

int button_pressed()
{
    return RB0 == 0;
}
