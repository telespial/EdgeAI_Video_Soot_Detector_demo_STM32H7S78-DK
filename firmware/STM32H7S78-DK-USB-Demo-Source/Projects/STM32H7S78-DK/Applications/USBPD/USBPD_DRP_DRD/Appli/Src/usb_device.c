/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           usb_device.c
  * @author         MCD Application Team
  * @brief          This file implements the USB Device
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

#include "usb_device.h"
#include "usbd_core.h"
#include "usbd_desc.h"
#include "usbd_hid.h"

/* USER CODE BEGIN Includes */
#include "usbpd_trace.h"
#include "cmsis_os2.h"
/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
typedef enum
{
  DEVICE_DISCONNECTED= 0,
  DEVICE_CONNECTED,
}DEVICE_CLASS_STATE;
__IO DEVICE_CLASS_STATE Device_State = DEVICE_DISCONNECTED;

QueueHandle_t UCPD_Device_MsgQueue;

osThreadId_t UCPD_Device_App_TaskHandle;
const osThreadAttr_t UCPD_Device_App_attributes = {
  .name = "UCPD_Device_App",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 512 * 4
};;

extern QueueHandle_t UCPD_Host_MsgQueue;
extern PCD_HandleTypeDef hpcd_USB_OTG_HS;
#if defined ( __ICCARM__ ) /* IAR Compiler */
  #pragma data_alignment=4
#endif /* defined ( __ICCARM__ ) */
extern __ALIGN_BEGIN USB_DRD_ModeMsg_TypeDef USB_DRD_State_Msg __ALIGN_END;
uint8_t HID_Buffer[4];
#define CURSOR_STEP 5
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */
extern void SystemClockConfig_Resume(void);
/* USER CODE END PFP */

/* USB Device Core handle declaration. */
USBD_HandleTypeDef hUsbDeviceHS;


/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/**
  * Init USB device Library, add supported class and start the library
  * @retval None
  */
void MX_USB_DEVICE_Init(void)
{
  /* USER CODE BEGIN USB_DEVICE_Init_PreTreatment */

  /* USER CODE END USB_DEVICE_Init_PreTreatment */

  /* Init Device Library, add supported class and start the library. */
  if (USBD_Init(&hUsbDeviceHS, &HID_Desc, DEVICE_HS) != USBD_OK)
  {
    Error_Handler();
  }
  if (USBD_RegisterClass(&hUsbDeviceHS, &USBD_HID) != USBD_OK)
  {
    Error_Handler();
  }
  if (USBD_Start(&hUsbDeviceHS) != USBD_OK)
  {
    Error_Handler();
  }

  /* USER CODE BEGIN USB_DEVICE_Init_PostTreatment */

  /* USER CODE END USB_DEVICE_Init_PostTreatment */
}


/**
  * @brief  Function implementing the UCPD_Device_App_Thread.
  * @param  argument: Not used
  * @retval None
  */
void UCPD_Device_App_Thread(void *argument)
{
  while (1)
  {
    /* Wait for message queue to start/stop the device */
    if (xQueueReceive(UCPD_Device_MsgQueue, &USB_DRD_State_Msg, portMAX_DELAY) != pdPASS)
    {
      /*Error*/
      Error_Handler();
    }

    /* Check if received message equal to USB_PCD_START */
    if (USB_DRD_State_Msg.DeviceState == START_USB_DEVICE)
    {
      /* Initialization of USB device */
      MX_USB_DEVICE_Init();
      Device_State = DEVICE_CONNECTED;
    }
    /* Check if received message equal to USB_PCD_STOP */
    else if (USB_DRD_State_Msg.DeviceState == STOP_USB_DEVICE)
    {
      if (hpcd_USB_OTG_HS.State == HAL_PCD_STATE_READY)
      {
        /* Stop USB Device */
        USBD_Stop(&hUsbDeviceHS);
        hpcd_USB_OTG_HS.State = HAL_PCD_STATE_RESET;
        Device_State = DEVICE_DISCONNECTED;
      }

      if (USB_DRD_State_Msg.HostState == START_USB_HOST)
      {
        /* Send message to start host */
        if (xQueueSend(UCPD_Host_MsgQueue, &USB_DRD_State_Msg, portMAX_DELAY) != pdPASS)
        {
          Error_Handler();
        }
      }
    }
    /* Else Error */
    else
    {
      /*Error*/
      Error_Handler();
    }
  }
}


void USB_DEVICE_RTOS_Init(void)
{
  /* Create queue before starting task that uses it. */
  UCPD_Device_MsgQueue = osMessageQueueNew(30, sizeof(USB_DRD_ModeMsg_TypeDef), NULL);
  if (UCPD_Device_MsgQueue == NULL)
  {
    Error_Handler();
  }

  UCPD_Device_App_TaskHandle = osThreadNew(UCPD_Device_App_Thread, NULL, &UCPD_Device_App_attributes);
}


/**
  * @}
  */

