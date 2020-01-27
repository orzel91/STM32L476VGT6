/*
 * config.h
 *
 *  Created on: 2 gru 2019
 *      Author: jarek
 */

#ifndef CONFIG_CONFIG_H_
#define CONFIG_CONFIG_H_


#include "hdr_gpio.h"
#include "hdr_bitband.h"
#include "rcc.h"
#include "gpio.h"

/*
+=============================================================================+
| global definitions
+=============================================================================+
*/
#define CPU_FREQ 80000000


/*
+=============================================================================+
| LEDs
+=============================================================================+
*/

#define LED_RED_PORT    GPIOB  // GPIO port to which a LED is connected
#define LED_RED_PIN     2      // pin number of a LED
#define LED_RED_MASK    P2     // mask of a LED pin

#define LED_GREEN_PORT  GPIOE  // GPIO port to which a LED is connected
#define LED_GREEN_PIN   8      // pin number of a LED
#define LED_GREEN_MASK  P8     // mask of a LED pin


/*
+=============================================================================+
| Buttons
+=============================================================================+
*/

#define JOY_CENTER_PORT  GPIOA  // GPIO port to which a button is connected
#define JOY_CENTER_PIN   0      // pin number of a button
#define JOY_CENTER_MASK  P0     // mask of a button pin

#define JOY_LEFT_PORT    GPIOA  // GPIO port to which a button is connected
#define JOY_LEFT_PIN     1      // pin number of a button
#define JOY_LEFT_MASK    P1     // mask of a button pin

#define JOY_DOWN_PORT    GPIOA  // GPIO port to which a button is connected
#define JOY_DOWN_PIN     5      // pin number of a button
#define JOY_DOWN_MASK    P5     // mask of a button pin

#define JOY_RIGHT_PORT   GPIOA  // GPIO port to which a button is connected
#define JOY_RIGHT_PIN    2      // pin number of a button
#define JOY_RIGHT_MASK   P2     // mask of a button pin

#define JOY_UP_PORT      GPIOA  // GPIO port to which a button is connected
#define JOY_UP_PIN       3      // pin number of a button
#define JOY_UP_MASK      P3     // mask of a button pin


/*
+=============================================================================+
| UART2
+=============================================================================+
*/

#define UART_BAUDRATE   115200

#define UART_TX_PORT    GPIOD  // GPIO port to which a LED is connected
#define UART_TX_PIN     5      // pin number of a LED
#define UART_TX_MASK    P5     // mask of a LED pin

#define UART_RX_PORT    GPIOD  // GPIO port to which a LED is connected
#define UART_RX_PIN     6      // pin number of a LED
#define UART_RX_MASK    P6     // mask of a LED pin

#endif /* CONFIG_CONFIG_H_ */
