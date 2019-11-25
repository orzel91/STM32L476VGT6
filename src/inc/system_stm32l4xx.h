/**
  ******************************************************************************
  * @file    system_stm32l4xx.h
  * @author  MCD Application Team
  * @brief   CMSIS Cortex-M4 Device System Source File for STM32L4xx devices.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/** @addtogroup CMSIS
  * @{
  */

/** @addtogroup stm32l4xx_system
  * @{
  */

/**
  * @brief Define to prevent recursive inclusion
  */
#ifndef __SYSTEM_STM32L4XX_H
#define __SYSTEM_STM32L4XX_H

#ifdef __cplusplus
 extern "C" {
#endif

/** @addtogroup STM32L4xx_System_Includes
  * @{
  */

/**
  * @}
  */


extern const uint8_t  AHBPrescTable[16];    /*!< AHB prescalers table values */
extern const uint8_t  APBPrescTable[8];     /*!< APB prescalers table values */
extern const uint32_t MSIRangeTable[12];    /*!< MSI ranges table values     */

/**
  * @}
  */

/** @addtogroup STM32L4xx_System_Exported_Constants
  * @{
  */

/**
  * @}
  */

/** @addtogroup STM32L4xx_System_Exported_Macros
  * @{
  */

/**
  * @}
  */

/** @addtogroup STM32L4xx_System_Exported_Functions
  * @{
  */

extern void SystemInit(void);
extern void SystemCoreClockUpdate(void);
/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /*__SYSTEM_STM32L4XX_H */

/**
  * @}
  */

/**
  * @}
  */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
