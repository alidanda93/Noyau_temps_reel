/*
 * drv_uart1.c
 *
 *  Created on: 7 nov. 2022
 *      Author: laurentf
 */

#include "drv_uart1.h"


extern SemaphoreHandle_t semaphori;

uint8_t drv_uart1_receive(char * pData, uint16_t size)
{
	HAL_UART_Receive_IT(&huart1, (uint8_t*)(pData), size);

	printf("Je vais Take semaphori\r\n");
	xSemaphoreTake(semaphori,portMAX_DELAY);

	/*
	if(xSemaphoreTake(semaphori,portMAX_DELAY)==pdTRUE)
	{
		printf("Good Take semaphori\r\n");
	}
	else
	{
		printf("Error Take semaphori\r\n");
	}

*/
	return 0;	// Life's too short for error management
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	BaseType_t higher_priority_task_woken;

	if (huart==&huart1){

		higher_priority_task_woken = pdFALSE;
		printf("Je vais Give\r\n");
		xSemaphoreGiveFromISR(semaphori,&higher_priority_task_woken);

		/*
		if(xSemaphoreGiveFromISR(semaphori,&higher_priority_task_woken)==pdTRUE)
		{
			printf("J ai Give\r\n");
		}
		else
		{
			printf("Error j ai pas Give\r\n");
		}
		*/
	}

	portYIELD_FROM_ISR(higher_priority_task_woken);

}

/*
void USART1_IRQHandler(char * pData, uint16_t size)
{
	BaseType_t higher_priority_task_woken = pdFALSE;
	xSemaphoreGiveFromISR(semaphori, &higher_priority_task_woken);
	HAL_UART_Receive_IT(&huart1, (uint8_t*)(pData), size);
	HAL_UART_IRQHandler(&huart1);
	portYIELD_FROM_ISR( &higher_priority_task_woken );
}
*/


uint8_t drv_uart1_transmit(const char * pData, uint16_t size)
{
	HAL_UART_Transmit(&huart1, (uint8_t*)pData, size, HAL_MAX_DELAY);

	return 0;	// Srsly, don't do that kids
}

