/*
 * File:   cesar.c
 * Author: gilda
 *
 * Created on 10 février 2025, 16:02
 */

#include "cesar.h"
#include "usart.h"

void display_mode_lcd(bool crypting)
{
    LCD_GoTo(0, 0);
    
    LCD_WriteString("Mode:");
    
    if (crypting)
    {
        LCD_WriteString(" Chiff");
    }
    else
    {
        LCD_WriteString(" Dechiff");
    }
}

void display_offset_lcd(int offset)
{
    LCD_GoTo(1, 0);
    
    LCD_WriteString("Offset: ");
    char buffer[4];
    sprintf(buffer, "%d", offset);
    LCD_WriteString(buffer);
}

void update_lcd(State s)
{
    LCD_Clear();
    display_mode_lcd(s.crypting);
    display_offset_lcd(s.offset);
}

void button_init()
{
    TRISB |= 0x10; // RB0 en entrée
    ANSELB = 0; // RB0 en numérique
    INTCONbits.INTE = 1;   // Activer l'interruption externe (RB0/INT)
    INTCONbits.GIE = 1;    // Activer les interruptions globales 
}

char encode(char c, char offset)
{
    return (c + offset) % 36;
}

char decode(char c, char offset)
{
    return (c - offset) % 36;
}

char index(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        return c - 'a' + 10;
    }
    if (c >= 'A' && c <= 'Z')
    {
        return c - 'A' + 10;
    }
    if (c >= '0' || c <= '9')
    {
        return c - '0';
    }
    return '\0';
}

char unindex(char c)
{
    if (c < 10)
    {
        return '0' + c;
    }
    return 'a' + c - 10;
}

void handle_char_received(State* s)
{
    if (RC1STAbits.OERR)
    {
        RC1STAbits.CREN = 0;// njdspdpouspmfvs
        RC1STAbits.CREN = 1;
    }
    else
    {
        char c = index(RC1REG);

        if (c != '\0')
        {
            if (s->crypting)
            {
                c = encode(c, s->offset);
            }
            else
            {
                c = decode(c, s->offset);
            }
            send_char(unindex(c));
        }
    }
    PIR1bits.RCIF = 0;
}

void handle_button_clicked(State* s)
{
    s->crypting = !s->crypting;
    update_lcd(*s);
    INTF = 0;
}