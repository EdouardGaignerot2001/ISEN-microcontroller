/*
 * File:   main.c
 * Author: gilda
 *
 * Created on February 10, 2025, 2:30 PM
 */

#include "lcd.h"
#include "spi.h"
#include "configbits.h"
#include <xc.h>

void main(void) {
    SPI_InitializePins();
    LCD_InitializePins();
    SPI_Initialize();
    LCD_Initialize();
    
    LCD_Clear();
    
    LCD_GoTo(0, 0);
    
    LCD_WriteString("Hello, world!");
    
    while(1){
    }
    
    return;
}
