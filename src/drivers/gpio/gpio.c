/** \file gpio.c
 * \brief GPIO driver.
 * \details GPIO default configuration and function for configuring a pin
 * \author Freddie Chopin, http://www.freddiechopin.info/
 * \date 2012-01-07
 */

/******************************************************************************
* chip: STM32F1x
* compiler: arm-none-eabi-gcc (Sourcery CodeBench Lite 2011.09-69) 4.6.1
*
* prefix: gpio_
*
* available global functions:
* 	void gpio_init(void)
* 	void gpio_pin_cfg(GPIO_TypeDef *port_ptr, uint32_t pin, uint32_t mode_cnf_value)
*
* available local functions:
*
* available interrupt handlers:
******************************************************************************/

/*
+=============================================================================+
| includes
+=============================================================================+
*/

#include "gpio.h"
#include <stdint.h>
#include "hdr_gpio.h"
#include "config.h"


/*
+=============================================================================+
| local definitions
+=============================================================================+
*/
#define GPIO_GET_MODER(combination)         (((combination) & 0xF) >> 0)
#define GPIO_GET_OTYPER(combination)        (((combination) & 0xF0) >> 4)
#define GPIO_GET_OSPEEDR(combination)       (((combination) & 0xF00) >> 8)
#define GPIO_GET_PUPDR(combination)         (((combination) & 0xF000) >> 12)
#define GPIO_GET_AFR(combination)           (((combination) & 0xF0000) >> 16)


/*
+=============================================================================+
| module variables
+=============================================================================+
*/

/*
+=============================================================================+
| local functions' declarations
+=============================================================================+
*/
static void buttonInit(void);
/*
+=============================================================================+
| global functions
+=============================================================================+
*/

void gpio_init(void)
{
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN | RCC_AHB2ENR_GPIOBEN | RCC_AHB2ENR_GPIOCEN |
			RCC_AHB2ENR_GPIODEN | RCC_AHB2ENR_GPIOEEN | RCC_AHB2ENR_GPIOFEN |
			RCC_AHB2ENR_GPIOGEN | RCC_AHB2ENR_GPIOHEN;	// enable all GPIOs

	// Init LED
    gpio_pinCfg(LED_RED_PORT, LED_RED_PIN, GPIO_OUT_PP_50MHz);
    gpio_pinCfg(LED_GREEN_PORT, LED_GREEN_PIN, GPIO_OUT_PP_50MHz);

    buttonInit();

}

void gpio_pinCfg(GPIO_TypeDef *port_ptr, uint32_t pin, uint32_t configuration)
{
    uint32_t moder, otyper, ospeedr, pupdr, afr, afrx;

    moder = port_ptr->MODER;                // localize
    moder &= ~(GPIO_MODER_mask << (pin * 2));   // clear current setting
    moder |= (GPIO_GET_MODER(configuration) << (pin * 2));  // apply new setting
    port_ptr->MODER = moder;                // save back

    otyper = port_ptr->OTYPER;              // localize
    otyper &= ~(GPIO_OTYPER_mask << pin);   // clear current setting
    otyper |= (GPIO_GET_OTYPER(configuration) << pin);  // apply new setting
    port_ptr->OTYPER = otyper;              // save back

    ospeedr = port_ptr->OSPEEDR;                // localize
    ospeedr &= ~(GPIO_OSPEEDR_mask << (pin * 2));   // clear current setting
    ospeedr |= (GPIO_GET_OSPEEDR(configuration) << (pin * 2));  // apply new setting
    port_ptr->OSPEEDR = ospeedr;                // save back

    pupdr = port_ptr->PUPDR;                // localize
    pupdr &= ~(GPIO_PUPDR_mask << (pin * 2));   // clear current setting
    pupdr |= (GPIO_GET_PUPDR(configuration) << (pin * 2));  // apply new setting
    port_ptr->PUPDR = pupdr;                // save back

    if (pin < 8)                            // determine which AFR register should be used
        afrx = 0;                           // AFRL - pins [0; 7]
    else
    {
        afrx = 1;                           // AFRH - pins [8; 15]
        pin -= 8;                           // trim pin number
    }

    afr = port_ptr->AFR[afrx];              // localize
    afr &= ~(GPIO_AFRx_mask << (pin * 4));  // clear current setting
    afr |= (GPIO_GET_AFR(configuration) << (pin * 4));  // apply new setting
    port_ptr->AFR[afrx] = afr;              // save back
}

void gpio_toggle(GPIO_TypeDef *port_ptr, gpioPin mask)
{
    if (port_ptr->ODR & mask) {
        port_ptr->BRR |=  mask;
    } else {
        port_ptr->BSRR |=  mask;
    }
}

void gpio_set(GPIO_TypeDef *port_ptr, gpioPin mask)
{
    port_ptr->BSRR |=  mask;
}

void gpio_clr(GPIO_TypeDef *port_ptr, gpioPin mask)
{
    port_ptr->BRR |=  mask;
}

bool gpio_checkButton(GPIO_TypeDef *port_ptr, gpioPin mask)
{
    if (port_ptr->IDR & mask) {
        return true;
    } else {
        return false;
    }
}

/*
+=============================================================================+
| local functions
+=============================================================================+
*/

static void buttonInit(void)
{
    // Init Buttons
    gpio_pinCfg(JOY_CENTER_PORT, JOY_CENTER_PIN, GPIO_IN_FLOATING);
    gpio_pinCfg(JOY_LEFT_PORT, JOY_LEFT_PIN, GPIO_IN_PULL_DOWN);
    gpio_pinCfg(JOY_DOWN_PORT, JOY_DOWN_PIN, GPIO_IN_PULL_DOWN);
    gpio_pinCfg(JOY_RIGHT_PORT, JOY_RIGHT_PIN, GPIO_IN_PULL_DOWN);
    gpio_pinCfg(JOY_UP_PORT, JOY_UP_PIN, GPIO_IN_PULL_DOWN);
}

/*
+=============================================================================+
| ISRs
+=============================================================================+
*/

/******************************************************************************
* END OF FILE
******************************************************************************/
