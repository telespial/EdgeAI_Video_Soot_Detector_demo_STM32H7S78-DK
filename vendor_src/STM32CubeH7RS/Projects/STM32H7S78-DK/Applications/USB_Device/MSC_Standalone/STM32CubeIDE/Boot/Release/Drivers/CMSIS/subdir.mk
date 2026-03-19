################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Projects/STM32H7S78-DK/Applications/USB_Device/MSC_Standalone/Boot/Src/system_stm32h7rsxx.c 

OBJS += \
./Drivers/CMSIS/system_stm32h7rsxx.o 

C_DEPS += \
./Drivers/CMSIS/system_stm32h7rsxx.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/system_stm32h7rsxx.o: /home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Projects/STM32H7S78-DK/Applications/USB_Device/MSC_Standalone/Boot/Src/system_stm32h7rsxx.c Drivers/CMSIS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32H7S7xx -c -I../../../Boot/Inc -I../../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc -I../../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc/Legacy -I../../../../../../../../Middlewares/ST/STM32_ExtMem_Manager -I../../../../../../../../Middlewares/ST/STM32_ExtMem_Manager/boot -I../../../../../../../../Middlewares/ST/STM32_ExtMem_Manager/sal -I../../../../../../../../Middlewares/ST/STM32_ExtMem_Manager/nor_sfdp -I../../../../../../../../Middlewares/ST/STM32_ExtMem_Manager/psram -I../../../../../../../../Middlewares/ST/STM32_ExtMem_Manager/sdcard -I../../../../../../../../Middlewares/ST/STM32_ExtMem_Manager/user -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32H7RSxx/Include -I../../../../../../../../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-CMSIS

clean-Drivers-2f-CMSIS:
	-$(RM) ./Drivers/CMSIS/system_stm32h7rsxx.cyclo ./Drivers/CMSIS/system_stm32h7rsxx.d ./Drivers/CMSIS/system_stm32h7rsxx.o ./Drivers/CMSIS/system_stm32h7rsxx.su

.PHONY: clean-Drivers-2f-CMSIS

