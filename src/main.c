#include <stdio.h>
#include <stdlib.h>

/* FreeRTOS kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
void vAssertCalled( unsigned long ulLine, const char * const pcFileName );

void task1(void* parameters);
void task2(void* parameters);

void __attribute__((__no_instrument_function__))  
__cyg_profile_func_enter(void *this_func, void *call_site)  
{  
	(void)call_site;
	
	//fprintf(fp, "E%p\n", this_func);
	printf("E%p\n", this_func);
}

void __attribute__((__no_instrument_function__))  
__cyg_profile_func_exit(void *this_func, void *call_site)  
{  
	(void)call_site;

	//fprintf(fp, "X%p\n", this_func);
	printf("X%p\n", this_func);
}

int main( void )
{
	xTaskCreate( task1, "Task1", 200, NULL, 1, NULL);

	/*task2Number = 2;
	xTaskCreate( task2, "Task2", 200, &task2Number, 1, NULL);*/

	vTaskStartScheduler();	

	return 0;
}

void task1(void* parameters)
{

	while(1)
	{
		vTaskEndScheduler();
		break;

	}
}

void task2(void* parameters)
{
	const TickType_t delay = 500;

	while(1)
	{
		vTaskDelay(delay);
	}
}

void vApplicationMallocFailedHook(void)
{
	printf("ERROR: Application Malloc Failed");
}


void vAssertCalled( unsigned long ulLine, const char * const pcFileName )
{
	/* Parameters are not used. */

 	taskENTER_CRITICAL();
	{
		printf("ERROR: vAssertCalled Line:%ld File:%s", ulLine, pcFileName);		
	}

	taskEXIT_CRITICAL();
}

/*-----------------------------------------------------------*/

