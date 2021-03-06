#include "rcc.h"
#include <stdint.h>
#include "stm32l476xx.h"
#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"
#include "config.h"


#define SYSTICK_FREQ 1000


void systemCoreClocInit(void)
{
    RCC->CR = RCC_CR_HSION;                // enable HSI clock
    while(!(RCC->CR & RCC_CR_HSIRDY));     // wait until HIS clock will be ready

    RCC->CR &= ~RCC_CR_PLLON;              // disable PLL
    while(RCC->CR & RCC_CR_PLLRDY);        // wait until PLL will be turned off

    RCC->PLLCFGR = RCC_PLLCFGR_PLLSRC_HSI; // HSI16 oscillator source clock selected

    RCC->PLLCFGR |= RCC_PLLCFGR_PLLN_1 | RCC_PLLCFGR_PLLN_3; // set PLL to multiplay x10

    RCC->CR |= RCC_CR_PLLON;               // enable PLL
    FLASH->ACR |= FLASH_ACR_LATENCY_4WS;

    while(!(RCC->CR & RCC_CR_PLLRDY));     // wait until PLL will be ready

    RCC->PLLCFGR |= RCC_PLLCFGR_PLLREN;    // Main PLL PLLCLK output enable

    RCC->CFGR |= RCC_CFGR_SW_PLL;          // change SYSCLK to PLL
    RCC->CFGR |= RCC_CFGR_PPRE1_DIV1;      // HCLK not divided
    RCC->CR &= ~RCC_CR_MSION;              // turn off MSI
}
