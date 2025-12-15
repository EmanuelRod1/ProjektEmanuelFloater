/*
 * touchscreen_task.cpp
 *
 *  Created on: Apr 11, 2024
 *      Author: loncar
 */
#include <touchscreen_task.h>
#include <version.h>
#include <stdio.h>
#include <cmsis_os2.h>
#include <debug_handler.h>
#include <../../External/ili9341/testimg.h>

/* LCD SCREEN CODE BEGIN Includes */
#include <string.h>
#include <stdarg.h>
#ifdef __cplusplus
extern "C" {
#endif
#include <ili9341.h>
#include <ili9341_touch.h>
#ifdef __cplusplus
}
#endif
#include <fonts.h>
#include <testimg.h>
#include "main.h"
#include <FreeRTOS.h>
#include <queue.h>
#include "semphr.h"
#include <time.h>
/* LCD SCREEN CODE END Includes */

void touchscreen_on() {
    //HAL_GPIO_WritePin(Power_Shield_5V_EN_GPIO_Port, Power_Shield_5V_EN_Pin, GPIO_PIN_SET);
    //HAL_GPIO_WritePin(Power_Shield_3V3_nEN_GPIO_Port, Power_Shield_3V3_nEN_Pin, GPIO_PIN_RESET);
}

void touchscreen_off() {
    //HAL_GPIO_WritePin(Power_Shield_5V_EN_GPIO_Port, Power_Shield_5V_EN_Pin, GPIO_PIN_RESET);
    //HAL_GPIO_WritePin(Power_Shield_3V3_nEN_GPIO_Port, Power_Shield_3V3_nEN_Pin, GPIO_PIN_SET);
}

void touchscreen_init() {
    touchscreen_on();
    ILI9341_Unselect();
    ILI9341_TouchUnselect();
    osDelay(10);
    ILI9341_Init();
}

void touchscreen_deinit() {
    ILI9341_Unselect();
    ILI9341_TouchUnselect();
    touchscreen_off();
}


//static SemaphoreHandle_t mutex = xSemaphoreCreateMutex();

//static SemaphoreHandle_t touchMutex = xSemaphoreCreateBinary();




osMessageQueueId_t displayQueueHandle;
const osMessageQueueAttr_t displayQueue_attributes = {
  .name = "displayQueue"
};

void setupTouchscreenObjects()
{
    displayQueueHandle = osMessageQueueNew (1, sizeof(display_data_t), &displayQueue_attributes);
}

void touchscreen_fill();

#define TEXT_SPACING 5
#define LINE_SIZE 1
#define SCREEN_TIMEOUT 10

void touchscreen_draw_overlay(uint8_t font_height, uint8_t rows, uint8_t* display_buffer, uint16_t display_buffer_size)
{
    uint16_t box_height = TEXT_SPACING*3 + font_height*2 + LINE_SIZE*2;
    ILI9341_FillScreen(ILI9341_BLACK, display_buffer, display_buffer_size);
    // make grid
    ILI9341_FillRectangle(ILI9341_WIDTH / 2, box_height, LINE_SIZE, ILI9341_HEIGHT - box_height, ILI9341_WHITE, display_buffer, display_buffer_size);

    for (int i=1; i < rows; i++)
    {
        ILI9341_FillRectangle(0, box_height*i, ILI9341_WIDTH, LINE_SIZE, ILI9341_WHITE, display_buffer, display_buffer_size);
    }
}

void display_write_box(uint16_t i, uint16_t j, uint16_t row, const char* str, FontDef font, uint16_t color, uint16_t bgcolor, uint8_t* display_buffer, uint16_t display_buffer_size)
{
    uint16_t box_height = TEXT_SPACING*3 + font.height*2 + LINE_SIZE*2;
    ILI9341_WriteString((ILI9341_WIDTH/2 + 2)*j, box_height*i + TEXT_SPACING + row*(font.height + TEXT_SPACING), str, font, color, bgcolor, display_buffer, display_buffer_size);
}

void displayHandler(void *argument)
{
    display_data_t data;
    Debug debug;

    debug.printf("Some other test!\r\n");

    char buffer[DISPLAY_MESSAGE_SIZE];
    FontDef font = Font_11x18;
    uint8_t character_display_buffer[Font_11x18.height*Font_11x18.width*2];
    uint16_t color_body = ILI9341_RED;
    uint16_t color_title = ILI9341_GREEN;
    uint8_t screen_on = RESET;

    touchscreen_deinit();

    int x = 0;


    for(;;)
    {

    	debug.printf("!!Touch touch touch! \r\n");

        // receive payload
        if (osMessageQueueGet(displayQueueHandle, (void *)&data, NULL, SCREEN_TIMEOUT*1000 ) != osOK)
        {
            // when screen on, turn off
            if (screen_on)
            {
                // turn off screen
                touchscreen_deinit();
                screen_on = RESET;
            }
            continue;
        }


        // turn on screen after getting a message
        if (!screen_on)
        {
            // initialize screen
            touchscreen_init();
            //touchscreen_draw_overlay(font.height, 6, character_display_buffer, sizeof(character_display_buffer));
            screen_on = SET;
        }




        /*if (xSemaphoreTake(mutex, 0) == pdTRUE) {

        	//time_t seconds;

        	//time(&seconds);
		*/
        	//display_write_box(0,0,0, (char*)data.message, font, color_title, ILI9341_BLACK, character_display_buffer, sizeof(character_display_buffer));
        	//sprintf(buffer, "%s", "Hello");
        	//display_write_box(0,0,1, buffer, font, color_title, ILI9341_BLACK, character_display_buffer, sizeof(character_display_buffer));
/*


        	xSemaphoreGive(mutex);
        }*/


        /*
         * Commented to test image drawing.
         * */

		// display message

        /*display_write_box(0,0,0, (char*)data.message, font, color_title, ILI9341_BLACK, character_display_buffer, sizeof(character_display_buffer));
        sprintf(buffer, "Fw: %s Id: %d", FW_VERSION, data.modem_id);
        display_write_box(0,0,1, buffer, font, color_title, ILI9341_BLACK, character_display_buffer, sizeof(character_display_buffer));

		// display voltage
		display_write_box(1,0,0, "Voltage", font, color_title, ILI9341_BLACK, character_display_buffer, sizeof(character_display_buffer));
		sprintf(buffer, "%*.2fV", 6, data.batteryVoltage/1000.0);
		display_write_box(1,0,1, buffer, font, color_body, ILI9341_BLACK, character_display_buffer, sizeof(character_display_buffer));

		// display switch top
		switch(data.detection_state)
		{
		case 0:
			sprintf(buffer, "%-*s", 9, "Idle");
			break;

		case 1:
			sprintf(buffer, "%-*s", 9, "Listening");
			break;

		case 2:
			sprintf(buffer, "%-*s", 9, "Satellite");
			break;

		case 3:
			sprintf(buffer, "%-*s", 9, "Surfacing");
			break;

		case 4:
			sprintf(buffer, "%-*s", 9, "Sinking");
			break;

		}
		display_write_box(1,1,0, "Detection", font, color_title, ILI9341_BLACK, character_display_buffer, sizeof(character_display_buffer));
		display_write_box(1,1,1, buffer, font, color_body, ILI9341_BLACK, character_display_buffer, sizeof(character_display_buffer));

		// display depth keeping configuration
		display_write_box(2,0,0, "Temp", font, color_title, ILI9341_BLACK, character_display_buffer, sizeof(character_display_buffer));
		sprintf(buffer, "%*.2fC", 6, data.temperature/100.0);
		display_write_box(2,0,1, buffer, font, color_body, ILI9341_BLACK, character_display_buffer, sizeof(character_display_buffer));
		// display pressure
		display_write_box(2,1,0, "Depth", font, color_title, ILI9341_BLACK, character_display_buffer, sizeof(character_display_buffer));
		sprintf(buffer, "%*.2fm", 6, data.depth/100.0);
		display_write_box(2,1,1, buffer, font, color_body, ILI9341_BLACK, character_display_buffer, sizeof(character_display_buffer));

		// display piston volume
		display_write_box(3,0,0, "Vp", font, color_title, ILI9341_BLACK, character_display_buffer, sizeof(character_display_buffer));
		sprintf(buffer, "%*.2fcc", 7, data.floaterVolume/100.0);
		display_write_box(3,0,1, buffer, font, color_body, ILI9341_BLACK, character_display_buffer, sizeof(character_display_buffer));
		// display motor current b
		display_write_box(3,1,0, "dVp", font, color_title, ILI9341_BLACK, character_display_buffer, sizeof(character_display_buffer));
		sprintf(buffer, "%*.2fcc/s", 6, data.floaterVolumeSpeed/100.0);
		display_write_box(3,1,1, buffer, font, color_body, ILI9341_BLACK, character_display_buffer, sizeof(character_display_buffer));

		// display motor current a
		display_write_box(4,0,0, "Mot I(A)", font, color_title, ILI9341_BLACK, character_display_buffer, sizeof(character_display_buffer));
		sprintf(buffer, "%*.2fA", 6, data.motor_current/1000.0);
		display_write_box(4,0,1, buffer, font, color_body, ILI9341_BLACK, character_display_buffer, sizeof(character_display_buffer));
		// display switch bottom
		display_write_box(4,1,0, "Sw bot", font, color_title, ILI9341_BLACK, character_display_buffer, sizeof(character_display_buffer));
		sprintf(buffer, "%-*s", 3, data.switch_bottom ? "ON" : "OFF");
		display_write_box(4,1,1, buffer, font, color_body, ILI9341_BLACK, character_display_buffer, sizeof(character_display_buffer));

		// display motor running configuration
		display_write_box(5,0,0, "Mot run", font, color_title, ILI9341_BLACK, character_display_buffer, sizeof(character_display_buffer));
		sprintf(buffer, "%-*s", 3, data.motor_running ? "ON" : "OFF");
		display_write_box(5,0,1, buffer, font, color_body, ILI9341_BLACK, character_display_buffer, sizeof(character_display_buffer));
		// display pressure
		display_write_box(5,1,0, "Mot fault", font, color_title, ILI9341_BLACK, character_display_buffer, sizeof(character_display_buffer));
		sprintf(buffer, "%-*s", 5, data.motor_fault ? "FAULT" : "OK");
		display_write_box(5,1,1, buffer, font, color_body, ILI9341_BLACK, character_display_buffer, sizeof(character_display_buffer));

		*/
		//ILI9341_DrawImage(0, 0, 240, 240, &test_img_240x240[0][0]);
        ILI9341_FillRectangle(x, 0, 100, 100, ILI9341_GREEN, character_display_buffer, sizeof(character_display_buffer));
        x += 4;
        if (x > 130) x = 130;

        //xQueueReceive(xQueue, &dx, portMAX_DELAY);




    }
}








void touchHandler(void *argument)
{

	Debug debug;
	int x = 0;
	//uint8_t character_display_buffer[Font_11x18.height*Font_11x18.width*2];
    for (;;)
    {

    	debug.printf("tttt test!\r\n");

    	x += 5;

    	debug.printf("x is : %d\r\n", x);
        // čeka dok ISR ne postavi semaphore
        /*if(xSemaphoreTake(touchMutex, portMAX_DELAY) == pdTRUE)
        {
            uint16_t x, y;

            // uzmi SPI mutex prije čitanja
            xSemaphoreTake(mutex, portMAX_DELAY);

            ILI9341_FillRectangle(0, 100, 100, 100, ILI9341_GREEN, character_display_buffer, sizeof(character_display_buffer));

            /*if(ILI9341_TouchGetCoordinates(&x, &y))
            {
                // pošalji koordinate na UI queue

            }

            ILI9341_TouchUnselect();*/
            //xSemaphoreGive(mutex);
        //
    	osDelay(1000);
    }
}





void EXTIx_IRQHandler(void)
{
    /*BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    HAL_GPIO_EXTI_IRQHandler(Touch_IRQ_Pin);

    // postavi semaphore
    xSemaphoreGiveFromISR(touchMutex, &xHigherPriorityTaskWoken);

    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);*/
}

