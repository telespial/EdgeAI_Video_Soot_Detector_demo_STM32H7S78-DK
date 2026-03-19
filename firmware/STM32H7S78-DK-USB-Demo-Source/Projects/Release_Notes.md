---
pagetitle: Release Notes for Projects of STM32CubeH7RS Firmware Package
lang: en
header-includes: <link rel="icon" type="image/x-icon" href="../_htmresc/favicon.png" />
---

::: {.row}
::: {.col-sm-12 .col-lg-4}

<center>
# Release Notes for 
# <mark>Projects of STM32CubeH7RS Firmware Package</mark>
Copyright &copy; 2022 STMicroelectronics\

[![ST logo](../_htmresc/st_logo_2020.png)](https://www.st.com){.logo}
</center>


# Purpose

The projects are a set of applicative tasks that aim to explain and provide use
cases of the different products features based on the products hardware (Boards,
STM32 Core(s) features, interconnections and peripherals) and built around the
different firmware components. They can be directly used or adapted by the
STM32CubeH7RS Firmware Package users.
They provide basic functionalities, show main features or demonstrate
performance. They are provided with preconfigured projects for the main
supported toolchains.

In the STM32CubeH7RS Firmware Package, the projects are organized in a sequential scheme based on the following levels:

- Boards: Hardware platform (discovery, nucleo boards)
- Project Category:
  - Applications
  - Examples
  - Examples_LL
  - Examples_MIX
  - ROT_Provisioning
  - Templates
  - Templates_Board
  - Templates_LL
- Project Class
- Project Subclass

The Project Class refers to the main peripherals (drivers), middleware
libraries or BSP classes while the projects Subclass stands for a project
specific feature within a class.

The exhaustive list of projects is provided in this table:
[STM32CubeProjectsList](STM32CubeProjectsList.html).

:::

::: {.col-sm-12 .col-lg-8}
# Update History

::: {.collapse}
<input type="checkbox" id="collapse-section3" checked aria-hidden="true">
<label for="collapse-section3" aria-hidden="true">__V1.2.0 / 05-February-2025__</label>
<div>

## Maintenance release

###  Maintenance Release of **STM32CubeH7RS** Firmware projects supporting **STM32H7Rx/Sx** devices mounted on STM32H7S78-DK board & NUCLEO-H7S3L8 board.

**New examples**
 
 Board                                 Example name
 ------------------------------------  ------------------------
 NUCLEO-H7S3L8                         XSPI_NOR_ReadWhileWrite_DTR

**Bug fixes**

  Headline
  ------------
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

## Contents

 Board                                 Project category                       Path
 -------------------                   ------------------------               ----------------------------------------
 STM32H7S78-DK                         Applications []{.icon-st-update}       Projects\\STM32H7S78-DK\\Applications
 STM32H7S78-DK                         Examples []{.icon-st-update}           Projects\\STM32H7S78-DK\\Examples
 STM32H7S78-DK                         ROT_Provisioning []{.icon-st-update}   Projects\\STM32H7S78-DK\\ROT_Provisioning
 STM32H7S78-DK                         Templates []{.icon-st-update}          Projects\\STM32H7S78-DK\\Templates
 STM32H7S78-DK                         Templates LL                           Projects\\STM32H7S78-DK\\Templates_LL
 NUCLEO-H7S3L8                         Applications []{.icon-st-update}       Projects\\NUCLEO-H7S3L8\\Applications
 NUCLEO-H7S3L8                         Examples []{.icon-st-update}           Projects\\NUCLEO-H7S3L8\\Examples
 NUCLEO-H7S3L8                         Examples_LL []{.icon-st-update}        Projects\\NUCLEO-H7S3L8\\Examples_LL
 NUCLEO-H7S3L8                         Examples_MIX                           Projects\\NUCLEO-H7S3L8\\Examples_MIX
 NUCLEO-H7S3L8                         ROT_Provisioning []{.icon-st-update}   Projects\\NUCLEO-H7S3L8\\ROT_Provisioning
 NUCLEO-H7S3L8                         Templates []{.icon-st-update}          Projects\\NUCLEO-H7S3L8\\Templates
 NUCLEO-H7S3L8                         Templates_Board                        Projects\\NUCLEO-H7S3L8\\Templates_Board 
 NUCLEO-H7S3L8                         Templates LL                           Projects\\NUCLEO-H7S3L8\\Templates_LL
 STM32H7RS_CUSTOM_HW                   Examples                               Projects\\STM32H7RS_CUSTOM_HW\\Examples

<small>The components flagged by "[]{.icon-st-update}" have changed since the
previous release. "[]{.icon-st-add}" are new.</small>

\

## Development Toolchains and Compilers

  Toolchain + ST-Link                                      Version                      Device           Patch(if available)
  ------------------------------------------------------   -------                      ---------        ----------------------
  IAR Embedded Workbench for ARM (EWARM)                   V9.20.1                      H7RSxx           [Patch EWARM](../Utilities/PC_Software/EWARMv9_STM32H7RSxx_V1.0.0.zip)
  RealView Microcontroller Development Kit (MDK-ARM)       V5.39                        H7RSxx           [Patch KEIL](../Utilities/PC_Software/Keil.STM32H7RSxx_DFP.1.0.0.zip)
  STM32CubeIDE V1.18.0 (GCC13) []{.icon-st-update}         V1.18.0 []{.icon-st-update}

## Supported Devices and boards

- STM32H7R7xx, STM32H7R3xx, STM32H7S3xx and STM32H7S7xx devices
- STM32H7S78-DK Discovery kit
- NUCLEO-H7S3L8 kit

\

<b>Warning</b>: The default BOOT0 switch position should be 1-2 on our DK board for normal boot operation from Flash for whatever operation (debug under IAR, flash programmer from STM32CubeProgrammer)

<b>Recommendation</b>: For projects using external memory, please check & set carefully required User Option Bytes configuration with STM32CubeProgrammer tool:

\

STM32H7S78-DK:

    - XSPI1_HSLV=1     I/O XSPIM_P1 High speed option enabled
    - XSPI2_HSLV=1     I/O XSPIM_P2 High speed option enabled
    - VDDIO_HSLV=0     I/O speed optimized to operate at 3.3V

NUCLEO-H7S3L8:

    - XSPI2_HSLV=1     I/O XSPIM_P2 High speed option enabled
    - VDDIO_HSLV=0     I/O speed optimized to operate at 3.3V

\

## Known Limitations

- Some projects are not generated with STM32CubeMX tool. For the exhaustive list please refer to this table [STM32CubeProjectsList](STM32CubeProjectsList.html)
-  The following STM32CubeIDE projects include only Debug configuration : 
    - NUCLEO-H7S3L8//Examples//XSPI//XSPI_NOR_ReadWhileWrite_DTR
    - STM32H7S78-DK//Examples//XSPI//XSPI_NOR_ReadWhileWrite_DTR
-  On STM32H7S78-DK revision D board, some audio glitches might be perceptible. The issue will be fixed in next release.
\

## Dependencies

- STM32CubeMX **V6.14.0**
  - Projects (Applications and Examples) are generated using STM32CubeMX version V6.14.0.

\

## Backward compatibility

- Not applicable

## Notes

- None

\

</div>
:::


::: {.collapse}
<input type="checkbox" id="collapse-section2" aria-hidden="true">
<label for="collapse-section2" aria-hidden="true">__V1.1.0 / 05-June-2024__</label>
<div>

## Maintenance release

###  Maintenance Release of **STM32CubeH7RS** Firmware projects supporting **STM32H7Rx/Sx** devices mounted on STM32H7S78-DK board & NUCLEO-H7S3L8 board.

**New feature**

  Add support of ExtMemLoaderloader generation for OPENBL in Nucleo & DK board templates_XIP
  Add converted projects on CubeIDE & MDK-ARM


**New examples**
 
 Board                                 Example name
 ------------------------------------  ------------------------
 NUCLEO-H7S3L8                         ADC_AnalogWatchdog
 NUCLEO-H7S3L8                         ADC_AnalogWatchdog_Init 
 NUCLEO-H7S3L8                         CRYP_SAES_ECB_CBC_AHK
 NUCLEO-H7S3L8                         DMA_Trigger
 NUCLEO-H7S3L8                         HAL_TimeBase_RTC_WKUP
 NUCLEO-H7S3L8                         I2C_WakeUpFromStop
 NUCLEO-H7S3L8                         PWR_STANDBY_RTC
 NUCLEO-H7S3L8                         PWR_EnterStandbyMode
 NUCLEO-H7S3L8                         RTC_LSI 
 NUCLEO-H7S3L8                         TIM_DMA_Init
 NUCLEO-H7S3L8                         TIM_OnePulse_Init
 NUCLEO-H7S3L8                         UART_ReceptionToIdle_CircularDMA
 STM32H7S78-DK                         LTDC_ColorKeying
 STM32H7S78-DK                         SD_ReadWrite_DMALinkedList
 STM32H7S78-DK                         USBPD_DRP_DRD

**Bug fixes**

  Headline
  ------------
  Correct Flash latency to 7 instead of 6 for CPU @600MHz
  Enable CSI prior to configure IO HSLV
  Avoid to write systematic user OB in FLASH at each startup

## Contents

 Board                                 Project category                 Path
 -------------------                   ------------------------         ----------------------------------------
 STM32H7S78-DK                         Applications []{.icon-st-update} Projects\\STM32H7S78-DK\\Applications
 STM32H7S78-DK                         Examples []{.icon-st-update}     Projects\\STM32H7S78-DK\\Examples
 STM32H7S78-DK                         ROT_Provisioning                 Projects\\STM32H7S78-DK\\ROT_Provisioning
 STM32H7S78-DK                         Templates []{.icon-st-update}      Projects\\STM32H7S78-DK\\Templates
 STM32H7S78-DK                         Templates LL                     Projects\\STM32H7S78-DK\\Templates_LL
 NUCLEO-H7S3L8                         Applications []{.icon-st-update} Projects\\NUCLEO-H7S3L8\\Applications
 NUCLEO-H7S3L8                         Examples []{.icon-st-update}     Projects\\NUCLEO-H7S3L8\\Examples
 NUCLEO-H7S3L8                         Examples_LL []{.icon-st-update}  Projects\\NUCLEO-H7S3L8\\Examples_LL
 NUCLEO-H7S3L8                         Examples_MIX                     Projects\\NUCLEO-H7S3L8\\Examples_MIX
 NUCLEO-H7S3L8                         ROT_Provisioning                 Projects\\NUCLEO-H7S3L8\\ROT_Provisioning
 NUCLEO-H7S3L8                         Templates []{.icon-st-update}      Projects\\NUCLEO-H7S3L8\\Templates
 NUCLEO-H7S3L8                         Templates_Board                  Projects\\NUCLEO-H7S3L8\\Templates_Board 
 NUCLEO-H7S3L8                         Templates LL                     Projects\\NUCLEO-H7S3L8\\Templates_LL
 STM32H7RS_CUSTOM_HW                   Examples                         Projects\\STM32H7RS_CUSTOM_HW\\Examples

<small>The components flagged by "[]{.icon-st-update}" have changed since the
previous release. "[]{.icon-st-add}" are new.</small>

\

## Development Toolchains and Compilers

  Toolchain + ST-Link                                      Version   Device           Patch(if available)
  ------------------------------------------------------   -------   ---------        ----------------------
  IAR Embedded Workbench for ARM (EWARM)                   V9.20.1   H7RSxx           [Patch EWARM](../Utilities/PC_Software/EWARMv9_STM32H7RSxx_V1.0.0.zip)
  RealView Microcontroller Development Kit (MDK-ARM)       V5.39     H7RSxx           [Patch KEIL](../Utilities/PC_Software/Keil.STM32H7RSxx_DFP.1.0.0.zip)
  STM32CubeIDE V1.16.0 (GCC12)                             V1.16.0

## Supported Devices and boards

- STM32H7R7xx, STM32H7R3xx, STM32H7S3xx and STM32H7S7xx devices
- STM32H7S78-DK Discovery kit
- NUCLEO-H7S3L8 kit

\

<b>Warning</b>: The default BOOT0 switch position should be 1-2 on our DK board for normal boot operation from Flash for whatever operation (debug under IAR, flash programmer from STM32CubeProgrammer)

<b>Recommendation</b>: For projects using external memory, please check & set carefully required User Option Bytes configuration with STM32CubeProgrammer tool:

\

STM32H7S78-DK:

    - XSPI1_HSLV=1     I/O XSPIM_P1 High speed option enabled
    - XSPI2_HSLV=1     I/O XSPIM_P2 High speed option enabled
    - VDDIO_HSLV=0     I/O speed optimized to operate at 3.3V

NUCLEO-H7S3L8:

    - XSPI2_HSLV=1     I/O XSPIM_P2 High speed option enabled
    - VDDIO_HSLV=0     I/O speed optimized to operate at 3.3V

\

## Known Limitations

- Some projects are not generated with STM32CubeMX tool. For the exhaustive list please refer to this table [STM32CubeProjectsList](STM32CubeProjectsList.html)

\

## Dependencies

- STM32CubeMX **V6.12.0**
  - Projects (Applications and Examples) are generated using STM32CubeMX version V6.12.0.

\

## Backward compatibility

- Not applicable

## Notes

- None

\

</div>
:::


::: {.collapse}
<input type="checkbox" id="collapse-section1" aria-hidden="true">
<label for="collapse-section1" aria-hidden="true">__V1.0.0 / 28-February-2024__</label>
<div>

## First release

###  Official Release of **STM32CubeH7RS** Firmware projects supporting **STM32H7Rx/Sx** devices mounted on STM32H7S78-DK board & NUCLEO-H7S3L8 board.

## Contents

 Board                                 Project category                 Path
 -------------------                   ------------------------         ----------------------------------------
 STM32H7S78-DK                         Applications                     Projects\\STM32H7S78-DK\\Applications
 STM32H7S78-DK                         Examples                         Projects\\STM32H7S78-DK\\Examples
 STM32H7S78-DK                         ROT_Provisioning                 Projects\\STM32H7S78-DK\\ROT_Provisioning
 STM32H7S78-DK                         Templates                        Projects\\STM32H7S78-DK\\Templates
 STM32H7S78-DK                         Templates LL                     Projects\\STM32H7S78-DK\\Templates_LL
 NUCLEO-H7S3L8                         Applications                     Projects\\NUCLEO-H7S3L8\\Applications
 NUCLEO-H7S3L8                         Examples                         Projects\\NUCLEO-H7S3L8\\Examples
 NUCLEO-H7S3L8                         Examples_LL                      Projects\\NUCLEO-H7S3L8\\Examples_LL
 NUCLEO-H7S3L8                         Examples_MIX                     Projects\\NUCLEO-H7S3L8\\Examples_MIX
 NUCLEO-H7S3L8                         ROT_Provisioning                 Projects\\NUCLEO-H7S3L8\\ROT_Provisioning
 NUCLEO-H7S3L8                         Templates                        Projects\\NUCLEO-H7S3L8\\Templates
 NUCLEO-H7S3L8                         Templates_Board                  Projects\\NUCLEO-H7S3L8\\Templates_Board 
 NUCLEO-H7S3L8                         Templates LL                     Projects\\NUCLEO-H7S3L8\\Templates_LL
 STM32H7RS_CUSTOM_HW                   Examples                         Projects\\STM32H7RS_CUSTOM_HW\\Examples

<small>The components flagged by "[]{.icon-st-update}" have changed since the
previous release. "[]{.icon-st-add}" are new.</small>

\

## Development Toolchains and Compilers

  Toolchain + ST-Link                                      Version   Device           Patch(if available)
  ------------------------------------------------------   -------   ---------        ----------------------
  IAR Embedded Workbench for ARM (EWARM)                   V9.20.1   H7RSxx           [Patch EWARM](../Utilities/PC_Software/EWARMv9_STM32H7RSxx_V1.0.0.zip)
  RealView Microcontroller Development Kit (MDK-ARM)       V5.38a    H7RSxx           [Patch KEIL](../Utilities/PC_Software/Keil.STM32H7RSxx_DFP.1.0.0.zip)
  STM32CubeIDE V1.15.0 (GCC12)                             V1.15.0

## Supported Devices and boards

- STM32H7R7xx, STM32H7R3xx, STM32H7S3xx and STM32H7S7xx devices
- STM32H7S78-DK Discovery kit
- NUCLEO-H7S3L8 kit

\

<b>Warning</b>: The default BOOT0 switch position should be 1-2 on our DK board for normal boot operation from Flash for whatever operation (debug under IAR, flash programmer from STM32CubeProgrammer)

<b>Recommendation</b>: For projects using external memory, please check & set carefully required User Option Bytes configuration with STM32CubeProgrammer tool:

\

STM32H7S78-DK:

    - XSPI1_HSLV=1     I/O XSPIM_P1 High speed option enabled
    - XSPI2_HSLV=1     I/O XSPIM_P2 High speed option enabled
    - VDDIO_HSLV=0     I/O speed optimized to operate at 3.3V

NUCLEO-H7S3L8:

    - XSPI2_HSLV=1     I/O XSPIM_P2 High speed option enabled
    - VDDIO_HSLV=0     I/O speed optimized to operate at 3.3V

\

## Known Limitations

- All projects not yet available on MDK-ARM & CubeIDE
- Some projects are not generated with STM32CubeMX tool. For the exhaustive list please refer to this table [STM32CubeProjectsList](STM32CubeProjectsList.html)

Those limitations will be corrected in maintenance release V1.1.0 planned in June 2024.

\

## Dependencies

- STM32CubeMX V6.11.0
  - Projects (Applications and Examples) are generated using STM32CubeMX version V6.11.0.

\

## Backward compatibility

- Not applicable

## Notes

- None

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
<abbr title="Based on template cx626901 version 2.0">Info</abbr>
:::
:::
</footer>