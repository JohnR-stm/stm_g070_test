/**
 * Copyright (c) 2026 IvanRomanov
 * Licensed under the MIT License. See LICENSE file in the project root.
 */

#include "stm32g0xx_ll_rcc.h"
//#include "stm32g0xx_ll_system.h" // FLASH
#include "stm32g0xx_ll_utils.h" 
#include "stm32g0xx_ll_bus.h"

//#include "stm32g0xx_ll_cortex.h"
//#include "stm32g0xx_ll_pwr.h"
//#include "stm32g0xx_ll_gpio.h"
//#include "stm32g070xx.h"

#include "system_init.h"


//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------

void system_clock_config(void)
{
  /*
  LL_FLASH_SetLatency(LL_FLASH_LATENCY_2);
  while(LL_FLASH_GetLatency() != LL_FLASH_LATENCY_2)
  {
  }  */
  
  // HSI configuration and activation 
  LL_RCC_HSI_Enable();
  while(LL_RCC_HSI_IsReady() != 1)
  {
  }
  
  LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SYSCFG);
  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_PWR);

  // Set AHB prescaler
  LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);

  // Sysclk activation on the HSI 
  LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_HSI);
  while(LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_HSI)
  {
  }

  // Set APB1 prescaler
  LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_1);
  LL_Init1msTick(16000000);  // stm32g0xx_ll_utils.h
  // Update CMSIS variable (which can be updated also through SystemCoreClockUpdate function) */
  LL_SetSystemCoreClock(16000000);  // stm32g0xx_ll_utils.h
}

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------

void nvic_priority_config(void)
{
  NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);
  NVIC_SetPriority(PendSV_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),PEND_SV_PRIORITY, 0));
  NVIC_SetPriority(SysTick_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),SYS_TICK_PRIORITY, 0));
}

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------

void system_delay(uint32_t delay)
{
  LL_mDelay(delay);
}

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


//-----------------------------------------------------------------------------
// PLL ENABLE
//-----------------------------------------------------------------------------


/*
void SystemClock_Config(void)
{
  

  /// HSI configuration and activation 
  LL_RCC_HSI_Enable();
  while(LL_RCC_HSI_IsReady() != 1)
  {
  }

  /// Main PLL configuration and activation 
  LL_RCC_PLL_ConfigDomain_SYS(LL_RCC_PLLSOURCE_HSI, LL_RCC_PLLM_DIV_1, 8, LL_RCC_PLLR_DIV_2);
  LL_RCC_PLL_Enable();
  LL_RCC_PLL_EnableDomain_SYS();
  while(LL_RCC_PLL_IsReady() != 1)
  {
  }

  /// Set AHB prescaler
  LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);

  /// Sysclk activation on the main PLL 
  LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_PLL);
  while(LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_PLL)
  {
  }

  /// Set APB1 prescaler
  LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_1);
  LL_Init1msTick(64000000);
  /// Update CMSIS variable (which can be updated also through SystemCoreClockUpdate function) 
  LL_SetSystemCoreClock(64000000);
}
*/

