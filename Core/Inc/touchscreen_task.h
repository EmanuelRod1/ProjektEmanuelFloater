/*
 * touchscreen_task.h
 *
 *  Created on: Apr 11, 2024
 *      Author: loncar
 */

#ifndef INC_TOUCHSCREEN_TASK_H_
#define INC_TOUCHSCREEN_TASK_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#define DISPLAY_MESSAGE_SIZE 64
typedef struct display_data_t
{
  uint16_t temperature;
  uint16_t batteryVoltage;
  uint16_t depth; // depth in cm
  int16_t floaterVolume; // volume [cm^3] * 100
  int16_t floaterVolumeSpeed;
  int16_t motor_current;
  uint8_t detection_state;
  uint8_t switch_bottom;
  uint8_t motor_running;
  uint8_t motor_fault;
  uint8_t modem_id;
  uint8_t message[DISPLAY_MESSAGE_SIZE];

} display_data_t;

void setupTouchscreenObjects();
void displayHandler(void *argument);

#ifdef __cplusplus
}
#endif
#endif /* INC_TOUCHSCREEN_TASK_H_ */
