/*
 * debug_handler.cpp
 *
 *  Created on: Apr 12, 2024
 *      Author: loncar
 */
#include <debug_handler.h>

#include <main.h>
#include <cmsis_os2.h>
#include <stm32l0xx_hal.h>
#include <stdio.h>
#include <stdarg.h> //for va_list var arg functions
#include <cstring>
#include <uart_utilities.h>

extern UART_HandleTypeDef DEBUG_UART;

#define DEBUG_MESSAGE_LIST_SIZE 2
#define DEBUG_MESSAGE_SIZE 64
#define DEBUG_DMA_SIZE DEBUG_MESSAGE_SIZE*2

uint8_t debug_buffer[DEBUG_DMA_SIZE];

static uint8_t debug_list[DEBUG_MESSAGE_LIST_SIZE*DEBUG_MESSAGE_SIZE];

//volatile size_t debug_cur_msg = 0;

dma_struct_t debug_rx_dma = {
        .size = DEBUG_DMA_SIZE,
        .head = 0,
        .tail = 0,
        .buffer = debug_buffer};
message_array_struct_t debug_msg_arr = {
        .list = debug_list,
        .msg_count = DEBUG_MESSAGE_LIST_SIZE,
        .msg_size = DEBUG_MESSAGE_SIZE,
        .msg_current = 0,
        .msg_current_size = 0
};
uart_rx_struct_t debug_urx = {
        .buf = debug_rx_dma,
        .msgs = debug_msg_arr,
        .payload_found = 0
};

extern osMessageQueueId_t modemRxQueueHandle;

osMessageQueueId_t debugTxQueueHandle;
const osMessageQueueAttr_t debugTxQueue_attributes = {
  .name = "debugTxQueue"
};

/* Definitions for debugTxSemaphore */
osSemaphoreId_t debugTxSemaphoreHandle;
const osSemaphoreAttr_t debugTxSemaphore_attributes = {
  .name = "debugTxSemaphore"
};

/* Definitions for debugRxSemaphore */
osSemaphoreId_t debugRxSemaphoreHandle;
const osSemaphoreAttr_t debugRxSemaphore_attributes = {
  .name = "debugRxSemaphore"
};

void debugRxCallback(UART_HandleTypeDef *huart, uint16_t dma_tail);
void debugTxDone(UART_HandleTypeDef *huart);

void registerDebugCallbacks()
{
    HAL_UART_RegisterRxEventCallback(&DEBUG_UART, debugRxCallback);
    HAL_UART_RegisterCallback(&DEBUG_UART, HAL_UART_TX_COMPLETE_CB_ID, debugTxDone);
}

void setupDebugRtosObjects()
{
	//https://stackoverflow.com/questions/67346516/using-queue-of-string-in-freertos
	debugTxQueueHandle = osMessageQueueNew (15, sizeof(debug_payload_t), &debugTxQueue_attributes);

	debugTxSemaphoreHandle = osSemaphoreNew(1, 1, &debugTxSemaphore_attributes);
	debugRxSemaphoreHandle = osSemaphoreNew(1, 0, &debugRxSemaphore_attributes);
}

void JumpToBootloader(void)
{
	HAL_NVIC_SystemReset();

//	HAL_SuspendTick();
//
//	/* Clear Interrupt Enable Register & Interrupt Pending Register */
//	for (int i=0;i<5;i++)
//	{
//	 NVIC->ICER[i]=0xFFFFFFFF;
//	 NVIC->ICPR[i]=0xFFFFFFFF;
//	}
//
//	HAL_FLASH_Unlock();
//
//	HAL_FLASH_OB_Unlock();
//
//	// RM0351 Rev 7 Page 93/1903
//	// AN2606 Rev 44 Page 23/372
//	CLEAR_BIT(FLASH->OPTR, FLASH_OPTR_nBOOT0);
//	SET_BIT(FLASH->OPTR, FLASH_OPTR_nBOOT1);
//	CLEAR_BIT(FLASH->OPTR, FLASH_OPTR_nSWBOOT0);
//
//	SET_BIT(FLASH->CR, FLASH_CR_OPTSTRT);
//
//	while(READ_BIT(FLASH->SR, FLASH_SR_BSY));
//
//	HAL_FLASH_OB_Launch();

//	typedef void (*pFunction)(void);
//	pFunction JumpToApplication;
//	uint32_t JumpAddress;
//	HAL_RCC_DeInit();
//	SysTick->CTRL = 0;
//	SysTick->LOAD = 0;
//	SysTick->VAL = 0;
//	/** * Step: Disable all interrupts */
//	__disable_irq();
//	/* ARM Cortex-M Programming Guide to Memory Barrier Instructions.*/
//	__DSB();
//	__HAL_SYSCFG_REMAPMEMORY_SYSTEMFLASH();
//	/* Remap is bot visible at once. Execute some unrelated command! */
//	__DSB();
//	__ISB();
//	JumpToApplication = (void (*)(void)) (*((uint32_t *)(0x1FFF0000 + 4)));
//	/* Initialize user application's Stack Pointer */
//	__set_MSP(*(__IO uint32_t*) 0x1FFF0000);
//	JumpToApplication();
}

void debugRxHandler(void *argument)
{
    //modem_payload_t payload;
    uint8_t last_read_msg = DEBUG_MESSAGE_LIST_SIZE - 1;

    // always be receiving from modem
    HAL_UARTEx_ReceiveToIdle_DMA(&DEBUG_UART, debug_buffer, sizeof(debug_buffer));


  /* Infinite loop */
    for(;;)
    {
        // acquire rx uart semaphore
        osSemaphoreAcquire(debugRxSemaphoreHandle, osWaitForever);

        // try parsing all stored messages
        while ((last_read_msg + 1u) % DEBUG_MESSAGE_LIST_SIZE != debug_urx.msgs.msg_current)
        {
            last_read_msg = (last_read_msg + 1) % DEBUG_MESSAGE_LIST_SIZE;

            if (strcmp((char*)&debug_list[last_read_msg*debug_urx.msgs.msg_size], "bootloader") == 0)
            {
                JumpToBootloader();
            }


        }
    }
}

void debugRxCallback(UART_HandleTypeDef *huart, uint16_t dma_tail)
{

	debug_urx.buf.tail = dma_tail;
    if (uartRxCallback(&debug_urx))
    {
        if (!osSemaphoreGetCount(debugRxSemaphoreHandle)) osSemaphoreRelease(debugRxSemaphoreHandle);
    }
}

void debugTxDone(UART_HandleTypeDef *huart)
{
	if (!osSemaphoreGetCount(debugTxSemaphoreHandle)) osSemaphoreRelease(debugTxSemaphoreHandle);
}

void debugTxHandler(void *argument)
{
  /* USER CODE BEGIN debugTxHandler */
	debug_payload_t payload;
	osStatus_t status;

	HAL_UART_Transmit(&DEBUG_UART, (uint8_t*)"started debug tx handler\r\n", 25, 1000);

	uint32_t stack_space = osThreadGetStackSpace(osThreadGetId());
	payload.size = sprintf((char*)payload.data,"debug stack space %ld\r\n",stack_space);
	HAL_UART_Transmit(&DEBUG_UART, payload.data, payload.size, 200);

  /* Infinite loop */
  for(;;)
  {
	  status = osSemaphoreAcquire(debugTxSemaphoreHandle, osWaitForever);
	  if(status != osOK) continue; // never happens if osWaitForever

	  status = osMessageQueueGet(debugTxQueueHandle, (void *)&payload, NULL, osWaitForever );
	  if(status != osOK) continue; // never happens if osWaitForever

	  HAL_UART_Transmit_DMA(&DEBUG_UART, payload.data, payload.size);
  }
  /* USER CODE END debugTxHandler */
}

void Debug::printf(const char *fmt, ...) {
	va_list args;
	va_start(args, fmt);
	payload.size = vsnprintf((char*)payload.data, sizeof(payload.data), fmt, args);
	va_end(args);

	osMessageQueuePut(debugTxQueueHandle, (void*)&payload, 0, 0);
}

void Debug::printf_direct(const char *fmt, ...) {
//	osSemaphoreAcquire(debugTxSemaphoreHandle, osWaitForever);
	va_list args;
	va_start(args, fmt);
	payload.size = vsnprintf((char*)payload.data, sizeof(payload.data), fmt, args);
	va_end(args);
	HAL_UART_Transmit_DMA(&DEBUG_UART, payload.data, payload.size);
}
