################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: gnu-custom
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/src/extra/widgets/meter/lv_meter.c 

C_DEPS += \
./Drivers/lvgl/src/extra/widgets/meter/lv_meter.d 

OBJS += \
./Drivers/lvgl/src/extra/widgets/meter/lv_meter.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/src/extra/widgets/meter/%.o Drivers/lvgl/src/extra/widgets/meter/%.su Drivers/lvgl/src/extra/widgets/meter/%.cyclo: ../Drivers/lvgl/src/extra/widgets/meter/%.c Drivers/lvgl/src/extra/widgets/meter/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L073xx -c -I../Core/Inc -I"/home/emanuel/STM32CubeIDE/workspace_1.18.0/ProjektEmanuelFloater/Drivers/lvgl" -I"/home/emanuel/STM32CubeIDE/workspace_1.18.0/ProjektEmanuelFloater/External/ili9341" -I"/home/emanuel/STM32CubeIDE/workspace_1.18.0/ProjektEmanuelFloater/External" -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0 -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-src-2f-extra-2f-widgets-2f-meter

clean-Drivers-2f-lvgl-2f-src-2f-extra-2f-widgets-2f-meter:
	-$(RM) ./Drivers/lvgl/src/extra/widgets/meter/lv_meter.cyclo ./Drivers/lvgl/src/extra/widgets/meter/lv_meter.d ./Drivers/lvgl/src/extra/widgets/meter/lv_meter.o ./Drivers/lvgl/src/extra/widgets/meter/lv_meter.su

.PHONY: clean-Drivers-2f-lvgl-2f-src-2f-extra-2f-widgets-2f-meter

