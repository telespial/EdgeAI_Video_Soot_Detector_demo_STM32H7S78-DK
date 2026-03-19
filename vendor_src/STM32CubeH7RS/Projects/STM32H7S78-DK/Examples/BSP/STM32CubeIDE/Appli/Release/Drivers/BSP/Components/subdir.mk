################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Drivers/BSP/Components/aps256xx/aps256xx.c \
/home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Drivers/BSP/Components/gt911/gt911.c \
/home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Drivers/BSP/Components/gt911/gt911_reg.c \
/home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Drivers/BSP/Components/mx66uw1g45g/mx66uw1g45g.c \
/home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Drivers/BSP/Components/wm8904/wm8904.c \
/home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Drivers/BSP/Components/wm8904/wm8904_reg.c 

OBJS += \
./Drivers/BSP/Components/aps256xx.o \
./Drivers/BSP/Components/gt911.o \
./Drivers/BSP/Components/gt911_reg.o \
./Drivers/BSP/Components/mx66uw1g45g.o \
./Drivers/BSP/Components/wm8904.o \
./Drivers/BSP/Components/wm8904_reg.o 

C_DEPS += \
./Drivers/BSP/Components/aps256xx.d \
./Drivers/BSP/Components/gt911.d \
./Drivers/BSP/Components/gt911_reg.d \
./Drivers/BSP/Components/mx66uw1g45g.d \
./Drivers/BSP/Components/wm8904.d \
./Drivers/BSP/Components/wm8904_reg.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/Components/aps256xx.o: /home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Drivers/BSP/Components/aps256xx/aps256xx.c Drivers/BSP/Components/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32H7S7xx -c -I../../../Inc -I../../../../../../../Drivers/BSP/STM32H7S78-DK -I../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc -I../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc/Legacy -I../../../../../../../Drivers/CMSIS/Device/ST/STM32H7RSxx/Include -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Utilities/lcd -Os -ffunction-sections -fdata-sections -Wall -Wno-format -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/Components/gt911.o: /home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Drivers/BSP/Components/gt911/gt911.c Drivers/BSP/Components/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32H7S7xx -c -I../../../Inc -I../../../../../../../Drivers/BSP/STM32H7S78-DK -I../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc -I../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc/Legacy -I../../../../../../../Drivers/CMSIS/Device/ST/STM32H7RSxx/Include -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Utilities/lcd -Os -ffunction-sections -fdata-sections -Wall -Wno-format -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/Components/gt911_reg.o: /home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Drivers/BSP/Components/gt911/gt911_reg.c Drivers/BSP/Components/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32H7S7xx -c -I../../../Inc -I../../../../../../../Drivers/BSP/STM32H7S78-DK -I../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc -I../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc/Legacy -I../../../../../../../Drivers/CMSIS/Device/ST/STM32H7RSxx/Include -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Utilities/lcd -Os -ffunction-sections -fdata-sections -Wall -Wno-format -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/Components/mx66uw1g45g.o: /home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Drivers/BSP/Components/mx66uw1g45g/mx66uw1g45g.c Drivers/BSP/Components/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32H7S7xx -c -I../../../Inc -I../../../../../../../Drivers/BSP/STM32H7S78-DK -I../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc -I../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc/Legacy -I../../../../../../../Drivers/CMSIS/Device/ST/STM32H7RSxx/Include -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Utilities/lcd -Os -ffunction-sections -fdata-sections -Wall -Wno-format -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/Components/wm8904.o: /home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Drivers/BSP/Components/wm8904/wm8904.c Drivers/BSP/Components/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32H7S7xx -c -I../../../Inc -I../../../../../../../Drivers/BSP/STM32H7S78-DK -I../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc -I../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc/Legacy -I../../../../../../../Drivers/CMSIS/Device/ST/STM32H7RSxx/Include -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Utilities/lcd -Os -ffunction-sections -fdata-sections -Wall -Wno-format -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/Components/wm8904_reg.o: /home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Drivers/BSP/Components/wm8904/wm8904_reg.c Drivers/BSP/Components/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32H7S7xx -c -I../../../Inc -I../../../../../../../Drivers/BSP/STM32H7S78-DK -I../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc -I../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc/Legacy -I../../../../../../../Drivers/CMSIS/Device/ST/STM32H7RSxx/Include -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Utilities/lcd -Os -ffunction-sections -fdata-sections -Wall -Wno-format -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-Components

clean-Drivers-2f-BSP-2f-Components:
	-$(RM) ./Drivers/BSP/Components/aps256xx.cyclo ./Drivers/BSP/Components/aps256xx.d ./Drivers/BSP/Components/aps256xx.o ./Drivers/BSP/Components/aps256xx.su ./Drivers/BSP/Components/gt911.cyclo ./Drivers/BSP/Components/gt911.d ./Drivers/BSP/Components/gt911.o ./Drivers/BSP/Components/gt911.su ./Drivers/BSP/Components/gt911_reg.cyclo ./Drivers/BSP/Components/gt911_reg.d ./Drivers/BSP/Components/gt911_reg.o ./Drivers/BSP/Components/gt911_reg.su ./Drivers/BSP/Components/mx66uw1g45g.cyclo ./Drivers/BSP/Components/mx66uw1g45g.d ./Drivers/BSP/Components/mx66uw1g45g.o ./Drivers/BSP/Components/mx66uw1g45g.su ./Drivers/BSP/Components/wm8904.cyclo ./Drivers/BSP/Components/wm8904.d ./Drivers/BSP/Components/wm8904.o ./Drivers/BSP/Components/wm8904.su ./Drivers/BSP/Components/wm8904_reg.cyclo ./Drivers/BSP/Components/wm8904_reg.d ./Drivers/BSP/Components/wm8904_reg.o ./Drivers/BSP/Components/wm8904_reg.su

.PHONY: clean-Drivers-2f-BSP-2f-Components

