/*
 * uart_utilities.h
 *
 *  Created on: Mar 31, 2025
 *      Author: Ivan
 */

#ifndef INC_UART_UTILITIES_H_
#define INC_UART_UTILITIES_H_
#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>

typedef struct dma_struct_t
{
    uint16_t size;
    size_t head, tail;
    uint8_t* buffer;
} dma_struct_t;

typedef struct message_array_struct_t
{
    uint8_t *list;
    size_t msg_count, msg_size; // rows, columns
    size_t msg_current, msg_current_size;
} message_array_struct_t;

typedef struct uart_rx_struct_t
{
    dma_struct_t buf;
    message_array_struct_t msgs;
    uint8_t payload_found;
} uart_rx_struct_t;

uint8_t uartRxCallback(uart_rx_struct_t *urx);

#ifdef __cplusplus
}
#endif

#endif /* INC_UART_UTILITIES_H_ */
