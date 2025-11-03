/*
 * debug_handler.h
 *
 *  Created on: Apr 12, 2024
 *      Author: loncar
 */

#ifndef SRC_DEBUG_HANDLER_H_
#define SRC_DEBUG_HANDLER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define DEBUG_TX_BUFFER_SIZE 256
typedef struct debug_payload_t
{
	uint8_t data[DEBUG_TX_BUFFER_SIZE];
	uint8_t size;
} debug_payload_t;

void registerDebugCallbacks();
void setupDebugRtosObjects();

void debugRxHandler(void *argument);
void debugTxHandler(void *argument);

#ifdef __cplusplus
class Debug
{
	debug_payload_t payload;
public:
	void printf(const char *fmt, ...);

	void printf_direct(const char *fmt, ...);

};
#endif

#ifdef __cplusplus
}
#endif

#endif /* SRC_DEBUG_HANDLER_H_ */
