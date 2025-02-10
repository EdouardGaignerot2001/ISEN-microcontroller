
#ifndef __USART__
#define	__USART__

#include <xc.h> // include processor files - each processor file is guarded.  

void config_USART();

void send_char(char c);

void config_USART_RX();

#endif

