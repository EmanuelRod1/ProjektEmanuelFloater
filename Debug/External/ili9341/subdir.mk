################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../External/ili9341/fonts.c \
../External/ili9341/ili9341.c \
../External/ili9341/ili9341_touch.c 

C_DEPS += \
./External/ili9341/fonts.d \
./External/ili9341/ili9341.d \
./External/ili9341/ili9341_touch.d 

OBJS += \
./External/ili9341/fonts.o \
./External/ili9341/ili9341.o \
./External/ili9341/ili9341_touch.o 


# Each subdirectory must supply rules for building sources it contributes
External/ili9341/%.o External/ili9341/%.su External/ili9341/%.cyclo: ../External/ili9341/%.c External/ili9341/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L073xx -c -I../Core/Inc -I"/home/emanuel/STM32CubeIDE/workspace_1.18.0/ProjektEmanuelFloater/External/ili9341" -I"/home/emanuel/STM32CubeIDE/workspace_1.18.0/ProjektEmanuelFloater/External" -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0 -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-External-2f-ili9341

clean-External-2f-ili9341:
	-$(RM) ./External/ili9341/fonts.cyclo ./External/ili9341/fonts.d ./External/ili9341/fonts.o ./External/ili9341/fonts.su ./External/ili9341/ili9341.cyclo ./External/ili9341/ili9341.d ./External/ili9341/ili9341.o ./External/ili9341/ili9341.su ./External/ili9341/ili9341_touch.cyclo ./External/ili9341/ili9341_touch.d ./External/ili9341/ili9341_touch.o ./External/ili9341/ili9341_touch.su

.PHONY: clean-External-2f-ili9341

