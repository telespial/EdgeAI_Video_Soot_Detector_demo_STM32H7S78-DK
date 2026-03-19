---
pagetitle: Release Notes for STM32CubeH7RS Firmware Package
lang: en
header-includes: <link rel="icon" type="image/x-icon" href="_htmresc/favicon.png" />
---

::: {.row}
::: {.col-sm-12 .col-lg-4}

<center>
# Release Notes for
# <mark>STM32CubeH7RS Firmware Package</mark>
Copyright &copy; 2024 STMicroelectronics\

[![ST logo](_htmresc/st_logo_2020.png)](https://www.st.com){.logo}
</center>

# Purpose

**STM32Cube is an STMicroelectronics original initiative to ease developers life by reducing development efforts, time and cost.</mark>**

STM32Cube covers STM32 portfolio.

STM32Cube Version 1.x includes:

- The STM32CubeMX, a graphical software configuration tool that allows to generate C initialization code using graphical wizards.
- A comprehensive embedded software platform, delivered per series
  - The STM32Cube HAL, an STM32 abstraction layer embedded software, ensuring maximized portability across STM32 portfolio.
  - Low-layer APIs (LL) offering a fast light-weight expert-oriented layer which is closer to the hardware than the HAL.
  - A consistent set of middleware components such as FAT file system, RTOS, USB and USB PD.

All embedded software utilities, delivered with a full set of examples.

The STM32Cube firmware solution offers a straightforward API with a modular architecture, making it simple to fine tune custom applications and scalable to fit most requirements.

![STM32Cube](_htmresc/STM32Cube_2020.bmp)

\

The HAL (Hardware Abstraction Layer) & LL (Low Layers) drivers provided within this package support the STM32H7R7xx/H7S7xx/H7R3xx/H7S3xx products.

The HAL and LL drivers provided within this package are compliant with MISRA-C:2012 guidelines, and have been reviewed with a static analysis tool to eliminate possible run-time errors.
Reports are available on demand.

For quick getting started with the STM32CubeH7RS firmware package, you can refer to UM3294 and download firmware updates and all the latest documentation from [www.st.com/stm32cubeH7RS](https://www.st.com/content/st_com/en/products/embedded-software/mcu-mpu-embedded-software/stm32-embedded-software/stm32cube-mcu-mpu-packages/stm32cubeh7rs.html)

Here is the list of references to user documents:

- [UM3294:](https://www.st.com/resource/en/user_manual/DM01040137.pdf) Getting started with STM32CubeH7RS for STM32H7Rx/Sx Series 
- [UM3309:](https://www.st.com/resource/en/user_manual/DM01054249.pdf) Description of STM32H7Rx/7Sx HAL and low-layer drivers
- [AN6077:](https://www.st.com/resource/en/application_note/DM01056813.pdf) STM32Cube MCU Package examples for STM32H7Rx/Sx series
- [Security with STM32H7Sx](https://wiki.st.com/stm32mcu/wiki/Category:STM32H7RS)
- [Getting started with External memory Manager and External memory loader](https://wiki.st.com/stm32mcu/wiki/Getting_started_with_External_memory_Manager_and_External_memory_loader)

:::

::: {.col-sm-12 .col-lg-8}
# Update History

::: {.collapse}
<input type="checkbox" id="collapse-section3" checked aria-hidden="true">
<label for="collapse-section3" aria-hidden="true">__V1.2.0 / 05-February-2025__</label>
<div>

## Maintenance release

- General updates to fix known defects and enhancements implementation
- Rework readme files of ROT applications
- Fix the MPU configuration in boot projects to avoid a blocking state that prevents jumping to the user application in closed mode
- Add a new NOR Flash example with Read While Write feature (RWW)
- CMSIS Core changes:
  - Fix CMSIS-DSP and CMSIS-NN files in CMSIS Core v5.9.0
  - Integrate issue #620 to fix endless loop in SCB_DisableDCache()
- Upgrade of **USBPD core** library to new version **V5.3.0**
- Upgrade of **USB host** library to new version **V3.5.3**
- Upgrade of **FreeRTOS** library to new version **V10.6.2 (ST modified 2024-10-11)**
- Upgrade of **STM32 ExtMem Manager** library to new version **V1.3.0**
- Upgrade of **mcuboot** library to new version **V1.7.2.25**
- Upgrade of **mbed-crypto** library to new version **V3.6.2 (ST modified 2024-11-25)**
- Upgrade of **LwIP** library to new version **V2.1.3 (ST modified 2024-12-13)**
- Upgrade of **FATFS** library to new version **R0.15 (ST modified 2024-12-20)**

## Contents

- **CMSIS** updates
  - CMSIS Core changes:
    - Fix CMSIS-DSP and CMSIS-NN files in CMSIS Core v5.9.0
    - Integrate issue #620 to fix endless loop in SCB_DisableDCache()
  - Remove flash size data register

- **HAL** updates
  - Remove unnecessary parentheses that causes compilation warning.
  - Enhance HAL code quality for MISRA-C Rule-8.13 by adding const qualifiers.
  - **HAL ADC**
    - Fix definition of VREFINT_CAL_ADDR, TEMPSENSOR_CAL1_ADDR, TEMPSENSOR_CAL2_ADDR macros.
    - Fix description of parameter Length in HAL_ADCEx_MultiModeStart_DMA() API.
  - **LL Cortex**
    - Remove all references to LL_MPU_TEX_LEVEL4 macro in LL cortex driver.
  - **HAL CRYP**
    - Update related to reliability issue when running AES GCM in interrupt mode.
    - Add SAES RESET using IPRST bit.
  - **HAL Flash**
    - Update the naming of defined Flash option byte keys to FLASH_OPT_KEY1 and FLASH_OPT_KEY2.
  - **HAL GPIO**
    - Add Pull-down capability in analog mode.
  - **HAL HASH**
    - Optimize HASH_WaitOnFlagUntilTimeout() API.
  - **LL RCC**
      - Update Timer clocks Prescaler definition.
  - **HAL RNG**
      - Update to distinguish error coming from RecoverSeedError or SeedError.
  - **HAL/LL DMA**
      - Remove duplicated assert checking.
      - Add missing assert checking in some LL linked-list case.
      - Fix in linked list node initialization.
  - **HAL DMA2D**
      - Fix incorrect word 'surcharged' in functions headers.
  - **HAL JPEG**
    - Fix HAL_JPEG_IRQHandler() API calling blocking DMA abort:
      - Replaced blocking HAL_DMA_Abort() with HAL_DMA_Abort_IT() in HAL_JPEG_IRQHandler() API.
      - Added a note to the JPEG_DMA_StartProcess() function to ensure that the DMA interrupt has a higher priority than the JPEG interrupt. This prevents the JPEG interrupt from preempting the DMA interrupt before the DMA state is updated to ready.
    - Remove multiple volatile reads in interrupt handler.
    - Remove non referenced local variable in JPEG_DMA_ContinueProcess static function.
    - Remove non referenced local variable in JPEG_Process static function.
  - **HAL FMC nand**
    - Add a fix to avoid compiler optimizations and ensure correct data reads in HAL_NAND_Read_Page_8b() and  HAL_NAND_Read_SpareArea_8b(), HAL_NAND_Read_Page_16b() and  HAL_NAND_Read_SpareArea_16b() APIs.
  - **HAL PKA**
    - Remove static global variables and add them to PKA handle to be compliant with HAL coding rules.
    - Add check for MontgomeryParam not equal to null in HAL_PKA_PointCheck() and HAL_PKA_PointCheck_IT() APIs.
  - **HAL SDIO**
    - Add new HAL SDIO driver.
  - **HAL SDMMC**
    - Fix Misra issue for unused parameter in ll_sdmmc source file.
    - Update MMC High Speed clock.
  - **HAL SPI**
    - Add protection against wrong transfer size during transmission.
    - Check coherence between data size and DMA TX configuration. 
    - Clear auto suspend flag in HAL_SPI_Receive() API.
    - Ensure DMA RX aborts after DMA TX in HAL_SPI_Abort_IT() API.
    - Fix CRC computation to feat with standard CRC16-CCITT (XMODEM).
    - Fix a bug reception when FIFO threshold is set.
  - **HAL XSPI**
    - Check BUSY flag instead of TC flag in indirect mode to be sure that command is well completed (FIFO flush).
    - Correct comments for XSPI_MemorySize and XSPI_ChipSelectBoundary related definitions.
  - **HAL ETH**
    - Correct the disabling PTP transmission issue by clearing the TTSE bit in DESC2.
    - Fix identical definitions of the ETH state code.
    - Fix the calculation of the tail pointer so that it points to the last updated descriptor.
    - Update the HAL_ETH_PTP_SetConfig() API to comply with the steps described in the reference manual guidelines.
    - Fix issue with filter Configuration in HAL_ETH_SetMACFilterConfig() API.
    - Add new API HAL_ETH_GetTxBuffersNumber() to get Buffers in use number.
    - Update HAL_ETH_ReadData() API to  properly handle the Context descriptor when timestamping is enabled.
  - **HAL FDCAN**
    - Fix assert issue when Standard or Extended filter numbers are zero.
  - **HAL I2C**
    - Move variable tmp declaration at the beginning in I2C_TransferCofig() function.
    - Update HAL_I2C_IsDeviceReady() API to take into account the number of trials.
  - **HAL I2S**
    - Add IOSwap APIs:
      - HAL_I2S_EnableIOSwap() API.
      - HAL_I2S_DisableIOSwap() API.
      - HAL_I2S_IsEnabledIOSwap() API.
    - Remove HAL_LOCK() APIs inside register callback functions.
  - **HAL MDIOS**
    - Remove multiple volatile reads or writes in interrupt handler (for better performance).
  - **LL LPUART**
    - Solve Coverity out-of-bound memory access warning in use of LPUART_PRESCALER_TAB array.
  - **HAL UART**
    - Correct DMA Rx abort procedure impact on ongoing Tx transfer in polling mode.
    - Correct references to HAL_UARTEx_WakeupCallback() and to HAL_UART_WAKEUP_CB_ID() APIs define, according to series capabilities.
    - Provide accurate position in RxEventCallback when ReceptionToIdle mode is used with DMA, when UART and DMA interrupts process is delayed.
  - **LL USART**
    - Solve Coverity out-of-bound memory access warning in use of USART_PRESCALER_TAB array.
  - **LL UCPD**
    - Add LL UCPD API LL_UCPD_IsActiveFlag_RxErr() API.
    - Correct wording in some LL API LL_UCPD_IsActiveFlag_xxx() API descriptions.
  - **LL UTILS**
    - Remove F_SIZE bit field and change PKG_CODE position to align vs latest RM.
    - Update LL_SetFlashLatency() and add missing VOS scale frequency.
  - **HAL IWDG**
    - Calculate the maximum IWDG Timeout period HAL_IWDG_DEFAULT_TIMEOUT, based on a Prescaler=128 at LSI frequency=32kHz (refer to the datasheet).
    - Fix incorrect word 'surcharged' in functions headers.
  - **HAL/LL USB**
    - Add multi packet support for iso transfer.
    - hal_hcd.c: ensure to reactivate the usb channel in case of transfer error.
    - Fix the condition on EONUM flag of DOEPCTLx register in HAL_PCD_IRQHandler() API to correctly check on the frame number parity.
    - Fix Misra-C 2012 Rule-10.7 issue.
  - **HAL WWDG**
    - Fix incorrect word 'surcharged' in functions headers.

- **BSP** updates
  - **BSP Components**
      - **wm8904**
        - Update input devices to be defined as bitfields.
        - Implement LINE_IN2 and digital microphone path.
        - Add 24KHz audio frequency support.
        - Update IsInitialized variable at the end of init function WM8904_Init().
      - **mx25uw25645g**
        - Fix prototype of MX25UW25645G_EnableSTRMemoryMappedMode()/MX25UW25645G_EnableDTRMemoryMappedMode() APIs.
  - **BSP Boards**
      - **STM32H7S78-DK**
        - Enable Hardware flow control of SD handle in MX_SDMMC1_SD_Init().
      - **STM32H7RSxx_Nucleo**
        - Fix Dynamic Clock Prescaler calculation in stm32h7rsxx_nucleo_xspi.c.
        - Use ReleasePowerDown command instead of No operation in BSP_XSPI_NOR_LeaveDeepPowerDown() API.

- **Middleware** updates:
  - Upgrade of **USBPD core** library to new version **V5.3.0**
  - Upgrade of **USB host** library to new version **V3.5.3**
  - Upgrade of **FreeRTOS** library to new version **V10.6.2 (ST modified 2024-10-11)**
  - Upgrade of **STM32 ExtMem Manager** library to new version **V1.3.0**
  - Upgrade of **mcuboot** library to new version **V1.7.2.25**
  - Upgrade of **mbed-crypto** library to new version **V3.6.2 (ST modified 2024-11-25)**
  - Upgrade of **LwIP** library to new version **V2.1.3 (ST modified 2024-12-13)**
  - Upgrade of **FATFS** library to new version **R0.15 (ST modified 2024-12-20)**

- **Project** updates
  - Fix the MPU configuration in boot projects to avoid a blocking state that prevents jumping to the user application in **closed mode**.
  - **FreeRTOS Applications**
      - Update applications following MW FreeRTOS component upgrade to V10.6.2.
      - Allow the user to use the ulExpectedIdleTime in PreSleepProcessing in FreeRTOS Lowpower application.
  - **FatFS Applications**
      - Align expected success/error behavior in readme files with the application behavior for all FATFS applications.
      - Remove the const from the variable wtext in fatfs file to resolve the empty file issue on the SD card.
      - Update the SD_IsDetected() function by returning "APP_SD_PRESENT" when the SD card is detected and "APP_SD_NO_PRESENT" when it is not.
      - Add MX_SDMMC1_SD_Init(); in MX_FATFS_Process() function when SD card is plugged to fix unplug/plug SD card.
  - **LwIP Applications**
      - Replace raw API by netif API in all LWIP applications.
      - Highlight the new JP6 configuration change in the README files for LwIP applications on STM32H7S78-DK board.
      - Add check on LAN8742_init() returned value in low_level_init() function.
      - Increase the stack and heap size of the application LwIP_TFTP_Server.
      - Increase the stack size of TCP and UDP threads to solve instable behavior of the application LwIP_UDPTCP_Echo_Server_Netconn_RTOS with STM32CubeIDE Debug mode.
  - **ROT Applications**
      - Add readme files to each subfolder of ROT_Provisioning.
      - Open the whole RAM space to the user application by default in the OEMiROT or OEMuROT applications.
      - Update ROT/OEMiROT_Boot/Inc/stm32_extmem_conf.h to resolve the scalar initializer warning.
      - Add "LOAD_AND_RUN_INT_RAM" configuration to NUCLEO-H7S3L8 (OEMiROT_Boot) README files.
      - Updated the stm32ExtLoaderFlash variable in the README files by changing -elbl to -el in the external loader paths in H7R section.
      - Enable the Option Bytes "XSPI1_HSLV" and "XSPI2_HSLV" by default for STiROT_iLoader project.
      - Align the Applications/ROT scatter files on Templates/Template_ROT.
      - Change the executable files folder, object files folder, and listing files folder to be under the Board name folder.
      - Move the MPU region allowing the execution of the application to index 0 of region_cfg_appli to Ensure that this first MPU region grants execution rights to the user application.
      - Add wiki links to README files of Template projects (OEMiROT Appli/STiROT Appli).
      - Revised all README files for OEMiROT_Boot, OEMiROT_Appli, STiROT_Appli, and STiROT_iLoader to enhance clarity and improve user understanding.
      - Enhance boot time after reconfiguration of XSPI.
      - Update documentation and provisioning processes for STiRoT_Appli, OEMIROT_Boot, OEMiROT_Appli, and templates, including removal of specific notes and added instructions for provisioning.
      - Add a "Provisioning" step and renumber the "Preliminary stage" to Step 0 to make the process more detailed.
  - **USB Applications**
      - Fix USBPD_CAD_Task() and USBPD_TaskUser() functions in usbpd_dpm_core.c file of the application USB_Host_DualClass_Standalone.
      - Remove HAL_PWREx_EnableUSBReg() function from stm32h7rsxx_hal_msp.c file in both Boot, Appli projects.
      - Fix the application description in the readme of the application USB_Device_HID_Standalone.
      - Set the region 0x70000000 a non cacheable region in order to solve instable behavior of the application MSC_Standalone with EWARM.
  - **XSPI Examples**
     - Add a new NOR Flash example with Read While Write feature (RWW).
  - **IWDG Examples**
      - Update IWDG_Reset example readme of NUCLEO-H7S3L8 board to further clarify expected behavior.
  - **JPEG Examples**
      - Fix issue in JPEG_EncodingFromXSPI_DMA example output.

 \

The exhaustive list of projects is provided in this table ([STM32CubeProjectsList.html](Projects/STM32CubeProjectsList.html)).

 Name           Version                             Release notes
 ----           -------                             -------------
 Projects       V1.2.0 []{.icon-st-update}          [release notes](Projects/Release_Notes.html)

\

## Components

<small>The components flagged by "[]{.icon-st-update}" have changed since the
previous release. "[]{.icon-st-add}" are new.</small>

**Drivers**

  Name                                      Version                          Release notes                                                 
  -----                                     ---------                        -----------                                                   
  CMSIS                                     V5.9.0 []{.icon-st-update}       [release notes](Drivers/CMSIS/Documentation/index.html)
  STM32H7RSxx CMSIS                         V1.2.0 []{.icon-st-update}       [release notes](Drivers/CMSIS/Device/ST/STM32H7RSxx/Release_Notes.html)
  STM32H7RSxx HAL                           V1.2.0 []{.icon-st-update}       [release notes](Drivers/STM32H7RSxx_HAL_Driver/Release_Notes.html)

**BSP Drivers**

  Name                                      Version                          Release notes                                                
  -----                                     ---------                        -----------                                                  
  STM32H7RSxx_Nucleo                        V1.1.0 []{.icon-st-update}       [release notes](Drivers/BSP/STM32H7RSxx_Nucleo/Release_Notes.html)
  STM32H7S78-DK                             V1.0.1 []{.icon-st-update}       [release notes](Drivers/BSP/STM32H7S78-DK/Release_Notes.html)
  aps256xx                                  V1.0.6                           [release notes](Drivers/BSP/Components/aps256xx/Release_Notes.html)
  Common                                    V7.3.0                           [release notes](Drivers/BSP/Components/Common/Release_Notes.html)
  wm8904                                    V1.1.0 []{.icon-st-update}       [release notes](Drivers/BSP/Components/wm8904/Release_Notes.html)
  gt911                                     V1.0.1                           [release notes](Drivers/BSP/Components/gt911/Release_Notes.html)
  lan8742                                   V1.0.3                           [release notes](Drivers/BSP/Components/lan8742/Release_Notes.html)
  mx25uw25645g                              V1.1.0 []{.icon-st-update}       [release notes](Drivers/BSP/Components/mx25uw25645g/Release_Notes.html)
  mx66uw1g45g                               V1.1.0                           [release notes](Drivers/BSP/Components/mx66uw1g45g/Release_Notes.html)
  ov5640                                    V4.0.2                           [release notes](Drivers/BSP/Components/ov5640/Release_Notes.html)
  rk050hr18                                 V1.0.0                           [release notes](Drivers/BSP/Components/rk050hr18/Release_Notes.html)
  tcpp0203                                  V1.2.3                           [release notes](Drivers/BSP/Components/tcpp0203/Release_Notes.html)

\

**Middlewares**

  Name                                    Version                              Release notes                                      
  ------                                  ----------                           ---------------                                    
  FatFS                                   R0.15 []{.icon-st-update}            [release notes](Middlewares/Third_Party/FatFs/documents/updates.html) ST modified 20241220 [release notes](Middlewares/Third_Party/FatFs/source/st_readme.txt)
  FreeRTOS                                v10.6.2 []{.icon-st-update}          [release notes](Middlewares/Third_Party/FreeRTOS/Source/readme.txt) ST modified 20241011 [release notes](Middlewares/Third_Party/FreeRTOS/Source/st_readme.txt)
  LwIP                                    v2.1.3 []{.icon-st-update}           [release notes](Middlewares/Third_Party/LwIP/CHANGELOG) ST modified 20241213 [release notes](Middlewares/Third_Party/LwIP/st_readme.txt)
  mbed-crypto                             v3.6.2_20241125 []{.icon-st-update}  [ST release notes](Middlewares/Third_Party/mbed-crypto/st_readme.txt)
  mcuboot                                 v1.7.2.25 []{.icon-st-update}        [release notes](Middlewares/Third_Party/mcuboot/docs/release-notes.md) ST modified 20240612 [release notes](Middlewares/Third_Party/mcuboot/st_readme.txt)
  OpenBootloader                          v6.1.1                               [release notes](Middlewares/ST/OpenBootloader/Release_Notes.html)
  STM32_ExtMem_Loader                     v1.1.0                               [release notes](Middlewares/ST/STM32_ExtMem_Loader/Release_Notes.html)
  STM32_ExtMem_Manager                    v1.3.0 []{.icon-st-update}           [release notes](Middlewares/ST/STM32_ExtMem_Manager/Release_Notes.html)
  STM32 USB Device Library                v2.11.3                              [release notes](Middlewares/ST/STM32_USB_Device_Library/Release_Notes.html)
  STM32 USB Host Library                  v3.5.3 []{.icon-st-update}             [release notes](Middlewares/ST/STM32_USB_Host_Library/Release_Notes.html)
  STM32_USBPD_Library - Core              v5.3.0 []{.icon-st-update}           [release notes](Middlewares/ST/STM32_USBPD_Library/Core/Release_Notes.html)
  STM32_USBPD_Library - Devices           v1.2.1                               [release notes](Middlewares/ST/STM32_USBPD_Library/Devices/STM32H7RSXX/Release_Notes.html)

\

**Utilities**

  Name                                    Version                          Release notes                                      
  ------                                  ----------                       ---------------                                    
  Common                                  v1.6.1                           [release notes](Utilities/Common/Release_Notes.html)
  CPU                                     v1.1.4                           [release notes](Utilities/CPU/Release_Notes.html)
  Fonts                                   v2.0.4                           [release notes](Utilities/Fonts/Release_Notes.html)
  GUI_INTERFACE                           v3.0.1                           [release notes](Utilities/GUI_INTERFACE/Release_Notes.html)
  JPEG                                    v2.0.6 []{.icon-st-update}       [release notes](Utilities/JPEG/Release_Notes.html)
  lcd                                     v2.0.3                           [release notes](Utilities/lcd/Release_Notes.html)
  lcd_trace                               v2.0.2                           [release notes](Utilities/lcd_trace/Release_Notes.html)
  log                                     v1.0.4                           [release notes](Utilities/Log/Release_Notes.html)
  ROT_AppliConfig                         v1.1.2                           [release notes](Utilities/PC_Software/ROT_AppliConfig/Release_Notes.html)
  TRACER_EMB                              v1.12.0 []{.icon-st-update}      [release notes](Utilities/TRACER_EMB/Release_Notes.html)

\

## Development Toolchains and Compilers

- IAR Embedded Workbench for ARM (EWARM) toolchain V9.20.1 + ST-Link
- RealView Microcontroller Development Kit (MDK-ARM) toolchain **V5.39** + ST-Link
  - Support of ARM Compiler 6 (AC-5 like warnings) for HAL/LL/BSP drivers and STMicroelectronics Middleware components
- STM32CubeIDE **V1.18.0** (GCC13)

\

## Supported Devices and boards

-   ROT applications are compatible with SFSP V1.0.0 (or higher).
-   STM32H7R7xx/H7S7xx/H7R3xx/H7S3xx
-   STM32H7S78-DK
-   NUCLEO-H7S3L8

\

## Known Limitations

-  Some examples and/or applications not supported by CubeMX
-  The following STM32CubeIDE projects include only Debug configuration : 
    - NUCLEO-H7S3L8//Examples//XSPI//XSPI_NOR_ReadWhileWrite_DTR
    - STM32H7S78-DK//Examples//XSPI//XSPI_NOR_ReadWhileWrite_DTR
-  On STM32H7S78-DK revision D board, some audio glitches might be perceptible. The issue will be fixed in next release.

## Dependencies


## Backward Compatibility

- Not applicable

\

</div>
:::

::: {.collapse}
<input type="checkbox" id="collapse-section2" aria-hidden="true">
<label for="collapse-section2" aria-hidden="true">__V1.1.0 / 05-June-2024__</label>
<div>

## Maintenance release

Maintenance Release of STM32CubeH7RS Firmware package supporting **STM32H7R7xx/H7R3xx/H7S3xx/H7S7xx** devices.

## Contents

### **Features**

STM32CubeH7RS gathers in one single package all the generic embedded software components required to develop an application on STM32H7Rx/7Sx microcontrollers.

 - Production–ready HAL and LL API drivers, checked with CodeSonar® static analysis tool, and developed in compliance with MISRA C® guidelines.
 - CMSIS CORE, DSP and RTOS software components.
 - Consistent set of middleware components (RTOS, USB Host, USB Device, USB Power Delivery, FAT file system, TCP/IP and Ethernet, OpenBootloader and mcuboot).
 - Up to 250 examples and applications for easy understanding, compatible with STM32CubeMX to facilitate the configuration through a graphical tool.
 - New Templates_Board project for NUCLEO-H7S3L8 demonstrating the STM32CubeMX "Start my project from ST Board" providing an easy access to ST boards' features.
 - New **STM32_ExtMem_Manager** and **STM32_ExtMem_Loader** components provide software implementation that facilitates external memories integration.

The STM32CubeH7RS reference firmware supports all the different configurations of the SMT32H7Sx, it implements Secure Boot and Secure Firmware Update functions demonstrated thru OEMiRoT example.


### **Projects**

The STM32CubeH7RS Firmware package contains project templates running on STMicroelectronics boards with preconfigured projects for the main supported toolchains.

Six template projects are provided in this release:

- Projects\\STM32H7S7S8-DK\\**Templates_LL**
  - Execution only in the internal Flash based on Low Layer drivers

- Projects\\STM32H7S7S8-DK\\Templates\\**Template**
  - Execution only in the internal Flash based on HAL drivers

- Projects\\STM32H7S7S8-DK\\Templates\\**Template_XIP**
  - Boot from internal Flash and eXecution In Place from external NOR flash
  - The Template_XIP project is composed of three sub-projects:
    - **Boot**: boot execution from the internal Flash with jump to application in external memory
    - **Appli**: application code that executes in the external NOR flash memory
    - **ExtMemLoader**: build the external Flash loader for DK

  - Warning: User options bytes configuration is required to run at the highest frequency on the external memory ([readme.html](Projects/STM32H7S78-DK/Templates/Template_XIP/readme.html))

- Projects\\STM32H7S7S8-DK\\Templates\\**Template_LRUN**
  - It boots from internal Flash, copies the application from external Flash to internal RAM and jumps to the application code in internal RAM (Sub-project Boot)
  - The Template_LRUN project is composed of two sub-projects:
    - **Boot**: copies the application from the external Flash to internal RAM and jumps to the application code in internal RAM
    - **Appli**: application code that will be executed in internal RAM

- Projects\\STM32H7S7S8-DK\\Templates\\**Template_ROT**
  - This project provides two Root Of Trust boot path reference templates:
    - **OEMiROT** boot path reference template: boot is performed through OEMiROT / OEMuROT bootpath after authenticity and integrity checks of the project firmware image.
    - **STiROT** boot path reference template: boot is performed through STiROT boot path after authenticity and integrity checks of the project firmware image.

- Projects\\NUCLEO-H7S3L8\\**Templates_Board**
  - Boot from internal Flash and eXecution In Place from external NOR flash
  - STM32CubeMX "Start my project from ST Board" providing an easy access to ST boards’ features with demonstration code based on HAL and BSP drivers

- Same template projects are provided on both boards (except Template_ROT only provided on STM32H7S7S8-DK and Templates_Board only provided on NUCLEO-H7S3L8)

 \

The exhaustive list of projects is provided in this table ([STM32CubeProjectsList.html](Projects/STM32CubeProjectsList.html)).

 Name           Version                             Release notes
 ----           -------                             -------------
 Projects       V1.1.0 []{.icon-st-update}          [release notes](Projects/Release_Notes.html)

\

## Components

<small>The components flagged by "[]{.icon-st-update}" have changed since the
previous release. "[]{.icon-st-add}" are new.</small>

**Drivers**

  Name                                      Version                          Release notes                                                 
  -----                                     ---------                        -----------                                                   
  CMSIS                                     V5.9.0                           [release notes](Drivers/CMSIS/Documentation/index.html)
  STM32H7RSxx CMSIS                         V1.1.0 []{.icon-st-update}       [release notes](Drivers/CMSIS/Device/ST/STM32H7RSxx/Release_Notes.html)
  STM32H7RSxx HAL                           V1.1.0 []{.icon-st-update}       [release notes](Drivers/STM32H7RSxx_HAL_Driver/Release_Notes.html)

**BSP Drivers**

  Name                                      Version                          Release notes                                                
  -----                                     ---------                        -----------                                                  
  STM32H7RSxx_Nucleo                        V1.0.0                           [release notes](Drivers/BSP/STM32H7RSxx_Nucleo/Release_Notes.html)
  STM32H7S78-DK                             V1.0.0                           [release notes](Drivers/BSP/STM32H7S78-DK/Release_Notes.html)
  aps256xx                                  V1.0.6                           [release notes](Drivers/BSP/Components/aps256xx/Release_Notes.html)
  Common                                    V7.3.0                           [release notes](Drivers/BSP/Components/Common/Release_Notes.html)
  wm8904                                    V1.0.0                           [release notes](Drivers/BSP/Components/wm8904/Release_Notes.html)
  gt911                                     V1.0.1                           [release notes](Drivers/BSP/Components/gt911/Release_Notes.html)
  lan8742                                   V1.0.3                           [release notes](Drivers/BSP/Components/lan8742/Release_Notes.html)
  mx25uw25645g                              V1.0.1 []{.icon-st-update}       [release notes](Drivers/BSP/Components/mx25uw25645g/Release_Notes.html)
  mx66uw1g45g                               V1.1.0                           [release notes](Drivers/BSP/Components/mx66uw1g45g/Release_Notes.html)
  ov5640                                    V4.0.2                           [release notes](Drivers/BSP/Components/ov5640/Release_Notes.html)
  rk050hr18                                 V1.0.0                           [release notes](Drivers/BSP/Components/rk050hr18/Release_Notes.html)
  tcpp0203                                  V1.2.3                           [release notes](Drivers/BSP/Components/tcpp0203/Release_Notes.html)

\

**Middlewares**

  Name                                    Version                              Release notes                                      
  ------                                  ----------                           ---------------                                    
  FatFS                                   R0.15                                [release notes](Middlewares/Third_Party/FatFs/documents/updates.html) ST modified 230818 [release notes](Middlewares/Third_Party/FatFs/source/st_readme.txt)
  FreeRTOS                                v10.5.1                              [release notes](Middlewares/Third_Party/FreeRTOS/Source/readme.txt) ST modified 231117 [release notes](Middlewares/Third_Party/FreeRTOS/Source/st_readme.txt)
  LwIP                                    v2.1.3                               [release notes](Middlewares/Third_Party/LwIP/CHANGELOG) ST modified 230818 [release notes](Middlewares/Third_Party/LwIP/st_readme.txt)
  mbed-crypto                             v2.28.8_20240527 []{.icon-st-add}    [ST release notes](Middlewares/Third_Party/mbed-crypto/st_readme.txt)
  mcuboot                                 v1.7.2.23                            [release notes](Middlewares/Third_Party/mcuboot/docs/release-notes.md) ST modified 240214 [release notes](Middlewares/Third_Party/mcuboot/st_readme.txt)
  OpenBootloader                          v6.1.1                               [release notes](Middlewares/ST/OpenBootloader/Release_Notes.html)
  STM32_ExtMem_Loader                     v1.1.0 []{.icon-st-update}           [release notes](Middlewares/ST/STM32_ExtMem_Loader/Release_Notes.html)
  STM32_ExtMem_Manager                    v1.1.0 []{.icon-st-update}           [release notes](Middlewares/ST/STM32_ExtMem_Manager/Release_Notes.html)
  STM32 USB Device Library                v2.11.3                              [release notes](Middlewares/ST/STM32_USB_Device_Library/Release_Notes.html)
  STM32 USB Host Library                  v3.5.2                               [release notes](Middlewares/ST/STM32_USB_Host_Library/Release_Notes.html)
  STM32_USBPD_Library - Core              v5.1.0                               [release notes](Middlewares/ST/STM32_USBPD_Library/Core/Release_Notes.html)
  STM32_USBPD_Library - Devices           v1.2.1                               [release notes](Middlewares/ST/STM32_USBPD_Library/Devices/STM32H7RSXX/Release_Notes.html)

\

**Utilities**

  Name                                    Version                          Release notes                                      
  ------                                  ----------                       ---------------                                    
  Common                                  v1.6.1                           [release notes](Utilities/Common/Release_Notes.html)
  CPU                                     v1.1.4                           [release notes](Utilities/CPU/Release_Notes.html)
  Fonts                                   v2.0.4                           [release notes](Utilities/Fonts/Release_Notes.html)
  GUI_INTERFACE                           v3.0.1                           [release notes](Utilities/GUI_INTERFACE/Release_Notes.html)
  JPEG                                    v2.0.3                           [release notes](Utilities/JPEG/Release_Notes.html)
  lcd                                     v2.0.3                           [release notes](Utilities/lcd/Release_Notes.html)
  lcd_trace                               v2.0.2                           [release notes](Utilities/lcd_trace/Release_Notes.html)
  log                                     v1.0.4                           [release notes](Utilities/Log/Release_Notes.html)
  ROT_AppliConfig                         v1.1.2                           [release notes](Utilities/PC_Software/ROT_AppliConfig/Release_Notes.html)
  TRACER_EMB                              v1.11.0                          [release notes](Utilities/TRACER_EMB/Release_Notes.html)

\

## Development Toolchains and Compilers

- IAR Embedded Workbench for ARM (EWARM) toolchain V9.20.1 + ST-Link
- RealView Microcontroller Development Kit (MDK-ARM) toolchain **V5.39** + ST-Link
  - Support of ARM Compiler 6 (AC-5 like warnings) for HAL/LL/BSP drivers and STMicroelectronics Middleware components
- STM32CubeIDE **V1.16.0** (GCC12)

\

## Supported Devices and boards

-   ROT applications are compatible with SFSP V1.0.0 (or higher).
-   STM32H7R7xx/H7S7xx/H7R3xx/H7S3xx
-   STM32H7S78-DK
-   NUCLEO-H7S3L8

\

## Known Limitations

-  Some examples and/or applications not supported by CubeMX
-  All projects not yet available on MDK-ARM & CubeIDE

## Dependencies


## Backward Compatibility

- Not applicable

\

</div>
:::

::: {.collapse}
<input type="checkbox" id="collapse-section1" aria-hidden="true">
<label for="collapse-section1" aria-hidden="true">__V1.0.0 / 28-February-2024__</label>
<div>

## First release

First Official Release of STM32CubeH7RS Firmware package supporting **STM32H7R7xx/H7R3xx/H7S3xx/H7S7xx** devices.

## Contents

### **Features**

STM32CubeH7RS gathers in one single package all the generic embedded software components required to develop an application on STM32H7Rx/7Sx microcontrollers.

 - Production–ready HAL and LL API drivers, checked with CodeSonar® static analysis tool, and developed in compliance with MISRA C® guidelines.
 - CMSIS CORE, DSP and RTOS software components.
 - Consistent set of middleware components (RTOS, USB Host, USB Device, USB Power Delivery, FAT file system, TCP/IP and Ethernet, OpenBootloader and mcuboot).
 - Up to 250 examples and applications for easy understanding, compatible with STM32CubeMX to facilitate the configuration through a graphical tool.
 - New Templates_Board project for NUCLEO-H7S3L8 demonstrating the STM32CubeMX "Start my project from ST Board" providing an easy access to ST boards' features.
 - New **STM32_ExtMem_Manager** and **STM32_ExtMem_Loader** components provide software implementation that facilitates external memories integration.

The STM32CubeH7RS reference firmware supports all the different configurations of the SMT32H7Sx, it implements Secure Boot and Secure Firmware Update functions demonstrated thru OEMiRoT example.


### **Projects**

The STM32CubeH7RS Firmware package contains project templates running on STMicroelectronics boards with preconfigured projects for the main supported toolchains.

SIx template projects are provided in this release:

- Projects\\STM32H7S7S8-DK\\**Templates_LL**
  - Execution only in the internal Flash based on Low Layer drivers

- Projects\\STM32H7S7S8-DK\\Templates\\**Template**
  - Execution only in the internal Flash based on HAL drivers

- Projects\\STM32H7S7S8-DK\\Templates\\**Template_XIP**
  - Boot from internal Flash and eXecution In Place from external NOR flash
  - The Template_XIP project is composed of three sub-projects:
    - **Boot**: boot execution from the internal Flash with jump to application in external memory
    - **Appli**: application code that executes in the external NOR flash memory
    - **ExtMemLoader**: build the external Flash loader for DK

  - Warning: User options bytes configuration is required to run at the highest frequency on the external memory ([readme.html](Projects/STM32H7S78-DK/Templates/Template_XIP/readme.html))

- Projects\\STM32H7S7S8-DK\\Templates\\**Template_LRUN**
  - It boots from internal Flash, copies the application from external Flash to internal RAM and jumps to the application code in internal RAM (Sub-project Boot)
  - The Template_LRUN project is composed of two sub-projects:
    - **Boot**: copies the application from the external Flash to internal RAM and jumps to the application code in internal RAM
    - **Appli**: application code that will be executed in internal RAM

- Projects\\STM32H7S7S8-DK\\Templates\\**Template_ROT**
  - This project provides two Root Of Trust boot path reference templates:
    - **OEMiROT** boot path reference template: boot is performed through OEMiROT / OEMuROT bootpath after authenticity and integrity checks of the project firmware image.
    - **STiROT** boot path reference template: boot is performed through STiROT boot path after authenticity and integrity checks of the project firmware image.

- Projects\\NUCLEO-H7S3L8\\**Templates_Board**
  - Boot from internal Flash and eXecution In Place from external NOR flash
  - STM32CubeMX "Start my project from ST Board" providing an easy access to ST boards’ features with demonstration code based on HAL and BSP drivers

- Same template projects are provided on both boards (except Template_ROT only provided on STM32H7S7S8-DK and Templates_Board only provided on NUCLEO-H7S3L8)

 \

The exhaustive list of projects is provided in this table ([STM32CubeProjectsList.html](Projects/STM32CubeProjectsList.html)).

 Name           Version                             Release notes
 ----           -------                             -------------
 Projects       V1.0.0                              [release notes](Projects/Release_Notes.html)

\

## Components

<small>The components flagged by "[]{.icon-st-update}" have changed since the
previous release. "[]{.icon-st-add}" are new.</small>

**Drivers**

  Name                                      Version                          Release notes                                                 
  -----                                     ---------                        -----------                                                   
  CMSIS                                     V5.9.0                           [release notes](Drivers/CMSIS/Documentation/index.html)
  STM32H7RSxx CMSIS                         V1.0.0                           [release notes](Drivers/CMSIS/Device/ST/STM32H7RSxx/Release_Notes.html)
  STM32H7RSxx HAL                           V1.0.0                           [release notes](Drivers/STM32H7RSxx_HAL_Driver/Release_Notes.html)

**BSP Drivers**

  Name                                      Version                          Release notes                                                
  -----                                     ---------                        -----------                                                  
  STM32H7RSxx_Nucleo                        V1.0.0                           [release notes](Drivers/BSP/STM32H7RSxx_Nucleo/Release_Notes.html)
  STM32H7S78-DK                             V1.0.0                           [release notes](Drivers/BSP/STM32H7S78-DK/Release_Notes.html)
  aps256xx                                  V1.0.6                           [release notes](Drivers/BSP/Components/aps256xx/Release_Notes.html)
  Common                                    V7.3.0                           [release notes](Drivers/BSP/Components/Common/Release_Notes.html)
  wm8904                                    V1.0.0                           [release notes](Drivers/BSP/Components/wm8904/Release_Notes.html)
  gt911                                     V1.0.1                           [release notes](Drivers/BSP/Components/gt911/Release_Notes.html)
  lan8742                                   V1.0.3                           [release notes](Drivers/BSP/Components/lan8742/Release_Notes.html)
  mx25uw25645g                              V1.0.0                           [release notes](Drivers/BSP/Components/mx25uw25645g/Release_Notes.html)
  mx66uw1g45g                               V1.1.0                           [release notes](Drivers/BSP/Components/mx66uw1g45g/Release_Notes.html)
  ov5640                                    V4.0.2                           [release notes](Drivers/BSP/Components/ov5640/Release_Notes.html)
  rk050hr18                                 V1.0.0                           [release notes](Drivers/BSP/Components/rk050hr18/Release_Notes.html)
  tcpp0203                                  V1.2.3                           [release notes](Drivers/BSP/Components/tcpp0203/Release_Notes.html)

\

**Middlewares**

  Name                                    Version                         Release notes                                      
  ------                                  ----------                      ---------------                                    
  FatFS                                   R0.15                           [release notes](Middlewares/Third_Party/FatFs/documents/updates.html) ST modified 230818 [release notes](Middlewares/Third_Party/FatFs/source/st_readme.txt)
  FreeRTOS                                v10.5.1                         [release notes](Middlewares/Third_Party/FreeRTOS/Source/readme.txt) ST modified 231117 [release notes](Middlewares/Third_Party/FreeRTOS/Source/st_readme.txt)
  LwIP                                    v2.1.3                          [release notes](Middlewares/Third_Party/LwIP/CHANGELOG) ST modified 230818 [release notes](Middlewares/Third_Party/LwIP/st_readme.txt)
  mcuboot                                 v1.7.2.23                       [release notes](Middlewares/Third_Party/mcuboot/docs/release-notes.md) ST modified 240214 [release notes](Middlewares/Third_Party/mcuboot/st_readme.txt)
  OpenBootloader                          v6.1.1                          [release notes](Middlewares/ST/OpenBootloader/Release_Notes.html)
  STM32_ExtMem_Loader                     v1.0.0                          [release notes](Middlewares/ST/STM32_ExtMem_Loader/Release_Notes.html)
  STM32_ExtMem_Manager                    v1.0.0                          [release notes](Middlewares/ST/STM32_ExtMem_Manager/Release_Notes.html)
  STM32 USB Device Library                v2.11.3                         [release notes](Middlewares/ST/STM32_USB_Device_Library/Release_Notes.html)
  STM32 USB Host Library                  v3.5.2                          [release notes](Middlewares/ST/STM32_USB_Host_Library/Release_Notes.html)
  STM32_USBPD_Library - Core              v5.1.0                          [release notes](Middlewares/ST/STM32_USBPD_Library/Core/Release_Notes.html)
  STM32_USBPD_Library - Devices           v1.2.1                          [release notes](Middlewares/ST/STM32_USBPD_Library/Devices/STM32H7RSXX/Release_Notes.html)

\

**Utilities**

  Name                                    Version                          Release notes                                      
  ------                                  ----------                       ---------------                                    
  Common                                  v1.6.1                           [release notes](Utilities/Common/Release_Notes.html)
  CPU                                     v1.1.4                           [release notes](Utilities/CPU/Release_Notes.html)
  Fonts                                   v2.0.4                           [release notes](Utilities/Fonts/Release_Notes.html)
  GUI_INTERFACE                           v3.0.1                           [release notes](Utilities/GUI_INTERFACE/Release_Notes.html)
  JPEG                                    v2.0.3                           [release notes](Utilities/JPEG/Release_Notes.html)
  lcd                                     v2.0.3                           [release notes](Utilities/lcd/Release_Notes.html)
  lcd_trace                               v2.0.2                           [release notes](Utilities/lcd_trace/Release_Notes.html)
  log                                     v1.0.4                           [release notes](Utilities/Log/Release_Notes.html)
  ROT_AppliConfig                         v1.1.2                           [release notes](Utilities/PC_Software/ROT_AppliConfig/Release_Notes.html)
  TRACER_EMB                              v1.11.0                          [release notes](Utilities/TRACER_EMB/Release_Notes.html)

\

## Development Toolchains and Compilers

- IAR Embedded Workbench for ARM (EWARM) toolchain V9.20.1 + ST-Link
- RealView Microcontroller Development Kit (MDK-ARM) toolchain V5.38a + ST-Link
  - Support of ARM Compiler 6 (AC-5 like warnings) for HAL/LL/BSP drivers and STMicroelectronics Middleware components
- STM32CubeIDE V1.15.0 (GCC12)

\

## Supported Devices and boards

-   ROT applications are compatible with SFSP V1.0.0 (or higher).
-   STM32H7R7xx/H7S7xx/H7R3xx/H7S3xx
-   STM32H7S78-DK
-   NUCLEO-H7S3L8

\

## Known Limitations

-  Some examples and/or applications not supported by CubeMX
-  All projects not yet available on MDK-ARM & CubeIDE

Those limitations will be corrected in maintenance release V1.1.0 planned in June 2024.

## Dependencies

- STM32CubeMX V6.11.0
  - Projects (Applications and Examples) are generated using STM32CubeMX version V6.11.0.

## Backward Compatibility

- Not applicable

\

</div>
:::


:::
:::

<footer class="sticky">
::: {.columns}
::: {.column width="95%"}
For complete documentation on STM32H7Rx/Sx, 

visit: [[stm32h7-series/stm32h7r3-7s3](https://www.st.com/content/st_com/en/products/microcontrollers-microprocessors/stm32-32-bit-arm-cortex-mcus/stm32-high-performance-mcus/stm32h7-series/stm32h7r3-7s3.html)]{style="font-color: blue;"}

visit: [[stm32h7-series/stm32h7r7-7s7](https://www.st.com/content/st_com/en/products/microcontrollers-microprocessors/stm32-32-bit-arm-cortex-mcus/stm32-high-performance-mcus/stm32h7-series/stm32h7r7-7s7.html)]{style="font-color: blue;"}

*This release note uses up to date web standards and, for this reason, should not be opened with Internet Explorer but preferably with popular browsers such as Google Chrome, Mozilla Firefox, Opera or Microsoft Edge.*
:::
::: {.column width="5%"}
<abbr title="Based on template cx566953 version 2.0">Info</abbr>
:::
:::
</footer>
