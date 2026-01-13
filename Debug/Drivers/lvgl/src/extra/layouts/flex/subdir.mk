################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: gnu-custom
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/src/extra/layouts/flex/lv_flex.c 

C_DEPS += \
./Drivers/lvgl/src/extra/layouts/flex/lv_flex.d 

OBJS += \
./Drivers/lvgl/src/extra/layouts/flex/lv_flex.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/src/extra/layouts/flex/%.o Drivers/lvgl/src/extra/layouts/flex/%.su Drivers/lvgl/src/extra/layouts/flex/%.cyclo: ../Drivers/lvgl/src/extra/layouts/flex/%.c Drivers/lvgl/src/extra/layouts/flex/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L073xx -c -I../Core/Inc -I"/home/emanuel/STM32CubeIDE/workspace_1.18.0/ProjektEmanuelFloater/Drivers/lvgl" -I"/home/emanuel/STM32CubeIDE/workspace_1.18.0/ProjektEmanuelFloater/External/ili9341" -I"/home/emanuel/STM32CubeIDE/workspace_1.18.0/ProjektEmanuelFloater/External" -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0 -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-src-2f-extra-2f-layouts-2f-flex

clean-Drivers-2f-lvgl-2f-src-2f-extra-2f-layouts-2f-flex:
	-$(RM) ./Drivers/lvgl/src/extra/layouts/flex/lv_flex.cyclo ./Drivers/lvgl/src/extra/layouts/flex/lv_flex.d ./Drivers/lvgl/src/extra/layouts/flex/lv_flex.o ./Drivers/lvgl/src/extra/layouts/flex/lv_flex.su

.PHONY: clean-Drivers-2f-lvgl-2f-src-2f-extra-2f-layouts-2f-flex

