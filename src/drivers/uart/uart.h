#ifndef _UART_H
#define _UART_H


#include <stdint.h>

void uart_init(uint32_t baudrate);
void uart_putChr(char data);


#endif // _UART_H
