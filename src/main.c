#include <stdint.h>
#include "stm32l476xx.h"
#include "config.h"
#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"
#include "SEGGER_SYSVIEW_FreeRTOS.h"


// Tasks prototypes
void vTask1Handler(void *params);
void vTask2Handler(void *params);

// Tasks handlers
TaskHandle_t xTaskHandle1 = NULL;
TaskHandle_t xTaskHandle2 = NULL;


int main(void)
{
    DWT->CTRL |= (1 << 0); // Enable CYCCNT in DWT_CTRL

    SEGGER_SYSVIEW_Conf();
    SEGGER_SYSVIEW_Start();

    systemCoreClocInit();
    gpio_init();

    xTaskCreate(vTask1Handler, "Task-1", configMINIMAL_STACK_SIZE, NULL, 2, &xTaskHandle1);
    xTaskCreate(vTask2Handler, "Task-2", configMINIMAL_STACK_SIZE, NULL, 2, &xTaskHandle2);

    vTaskStartScheduler();

    while (1)
    {
    }
}

void vTask1Handler(void *params)
{
    (void)params;

    while (1)
    {
        gpio_toggle(LED_RED_PORT, LED_RED_MASK);
        vTaskDelay(250);
    }
}

void vTask2Handler(void *params)
{
    (void)params;

    while (1)
    {
        gpio_toggle(LED_GREEN_PORT, LED_GREEN_MASK);
        vTaskDelay(500);
    }
}
