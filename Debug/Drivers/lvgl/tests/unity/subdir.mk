################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: gnu-custom
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/tests/unity/unity.c \
../Drivers/lvgl/tests/unity/unity_support.c 

C_DEPS += \
./Drivers/lvgl/tests/unity/unity.d \
./Drivers/lvgl/tests/unity/unity_support.d 

OBJS += \
./Drivers/lvgl/tests/unity/unity.o \
./Drivers/lvgl/tests/unity/unity_support.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/tests/unity/%.o Drivers/lvgl/tests/unity/%.su Drivers/lvgl/tests/unity/%.cyclo: ../Drivers/lvgl/tests/unity/%.c Drivers/lvgl/tests/unity/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L073xx -c -I../Core/Inc -I"/home/emanuel/STM32CubeIDE/workspace_1.18.0/ProjektEmanuelFloater/Drivers/lvgl" -I"/home/emanuel/STM32CubeIDE/workspace_1.18.0/ProjektEmanuelFloater/External/ili9341" -I"/home/emanuel/STM32CubeIDE/workspace_1.18.0/ProjektEmanuelFloater/External" -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0 -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-tests-2f-unity

clean-Drivers-2f-lvgl-2f-tests-2f-unity:
	-$(RM) ./Drivers/lvgl/tests/unity/unity.cyclo ./Drivers/lvgl/tests/unity/unity.d ./Drivers/lvgl/tests/unity/unity.o ./Drivers/lvgl/tests/unity/unity.su ./Drivers/lvgl/tests/unity/unity_support.cyclo ./Drivers/lvgl/tests/unity/unity_support.d ./Drivers/lvgl/tests/unity/unity_support.o ./Drivers/lvgl/tests/unity/unity_support.su

.PHONY: clean-Drivers-2f-lvgl-2f-tests-2f-unity

