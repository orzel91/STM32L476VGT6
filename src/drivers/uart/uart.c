#include "uart.h"
#include "config.h"
#include <stddef.h>
#include "fifo.h"
#include <string.h>
#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"
#include "queue.h"
#include "printf.h"
#include "gpio.h"
#include "timers.h"
#include <stdlib.h>


#define UART_BUFF_SIZE 128

#define LED_ON_CMD           1
#define LED_OFF_CMD          2
#define LED_TOGGLE_CMD       3
#define LED_TOGGLE_STOP_CMD  4
#define LED_STATUS           5

/*
+=============================================================================+
| typedefs
+=============================================================================+
*/

typedef struct
{
    uint8_t cmdNr;
    uint8_t cmdArgs[10];
} AppCmds;

typedef struct {
    volatile uint8_t buff[UART_BUFF_SIZE];
    FIFO_BUFFER fifo;
} UartData;


/*
+=============================================================================+
| local functions' declarations
+=============================================================================+
*/
static void uart_periphInit(uint32_t baudrate);
static void vTask1MenuDisplay(void* params);
static void vTask2CmdHandling(void* params);
static void vTask3CmdProcess(void* params);
static void vTask4UartWrite(void* params);
static uint8_t getCmdCode(uint8_t cmd);
static uint8_t getArguments(uint8_t *buff);
static void ledToggle(TimerHandle_t xTimer);
static void ledToggleStart(uint32_t duration);
static void ledToggleStop(void);

/*
+=============================================================================+
| module variables
+=============================================================================+
*/
static UartData txData;
static UartData rxData;

// task tcb pointers
static TaskHandle_t xTask1TcbPtr = NULL;
static TaskHandle_t xTask2TcbPtr = NULL;
static TaskHandle_t xTask3TcbPtr = NULL;
static TaskHandle_t xTask4TcbPtr = NULL;

// queue handlers
static QueueHandle_t cmdQueue = NULL;
static QueueHandle_t writeQueue = NULL;

// software timers handlers
static TimerHandle_t ledToggleHandle = NULL;

static const char menu[] =  {"\
\r\nMENU\
\r\n1.LED_ON\
\r\n2.LED_OFF\
\r\n3.LED_TOGGLE\
\r\n4.LED_TOGGLE_OFF\
\r\n5.LED_STATUS\
\r\n6.EXIT_APP\
\r\nType option: "
};

/*
+=============================================================================+
| global functions
+=============================================================================+
*/
bool uart_init(uint32_t baudrate)
{
    FIFO_Init(&txData.fifo, txData.buff, sizeof(txData.buff));
    FIFO_Init(&rxData.fifo, rxData.buff, sizeof(rxData.buff));
    uart_periphInit(baudrate);

    // create command queue
    cmdQueue = xQueueCreate(10, sizeof(AppCmds));

    // create write queue
    writeQueue = xQueueCreate(10, sizeof(char*));

    if ((cmdQueue != NULL) && (writeQueue != NULL))
    {
        xTaskCreate(vTask1MenuDisplay, "T1-Menu", 500, NULL, 1, &xTask1TcbPtr);
        xTaskCreate(vTask2CmdHandling, "T2-CmdHandle", 500, NULL, 2, &xTask2TcbPtr);
        xTaskCreate(vTask3CmdProcess, "T3-CmdProcess", 500, NULL, 2, &xTask3TcbPtr);
        xTaskCreate(vTask4UartWrite, "T4-UARTWrite", 500, NULL, 2, &xTask4TcbPtr);

        return true;
    }
    else
    {
        printf_("Creation of Queues on heap was not possible");
        return false;
    }

}


void uart_putChr(char data)
{
    FIFO_Put(&txData.fifo, (uint8_t)(data & 0xFFU));

    if (!(USART2->CR1 & USART_CR1_TXEIE))
    {
        USART2->CR1 |= USART_CR1_TXEIE; // TXE Interrupt Enable
    }


    if (USART2->ISR & USART_ISR_TXE)
    {
        USART2->TDR = FIFO_Get(&txData.fifo);
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

    // set priority of uart interrupt regarding to RTOS
    NVIC_SetPriority(USART2_IRQn, 5);

    // Enable interrupts in NVIC
    NVIC_EnableIRQ(USART2_IRQn);

    // Configure USART
    USART2->BRR = CPU_FREQ / baudrate; // Set baudrate
    USART2->CR1 = USART_CR1_UE;        // USART Enable
    USART2->CR1 |= USART_CR1_TE;       // Transmitter Enable
    USART2->CR1 |= USART_CR1_RE;       // Receiver Enable
    USART2->CR1 |= USART_CR1_RXNEIE;   // RXNE Interrupt Enable
}


static void vTask1MenuDisplay(void* params)
{
    UNUSED(params);
    const char *pData = menu;

    while(1)
    {
        xQueueSend(writeQueue, &pData, portMAX_DELAY);

        // block this task until someone notifies
        xTaskNotifyWait(0, 0, NULL, portMAX_DELAY);
    }
}

static void vTask2CmdHandling(void* params)
{
    UNUSED(params);
    AppCmds newCmd;

    memset(&newCmd, 0, sizeof(newCmd));

    while(1)
    {
        // wait for notification, block
        xTaskNotifyWait(0, 0, NULL, portMAX_DELAY);

        taskENTER_CRITICAL();
        newCmd.cmdNr = getCmdCode(FIFO_Get(&rxData.fifo));
        getArguments(newCmd.cmdArgs);
        taskEXIT_CRITICAL();

        // send cmd to cmdQueue
        xQueueSend(cmdQueue, &newCmd, portMAX_DELAY);
    }
}

static void vTask3CmdProcess(void* params)
{
    UNUSED(params);
    AppCmds newCommand;
    memset(&newCommand, 0, sizeof(newCommand));

    while(1)
    {
        xQueueReceive(cmdQueue, (void*)&newCommand, portMAX_DELAY);

        printf_("%d\n", newCommand.cmdNr);

        if (newCommand.cmdNr == LED_ON_CMD)
        {
            gpio_set(LED_GREEN_PORT, LED_GREEN_MASK);
        }
        else if (newCommand.cmdNr == LED_OFF_CMD)
        {
            gpio_clr(LED_GREEN_PORT, LED_GREEN_MASK);
        }
        else if (newCommand.cmdNr == LED_TOGGLE_CMD)
        {
            ledToggleStart(pdMS_TO_TICKS(500));
        }
        else if (newCommand.cmdNr == LED_TOGGLE_STOP_CMD)
        {
            ledToggleStop();
        }
        else if (newCommand.cmdNr == LED_STATUS)
        {
            printf_("LED status: %d", gpio_check(LED_GREEN_PORT, LED_GREEN_MASK));
        }
        else
        {
            printf_("Bad command number");
        }

    }
}

static void vTask4UartWrite(void* params)
{
    UNUSED(params);
    char *pData = NULL;

    while(1)
    {
        xQueueReceive(writeQueue, &pData, portMAX_DELAY);
        printf("%s", pData);
    }
}

static uint8_t getCmdCode(uint8_t cmd)
{
    char tmp = 0;
    tmp = (char)cmd;
    tmp = atoi(&tmp);
    return tmp;
}

static uint8_t getArguments(uint8_t *buff)
{
    UNUSED(buff);
    return 1;
}

static void ledToggle(TimerHandle_t xTimer)
{
    UNUSED(xTimer);
    gpio_toggle(LED_GREEN_PORT, LED_GREEN_MASK);
}

static void ledToggleStart(uint32_t duration)
{
    if (ledToggleHandle == NULL)
    {
        // create timer
        ledToggleHandle = xTimerCreate("LED-TIMER", duration, pdTRUE, NULL, ledToggle);

        // start timer
        xTimerStart(ledToggleHandle, portMAX_DELAY);
    }
    else
    {
        // start timer
        xTimerStart(ledToggleHandle, portMAX_DELAY);
    }
}

static void ledToggleStop(void)
{
    if (xTimerIsTimerActive(ledToggleHandle) != pdFALSE) {
        xTimerStop(ledToggleHandle, portMAX_DELAY);
    }
}

/*
+=============================================================================+
| ISRs
+=============================================================================+
*/
void USART2_IRQHandler(void)
{
    uint8_t tmpData = 0;
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    if (USART2->ISR & USART_ISR_TXE)
    {
        tmpData = FIFO_Get(&txData.fifo);

        if (tmpData) {
            USART2->TDR = tmpData;
        } else {
            USART2->CR1 &= ~USART_CR1_TXEIE; // TXE Interrupt Disable
        }
    }

    if (USART2->ISR & USART_ISR_RXNE)
    {
        tmpData = USART2->RDR;

        if (tmpData == '\r') {
            xTaskNotifyFromISR(xTask2TcbPtr, 0, eNoAction, &xHigherPriorityTaskWoken);
            xTaskNotifyFromISR(xTask1TcbPtr, 0, eNoAction, &xHigherPriorityTaskWoken);
        } else {
            FIFO_Put(&rxData.fifo, tmpData);
        }

        if (xHigherPriorityTaskWoken) {
            taskYIELD();
        }
    }

}
