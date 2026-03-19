################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Projects/STM32H7S78-DK/Examples/BSP/Src/audio_play.c \
/home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Projects/STM32H7S78-DK/Examples/BSP/Src/audio_record.c \
/home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Projects/STM32H7S78-DK/Examples/BSP/Src/lcd.c \
/home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Projects/STM32H7S78-DK/Examples/BSP/Src/main.c \
/home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Projects/STM32H7S78-DK/Examples/BSP/Src/sd.c \
/home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Projects/STM32H7S78-DK/Examples/BSP/Src/stm32h7rsxx_hal_msp.c \
/home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Projects/STM32H7S78-DK/Examples/BSP/Src/stm32h7rsxx_it.c \
../Application/User/syscalls.c \
../Application/User/sysmem.c \
/home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Projects/STM32H7S78-DK/Examples/BSP/Src/touchscreen.c 

OBJS += \
./Application/User/audio_play.o \
./Application/User/audio_record.o \
./Application/User/lcd.o \
./Application/User/main.o \
./Application/User/sd.o \
./Application/User/stm32h7rsxx_hal_msp.o \
./Application/User/stm32h7rsxx_it.o \
./Application/User/syscalls.o \
./Application/User/sysmem.o \
./Application/User/touchscreen.o 

C_DEPS += \
./Application/User/audio_play.d \
./Application/User/audio_record.d \
./Application/User/lcd.d \
./Application/User/main.d \
./Application/User/sd.d \
./Application/User/stm32h7rsxx_hal_msp.d \
./Application/User/stm32h7rsxx_it.d \
./Application/User/syscalls.d \
./Application/User/sysmem.d \
./Application/User/touchscreen.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/audio_play.o: /home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Projects/STM32H7S78-DK/Examples/BSP/Src/audio_play.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32H7S7xx -c -I../../../Inc -I../../../../../../../Drivers/BSP/STM32H7S78-DK -I../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc -I../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc/Legacy -I../../../../../../../Drivers/CMSIS/Device/ST/STM32H7RSxx/Include -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Utilities/lcd -Os -ffunction-sections -fdata-sections -Wall -Wno-format -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/audio_record.o: /home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Projects/STM32H7S78-DK/Examples/BSP/Src/audio_record.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32H7S7xx -c -I../../../Inc -I../../../../../../../Drivers/BSP/STM32H7S78-DK -I../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc -I../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc/Legacy -I../../../../../../../Drivers/CMSIS/Device/ST/STM32H7RSxx/Include -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Utilities/lcd -Os -ffunction-sections -fdata-sections -Wall -Wno-format -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/lcd.o: /home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Projects/STM32H7S78-DK/Examples/BSP/Src/lcd.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32H7S7xx -c -I../../../Inc -I../../../../../../../Drivers/BSP/STM32H7S78-DK -I../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc -I../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc/Legacy -I../../../../../../../Drivers/CMSIS/Device/ST/STM32H7RSxx/Include -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Utilities/lcd -Os -ffunction-sections -fdata-sections -Wall -Wno-format -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/main.o: /home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Projects/STM32H7S78-DK/Examples/BSP/Src/main.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32H7S7xx -c -I../../../Inc -I../../../../../../../Drivers/BSP/STM32H7S78-DK -I../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc -I../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc/Legacy -I../../../../../../../Drivers/CMSIS/Device/ST/STM32H7RSxx/Include -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Utilities/lcd -Os -ffunction-sections -fdata-sections -Wall -Wno-format -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/sd.o: /home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Projects/STM32H7S78-DK/Examples/BSP/Src/sd.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32H7S7xx -c -I../../../Inc -I../../../../../../../Drivers/BSP/STM32H7S78-DK -I../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc -I../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc/Legacy -I../../../../../../../Drivers/CMSIS/Device/ST/STM32H7RSxx/Include -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Utilities/lcd -Os -ffunction-sections -fdata-sections -Wall -Wno-format -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/stm32h7rsxx_hal_msp.o: /home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Projects/STM32H7S78-DK/Examples/BSP/Src/stm32h7rsxx_hal_msp.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32H7S7xx -c -I../../../Inc -I../../../../../../../Drivers/BSP/STM32H7S78-DK -I../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc -I../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc/Legacy -I../../../../../../../Drivers/CMSIS/Device/ST/STM32H7RSxx/Include -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Utilities/lcd -Os -ffunction-sections -fdata-sections -Wall -Wno-format -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/stm32h7rsxx_it.o: /home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Projects/STM32H7S78-DK/Examples/BSP/Src/stm32h7rsxx_it.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32H7S7xx -c -I../../../Inc -I../../../../../../../Drivers/BSP/STM32H7S78-DK -I../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc -I../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc/Legacy -I../../../../../../../Drivers/CMSIS/Device/ST/STM32H7RSxx/Include -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Utilities/lcd -Os -ffunction-sections -fdata-sections -Wall -Wno-format -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/%.o Application/User/%.su Application/User/%.cyclo: ../Application/User/%.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32H7S7xx -c -I../../../Inc -I../../../../../../../Drivers/BSP/STM32H7S78-DK -I../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc -I../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc/Legacy -I../../../../../../../Drivers/CMSIS/Device/ST/STM32H7RSxx/Include -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Utilities/lcd -Os -ffunction-sections -fdata-sections -Wall -Wno-format -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/touchscreen.o: /home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Projects/STM32H7S78-DK/Examples/BSP/Src/touchscreen.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32H7S7xx -c -I../../../Inc -I../../../../../../../Drivers/BSP/STM32H7S78-DK -I../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc -I../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc/Legacy -I../../../../../../../Drivers/CMSIS/Device/ST/STM32H7RSxx/Include -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Utilities/lcd -Os -ffunction-sections -fdata-sections -Wall -Wno-format -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-User

clean-Application-2f-User:
	-$(RM) ./Application/User/audio_play.cyclo ./Application/User/audio_play.d ./Application/User/audio_play.o ./Application/User/audio_play.su ./Application/User/audio_record.cyclo ./Application/User/audio_record.d ./Application/User/audio_record.o ./Application/User/audio_record.su ./Application/User/lcd.cyclo ./Application/User/lcd.d ./Application/User/lcd.o ./Application/User/lcd.su ./Application/User/main.cyclo ./Application/User/main.d ./Application/User/main.o ./Application/User/main.su ./Application/User/sd.cyclo ./Application/User/sd.d ./Application/User/sd.o ./Application/User/sd.su ./Application/User/stm32h7rsxx_hal_msp.cyclo ./Application/User/stm32h7rsxx_hal_msp.d ./Application/User/stm32h7rsxx_hal_msp.o ./Application/User/stm32h7rsxx_hal_msp.su ./Application/User/stm32h7rsxx_it.cyclo ./Application/User/stm32h7rsxx_it.d ./Application/User/stm32h7rsxx_it.o ./Application/User/stm32h7rsxx_it.su ./Application/User/syscalls.cyclo ./Application/User/syscalls.d ./Application/User/syscalls.o ./Application/User/syscalls.su ./Application/User/sysmem.cyclo ./Application/User/sysmem.d ./Application/User/sysmem.o ./Application/User/sysmem.su ./Application/User/touchscreen.cyclo ./Application/User/touchscreen.d ./Application/User/touchscreen.o ./Application/User/touchscreen.su

.PHONY: clean-Application-2f-User

