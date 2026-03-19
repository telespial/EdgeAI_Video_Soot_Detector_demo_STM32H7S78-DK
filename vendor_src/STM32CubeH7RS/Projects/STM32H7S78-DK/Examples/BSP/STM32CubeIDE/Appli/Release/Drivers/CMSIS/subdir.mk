################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Drivers/CMSIS/Device/ST/STM32H7RSxx/Source/Templates/system_stm32h7rsxx.c 

OBJS += \
./Drivers/CMSIS/system_stm32h7rsxx.o 

C_DEPS += \
./Drivers/CMSIS/system_stm32h7rsxx.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/system_stm32h7rsxx.o: /home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Drivers/CMSIS/Device/ST/STM32H7RSxx/Source/Templates/system_stm32h7rsxx.c Drivers/CMSIS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32H7S7xx -c -I../../../Inc -I../../../../../../../Drivers/BSP/STM32H7S78-DK -I../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc -I../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc/Legacy -I../../../../../../../Drivers/CMSIS/Device/ST/STM32H7RSxx/Include -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Utilities/lcd -Os -ffunction-sections -fdata-sections -Wall -Wno-format -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-CMSIS

clean-Drivers-2f-CMSIS:
	-$(RM) ./Drivers/CMSIS/system_stm32h7rsxx.cyclo ./Drivers/CMSIS/system_stm32h7rsxx.d ./Drivers/CMSIS/system_stm32h7rsxx.o ./Drivers/CMSIS/system_stm32h7rsxx.su

.PHONY: clean-Drivers-2f-CMSIS

