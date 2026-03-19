################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery.c \
/home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery_audio.c \
/home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery_bus.c \
/home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery_lcd.c \
/home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery_sd.c \
/home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery_ts.c \
/home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery_xspi.c 

OBJS += \
./Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery.o \
./Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery_audio.o \
./Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery_bus.o \
./Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery_lcd.o \
./Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery_sd.o \
./Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery_ts.o \
./Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery_xspi.o 

C_DEPS += \
./Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery.d \
./Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery_audio.d \
./Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery_bus.d \
./Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery_lcd.d \
./Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery_sd.d \
./Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery_ts.d \
./Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery_xspi.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery.o: /home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery.c Drivers/BSP/STM32H7S78-DK/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32H7S7xx -c -I../../../Inc -I../../../../../../../Drivers/BSP/STM32H7S78-DK -I../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc -I../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc/Legacy -I../../../../../../../Drivers/CMSIS/Device/ST/STM32H7RSxx/Include -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Utilities/lcd -Os -ffunction-sections -fdata-sections -Wall -Wno-format -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery_audio.o: /home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery_audio.c Drivers/BSP/STM32H7S78-DK/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32H7S7xx -c -I../../../Inc -I../../../../../../../Drivers/BSP/STM32H7S78-DK -I../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc -I../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc/Legacy -I../../../../../../../Drivers/CMSIS/Device/ST/STM32H7RSxx/Include -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Utilities/lcd -Os -ffunction-sections -fdata-sections -Wall -Wno-format -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery_bus.o: /home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery_bus.c Drivers/BSP/STM32H7S78-DK/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32H7S7xx -c -I../../../Inc -I../../../../../../../Drivers/BSP/STM32H7S78-DK -I../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc -I../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc/Legacy -I../../../../../../../Drivers/CMSIS/Device/ST/STM32H7RSxx/Include -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Utilities/lcd -Os -ffunction-sections -fdata-sections -Wall -Wno-format -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery_lcd.o: /home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery_lcd.c Drivers/BSP/STM32H7S78-DK/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32H7S7xx -c -I../../../Inc -I../../../../../../../Drivers/BSP/STM32H7S78-DK -I../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc -I../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc/Legacy -I../../../../../../../Drivers/CMSIS/Device/ST/STM32H7RSxx/Include -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Utilities/lcd -Os -ffunction-sections -fdata-sections -Wall -Wno-format -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery_sd.o: /home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery_sd.c Drivers/BSP/STM32H7S78-DK/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32H7S7xx -c -I../../../Inc -I../../../../../../../Drivers/BSP/STM32H7S78-DK -I../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc -I../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc/Legacy -I../../../../../../../Drivers/CMSIS/Device/ST/STM32H7RSxx/Include -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Utilities/lcd -Os -ffunction-sections -fdata-sections -Wall -Wno-format -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery_ts.o: /home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery_ts.c Drivers/BSP/STM32H7S78-DK/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32H7S7xx -c -I../../../Inc -I../../../../../../../Drivers/BSP/STM32H7S78-DK -I../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc -I../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc/Legacy -I../../../../../../../Drivers/CMSIS/Device/ST/STM32H7RSxx/Include -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Utilities/lcd -Os -ffunction-sections -fdata-sections -Wall -Wno-format -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery_xspi.o: /home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery_xspi.c Drivers/BSP/STM32H7S78-DK/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32H7S7xx -c -I../../../Inc -I../../../../../../../Drivers/BSP/STM32H7S78-DK -I../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc -I../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc/Legacy -I../../../../../../../Drivers/CMSIS/Device/ST/STM32H7RSxx/Include -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Utilities/lcd -Os -ffunction-sections -fdata-sections -Wall -Wno-format -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-STM32H7S78-2d-DK

clean-Drivers-2f-BSP-2f-STM32H7S78-2d-DK:
	-$(RM) ./Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery.cyclo ./Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery.d ./Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery.o ./Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery.su ./Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery_audio.cyclo ./Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery_audio.d ./Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery_audio.o ./Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery_audio.su ./Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery_bus.cyclo ./Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery_bus.d ./Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery_bus.o ./Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery_bus.su ./Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery_lcd.cyclo ./Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery_lcd.d ./Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery_lcd.o ./Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery_lcd.su ./Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery_sd.cyclo ./Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery_sd.d ./Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery_sd.o ./Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery_sd.su ./Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery_ts.cyclo ./Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery_ts.d ./Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery_ts.o ./Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery_ts.su ./Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery_xspi.cyclo ./Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery_xspi.d ./Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery_xspi.o ./Drivers/BSP/STM32H7S78-DK/stm32h7s78_discovery_xspi.su

.PHONY: clean-Drivers-2f-BSP-2f-STM32H7S78-2d-DK

