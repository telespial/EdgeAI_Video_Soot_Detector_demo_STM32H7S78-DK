---
pagetitle: Release Notes for STM32H7RSxx Nucleo Drivers
lang: en
header-includes: <link rel="icon" type="image/x-icon" href="_htmresc/favicon.png" />
---

::: {.row}
::: {.col-sm-12 .col-lg-4}

<center>
# Release Notes for
# <mark>STM32H7RSxx_Nucleo</mark>
Copyright &copy; 2024 STMicroelectronics\
    
[![ST logo](_htmresc/st_logo_2020.png)](https://www.st.com){.logo}
</center>

# Purpose

This driver provides a set of functions to manage:

- 256-Mbit Octo-SPI flash memory, user LEDs and push-button available on STM32H7RSxx_Nucleo Kit from STMicroelectronics

:::

::: {.col-sm-12 .col-lg-8}
# Update History
::: {.collapse}
<input type="checkbox" id="collapse-section2" checked aria-hidden="true">
<label for="collapse-section2" aria-hidden="true">__V1.1.0 / 13-January-2025__</label>
<div>

## Maintenance release

## Contents

- Fix Dynamic Clock Prescaler calculation in stm32h7rsxx_nucleo_xspi.c
- Use ReleasePowerDown command instead of No operation in BSP_XSPI_NOR_LeaveDeepPowerDown() API

## Supported Devices and boards

-   STM32H7S3L8H6
-   NUCLEO-H7S3L8

## Known Limitations

- None

## Dependencies

- None

## Notes

- None


\

</div>
:::

::: {.collapse}
<input type="checkbox" id="collapse-section1" aria-hidden="true">
<label for="collapse-section1" aria-hidden="true">__V1.0.0 / 28-February-2024__</label>
<div>

## Main Changes

###  Official release of **STM32H7RSxx_Nucleo** BSP Board drivers

## Contents

- Official release of board drivers for **STM32H7Rx/7Sx Nucleo-144 board** 

## Supported Devices and boards

-   STM32H7S3L8H6
-   NUCLEO-H7S3L8

## Known Limitations

- None

## Dependencies

- None

## Notes

stm32h7rsxx_nucleo_conf_template.h file must be copied in user application as stm32h7rsxx_nucleo_conf.h with optional configuration update


\

</div>
:::

:::
:::

<footer class="sticky">
::: {.columns}
::: {.column width="95%"}
For complete documentation on STM32,
visit: [www.st.com](http://www.st.com)

*This release note uses up to date web standards and, for this reason, should not be opened with Internet Explorer but preferably with popular browsers such as Google Chrome, Mozilla Firefox, Opera or Microsoft Edge.*
:::
::: {.column width="5%"}
<abbr title="Based on template cx566953 version 2.0">Info</abbr>
:::
:::
</footer>
