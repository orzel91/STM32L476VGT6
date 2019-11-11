/*---------------------------------------------------------------------------------------------------------------------+
| provide default weak handlers
+---------------------------------------------------------------------------------------------------------------------*/

// NMI
__attribute__ ((weak)) void NMI_Handler(void)
{
	while (1);
}

// Hard Fault
__attribute__ ((weak)) void HardFault_Handler(void)
{
	while (1);
}

// MPU Fault
__attribute__ ((weak)) void MemManage_Handler(void)
{
	while (1);
}

// Bus Fault
__attribute__ ((weak)) void BusFault_Handler(void)
{
	while (1);
}

// Usage Fault
__attribute__ ((weak)) void UsageFault_Handler(void)
{
	while (1);
}

// Reserved 0x1C
__attribute__ ((weak)) void __Reserved_0x1C_Handler(void)
{
	while (1);
}

// Reserved 0x20
__attribute__ ((weak)) void __Reserved_0x20_Handler(void)
{
	while (1);
}

// Reserved 0x24
__attribute__ ((weak)) void __Reserved_0x24_Handler(void)
{
	while (1);
}

// Reserved 0x28
__attribute__ ((weak)) void __Reserved_0x28_Handler(void)
{
	while (1);
}

// SVCall
__attribute__ ((weak)) void SVC_Handler(void)
{
	while (1);
}

// Debug Monitor
__attribute__ ((weak)) void DebugMon_Handler(void)
{
	while (1);
}

// Reserved 0x34
__attribute__ ((weak)) void __Reserved_0x34_Handler(void)
{
	while (1);
}

// PendSV
__attribute__ ((weak)) void PendSV_Handler(void)
{
	while (1);
}

// SysTick
__attribute__ ((weak)) void SysTick_Handler(void)
{
	while (1);
}

// WWDG
__attribute__ ((weak)) void WWDG_IRQHandler(void)
{
	while (1);
}

// PVD_PVM
__attribute__ ((weak)) void PVD_PVM_IRQHandler(void)
{
	while (1);
}

// TAMP_STAMP
__attribute__ ((weak)) void TAMP_STAMP_IRQHandler(void)
{
	while (1);
}

// RTC_WKUP
__attribute__ ((weak)) void RTC_WKUP_IRQHandler(void)
{
	while (1);
}

// FLASH
__attribute__ ((weak)) void FLASH_IRQHandler(void)
{
	while (1);
}

// RCC
__attribute__ ((weak)) void RCC_IRQHandler(void)
{
	while (1);
}

// EXTI0
__attribute__ ((weak)) void EXTI0_IRQHandler(void)
{
	while (1);
}

// EXTI1
__attribute__ ((weak)) void EXTI1_IRQHandler(void)
{
	while (1);
}

// EXTI2
__attribute__ ((weak)) void EXTI2_IRQHandler(void)
{
	while (1);
}

// EXTI3
__attribute__ ((weak)) void EXTI3_IRQHandler(void)
{
	while (1);
}

// EXTI4
__attribute__ ((weak)) void EXTI4_IRQHandler(void)
{
	while (1);
}

// DMA1_Channel1
__attribute__ ((weak)) void DMA1_Channel1_IRQHandler(void)
{
	while (1);
}

// DMA1_Channel2
__attribute__ ((weak)) void DMA1_Channel2_IRQHandler(void)
{
	while (1);
}

// DMA1_Channel3
__attribute__ ((weak)) void DMA1_Channel3_IRQHandler(void)
{
	while (1);
}

// DMA1_Channel4
__attribute__ ((weak)) void DMA1_Channel4_IRQHandler(void)
{
	while (1);
}

// DMA1_Channel5
__attribute__ ((weak)) void DMA1_Channel5_IRQHandler(void)
{
	while (1);
}

// DMA1_Channel6
__attribute__ ((weak)) void DMA1_Channel6_IRQHandler(void)
{
	while (1);
}

// DMA1_Channel7
__attribute__ ((weak)) void DMA1_Channel7_IRQHandler(void)
{
	while (1);
}

// ADC1_2
__attribute__ ((weak)) void ADC1_2_IRQHandler(void)
{
	while (1);
}

// CAN1_TX
__attribute__ ((weak)) void CAN1_TX_IRQHandler(void)
{
	while (1);
}

// CAN1_RX0
__attribute__ ((weak)) void CAN1_RX0_IRQHandler(void)
{
	while (1);
}

// CAN1_RX1
__attribute__ ((weak)) void CAN1_RX1_IRQHandler(void)
{
	while (1);
}

// CAN1_SCE
__attribute__ ((weak)) void CAN1_SCE_IRQHandler(void)
{
	while (1);
}

// EXTI9_5
__attribute__ ((weak)) void EXTI9_5_IRQHandler(void)
{
	while (1);
}

// TIM1_BRK_TIM15
__attribute__ ((weak)) void TIM1_BRK_TIM15_IRQHandler(void)
{
	while (1);
}

// TIM1_UP_TIM16
__attribute__ ((weak)) void TIM1_UP_TIM16_IRQHandler(void)
{
	while (1);
}

// TIM1_TRG_COM_TIM17
__attribute__ ((weak)) void TIM1_TRG_COM_TIM17_IRQHandler(void)
{
	while (1);
}

// TIM1_CC
__attribute__ ((weak)) void TIM1_CC_IRQHandler(void)
{
	while (1);
}

// TIM2
__attribute__ ((weak)) void TIM2_IRQHandler(void)
{
	while (1);
}

// TIM3
__attribute__ ((weak)) void TIM3_IRQHandler(void)
{
	while (1);
}

// TIM4
__attribute__ ((weak)) void TIM4_IRQHandler(void)
{
	while (1);
}

// I2C1_EV
__attribute__ ((weak)) void I2C1_EV_IRQHandler(void)
{
	while (1);
}

// I2C1_ER
__attribute__ ((weak)) void I2C1_ER_IRQHandler(void)
{
	while (1);
}

// I2C2_EV
__attribute__ ((weak)) void I2C2_EV_IRQHandler(void)
{
	while (1);
}

// I2C2_ER
__attribute__ ((weak)) void I2C2_ER_IRQHandler(void)
{
	while (1);
}

// SPI1
__attribute__ ((weak)) void SPI1_IRQHandler(void)
{
	while (1);
}

// SPI2
__attribute__ ((weak)) void SPI2_IRQHandler(void)
{
	while (1);
}

// USART1
__attribute__ ((weak)) void USART1_IRQHandler(void)
{
	while (1);
}

// USART2
__attribute__ ((weak)) void USART2_IRQHandler(void)
{
	while (1);
}

// USART3
__attribute__ ((weak)) void USART3_IRQHandler(void)
{
	while (1);
}

// EXTI15_10
__attribute__ ((weak)) void EXTI15_10_IRQHandler(void)
{
	while (1);
}

// RTC_Alarm
__attribute__ ((weak)) void RTC_Alarm_IRQHandler(void)
{
	while (1);
}

// DFSDM1_FLT3
__attribute__ ((weak)) void DFSDM1_FLT3_IRQHandler(void)
{
	while (1);
}

// TIM8_BRK
__attribute__ ((weak)) void TIM8_BRK_IRQHandler(void)
{
	while (1);
}

// TIM8_UP
__attribute__ ((weak)) void TIM8_UP_IRQHandler(void)
{
	while (1);
}

// TIM8_TRG_COM
__attribute__ ((weak)) void TIM8_TRG_COM_IRQHandler(void)
{
	while (1);
}

// TIM8_CC
__attribute__ ((weak)) void TIM8_CC_IRQHandler(void)
{
	while (1);
}

// ADC3
__attribute__ ((weak)) void ADC3_IRQHandler(void)
{
	while (1);
}

// FMC
__attribute__ ((weak)) void FMC_IRQHandler(void)
{
	while (1);
}

// SDMMC1
__attribute__ ((weak)) void SDMMC1_IRQHandler(void)
{
	while (1);
}

// TIM5
__attribute__ ((weak)) void TIM5_IRQHandler(void)
{
	while (1);
}

// SPI3
__attribute__ ((weak)) void SPI3_IRQHandler(void)
{
	while (1);
}

// UART4
__attribute__ ((weak)) void UART4_IRQHandler(void)
{
	while (1);
}

// UART5
__attribute__ ((weak)) void UART5_IRQHandler(void)
{
	while (1);
}

// TIM6_DAC
__attribute__ ((weak)) void TIM6_DAC_IRQHandler(void)
{
	while (1);
}

// TIM7
__attribute__ ((weak)) void TIM7_IRQHandler(void)
{
	while (1);
}

// DMA2_Channel1
__attribute__ ((weak)) void DMA2_Channel1_IRQHandler(void)
{
	while (1);
}

// DMA2_Channel2
__attribute__ ((weak)) void DMA2_Channel2_IRQHandler(void)
{
	while (1);
}

// DMA2_Channel3
__attribute__ ((weak)) void DMA2_Channel3_IRQHandler(void)
{
	while (1);
}

// DMA2_Channel4
__attribute__ ((weak)) void DMA2_Channel4_IRQHandler(void)
{
	while (1);
}

// DMA2_Channel5
__attribute__ ((weak)) void DMA2_Channel5_IRQHandler(void)
{
	while (1);
}

// DFSDM1_FLT0
__attribute__ ((weak)) void DFSDM1_FLT0_IRQHandler(void)
{
	while (1);
}

// DFSDM1_FLT1
__attribute__ ((weak)) void DFSDM1_FLT1_IRQHandler(void)
{
	while (1);
}

// DFSDM1_FLT2
__attribute__ ((weak)) void DFSDM1_FLT2_IRQHandler(void)
{
	while (1);
}

// COMP
__attribute__ ((weak)) void COMP_IRQHandler(void)
{
	while (1);
}

// LPTIM1
__attribute__ ((weak)) void LPTIM1_IRQHandler(void)
{
	while (1);
}

// LPTIM2
__attribute__ ((weak)) void LPTIM2_IRQHandler(void)
{
	while (1);
}

// OTG_FS
__attribute__ ((weak)) void OTG_FS_IRQHandler(void)
{
	while (1);
}

// DMA2_Channel6
__attribute__ ((weak)) void DMA2_Channel6_IRQHandler(void)
{
	while (1);
}

// DMA2_Channel7
__attribute__ ((weak)) void DMA2_Channel7_IRQHandler(void)
{
	while (1);
}

// LPUART1
__attribute__ ((weak)) void LPUART1_IRQHandler(void)
{
	while (1);
}

// QUADSPI
__attribute__ ((weak)) void QUADSPI_IRQHandler(void)
{
	while (1);
}

// I2C3_EV
__attribute__ ((weak)) void I2C3_EV_IRQHandler(void)
{
	while (1);
}

// I2C3_ER
__attribute__ ((weak)) void I2C3_ER_IRQHandler(void)
{
	while (1);
}

// SAI1
__attribute__ ((weak)) void SAI1_IRQHandler(void)
{
	while (1);
}

// SAI2
__attribute__ ((weak)) void SAI2_IRQHandler(void)
{
	while (1);
}

// SWPMI1
__attribute__ ((weak)) void SWPMI1_IRQHandler(void)
{
	while (1);
}

// TSC
__attribute__ ((weak)) void TSC_IRQHandler(void)
{
	while (1);
}

// LCD
__attribute__ ((weak)) void LCD_IRQHandler(void)
{
	while (1);
}

// AES
__attribute__ ((weak)) void AES_IRQHandler(void)
{
	while (1);
}

// RNG
__attribute__ ((weak)) void RNG_IRQHandler(void)
{
	while (1);
}

// FPU
__attribute__ ((weak)) void FPU_IRQHandler(void)
{
	while (1);
}


/*---------------------------------------------------------------------------------------------------------------------+
| vector table
+---------------------------------------------------------------------------------------------------------------------*/

extern const char __main_stack_end;			// imported main stack end (from linker script)

void Reset_Handler(void);					// import the address of Reset_Handler()

void (* const vectors[])(void) __attribute__ ((section(".vectors"))) =
{
	(void (*)(void))&__main_stack_end,
    Reset_Handler,
    NMI_Handler,
    HardFault_Handler,
    MemManage_Handler,
    BusFault_Handler,
    UsageFault_Handler,
    __Reserved_0x1C_Handler,
    __Reserved_0x20_Handler,
    __Reserved_0x24_Handler,
    __Reserved_0x28_Handler,
    SVC_Handler,
    DebugMon_Handler,
    __Reserved_0x34_Handler,
    PendSV_Handler,
    SysTick_Handler,
    WWDG_IRQHandler,
    PVD_PVM_IRQHandler,
    TAMP_STAMP_IRQHandler,
    RTC_WKUP_IRQHandler,
    FLASH_IRQHandler,
    RCC_IRQHandler,
    EXTI0_IRQHandler,
    EXTI1_IRQHandler,
    EXTI2_IRQHandler,
    EXTI3_IRQHandler,
    EXTI4_IRQHandler,
    DMA1_Channel1_IRQHandler,
    DMA1_Channel2_IRQHandler,
    DMA1_Channel3_IRQHandler,
    DMA1_Channel4_IRQHandler,
    DMA1_Channel5_IRQHandler,
    DMA1_Channel6_IRQHandler,
    DMA1_Channel7_IRQHandler,
    ADC1_2_IRQHandler,
    CAN1_TX_IRQHandler,
    CAN1_RX0_IRQHandler,
    CAN1_RX1_IRQHandler,
    CAN1_SCE_IRQHandler,
    EXTI9_5_IRQHandler,
    TIM1_BRK_TIM15_IRQHandler,
    TIM1_UP_TIM16_IRQHandler,
    TIM1_TRG_COM_TIM17_IRQHandler,
    TIM1_CC_IRQHandler,
    TIM2_IRQHandler,
    TIM3_IRQHandler,
    TIM4_IRQHandler,
    I2C1_EV_IRQHandler,
    I2C1_ER_IRQHandler,
    I2C2_EV_IRQHandler,
    I2C2_ER_IRQHandler,
    SPI1_IRQHandler,
    SPI2_IRQHandler,
    USART1_IRQHandler,
    USART2_IRQHandler,
    USART3_IRQHandler,
    EXTI15_10_IRQHandler,
    RTC_Alarm_IRQHandler,
    DFSDM1_FLT3_IRQHandler,
    TIM8_BRK_IRQHandler,
    TIM8_UP_IRQHandler,
    TIM8_TRG_COM_IRQHandler,
    TIM8_CC_IRQHandler,
    ADC3_IRQHandler,
    FMC_IRQHandler,
    SDMMC1_IRQHandler,
    TIM5_IRQHandler,
    SPI3_IRQHandler,
    UART4_IRQHandler,
    UART5_IRQHandler,
    TIM6_DAC_IRQHandler,
    TIM7_IRQHandler,
    DMA2_Channel1_IRQHandler,
    DMA2_Channel2_IRQHandler,
    DMA2_Channel3_IRQHandler,
    DMA2_Channel4_IRQHandler,
    DMA2_Channel5_IRQHandler,
    DFSDM1_FLT0_IRQHandler,
    DFSDM1_FLT1_IRQHandler,
    DFSDM1_FLT2_IRQHandler,
    COMP_IRQHandler,
    LPTIM1_IRQHandler,
    LPTIM2_IRQHandler,
    OTG_FS_IRQHandler,
    DMA2_Channel6_IRQHandler,
    DMA2_Channel7_IRQHandler,
    LPUART1_IRQHandler,
    QUADSPI_IRQHandler,
    I2C3_EV_IRQHandler,
    I2C3_ER_IRQHandler,
    SAI1_IRQHandler,
    SAI2_IRQHandler,
    SWPMI1_IRQHandler,
    TSC_IRQHandler,
    LCD_IRQHandler,
    AES_IRQHandler,
    RNG_IRQHandler,
    FPU_IRQHandler
};