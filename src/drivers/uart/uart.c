#include "uart.h"
#include "config.h"
#include <stddef.h>
#include "fifo.h"
#include <string.h>

#define UART_BUFF_SIZE 128


/*
+=============================================================================+
| typedefs
+=============================================================================+
*/
typedef enum {
    UART_NOT_INTIALIZED = 0,
    UART_IDLE,
    UART_SENDING
} UartState;

typedef struct {
    volatile UartState state;
    volatile uint8_t buff[UART_BUFF_SIZE];
    FIFO_BUFFER fifo;
} UartData;


/*
+=============================================================================+
| local functions' declarations
+=============================================================================+
*/
static void uart_periphInit(uint32_t baudrate);


/*
+=============================================================================+
| module variables
+=============================================================================+
*/
static UartData uart;


/*
+=============================================================================+
| global functions
+=============================================================================+
*/
void uart_init(uint32_t baudrate)
{
    memset(&uart, 0, sizeof(uart));
    FIFO_Init(&uart.fifo, uart.buff, sizeof(uart.buff));
    uart_periphInit(baudrate);
    uart.state = UART_IDLE;
}


void uart_putChr(char data)
{
    FIFO_Put(&uart.fifo, (uint8_t)(data & 0xFFU));

    if (!(USART2->CR1 & USART_CR1_TXEIE))
    {
        USART2->CR1 |= USART_CR1_TXEIE; // TXE Interrupt Enable
    }


    if (USART2->ISR & USART_ISR_TXE)
    {
        USART2->TDR = FIFO_Get(&uart.fifo);
        uart.state = UART_SENDING;
    }
}


/*
+=============================================================================+
| local functions
+=============================================================================+
*/
static void uart_periphInit(uint32_t baudrate)
{
    // Turn on clock for UART
    RCC->APB1ENR1 |= RCC_APB1ENR1_USART2EN;

    // Configure PIN
    gpio_pinCfg(UART_TX_PORT, UART_TX_PIN, GPIO_AF7_OD_50MHz_PULL_UP);
    gpio_pinCfg(UART_RX_PORT, UART_RX_PIN, GPIO_AF7_OD_50MHz_PULL_UP);

    // Configure USART
    USART2->BRR = CPU_FREQ / baudrate;
    USART2->CR1 = USART_CR1_UE;        // USART Enable
    USART2->CR1 |= USART_CR1_TE;       // Transmitter Enable

    // Enable interrupts in NVIC
    NVIC_EnableIRQ(USART2_IRQn);
}


/*
+=============================================================================+
| ISRs
+=============================================================================+
*/
void USART2_IRQHandler(void)
{
    uint8_t tmpData = 0;

    if (USART2->ISR & USART_ISR_TXE)
    {
        tmpData = FIFO_Get(&uart.fifo);

        if (tmpData) {
            USART2->TDR = tmpData;
        } else {
            USART2->CR1 &= ~USART_CR1_TXEIE; // TXE Interrupt Disable
            uart.state = UART_IDLE;
        }
    }
}
