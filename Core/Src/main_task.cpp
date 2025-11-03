/*
 * task_creation.cpp
 *
 *  Created on: Apr 11, 2024
 *      Author: loncar
 */
#include <cmsis_os2.h>
#include <stdlib.h>
#include <stdio.h>

#include <main_task.h>
#include <debug_handler.h>
#include <touchscreen_task.h>

#include <string.h>
#include <math.h>
#include <main.h>

extern osMessageQueueId_t displayQueueHandle;

int touchscreenUpdatePrescaler = 2;


void mainHandler(void *argument)
{
	Debug debug;

	uint32_t start_tick;

    display_data_t display_data;

	uint32_t loop_sequence = 0;

	start_tick = osKernelGetTickCount();
	for(;;)
	{
		osDelayUntil(start_tick + 500);
		start_tick = osKernelGetTickCount();

		display_data.detection_state = 2;
		display_data.switch_bottom = 1;
		display_data.motor_current = 3;
		display_data.floaterVolumeSpeed = 4;
		display_data.motor_running = 1;
		display_data.motor_fault = 1;
		display_data.depth = 1234;
		display_data.temperature = 2856;
		display_data.batteryVoltage = 27654;
		display_data.floaterVolume= 12345; // originally /100
		sprintf((char*)display_data.message, "%02d/%02d/%02d %02d:%02d:%02d.%02d", 25, 11, 4, 5, 6, 7, 20);
		display_data.modem_id = 056;

		if (osMessageQueueGetCount(displayQueueHandle)) osMessageQueueReset(displayQueueHandle);
		osMessageQueuePut(displayQueueHandle, &display_data, 0, 10);

		debug.printf("Test!\r\n");
	}
}
