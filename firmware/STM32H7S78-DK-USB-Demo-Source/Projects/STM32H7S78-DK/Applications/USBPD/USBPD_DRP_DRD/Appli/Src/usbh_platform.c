/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : usbh_platform.c

  * @brief          : This file implements the USB platform
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "usbh_platform.h"
#include "stm32h7s78_discovery_usbpd_pwr.h"

/* USER CODE BEGIN INCLUDE */

volatile uint32_t g_vbus_drive_call_count = 0U;
volatile uint32_t g_vbus_drive_last_state = 0U;
volatile int32_t g_vbus_pwr_init_rc = 0;
volatile int32_t g_vbus_pwr_vbus_init_rc = 0;
volatile int32_t g_vbus_pwr_role_rc = 0;
volatile int32_t g_vbus_pwr_on_rc = 0;
volatile int32_t g_vbus_pwr_off_rc = 0;

/* USER CODE END INCLUDE */

/**
  * @brief  Drive VBUS.
  * @param  state : VBUS state
  *          This parameter can be one of the these values:
  *          - 1 : VBUS Active
  *          - 0 : VBUS Inactive
  */
void MX_DriverVbusHS(uint8_t state)
{
  static uint8_t usbpd_pwr_inited = 0U;
  g_vbus_drive_call_count++;
  g_vbus_drive_last_state = (uint32_t)state;

  if (usbpd_pwr_inited == 0U)
  {
    g_vbus_pwr_init_rc = BSP_USBPD_PWR_Init(USBPD_PWR_TYPE_C_PORT_1);
    g_vbus_pwr_vbus_init_rc = BSP_USBPD_PWR_VBUSInit(USBPD_PWR_TYPE_C_PORT_1);
    g_vbus_pwr_role_rc = BSP_USBPD_PWR_SetRole(USBPD_PWR_TYPE_C_PORT_1, POWER_ROLE_SOURCE);
    usbpd_pwr_inited = 1U;
  }

  if (state != 0U)
  {
    g_vbus_pwr_on_rc = BSP_USBPD_PWR_VBUSOn(USBPD_PWR_TYPE_C_PORT_1);
  }
  else
  {
    /* Keep USB1 powered for camera-host use case: ignore host stack VBUS-off requests. */
    g_vbus_pwr_off_rc = BSP_ERROR_NONE;
    g_vbus_pwr_on_rc = BSP_USBPD_PWR_VBUSOn(USBPD_PWR_TYPE_C_PORT_1);
  }
}

