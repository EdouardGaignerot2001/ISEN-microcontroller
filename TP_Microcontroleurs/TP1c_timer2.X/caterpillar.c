#include "caterpillar.h"

char get_D_from_state(char state)
{
    return state & 0xf;
}

char get_B_from_state(char state)
{
    return state >> 4;
}

char get_state()
{
    return LATD + (LATB << 4);
}

void next_state(char* state)
{
    if (*state == 0x80)
    {
        *state = 0x1;
    }
    else
    {
        *state <<= 1;
    }
}