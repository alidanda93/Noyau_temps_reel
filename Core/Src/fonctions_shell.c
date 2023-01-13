#include "fonctions_shell.h"
#include "basic_shell.h"

extern int LED_DELAY;
extern TaskHandle_t xHandleLED;
extern char print_buffer[BUFFER_SIZE];


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

int led( int argc, char ** argv)
{
	int state=0;
	if(argc != 2)
		{
			int size = snprintf (print_buffer, BUFFER_SIZE, "Error y a pas le bon nombre d'argument pour la LED\r\n");
			uart_write(print_buffer, size);
			return -1;
		}
	else
		{
			LED_DELAY = atoi(argv[1]);
			switch(LED_DELAY)
			{
				case 0 :

					vTaskSuspend(xHandleLED);


				default :

					HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
					vTaskDelay(LED_DELAY);

			}
		}

	return 0;
}

