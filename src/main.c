#include <stdio.h>
#include <stdlib.h>

/* FreeRTOS kernel includes. */
#include "FreeRTOS.h"
#include "task.h"

void vAssertCalled( unsigned long ulLine, const char * const pcFileName );
void task1(void* parameters);

int main( void )
{
	xTaskCreate( task1, "Task1", 200, NULL, 1, NULL);
	vTaskStartScheduler();	

	return 0;
}

void task1(void* parameters)
{
	while(1)
	{
		printf("task1 running\n");
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

