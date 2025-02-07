#include <xc.h>
#include "configbits.h"

// #definitions
#define MASK_LED1 0x01 // d�fini l'octet MASK_LED1 a la valeur 0000 0001 ou le bit de poids faible correspond a l'etat de la led1
#define MASK_LED2 0x02
#define MASK_LED3 0x04
#define MASK_LED4 0x08
#define MASK_LED5 0x01
#define MASK_LED6 0x02
#define MASK_LED7 0x04
#define MASK_LED8 0x08

/*--------+------+----------
 El�ment | Port | # de bit
 --------+------+----------
 D1      | D    | 0
 D2      | D    | 1
 D3      | D    | 2
 D4      | D    | 3
 D5      | D    | 4
 D6      | D    | 5
 D7      | D    | 6
 D8      | D    | 7
 --------+------+----------*/


void output_D(char mask);
void output_B(char mask);
void enable_D(char mask);
void disable_D(char mask);
void disable_B(char mask);
void enable_B(char mask);
void output_all();
void enable_all();
void disable_all();
void chenillard();