################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Drivers/BSP/Components/aps256xx/aps256xx.c \
/home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Drivers/BSP/Components/gt911/gt911.c \
/home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Drivers/BSP/Components/gt911/gt911_reg.c \
/home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Drivers/BSP/Components/tcpp0203/tcpp0203.c \
/home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Drivers/BSP/Components/tcpp0203/tcpp0203_reg.c 

OBJS += \
./Drivers/BSP/Components/aps256xx.o \
./Drivers/BSP/Components/gt911.o \
./Drivers/BSP/Components/gt911_reg.o \
./Drivers/BSP/Components/tcpp0203.o \
./Drivers/BSP/Components/tcpp0203_reg.o 

C_DEPS += \
./Drivers/BSP/Components/aps256xx.d \
./Drivers/BSP/Components/gt911.d \
./Drivers/BSP/Components/gt911_reg.d \
./Drivers/BSP/Components/tcpp0203.d \
./Drivers/BSP/Components/tcpp0203_reg.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/Components/aps256xx.o: /home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Drivers/BSP/Components/aps256xx/aps256xx.c Drivers/BSP/Components/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H7S7xx -DUSE_FULL_LL_DRIVER -DUSBPD_PORT_COUNT=1 -D_SNK -DUSBPDCORE_LIB_NO_PD -DTCPP0203_SUPPORT -c -I../../../Appli/Inc -I../../../../../../../../Drivers/BSP/STM32H7S78-DK -I../../.././../../../../../Drivers/BSP/Components/tcpp0203 -I../../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../../Utilities/lcd -I../../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc -I../../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc/Legacy -I../../../../../../../../Middlewares/ST/STM32_USBPD_Library/Core/inc -I../../../../../../../../Middlewares/ST/STM32_USBPD_Library/Devices/STM32H7RSXX/inc -I../../../../../../../../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../../../../../../../../Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32H7RSxx/Include -I../../../../../../../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/Components/gt911.o: /home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Drivers/BSP/Components/gt911/gt911.c Drivers/BSP/Components/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H7S7xx -DUSE_FULL_LL_DRIVER -DUSBPD_PORT_COUNT=1 -D_SNK -DUSBPDCORE_LIB_NO_PD -DTCPP0203_SUPPORT -c -I../../../Appli/Inc -I../../../../../../../../Drivers/BSP/STM32H7S78-DK -I../../.././../../../../../Drivers/BSP/Components/tcpp0203 -I../../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../../Utilities/lcd -I../../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc -I../../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc/Legacy -I../../../../../../../../Middlewares/ST/STM32_USBPD_Library/Core/inc -I../../../../../../../../Middlewares/ST/STM32_USBPD_Library/Devices/STM32H7RSXX/inc -I../../../../../../../../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../../../../../../../../Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32H7RSxx/Include -I../../../../../../../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/Components/gt911_reg.o: /home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Drivers/BSP/Components/gt911/gt911_reg.c Drivers/BSP/Components/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H7S7xx -DUSE_FULL_LL_DRIVER -DUSBPD_PORT_COUNT=1 -D_SNK -DUSBPDCORE_LIB_NO_PD -DTCPP0203_SUPPORT -c -I../../../Appli/Inc -I../../../../../../../../Drivers/BSP/STM32H7S78-DK -I../../.././../../../../../Drivers/BSP/Components/tcpp0203 -I../../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../../Utilities/lcd -I../../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc -I../../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc/Legacy -I../../../../../../../../Middlewares/ST/STM32_USBPD_Library/Core/inc -I../../../../../../../../Middlewares/ST/STM32_USBPD_Library/Devices/STM32H7RSXX/inc -I../../../../../../../../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../../../../../../../../Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32H7RSxx/Include -I../../../../../../../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/Components/tcpp0203.o: /home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Drivers/BSP/Components/tcpp0203/tcpp0203.c Drivers/BSP/Components/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H7S7xx -DUSE_FULL_LL_DRIVER -DUSBPD_PORT_COUNT=1 -D_SNK -DUSBPDCORE_LIB_NO_PD -DTCPP0203_SUPPORT -c -I../../../Appli/Inc -I../../../../../../../../Drivers/BSP/STM32H7S78-DK -I../../.././../../../../../Drivers/BSP/Components/tcpp0203 -I../../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../../Utilities/lcd -I../../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc -I../../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc/Legacy -I../../../../../../../../Middlewares/ST/STM32_USBPD_Library/Core/inc -I../../../../../../../../Middlewares/ST/STM32_USBPD_Library/Devices/STM32H7RSXX/inc -I../../../../../../../../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../../../../../../../../Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32H7RSxx/Include -I../../../../../../../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/Components/tcpp0203_reg.o: /home/user/python_projects/EmbeddedX/projects/soot_detector/vendor_src/STM32CubeH7RS/Drivers/BSP/Components/tcpp0203/tcpp0203_reg.c Drivers/BSP/Components/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H7S7xx -DUSE_FULL_LL_DRIVER -DUSBPD_PORT_COUNT=1 -D_SNK -DUSBPDCORE_LIB_NO_PD -DTCPP0203_SUPPORT -c -I../../../Appli/Inc -I../../../../../../../../Drivers/BSP/STM32H7S78-DK -I../../.././../../../../../Drivers/BSP/Components/tcpp0203 -I../../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../../Utilities/lcd -I../../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc -I../../../../../../../../Drivers/STM32H7RSxx_HAL_Driver/Inc/Legacy -I../../../../../../../../Middlewares/ST/STM32_USBPD_Library/Core/inc -I../../../../../../../../Middlewares/ST/STM32_USBPD_Library/Devices/STM32H7RSXX/inc -I../../../../../../../../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../../../../../../../../Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32H7RSxx/Include -I../../../../../../../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-Components

clean-Drivers-2f-BSP-2f-Components:
	-$(RM) ./Drivers/BSP/Components/aps256xx.cyclo ./Drivers/BSP/Components/aps256xx.d ./Drivers/BSP/Components/aps256xx.o ./Drivers/BSP/Components/aps256xx.su ./Drivers/BSP/Components/gt911.cyclo ./Drivers/BSP/Components/gt911.d ./Drivers/BSP/Components/gt911.o ./Drivers/BSP/Components/gt911.su ./Drivers/BSP/Components/gt911_reg.cyclo ./Drivers/BSP/Components/gt911_reg.d ./Drivers/BSP/Components/gt911_reg.o ./Drivers/BSP/Components/gt911_reg.su ./Drivers/BSP/Components/tcpp0203.cyclo ./Drivers/BSP/Components/tcpp0203.d ./Drivers/BSP/Components/tcpp0203.o ./Drivers/BSP/Components/tcpp0203.su ./Drivers/BSP/Components/tcpp0203_reg.cyclo ./Drivers/BSP/Components/tcpp0203_reg.d ./Drivers/BSP/Components/tcpp0203_reg.o ./Drivers/BSP/Components/tcpp0203_reg.su

.PHONY: clean-Drivers-2f-BSP-2f-Components

