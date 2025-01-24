#ifndef __CATERPILLAR__
#define __CATERPILLAR__

#include <xc.h>

char get_D_from_state(char state);

char get_B_from_state(char state);

char get_state();

void next_state(char* state);

#endif