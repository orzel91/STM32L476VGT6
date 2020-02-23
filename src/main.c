#include <stdint.h>
#include "stm32l476xx.h"
#include "config.h"
#include "printf.h"
#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"
#include "SEGGER_SYSVIEW_FreeRTOS.h"

int main(void)
{
    bool initPass = true;

    DWT->CTRL |= (1 << 0); // Enable CYCCNT in DWT_CTRL

    SEGGER_SYSVIEW_Conf();
    SEGGER_SYSVIEW_Start();

    systemCoreClocInit();
    gpio_init();
    initPass = uart_init(UART_BAUDRATE);

    if (initPass)
    {
        vTaskStartScheduler();
    }

    while(1)
    {

    }
}


