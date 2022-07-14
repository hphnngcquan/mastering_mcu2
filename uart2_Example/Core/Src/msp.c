/*
 * msp.c
 *
 *  Created on: Jul 14, 2022
 *      Author: NONAMENEEDED
 */
#include "stm32f4xx_hal.h"

/**
  * @brief  Initialize the MSP.
  * @retval None
  */
void HAL_MspInit(void)
{
	//Here will do low level processor specific inits
		//1. Set up the priority grouping of the arm cortex mx processor
		HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

		//2. Enable the required system exceptions of the arm cortex mx processor
		SCB->SHCSR |= 0x7 << 16; // usg fault, memory fault and bus fault system exception


		//3. Configure the priority for the system exceptions
		HAL_NVIC_SetPriority(MemoryManagement_IRQn, 0, 0);
		HAL_NVIC_SetPriority(BusFault_IRQn, 0, 0);
		HAL_NVIC_SetPriority(UsageFault_IRQn, 0, 0);
}
