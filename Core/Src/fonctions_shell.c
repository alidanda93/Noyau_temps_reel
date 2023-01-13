#include "fonctions_shell.h"
#include "basic_shell.h"

extern TaskHandle_t xHandleLED;
extern char print_buffer[BUFFER_SIZE];
extern int LED_DELAY;


int fonction(int argc, char ** argv)
{
	int size = snprintf (print_buffer, BUFFER_SIZE, "Je suis une fonction bidon\r\n");
	uart_write(print_buffer, size);

	return 0;
}


int addition( int argc, char ** argv)
{
	if(argc !=3)
	{
		int size = snprintf (print_buffer, BUFFER_SIZE, "Error y a pas le bon nombre d'argument pour une somme de deux\r\n");
		uart_write(print_buffer, size);
		return -1;
	}
	else
	{
		int a = atoi(argv[1]);
		int b = atoi(argv[2]);
		int size = snprintf (print_buffer, BUFFER_SIZE, "%d + %d = %d\r\n\r\n", a, b, a+b);
		uart_write(print_buffer, size);

	}
	return 0;
}

/*
int led( int argc, char ** argv, void * pvParameters)
{
	int LED_Delay_local_var = (int) pvParameters;
	while(1){
		xSemaphoreTake(semaphore_led,HAL_MAX_DELAY);
		if(argc != 2)
			{
				int size = snprintf (print_buffer, BUFFER_SIZE, "Error y a pas le bon nombre d'argument de la LED\r\n");
				uart_write(print_buffer, size);
				vTaskDelay(LED_Delay_local_var);
			}
		else
			{
			LED_Delay_local_var = atoi(argv[1]);
				switch(LED_Delay_local_var)
				{
					case 0 :

						vTaskSuspend(xHandleLED);


					default :

						HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
						vTaskDelay(LED_Delay_local_var);

				}
			}
		xSemaphoreGive(semaphore_led);
	}

	return 0;
}
*/

int setLedRate( int argc, char ** argv)
{
	if(argc!=2)
	{
		int size = snprintf (print_buffer, BUFFER_SIZE, "Error y a pas le bon nombre d'arguments pour la fonction setLedRate\r\n");
		uart_write(print_buffer, size);
	}
	else
	{
		LED_DELAY = atoi(argv[1]);
	}
	printf("%d\n\r", LED_DELAY);
	return 0;
}


int led()
{
	int LED_Delay_local_var;

	while(1)
	{
		LED_Delay_local_var = LED_DELAY;
		//printf("%d\n\r", LED_Delay_local_var);
		switch(LED_Delay_local_var)
				{
					case 0 :
						HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin,RESET);
						vTaskSuspend(xHandleLED);
						break;


					default :
						vTaskResume(xHandleLED);
						HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
						vTaskDelay(LED_Delay_local_var);
						break;

				}
		vTaskDelay(LED_Delay_local_var);
	}

	return 0;
}
