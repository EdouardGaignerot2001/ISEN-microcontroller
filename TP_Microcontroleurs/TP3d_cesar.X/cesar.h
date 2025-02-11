/*
 * File:   cesar.h
 * Author: gilda
 *
 * Created on 10 février 2025, 16:01
 */
#ifndef __CESAR__
#define __CESAR__
#include <xc.h>
#include "lcd.h"
#include "spi.h"
#include <stdio.h>

#define bool char
#define true 1
#define false 0

typedef struct State 
{
    bool crypting;
    char offset;
} State;

void display_mode_lcd(bool crypting);
void display_offset_lcd(int offset);
void update_lcd(State s);
void button_init();
char encode(char c, char offset);
char decode(char c, char offset);;
char index(char c);
char unindex(char c);
void handle_char_received();
void handle_button_clicked();


#endif