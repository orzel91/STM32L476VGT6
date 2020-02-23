#ifndef _UART_H
#define _UART_H


#include <stdint.h>
#include <stdbool.h>

bool uart_init(uint32_t baudrate);
void uart_putChr(char data);


#endif // _UART_H
