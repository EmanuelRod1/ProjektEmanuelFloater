/*
 * uart_utilities.c
 *
 *  Created on: Mar 31, 2025
 *      Author: Ivan
 */
#include <uart_utilities.h>
#include <string.h>

uint8_t uartRxCallback(uart_rx_struct_t *urx)
{

  size_t count = urx->msgs.msg_count;
  size_t size = urx->msgs.msg_size;
  size_t curr = urx->msgs.msg_current;
  size_t curr_size = urx->msgs.msg_current_size;

  /* Check if number of received data in reception buffer has changed */
  if (urx->buf.head != urx->buf.tail)
  {
    /* Check if position of index in reception buffer has simply be increased
       of if end of buffer has been reached */
    if (urx->buf.head < urx->buf.tail)
    {
        for(register size_t i=urx->buf.head; i<urx->buf.tail; i++)
        {
            urx->msgs.list[curr*size + curr_size++]= urx->buf.buffer[i];
            urx->payload_found = (urx->payload_found == 0 && urx->msgs.list[curr*size + curr_size-1] == '\r') ? 1
              : (urx->payload_found == 1 && urx->msgs.list[curr*size + curr_size-1] == '\n') ? 2
              : 0;

            if(urx->payload_found==2)
            {
                urx->msgs.list[curr*size + curr_size-2] = 0;
                urx->msgs.list[curr*size + curr_size-1] = 0;
                curr = curr == count-1 ? 0 : curr + 1;
                memset(&urx->msgs.list[curr*size],0, size);
                curr_size=0;
            }
        }
    }
    else
    {
        for(register size_t i=urx->buf.head; i<urx->buf.size; i++)
        {
            urx->msgs.list[curr*size + curr_size++]= urx->buf.buffer[i];
            urx->payload_found = (urx->payload_found == 0 && urx->msgs.list[curr*size + curr_size-1] == '\r') ? 1
              : (urx->payload_found == 1 && urx->msgs.list[curr*size + curr_size-1] == '\n') ? 2
              : 0;

            if(urx->payload_found==2)
            {
                urx->msgs.list[curr*size + curr_size-2] = 0;
                urx->msgs.list[curr*size + curr_size-1] = 0;
                curr = curr == count-1 ? 0 : curr + 1;
                memset(&urx->msgs.list[curr*size], 0, size);
                curr_size=0;
            }
        }
        for(register size_t i=0; i<urx->buf.tail; i++)
        {
            urx->msgs.list[curr*size + curr_size++]= urx->buf.buffer[i];
            urx->payload_found = (urx->payload_found == 0 && urx->msgs.list[curr*size + curr_size-1] == '\r') ? 1
              : (urx->payload_found == 1 && urx->msgs.list[curr*size + curr_size-1] == '\n') ? 2
              : 0;

            if(urx->payload_found==2)
            {
                urx->msgs.list[curr*size + curr_size-2] = 0;
                urx->msgs.list[curr*size + curr_size-1] = 0;

                curr = curr == count-1 ? 0 : curr + 1;
                memset(&urx->msgs.list[curr*size],0,size);
                curr_size=0;
            }
        }
    }
    urx->buf.head = urx->buf.tail;

    urx->msgs.msg_count = count;
    urx->msgs.msg_size = size;
    urx->msgs.msg_current = curr;
    urx->msgs.msg_current_size = curr_size;

    return 1;
  }
  return 0;
}
