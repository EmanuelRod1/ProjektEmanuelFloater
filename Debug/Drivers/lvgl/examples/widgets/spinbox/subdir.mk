################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: gnu-custom
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/examples/widgets/spinbox/lv_example_spinbox_1.c 

C_DEPS += \
./Drivers/lvgl/examples/widgets/spinbox/lv_example_spinbox_1.d 

OBJS += \
./Drivers/lvgl/examples/widgets/spinbox/lv_example_spinbox_1.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/examples/widgets/spinbox/%.o Drivers/lvgl/examples/widgets/spinbox/%.su Drivers/lvgl/examples/widgets/spinbox/%.cyclo: ../Drivers/lvgl/examples/widgets/spinbox/%.c Drivers/lvgl/examples/widgets/spinbox/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L073xx -c -I../Core/Inc -I"/home/emanuel/STM32CubeIDE/workspace_1.18.0/ProjektEmanuelFloater/Drivers/lvgl" -I"/home/emanuel/STM32CubeIDE/workspace_1.18.0/ProjektEmanuelFloater/External/ili9341" -I"/home/emanuel/STM32CubeIDE/workspace_1.18.0/ProjektEmanuelFloater/External" -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0 -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-examples-2f-widgets-2f-spinbox

clean-Drivers-2f-lvgl-2f-examples-2f-widgets-2f-spinbox:
	-$(RM) ./Drivers/lvgl/examples/widgets/spinbox/lv_example_spinbox_1.cyclo ./Drivers/lvgl/examples/widgets/spinbox/lv_example_spinbox_1.d ./Drivers/lvgl/examples/widgets/spinbox/lv_example_spinbox_1.o ./Drivers/lvgl/examples/widgets/spinbox/lv_example_spinbox_1.su

.PHONY: clean-Drivers-2f-lvgl-2f-examples-2f-widgets-2f-spinbox

