#include <stdint.h>
#include "stm32l476xx.h"
#include "config.h"
#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"
#include "printf.h"
#include "uart.h"


TaskHandle_t xTaskHandle1 = NULL;
TaskHandle_t xTaskHandle2 = NULL;


// Tasks prototypes
void vTask1Handler(void* params);
void vTask2Handler(void* params);



int main(void)
{

    systemCoreClocInit();
    gpio_init();
    gpio_pinCfg(LED_RED_PORT, LED_RED_PIN, GPIO_OUT_PP_50MHz);
    gpio_pinCfg(LED_GREEN_PORT, LED_GREEN_PIN, GPIO_OUT_PP_50MHz);

    uart_init(UART_BAUDRATE);

    xTaskCreate(vTask1Handler, "Task-1", configMINIMAL_STACK_SIZE, NULL, 2, &xTaskHandle1);
    xTaskCreate(vTask2Handler, "Task-2", configMINIMAL_STACK_SIZE, NULL, 2, &xTaskHandle2);

    vTaskStartScheduler();

    while(1)
    {

    }
}


void vTask1Handler(void* params)
{


    while(1)
    {
        printf_("task1\n");
        gpio_toggle(LED_RED_PORT, LED_RED_MASK);
        vTaskDelay(250);
    }
}

void vTask2Handler(void* params)
{
    while(1)
    {
        printf_("task2\n");
        gpio_toggle(LED_GREEN_PORT, LED_GREEN_MASK);
        vTaskDelay(500);
    }
}



