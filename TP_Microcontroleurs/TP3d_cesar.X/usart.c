/*
 * File:   usart.c
 * Author: gilda
 *
 * Created on February 10, 2025, 1:44 PM
 */


#include "usart.h"

void config_USART()
{
    // Assignation des pins de réception (RX) et de transmission (TX) aux entrées RX/TX du module EUSART. A l?aide du module PPS
    // Connecter RC6 à TX/CK (via le registre RC6PPS)
    RC6PPS = 0b10100;
    // Connecter RC7 à RX (via le registre RXPPS)
    RXPPS = (0b10 << 3) + 7; // selection du registre C
    
    // Configuration des pins RC6 et RC7 via les registres TRISx, ANSELx, LATx
    // RC6 : Sortie
    TRISC6 = 0;
    ANSELCbits.ANSC6 = 0;
    LATCbits.LATC6 = 0;
    // RC7 : Entrée numérique
    TRISC7 = 1;
    ANSELCbits.ANSC7 = 0;
    
    // Configuration de la vitesse de transmission (baudrate) à 9600 bauds à travers trois bits de configuration et un registre 16 bits
    // Bit SYNC (registre TX1STA; on utilisera le module en mode asynchrone, donc SYNC=0)
    TX1STAbits.SYNC = 0;
    // Bit BRGH (registre TX1STA) = 0
    TX1STAbits.BRGH = 0;
    // Bit BRG16 (registre BAUD1CON) = 0
    BAUD1CONbits.BRG16 = 0;
    // Registres SP1BRGH, SP1BRGL (SP1BRG) = 12
    SP1BRGH = 0;
    SP1BRGL = 12;
    
    // Activation du module EUSART
    // Activation des pins (Bit SPEN, registre RC1STA)
    RC1STAbits.SPEN = 1;
    // Activation du transmitter (Bit TXEN, registre TX1STA)
    TX1STAbits.TXEN = 1;
    // Activation du receiver (Bit CREN, registre RC1STA)
    RC1STAbits.CREN = 1;
}

void config_USART_RX()
{
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;;
    PIE1bits.RCIE = 1;
    RC1STAbits.RX9 = 0;
}

void send_char(char c)
{
    TX1REG = c;
}