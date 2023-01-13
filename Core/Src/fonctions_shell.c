#include "fonctions_shell.h"

extern int LED_DELAY;
extern TaskHandle_t xHandleLED;

int fonction(h_shell_t * h_shell, int argc, char ** argv)
{
	int size = snprintf (h_shell->print_buffer, BUFFER_SIZE, "Je suis une fonction bidon\r\n");
	h_shell->drv.transmit(h_shell->print_buffer, size);

	return 0;
}


int addition(h_shell_t * h_shell, int argc, char ** argv)
{
	if(argc !=3)
	{
		int size = snprintf (h_shell->print_buffer, BUFFER_SIZE, "Error y a pas le bon nombre d'argument\r\n");
		h_shell->drv.transmit(h_shell->print_buffer, size);
		return -1;
	}
	else
	{
		int a = atoi(argv[1]);
		int b = atoi(argv[2]);
		int size = snprintf (h_shell->print_buffer, BUFFER_SIZE, "%d + %d = %d\r\n\r\n", a, b, a+b);
		h_shell->drv.transmit(h_shell->print_buffer, size);

	}
	return 0;
}

int led(h_shell_t * h_shell, int argc, char ** argv)
{
	if(argc != 2)
		{
			int size = snprintf (h_shell->print_buffer, BUFFER_SIZE, "Error y a pas le bon nombre d'argument\r\n");
			h_shell->drv.transmit(h_shell->print_buffer, size);
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

