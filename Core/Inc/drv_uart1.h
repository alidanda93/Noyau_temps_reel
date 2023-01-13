/*
 * drv_uart1.h
 *
 *  Created on: 7 nov. 2022
 *      Author: laurentf
 */

#ifndef DRV_UART1_H_
#define DRV_UART1_H_

#include <stdint.h>
#include "usart.h"
#include "gpio.h"
#include "main.h"
#include "cmsis_os.h"
#include "stdlib.h"

uint8_t drv_uart1_receive(char * pData, uint16_t size);
uint8_t drv_uart1_transmit(const char * pData, uint16_t size);
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);

#endif /* DRV_UART1_H_ */
