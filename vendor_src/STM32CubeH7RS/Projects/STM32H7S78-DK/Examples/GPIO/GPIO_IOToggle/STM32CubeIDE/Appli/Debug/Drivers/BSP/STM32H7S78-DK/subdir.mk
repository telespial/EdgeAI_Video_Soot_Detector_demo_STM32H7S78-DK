################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery.c 

OBJS += \
./Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery.o 

C_DEPS += \
./Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery.o: /home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery.c Drivers/BSP/STM32H7S78-DK/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H7S7xx -c -I../../../Appli/Inc -I../../../../../../../../Drivers/BSP/STM32H7S78-DK -I../../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc -I../../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc/Legacy -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32H7RSxx/Include -I../../../../../../../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-STM32H7S78-2d-DK

clean-Drivers-2f-BSP-2f-STM32H7S78-2d-DK:
	-$(RM) ./Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery.cyclo ./Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery.d ./Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery.o ./Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery.su

.PHONY: clean-Drivers-2f-BSP-2f-STM32H7S78-2d-DK

