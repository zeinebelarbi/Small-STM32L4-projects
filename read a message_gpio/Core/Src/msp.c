/*
 * msp.c
 *
 *  Created on: Dec 4, 2022
 *      Author: LENOVO
 */
#include "stm32l4xx_hal.h"



void HAL_MspInit(void)
{
	//1-Set the priority grouping of arm CORTEX processor
	HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);
    //2-Enable the required system exceptions of the arm CORTEX processor
	SCB->SHCSR |=(7<<16) ;
	//3-configure the priority for the system exceptions
	HAL_NVIC_SetPriority( MemoryManagement_IRQn, 0 , 0);
	HAL_NVIC_SetPriority( BusFault_IRQn , 0 , 0);
	HAL_NVIC_SetPriority( UsageFault_IRQn , 0 , 0);
}
 void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
	 //1- Enable the clock for the UART2 peripherics
	 __HAL_RCC_USART1_CLK_ENABLE();
	 __HAL_RCC_GPIOB_CLK_ENABLE();
	 //2-do the pin muxing configurations
	 GPIO_InitTypeDef gpio_uart;
	 gpio_uart.Alternate=GPIO_AF7_USART1;
	 gpio_uart.Mode=GPIO_MODE_AF_PP ;
	 gpio_uart.Pin=GPIO_PIN_6  | GPIO_PIN_7 ;
	 gpio_uart.Pull=GPIO_PULLUP;
	 gpio_uart.Speed=GPIO_SPEED_FREQ_MEDIUM;
     HAL_GPIO_Init(GPIOB, &gpio_uart);
}

