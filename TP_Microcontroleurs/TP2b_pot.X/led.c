#include "led.h"

void output_D(char mask)
{
    TRISD &= ~mask; // on active la sortie  sur le port D 
}

void output_B(char mask)
{
    TRISB &= ~mask; // on active la sortie sur le port D 
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

void output_all()
{
    output_D(MASK_LED1 | MASK_LED2 | MASK_LED3 | MASK_LED4); // on active la sortie pour les LED1-LED4 sur le port D 
    output_B(MASK_LED5 | MASK_LED6 | MASK_LED7 | MASK_LED8); // on active la sortie pour la LED5-LED8 sur le port B
}

void enable_all()
{
    enable_D(MASK_LED1 | MASK_LED2 | MASK_LED3 | MASK_LED4); // on active les LED1-LED4 sur le port D
    enable_B(MASK_LED5 | MASK_LED6 | MASK_LED7 | MASK_LED8); // on active la LED5-LED8 sur le port D
}

void disable_all()
{
    disable_D(MASK_LED1 | MASK_LED2 | MASK_LED3 | MASK_LED4); // on active les LED1-LED4 sur le port D
    disable_B(MASK_LED5 | MASK_LED6 | MASK_LED7 | MASK_LED8); // on active la LED5-LED8 sur le port D
}

void chenillard()
{
    enable_D(MASK_LED1);
    __delay_ms(1000); // Attend pendant 250 ms
    disable_D(MASK_LED1);
    
    enable_D(MASK_LED2);
    __delay_ms(1000); // Attend pendant 250 ms
    disable_D(MASK_LED2);
    
    enable_D(MASK_LED3);
    __delay_ms(1000); // Attend pendant 250 ms
    disable_D(MASK_LED3);
    
    enable_D(MASK_LED4);
    __delay_ms(1000); // Attend pendant 250 ms
    disable_D(MASK_LED4);
    
    enable_B(MASK_LED5);
    __delay_ms(1000); // Attend pendant 250 ms
    disable_B(MASK_LED5);
    
    enable_B(MASK_LED6);
    __delay_ms(1000); // Attend pendant 250 ms
    disable_B(MASK_LED6);
    
    enable_B(MASK_LED7);
    __delay_ms(1000); // Attend pendant 250 ms
    disable_B(MASK_LED7);
    
    enable_B(MASK_LED8);
    __delay_ms(1000); // Attend pendant 250 ms
    disable_B(MASK_LED8);
}