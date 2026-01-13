################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: gnu-custom
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/demos/music/lv_demo_music.c \
../Drivers/lvgl/demos/music/lv_demo_music_list.c \
../Drivers/lvgl/demos/music/lv_demo_music_main.c 

C_DEPS += \
./Drivers/lvgl/demos/music/lv_demo_music.d \
./Drivers/lvgl/demos/music/lv_demo_music_list.d \
./Drivers/lvgl/demos/music/lv_demo_music_main.d 

OBJS += \
./Drivers/lvgl/demos/music/lv_demo_music.o \
./Drivers/lvgl/demos/music/lv_demo_music_list.o \
./Drivers/lvgl/demos/music/lv_demo_music_main.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/demos/music/%.o Drivers/lvgl/demos/music/%.su Drivers/lvgl/demos/music/%.cyclo: ../Drivers/lvgl/demos/music/%.c Drivers/lvgl/demos/music/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L073xx -c -I../Core/Inc -I"/home/emanuel/STM32CubeIDE/workspace_1.18.0/ProjektEmanuelFloater/Drivers/lvgl" -I"/home/emanuel/STM32CubeIDE/workspace_1.18.0/ProjektEmanuelFloater/External/ili9341" -I"/home/emanuel/STM32CubeIDE/workspace_1.18.0/ProjektEmanuelFloater/External" -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM0 -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-demos-2f-music

clean-Drivers-2f-lvgl-2f-demos-2f-music:
	-$(RM) ./Drivers/lvgl/demos/music/lv_demo_music.cyclo ./Drivers/lvgl/demos/music/lv_demo_music.d ./Drivers/lvgl/demos/music/lv_demo_music.o ./Drivers/lvgl/demos/music/lv_demo_music.su ./Drivers/lvgl/demos/music/lv_demo_music_list.cyclo ./Drivers/lvgl/demos/music/lv_demo_music_list.d ./Drivers/lvgl/demos/music/lv_demo_music_list.o ./Drivers/lvgl/demos/music/lv_demo_music_list.su ./Drivers/lvgl/demos/music/lv_demo_music_main.cyclo ./Drivers/lvgl/demos/music/lv_demo_music_main.d ./Drivers/lvgl/demos/music/lv_demo_music_main.o ./Drivers/lvgl/demos/music/lv_demo_music_main.su

.PHONY: clean-Drivers-2f-lvgl-2f-demos-2f-music

