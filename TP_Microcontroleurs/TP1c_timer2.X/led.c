#include "led.h"

void output_D(char mask)
{
    TRISD &= ~mask; // on active la sortie  sur le port D 
}

void output_B(char mask)
{
    TRISB &= ~mask; // on active la sortie sur le port B
}

void enable_D(char mask)
{
    LATD |= mask; // on active les pin selon le mask sur le port D
}

void disable_D(char mask)
{
    LATD &= ~mask; // on desactive les pin selon le mask sur le port D
}

void disable_B(char mask)
{
    LATB &= ~mask; // on desactive les pin selon le mask sur le port D
}

void enable_B(char mask)
{
    LATB |= mask; // on ative les pin selon le mask sur le port B
}