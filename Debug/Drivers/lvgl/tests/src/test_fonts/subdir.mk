################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: gnu-custom
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/tests/src/test_fonts/font_1.c \
../Drivers/lvgl/tests/src/test_fonts/font_2.c \
../Drivers/lvgl/tests/src/test_fonts/font_3.c \
../Drivers/lvgl/tests/src/test_fonts/ubuntu_font.c 

C_DEPS += \
./Drivers/lvgl/tests/src/test_fonts/font_1.d \
./Drivers/lvgl/tests/src/test_fonts/font_2.d \
./Drivers/lvgl/tests/src/test_fonts/font_3.d \
./Drivers/lvgl/tests/src/test_fonts/ubuntu_font.d 

OBJS += \
./Drivers/lvgl/tests/src/test_fonts/font_1.o \
./Drivers/lvgl/tests/src/test_fonts/font_2.o \
./Drivers/lvgl/tests/src/test_fonts/font_3.o \
./Drivers/lvgl/tests/src/test_fonts/ubuntu_font.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/tests/src/test_fonts/%.o Drivers/lvgl/tests/src/test_fonts/%.su Drivers/lvgl/tests/src/test_fonts/%.cyclo: ../Drivers/lvgl/tests/src/test_fonts/%.c Drivers/lvgl/tests/src/test_fonts/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L073xx -c -I../Core/Inc -I"/home/emanuel/STM32CubeIDE/workspace_1.18.0/ProjektEmanuelFloater/Drivers/lvgl" -I"/home/emanuel/STM32CubeIDE/workspace_1.18.0/ProjektEmanuelFloater/External/ili9341" -I"/home/emanuel/STM32CubeIDE/workspace_1.18.0/ProjektEmanuelFloater/External" -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0 -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-tests-2f-src-2f-test_fonts

clean-Drivers-2f-lvgl-2f-tests-2f-src-2f-test_fonts:
	-$(RM) ./Drivers/lvgl/tests/src/test_fonts/font_1.cyclo ./Drivers/lvgl/tests/src/test_fonts/font_1.d ./Drivers/lvgl/tests/src/test_fonts/font_1.o ./Drivers/lvgl/tests/src/test_fonts/font_1.su ./Drivers/lvgl/tests/src/test_fonts/font_2.cyclo ./Drivers/lvgl/tests/src/test_fonts/font_2.d ./Drivers/lvgl/tests/src/test_fonts/font_2.o ./Drivers/lvgl/tests/src/test_fonts/font_2.su ./Drivers/lvgl/tests/src/test_fonts/font_3.cyclo ./Drivers/lvgl/tests/src/test_fonts/font_3.d ./Drivers/lvgl/tests/src/test_fonts/font_3.o ./Drivers/lvgl/tests/src/test_fonts/font_3.su ./Drivers/lvgl/tests/src/test_fonts/ubuntu_font.cyclo ./Drivers/lvgl/tests/src/test_fonts/ubuntu_font.d ./Drivers/lvgl/tests/src/test_fonts/ubuntu_font.o ./Drivers/lvgl/tests/src/test_fonts/ubuntu_font.su

.PHONY: clean-Drivers-2f-lvgl-2f-tests-2f-src-2f-test_fonts

