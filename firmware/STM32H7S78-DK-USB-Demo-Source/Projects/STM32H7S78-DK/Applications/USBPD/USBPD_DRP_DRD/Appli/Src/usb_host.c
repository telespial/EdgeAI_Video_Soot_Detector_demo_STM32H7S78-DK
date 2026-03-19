/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    : USB_Host/HID_Standalone/USB_Host/App/usb_host.c
  * @author  : MCD Application Team
  * @brief   : This file implements the USB Host
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

#include "main.h"
#include "usbh_core.h"
#include "usbh_ctlreq.h"
#include "usbh_ioreq.h"
#include "usbh_pipes.h"
#include "usbh_hid.h"
#include "usbpd_trace.h"
#include "cmsis_os2.h"
#include "stm32h7s78_discovery_usbpd_pwr.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
typedef enum
{
  HOST_CLASS_APP_IDLE = 0,
  HOST_CLASS_APP_WAIT,
  HOST_CLASS_APP_CAMERA_VIDEO,
  HOST_CLASS_NOT_SUPPORTED
}HOST_CLASS_STATE;
__IO HOST_CLASS_STATE host_class_app_state = HOST_CLASS_APP_IDLE;
QueueHandle_t UCPD_Host_MsgQueue;

extern QueueHandle_t UCPD_Device_MsgQueue;
extern HCD_HandleTypeDef hhcd_USB_OTG_HS;

osThreadId_t USBH_TaskHandle;
const osThreadAttr_t USBH_Task_attributes = {
  .name = "USBH_Task",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 512 * 4
};;

osThreadId_t UCPD_Host_App_TaskHandle;
const osThreadAttr_t UCPD_Host_App_attributes = {
  .name = "UCPD_Host_App",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 512 * 4
};;


#if defined ( __ICCARM__ ) /* IAR Compiler */
  #pragma data_alignment=4
#endif /* defined ( __ICCARM__ ) */
__ALIGN_BEGIN USB_DRD_ModeMsg_TypeDef USB_DRD_State_Msg __ALIGN_END;
uint8_t interface;

#define USB_VIDEO_CLASS_CODE             0x0EU
#define USB_VIDEO_SUBCLASS_CONTROL       0x01U
#define USB_VIDEO_SUBCLASS_STREAMING     0x02U
#define USB_EP_TYPE_MASK                 0x03U
#define USB_EP_TYPE_ISO                  0x01U
#define USB_EP_TYPE_BULK                 0x02U
#define USB_EP_DIR_IN                    0x80U
#define USB_EP_MPS_MASK                  0x07FFU
#define USB_EP_HS_MULT_MASK              0x1800U
#define USB_EP_HS_MULT_SHIFT             11U
#define CAMERA_RX_BUFFER_SIZE            3072U
#define UVC_REQ_SET_CUR                  0x01U
#define UVC_REQ_GET_CUR                  0x81U
#define UVC_REQ_GET_LEN                  0x85U
#define UVC_VS_PROBE_CONTROL             0x01U
#define UVC_VS_COMMIT_CONTROL            0x02U
#define UVC_PROBE_COMMIT_LEN             26U
#define UVC_PROBE_COMMIT_LEN_15          34U
#define USB_DESC_TYPE_CS_INTERFACE       0x24U
#define UVC_VC_HEADER_SUBTYPE            0x01U
#define UVC_VS_FORMAT_UNCOMPRESSED       0x04U
#define UVC_VS_FRAME_UNCOMPRESSED        0x05U
#define UVC_VS_FORMAT_MJPEG              0x06U
#define UVC_VS_FRAME_MJPEG               0x07U
#define UVC_VS_FORMAT_FRAME_BASED        0x10U
#define UVC_VS_FRAME_FRAME_BASED         0x11U
#define CAMERA_MAX_STREAM_CANDIDATES     8U

typedef enum
{
  CAMERA_REQ_IDLE = 0,
  CAMERA_REQ_UVC_GET_PROBE,
  CAMERA_REQ_UVC_SET_PROBE,
  CAMERA_REQ_UVC_SET_COMMIT,
  CAMERA_REQ_SET_STREAMING_ALT,
  CAMERA_REQ_READY,
  CAMERA_REQ_FAILED
} CAMERA_REQ_STATE;

static CAMERA_REQ_STATE camera_req_state = CAMERA_REQ_IDLE;
static uint8_t camera_vs_interface = 0xFFU;
static uint8_t camera_vs_alt = 0U;
static uint8_t camera_ep_in = 0U;
static uint8_t camera_ep_type = USB_EP_TYPE_ISO;
static uint16_t camera_ep_mps = 0U;
static uint16_t camera_ep_payload_mps = 0U;
static uint8_t camera_ep_interval = 0U;
static uint8_t camera_pipe_in = 0xFFU;
static uint8_t camera_rx_armed = 0U;
static uint8_t camera_rx_buf[CAMERA_RX_BUFFER_SIZE];
static uint16_t camera_rx_len = 0U;
static uint16_t camera_rx_target_alt = 0U;
static uint8_t camera_set_alt_stage = 0U;
static uint8_t camera_uvc_probe_commit[UVC_PROBE_COMMIT_LEN_15];
static uint16_t camera_uvc_probe_len = UVC_PROBE_COMMIT_LEN;
static uint16_t camera_uvc_bcd = 0x0000U;
static uint8_t camera_uvc_format_index = 1U;
static uint8_t camera_uvc_frame_index = 1U;
static uint32_t camera_uvc_frame_interval = 333333U;
static uint32_t camera_uvc_frame_size = 640U * 480U * 2U;
static uint8_t camera_uvc_probe_fallback_used = 0U;
static uint32_t camera_rx_packet_count = 0U;
static uint32_t camera_rx_byte_count = 0U;
static uint32_t camera_last_rx_tick = 0U;

typedef struct
{
  uint8_t interface_num;
  uint8_t alt_setting;
  uint8_t ep_in;
  uint8_t ep_type;
  uint16_t ep_mps;
  uint8_t ep_interval;
} CAMERA_STREAM_CANDIDATE;

static CAMERA_STREAM_CANDIDATE camera_candidates[CAMERA_MAX_STREAM_CANDIDATES];
static uint8_t camera_candidate_count = 0U;
static uint8_t camera_candidate_idx = 0U;

/* Simple cross-module diagnostic state for TouchGFX screen feedback. */
volatile uint32_t g_usb_host_diag_state = 0U;
volatile uint32_t g_usb1_vbus_state = 0U;
volatile uint32_t g_usb1_vbus_mv = 0U;
volatile int32_t g_usb1_vbus_is_on_rc = 0;
volatile int32_t g_usb1_vbus_get_mv_rc = 0;
volatile int32_t g_usb1_vbus_keepalive_role_rc = 0;
volatile int32_t g_usb1_vbus_keepalive_on_rc = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */
static uint8_t USBH_DetectVideoInterface(USBH_HandleTypeDef *phost);
static void USBH_CAMERA_LoadCandidate(uint8_t idx);
static void USBH_CAMERA_ParseUVCDescriptors(USBH_HandleTypeDef *phost);
static void USBH_CAMERA_BuildProbeDefaults(void);
static USBH_StatusTypeDef USBH_CAMERA_UVCGetControl(USBH_HandleTypeDef *phost, uint8_t control);
static USBH_StatusTypeDef USBH_CAMERA_UVCGetLen(USBH_HandleTypeDef *phost, uint8_t control, uint16_t *len);
static USBH_StatusTypeDef USBH_CAMERA_UVCSetControl(USBH_HandleTypeDef *phost, uint8_t control);
static USBH_StatusTypeDef USBH_CAMERA_InterfaceInit(USBH_HandleTypeDef *phost);
static USBH_StatusTypeDef USBH_CAMERA_InterfaceDeInit(USBH_HandleTypeDef *phost);
static USBH_StatusTypeDef USBH_CAMERA_ClassRequest(USBH_HandleTypeDef *phost);
static USBH_StatusTypeDef USBH_CAMERA_Process(USBH_HandleTypeDef *phost);
static void USBH_EnsureStarted(void);
/* USER CODE END PFP */

/* USB Host core handle declaration */
USBH_HandleTypeDef hUsbHostHS;
ApplicationTypeDef Appli_state = APPLICATION_IDLE;
static uint8_t g_usb_host_started = 0U;

/*
 * -- Insert your variables declaration here --
 */
/* USER CODE BEGIN 0 */
USBH_ClassTypeDef CAMERA_Class =
{
  "CAMERA",
  0x0EU, /* USB Video class code */
  USBH_CAMERA_InterfaceInit,
  USBH_CAMERA_InterfaceDeInit,
  USBH_CAMERA_ClassRequest,
  USBH_CAMERA_Process
};

/* USER CODE END 0 */

/*
 * user callback declaration
 */
static void USBH_UserProcess(USBH_HandleTypeDef *phost, uint8_t id);

/*
 * -- Insert your external function declaration here --
 */
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/**
  * Init USB host library, add supported class and start the library
  * @retval None
  */
void MX_USB_HOST_Init(void)
{
  /* USER CODE BEGIN USB_HOST_Init_PreTreatment */

  /* USER CODE END USB_HOST_Init_PreTreatment */

  g_usb_host_diag_state = 0U;
  /* Init host Library, add supported class and start the library. */
  if (USBH_Init(&hUsbHostHS, USBH_UserProcess, HOST_HS) != USBH_OK)
  {
    Error_Handler();
  }
  /* Camera-only host mode: do not register HID class. */
  if (USBH_RegisterClass(&hUsbHostHS, &CAMERA_Class) != USBH_OK)
  {
    Error_Handler();
  }
  if (USBH_Start(&hUsbHostHS) != USBH_OK)
  {
    Error_Handler();
  }
  g_usb_host_started = 1U;
  /* USER CODE BEGIN USB_HOST_Init_PostTreatment */

  /* USER CODE END USB_HOST_Init_PostTreatment */
}

/*
 * user callback definition
 */
static void USBH_UserProcess(USBH_HandleTypeDef *phost, uint8_t id)
{
  /* USER CODE BEGIN CALL_BACK_1 */
  switch(id)
  {
  case HOST_USER_SELECT_CONFIGURATION:
    g_usb_host_diag_state = 1U;
    if (USBH_DetectVideoInterface(phost) != 0U)
    {
      host_class_app_state = HOST_CLASS_APP_CAMERA_VIDEO;
      USBPD_TRACE_Add(USBPD_TRACE_DEBUG, 0, 0, (uint8_t*)"USB camera interface", 20);
      g_usb_host_diag_state = 2U;
    }
    else
    {
      host_class_app_state = HOST_CLASS_NOT_SUPPORTED;
      USBPD_TRACE_Add(USBPD_TRACE_DEBUG, 0, 0, (uint8_t*)"USB class unsupported", 21);
    }
  break;

  case HOST_USER_DISCONNECTION:
    Appli_state = APPLICATION_DISCONNECT;
    host_class_app_state = HOST_CLASS_APP_IDLE;
    camera_req_state = CAMERA_REQ_IDLE;
    g_usb_host_diag_state = 0U;
  break;

  case HOST_USER_CLASS_ACTIVE:
    Appli_state = APPLICATION_READY;
    if ((hUsbHostHS.pActiveClass != NULL) && (hUsbHostHS.pActiveClass->ClassCode == 0x0EU))
    {
      host_class_app_state = HOST_CLASS_APP_CAMERA_VIDEO;
      USBPD_TRACE_Add(USBPD_TRACE_DEBUG, 0, 0, (uint8_t*)"USB camera class active", 23);
      g_usb_host_diag_state = 3U;
    }
    else if ((hUsbHostHS.pActiveClass != NULL) && (hUsbHostHS.pActiveClass->ClassCode == 0x03U))
    {
      host_class_app_state = HOST_CLASS_APP_WAIT;
      USBPD_TRACE_Add(USBPD_TRACE_DEBUG, 0, 0, (uint8_t*)"USB HID class active", 20);
      g_usb_host_diag_state = 4U;
    }
    else
    {
      host_class_app_state = HOST_CLASS_NOT_SUPPORTED;
      USBPD_TRACE_Add(USBPD_TRACE_DEBUG, 0, 0, (uint8_t*)"USB class active", 16);
      g_usb_host_diag_state = 6U;
    }
  break;

  case HOST_USER_CONNECTION:
    Appli_state = APPLICATION_START;
    host_class_app_state = HOST_CLASS_APP_WAIT;
    g_usb_host_diag_state = 1U;
  break;

  default:
  break;
  }
  /* USER CODE END CALL_BACK_1 */
}

static void USBH_EnsureStarted(void)
{
  if (g_usb_host_started == 0U)
  {
    MX_USB_HOST_Init();
  }
}

/* USER CODE BEGIN 2 */
static uint8_t USBH_DetectVideoInterface(USBH_HandleTypeDef *phost)
{
  uint16_t ptr = 0U;
  uint16_t total = phost->device.CfgDesc.wTotalLength;
  uint8_t len;
  uint8_t type;
  uint8_t found_stream = 0U;
  uint16_t best_mps = 0U;
  uint8_t best_type = 0xFFU;
  uint8_t ep_type;
  uint8_t cur_if = 0xFFU;
  uint8_t cur_alt = 0U;
  uint8_t cur_class = 0xFFU;
  uint8_t cur_subclass = 0xFFU;
  uint16_t wmax_raw;
  uint16_t wmax_pkt;
  uint8_t epaddr;
  uint8_t c;

  camera_vs_interface = 0xFFU;
  camera_vs_alt = 0U;
  camera_ep_in = 0U;
  camera_ep_type = USB_EP_TYPE_ISO;
  camera_ep_mps = 0U;
  camera_ep_payload_mps = 0U;
  camera_ep_interval = 0U;
  camera_candidate_count = 0U;
  camera_candidate_idx = 0U;

  for (interface = 0U; interface < phost->device.CfgDesc.bNumInterfaces; interface++)
  {
    if ((phost->device.CfgDesc.Itf_Desc[interface].bInterfaceClass == USB_VIDEO_CLASS_CODE) &&
        (phost->device.CfgDesc.Itf_Desc[interface].bInterfaceSubClass == USB_VIDEO_SUBCLASS_CONTROL))
    {
      break;
    }
  }

  while ((ptr + 2U) <= total)
  {
    len = phost->device.CfgDesc_Raw[ptr];
    type = phost->device.CfgDesc_Raw[ptr + 1U];
    if ((len < 2U) || ((ptr + len) > total))
    {
      break;
    }

    if ((type == USB_DESC_TYPE_INTERFACE) && (len >= USB_INTERFACE_DESC_SIZE))
    {
      cur_if = phost->device.CfgDesc_Raw[ptr + 2U];
      cur_alt = phost->device.CfgDesc_Raw[ptr + 3U];
      cur_class = phost->device.CfgDesc_Raw[ptr + 5U];
      cur_subclass = phost->device.CfgDesc_Raw[ptr + 6U];
    }
    else if ((type == USB_DESC_TYPE_ENDPOINT) && (len >= USB_ENDPOINT_DESC_SIZE))
    {
      if ((cur_class == USB_VIDEO_CLASS_CODE) && (cur_subclass == USB_VIDEO_SUBCLASS_STREAMING))
      {
        ep_type = (phost->device.CfgDesc_Raw[ptr + 3U] & USB_EP_TYPE_MASK);
        epaddr = phost->device.CfgDesc_Raw[ptr + 2U];
        wmax_raw = LE16(&phost->device.CfgDesc_Raw[ptr + 4U]);
        wmax_pkt = (uint16_t)(wmax_raw & USB_EP_MPS_MASK);
        if (((ep_type == USB_EP_TYPE_ISO) || (ep_type == USB_EP_TYPE_BULK)) &&
            ((epaddr & USB_EP_DIR_IN) != 0U) &&
            (wmax_pkt > 0U))
        {
          uint16_t candidate_mps = wmax_raw;
          uint16_t candidate_payload_mps = wmax_pkt;
          uint8_t exists = 0U;
          uint8_t candidate_type_prio = (ep_type == USB_EP_TYPE_ISO) ? 0U : 1U;
          uint8_t best_type_prio = (best_type == USB_EP_TYPE_ISO) ? 0U : 1U;

          for (c = 0U; c < camera_candidate_count; c++)
          {
            if ((camera_candidates[c].interface_num == cur_if) &&
                (camera_candidates[c].alt_setting == cur_alt) &&
                (camera_candidates[c].ep_in == epaddr))
            {
              exists = 1U;
              break;
            }
          }
          if ((exists == 0U) && (camera_candidate_count < CAMERA_MAX_STREAM_CANDIDATES))
          {
            camera_candidates[camera_candidate_count].interface_num = cur_if;
            camera_candidates[camera_candidate_count].alt_setting = cur_alt;
            camera_candidates[camera_candidate_count].ep_in = epaddr;
            camera_candidates[camera_candidate_count].ep_type = ep_type;
            camera_candidates[camera_candidate_count].ep_mps = candidate_mps;
            camera_candidates[camera_candidate_count].ep_interval = phost->device.CfgDesc_Raw[ptr + 6U];
            camera_candidate_count++;
          }

          if ((found_stream == 0U) ||
              (candidate_type_prio < best_type_prio) ||
              ((candidate_type_prio == best_type_prio) && (candidate_mps > best_mps)))
          {
            camera_vs_interface = cur_if;
            camera_vs_alt = cur_alt;
            camera_ep_in = epaddr;
            camera_ep_type = ep_type;
            camera_ep_mps = candidate_mps;
            camera_ep_payload_mps = candidate_payload_mps;
            camera_ep_interval = phost->device.CfgDesc_Raw[ptr + 6U];
            best_mps = candidate_mps;
            best_type = ep_type;
            found_stream = 1U;
          }
        }
      }
    }
    ptr = (uint16_t)(ptr + len);
  }
  return found_stream;
}

static void USBH_CAMERA_LoadCandidate(uint8_t idx)
{
  if (idx >= camera_candidate_count)
  {
    return;
  }
  camera_vs_interface = camera_candidates[idx].interface_num;
  camera_vs_alt = camera_candidates[idx].alt_setting;
  camera_ep_in = camera_candidates[idx].ep_in;
  camera_ep_type = camera_candidates[idx].ep_type;
  camera_ep_mps = camera_candidates[idx].ep_mps;
  camera_ep_payload_mps = (uint16_t)(camera_ep_mps & USB_EP_MPS_MASK);
  camera_ep_interval = camera_candidates[idx].ep_interval;
}

static void USBH_CAMERA_ParseUVCDescriptors(USBH_HandleTypeDef *phost)
{
  uint16_t ptr = 0U;
  uint16_t total = phost->device.CfgDesc.wTotalLength;
  uint8_t len;
  uint8_t type;
  uint8_t cur_if = 0xFFU;
  uint8_t cur_sub = 0xFFU;
  uint8_t sub;
  uint8_t cur_format_sub = 0U;
  uint8_t cur_format_idx = 0U;
  uint8_t have_pick = 0U;
  uint8_t pick_format = 1U;
  uint8_t pick_frame = 1U;
  uint32_t pick_interval = 333333U;
  uint32_t pick_size = 640U * 480U * 2U;
  uint8_t pick_mjpeg = 0U;

  camera_uvc_bcd = 0x0000U;
  camera_uvc_format_index = 1U;
  camera_uvc_frame_index = 1U;
  camera_uvc_frame_interval = 333333U;
  camera_uvc_frame_size = 640U * 480U * 2U;

  while ((ptr + 2U) <= total)
  {
    len = phost->device.CfgDesc_Raw[ptr];
    type = phost->device.CfgDesc_Raw[ptr + 1U];
    if ((len < 2U) || ((ptr + len) > total))
    {
      break;
    }

    if ((type == USB_DESC_TYPE_INTERFACE) && (len >= USB_INTERFACE_DESC_SIZE))
    {
      cur_if = phost->device.CfgDesc_Raw[ptr + 2U];
      cur_sub = phost->device.CfgDesc_Raw[ptr + 6U];
    }
    else if ((type == USB_DESC_TYPE_CS_INTERFACE) && (len >= 3U))
    {
      sub = phost->device.CfgDesc_Raw[ptr + 2U];
      if ((cur_sub == USB_VIDEO_SUBCLASS_CONTROL) && (sub == UVC_VC_HEADER_SUBTYPE) && (len >= 5U))
      {
        camera_uvc_bcd = LE16(&phost->device.CfgDesc_Raw[ptr + 3U]);
      }
      else if ((cur_if == camera_vs_interface) && (cur_sub == USB_VIDEO_SUBCLASS_STREAMING))
      {
        if (((sub == UVC_VS_FORMAT_UNCOMPRESSED) || (sub == UVC_VS_FORMAT_MJPEG) || (sub == UVC_VS_FORMAT_FRAME_BASED)) &&
            (len >= 4U))
        {
          cur_format_sub = sub;
          cur_format_idx = phost->device.CfgDesc_Raw[ptr + 3U];
        }
        else if (((sub == UVC_VS_FRAME_UNCOMPRESSED) || (sub == UVC_VS_FRAME_MJPEG) || (sub == UVC_VS_FRAME_FRAME_BASED)) &&
                 (len >= 26U))
        {
          uint8_t frame_idx = phost->device.CfgDesc_Raw[ptr + 3U];
          uint32_t frame_size = LE32(&phost->device.CfgDesc_Raw[ptr + 17U]);
          uint32_t frame_interval = LE32(&phost->device.CfgDesc_Raw[ptr + 21U]);
          uint8_t is_mjpeg = (cur_format_sub == UVC_VS_FORMAT_MJPEG) ? 1U : 0U;

          if (have_pick == 0U)
          {
            have_pick = 1U;
            pick_format = (cur_format_idx == 0U) ? 1U : cur_format_idx;
            pick_frame = frame_idx;
            pick_interval = frame_interval;
            pick_size = frame_size;
            pick_mjpeg = is_mjpeg;
          }
          else if ((is_mjpeg > pick_mjpeg) ||
                   ((is_mjpeg == pick_mjpeg) && (frame_size < pick_size)))
          {
            pick_format = (cur_format_idx == 0U) ? 1U : cur_format_idx;
            pick_frame = frame_idx;
            pick_interval = frame_interval;
            pick_size = frame_size;
            pick_mjpeg = is_mjpeg;
          }
        }
      }
    }

    ptr = (uint16_t)(ptr + len);
  }

  if (have_pick != 0U)
  {
    camera_uvc_format_index = pick_format;
    camera_uvc_frame_index = pick_frame;
    camera_uvc_frame_interval = pick_interval;
    camera_uvc_frame_size = pick_size;
  }

  camera_uvc_probe_len = (camera_uvc_bcd >= 0x0150U) ? UVC_PROBE_COMMIT_LEN_15 : UVC_PROBE_COMMIT_LEN;
}

static void USBH_CAMERA_BuildProbeDefaults(void)
{
  (void)USBH_memset(camera_uvc_probe_commit, 0, sizeof(camera_uvc_probe_commit));
  camera_uvc_probe_commit[0] = 0x01U; /* bmHint: dwFrameInterval is valid */
  camera_uvc_probe_commit[1] = 0x00U;
  camera_uvc_probe_commit[2] = (camera_uvc_format_index == 0U) ? 1U : camera_uvc_format_index;
  camera_uvc_probe_commit[3] = (camera_uvc_frame_index == 0U) ? 1U : camera_uvc_frame_index;
  camera_uvc_probe_commit[4] = (uint8_t)(camera_uvc_frame_interval & 0xFFU);
  camera_uvc_probe_commit[5] = (uint8_t)((camera_uvc_frame_interval >> 8U) & 0xFFU);
  camera_uvc_probe_commit[6] = (uint8_t)((camera_uvc_frame_interval >> 16U) & 0xFFU);
  camera_uvc_probe_commit[7] = (uint8_t)((camera_uvc_frame_interval >> 24U) & 0xFFU);
  camera_uvc_probe_commit[18] = (uint8_t)(camera_uvc_frame_size & 0xFFU);
  camera_uvc_probe_commit[19] = (uint8_t)((camera_uvc_frame_size >> 8U) & 0xFFU);
  camera_uvc_probe_commit[20] = (uint8_t)((camera_uvc_frame_size >> 16U) & 0xFFU);
  camera_uvc_probe_commit[21] = (uint8_t)((camera_uvc_frame_size >> 24U) & 0xFFU);
  camera_uvc_probe_commit[22] = (uint8_t)(camera_ep_payload_mps & 0xFFU);
  camera_uvc_probe_commit[23] = (uint8_t)((camera_ep_payload_mps >> 8U) & 0xFFU);
  camera_uvc_probe_commit[24] = 0x00U;
  camera_uvc_probe_commit[25] = 0x00U;
}

static USBH_StatusTypeDef USBH_CAMERA_UVCGetControl(USBH_HandleTypeDef *phost, uint8_t control)
{
  phost->Control.setup.b.bmRequestType = USB_D2H | USB_REQ_TYPE_CLASS | USB_REQ_RECIPIENT_INTERFACE;
  phost->Control.setup.b.bRequest = UVC_REQ_GET_CUR;
  phost->Control.setup.b.wValue.w = (uint16_t)((uint16_t)control << 8U);
  phost->Control.setup.b.wIndex.w = camera_vs_interface;
  phost->Control.setup.b.wLength.w = camera_uvc_probe_len;
  return USBH_CtlReq(phost, camera_uvc_probe_commit, camera_uvc_probe_len);
}

static USBH_StatusTypeDef USBH_CAMERA_UVCGetLen(USBH_HandleTypeDef *phost, uint8_t control, uint16_t *len)
{
  uint8_t resp[2];
  USBH_StatusTypeDef status;
  uint16_t val;

  phost->Control.setup.b.bmRequestType = USB_D2H | USB_REQ_TYPE_CLASS | USB_REQ_RECIPIENT_INTERFACE;
  phost->Control.setup.b.bRequest = UVC_REQ_GET_LEN;
  phost->Control.setup.b.wValue.w = (uint16_t)((uint16_t)control << 8U);
  phost->Control.setup.b.wIndex.w = camera_vs_interface;
  phost->Control.setup.b.wLength.w = 2U;
  status = USBH_CtlReq(phost, resp, 2U);
  if (status != USBH_OK)
  {
    return status;
  }

  val = LE16(resp);
  if ((val >= UVC_PROBE_COMMIT_LEN) && (val <= UVC_PROBE_COMMIT_LEN_15))
  {
    *len = val;
  }
  return USBH_OK;
}

static USBH_StatusTypeDef USBH_CAMERA_UVCSetControl(USBH_HandleTypeDef *phost, uint8_t control)
{
  phost->Control.setup.b.bmRequestType = USB_H2D | USB_REQ_TYPE_CLASS | USB_REQ_RECIPIENT_INTERFACE;
  phost->Control.setup.b.bRequest = UVC_REQ_SET_CUR;
  phost->Control.setup.b.wValue.w = (uint16_t)((uint16_t)control << 8U);
  phost->Control.setup.b.wIndex.w = camera_vs_interface;
  phost->Control.setup.b.wLength.w = camera_uvc_probe_len;
  return USBH_CtlReq(phost, camera_uvc_probe_commit, camera_uvc_probe_len);
}

static USBH_StatusTypeDef USBH_CAMERA_InterfaceInit(USBH_HandleTypeDef *phost)
{
  uint32_t rx_window = camera_ep_payload_mps;

  if (USBH_DetectVideoInterface(phost) == 0U)
  {
    camera_req_state = CAMERA_REQ_FAILED;
    USBPD_TRACE_Add(USBPD_TRACE_DEBUG, 0, 0, (uint8_t*)"UVC stream endpoint not found", 29);
    return USBH_FAIL;
  }

  camera_pipe_in = 0xFFU;
  if ((camera_ep_type == USB_EP_TYPE_ISO) && (phost->device.speed == (uint8_t)USBH_SPEED_HIGH))
  {
    uint8_t mult = (uint8_t)(((camera_ep_mps & USB_EP_HS_MULT_MASK) >> USB_EP_HS_MULT_SHIFT) + 1U);
    rx_window = (uint32_t)camera_ep_payload_mps * (uint32_t)mult;
  }
  camera_rx_len = (rx_window <= CAMERA_RX_BUFFER_SIZE) ? (uint16_t)rx_window : CAMERA_RX_BUFFER_SIZE;
  camera_rx_target_alt = camera_vs_alt;
  camera_set_alt_stage = 0U;
  camera_rx_armed = 0U;
  camera_rx_packet_count = 0U;
  camera_rx_byte_count = 0U;
  camera_uvc_probe_fallback_used = 0U;
  if (camera_candidate_count > 0U)
  {
    camera_candidate_idx = 0U;
    USBH_CAMERA_LoadCandidate(camera_candidate_idx);
  }
  USBH_CAMERA_ParseUVCDescriptors(phost);
  USBH_CAMERA_BuildProbeDefaults();
  /* Full UVC handshake: GET_PROBE -> SET_PROBE -> SET_COMMIT -> SET_INTERFACE. */
  camera_req_state = CAMERA_REQ_UVC_GET_PROBE;
  USBPD_TRACE_Add(USBPD_TRACE_DEBUG, 0, 0, (uint8_t*)"UVC stream detected", 19);
  return USBH_OK;
}

static USBH_StatusTypeDef USBH_CAMERA_InterfaceDeInit(USBH_HandleTypeDef *phost)
{
  if (camera_pipe_in != 0xFFU)
  {
    (void)USBH_ClosePipe(phost, camera_pipe_in);
    (void)USBH_FreePipe(phost, camera_pipe_in);
    camera_pipe_in = 0xFFU;
  }
  camera_rx_armed = 0U;
  camera_set_alt_stage = 0U;
  camera_rx_target_alt = 0U;
  return USBH_OK;
}

static USBH_StatusTypeDef USBH_CAMERA_ClassRequest(USBH_HandleTypeDef *phost)
{
  USBH_StatusTypeDef status;
  uint16_t probe_len = camera_uvc_probe_len;

  if (camera_req_state == CAMERA_REQ_UVC_GET_PROBE)
  {
    status = USBH_CAMERA_UVCGetLen(phost, UVC_VS_PROBE_CONTROL, &probe_len);
    if (status == USBH_OK)
    {
      camera_uvc_probe_len = probe_len;
    }
    else if (status == USBH_BUSY)
    {
      return USBH_BUSY;
    }

    status = USBH_CAMERA_UVCGetControl(phost, UVC_VS_PROBE_CONTROL);
    if (status == USBH_OK)
    {
      camera_req_state = CAMERA_REQ_UVC_SET_PROBE;
      USBPD_TRACE_Add(USBPD_TRACE_DEBUG, 0, 0, (uint8_t*)"UVC GET_PROBE OK", 16);
      return USBH_BUSY;
    }
    if (status == USBH_BUSY)
    {
      return USBH_BUSY;
    }
    if ((camera_uvc_probe_len == UVC_PROBE_COMMIT_LEN_15) && (camera_uvc_probe_fallback_used == 0U))
    {
      camera_uvc_probe_len = UVC_PROBE_COMMIT_LEN;
      camera_uvc_probe_fallback_used = 1U;
      USBPD_TRACE_Add(USBPD_TRACE_DEBUG, 0, 0, (uint8_t*)"UVC probe len fallback", 22);
      return USBH_BUSY;
    }
    /* Some webcams reject GET_CUR before SET_CUR. Continue with stream alt anyway. */
    USBH_CAMERA_BuildProbeDefaults();
    camera_req_state = CAMERA_REQ_UVC_SET_PROBE;
    USBPD_TRACE_Add(USBPD_TRACE_DEBUG, 0, 0, (uint8_t*)"UVC GET_PROBE use defaults", 26);
    return USBH_BUSY;
  }

  if (camera_req_state == CAMERA_REQ_UVC_SET_PROBE)
  {
    status = USBH_CAMERA_UVCSetControl(phost, UVC_VS_PROBE_CONTROL);
    if (status == USBH_OK)
    {
      camera_req_state = CAMERA_REQ_UVC_SET_COMMIT;
      USBPD_TRACE_Add(USBPD_TRACE_DEBUG, 0, 0, (uint8_t*)"UVC SET_PROBE OK", 16);
      return USBH_BUSY;
    }
    if (status == USBH_BUSY)
    {
      return USBH_BUSY;
    }
    if ((camera_uvc_probe_len == UVC_PROBE_COMMIT_LEN_15) && (camera_uvc_probe_fallback_used == 0U))
    {
      camera_uvc_probe_len = UVC_PROBE_COMMIT_LEN;
      camera_uvc_probe_fallback_used = 1U;
      USBH_CAMERA_BuildProbeDefaults();
      return USBH_BUSY;
    }
    /* Some webcams reject SET_CUR probe but still accept direct streaming alt. */
    camera_set_alt_stage = 0U;
    camera_req_state = CAMERA_REQ_SET_STREAMING_ALT;
    USBPD_TRACE_Add(USBPD_TRACE_DEBUG, 0, 0, (uint8_t*)"UVC SET_PROBE FAIL -> ALT", 25);
    return USBH_BUSY;
  }

  if (camera_req_state == CAMERA_REQ_UVC_SET_COMMIT)
  {
    status = USBH_CAMERA_UVCSetControl(phost, UVC_VS_COMMIT_CONTROL);
    if (status == USBH_OK)
    {
      camera_req_state = CAMERA_REQ_SET_STREAMING_ALT;
      USBPD_TRACE_Add(USBPD_TRACE_DEBUG, 0, 0, (uint8_t*)"UVC SET_COMMIT OK", 17);
      return USBH_BUSY;
    }
    if (status == USBH_BUSY)
    {
      return USBH_BUSY;
    }
    if ((camera_uvc_probe_len == UVC_PROBE_COMMIT_LEN_15) && (camera_uvc_probe_fallback_used == 0U))
    {
      camera_uvc_probe_len = UVC_PROBE_COMMIT_LEN;
      camera_uvc_probe_fallback_used = 1U;
      USBH_CAMERA_BuildProbeDefaults();
      camera_req_state = CAMERA_REQ_UVC_SET_PROBE;
      return USBH_BUSY;
    }
    /* Fallback: try streaming alt even if COMMIT is rejected. */
    camera_set_alt_stage = 0U;
    camera_req_state = CAMERA_REQ_SET_STREAMING_ALT;
    USBPD_TRACE_Add(USBPD_TRACE_DEBUG, 0, 0, (uint8_t*)"UVC SET_COMMIT FAIL -> ALT", 26);
    return USBH_BUSY;
  }

  if (camera_req_state == CAMERA_REQ_SET_STREAMING_ALT)
  {
    uint8_t if_idx = USBH_FindInterfaceIndex(phost, camera_vs_interface, camera_vs_alt);
    uint8_t set_alt = (uint8_t)((camera_set_alt_stage == 0U) ? 0U : camera_rx_target_alt);

    if (if_idx != 0xFFU)
    {
      (void)USBH_SelectInterface(phost, if_idx);
    }

    status = USBH_SetInterface(phost, camera_vs_interface, set_alt);
    if (status == USBH_OK)
    {
      if ((camera_set_alt_stage == 0U) && (camera_rx_target_alt != 0U))
      {
        camera_set_alt_stage = 1U;
        return USBH_BUSY;
      }

      camera_pipe_in = USBH_AllocPipe(phost, camera_ep_in);
      if (camera_pipe_in == 0xFFU)
      {
        camera_req_state = CAMERA_REQ_FAILED;
        USBPD_TRACE_Add(USBPD_TRACE_DEBUG, 0, 0, (uint8_t*)"UVC pipe alloc fail", 19);
        return USBH_FAIL;
      }

      status = USBH_OpenPipe(phost, camera_pipe_in, camera_ep_in, phost->device.address,
                             phost->device.speed, camera_ep_type, camera_ep_mps);
      if (status != USBH_OK)
      {
        (void)USBH_FreePipe(phost, camera_pipe_in);
        camera_pipe_in = 0xFFU;
        if ((camera_candidate_idx + 1U) < camera_candidate_count)
        {
          camera_candidate_idx++;
          USBH_CAMERA_LoadCandidate(camera_candidate_idx);
          camera_uvc_probe_fallback_used = 0U;
          USBH_CAMERA_BuildProbeDefaults();
          camera_rx_target_alt = camera_vs_alt;
          camera_set_alt_stage = 0U;
          camera_req_state = CAMERA_REQ_UVC_SET_PROBE;
          USBPD_TRACE_Add(USBPD_TRACE_DEBUG, 0, 0, (uint8_t*)"UVC next candidate", 18);
          return USBH_BUSY;
        }
        camera_req_state = CAMERA_REQ_FAILED;
        USBPD_TRACE_Add(USBPD_TRACE_DEBUG, 0, 0, (uint8_t*)"UVC pipe open fail", 18);
        return USBH_FAIL;
      }
      (void)USBH_LL_SetToggle(phost, camera_pipe_in, 0U);
      camera_last_rx_tick = HAL_GetTick();

      camera_req_state = CAMERA_REQ_READY;
      USBPD_TRACE_Add(USBPD_TRACE_DEBUG, 0, 0, (uint8_t*)"UVC SET_INTERFACE OK", 20);
      return USBH_OK;
    }
    if (status == USBH_BUSY)
    {
      return USBH_BUSY;
    }
    if ((camera_candidate_idx + 1U) < camera_candidate_count)
    {
      camera_candidate_idx++;
      USBH_CAMERA_LoadCandidate(camera_candidate_idx);
      camera_uvc_probe_fallback_used = 0U;
      USBH_CAMERA_BuildProbeDefaults();
      camera_rx_target_alt = camera_vs_alt;
      camera_set_alt_stage = 0U;
      camera_req_state = CAMERA_REQ_UVC_SET_PROBE;
      USBPD_TRACE_Add(USBPD_TRACE_DEBUG, 0, 0, (uint8_t*)"UVC next candidate", 18);
      return USBH_BUSY;
    }
    camera_req_state = CAMERA_REQ_FAILED;
    USBPD_TRACE_Add(USBPD_TRACE_DEBUG, 0, 0, (uint8_t*)"UVC SET_INTERFACE FAIL", 22);
    return status;
  }

  if (camera_req_state == CAMERA_REQ_READY)
  {
    return USBH_OK;
  }

  return USBH_FAIL;
}

static USBH_StatusTypeDef USBH_CAMERA_Process(USBH_HandleTypeDef *phost)
{
  if ((camera_req_state == CAMERA_REQ_READY) && (camera_pipe_in != 0xFFU))
  {
    if (camera_rx_armed == 0U)
    {
      if (camera_ep_type == USB_EP_TYPE_ISO)
      {
        (void)USBH_IsocReceiveData(phost, camera_rx_buf, camera_rx_len, camera_pipe_in);
      }
      else
      {
        (void)USBH_BulkReceiveData(phost, camera_rx_buf, camera_rx_len, camera_pipe_in);
      }
      camera_rx_armed = 1U;
    }
    else
    {
      USBH_URBStateTypeDef urb = USBH_LL_GetURBState(phost, camera_pipe_in);
      if (urb == USBH_URB_DONE)
      {
        camera_rx_packet_count++;
        camera_rx_byte_count += USBH_LL_GetLastXferSize(phost, camera_pipe_in);
        camera_last_rx_tick = HAL_GetTick();
        if ((camera_rx_packet_count % 200U) == 0U)
        {
          USBPD_TRACE_Add(USBPD_TRACE_DEBUG, 0, 0, (uint8_t*)"UVC RX active", 13);
        }

        if (camera_ep_type == USB_EP_TYPE_ISO)
        {
          (void)USBH_IsocReceiveData(phost, camera_rx_buf, camera_rx_len, camera_pipe_in);
        }
        else
        {
          (void)USBH_BulkReceiveData(phost, camera_rx_buf, camera_rx_len, camera_pipe_in);
        }
      }
      else if ((urb == USBH_URB_ERROR) || (urb == USBH_URB_STALL))
      {
        camera_rx_armed = 0U;
      }
      else if ((HAL_GetTick() - camera_last_rx_tick) > 1500U)
      {
        if (camera_pipe_in != 0xFFU)
        {
          (void)USBH_ClosePipe(phost, camera_pipe_in);
          (void)USBH_FreePipe(phost, camera_pipe_in);
          camera_pipe_in = 0xFFU;
        }
        camera_rx_armed = 0U;
        if ((camera_candidate_idx + 1U) < camera_candidate_count)
        {
          camera_candidate_idx++;
          USBH_CAMERA_LoadCandidate(camera_candidate_idx);
          camera_uvc_probe_fallback_used = 0U;
          USBH_CAMERA_BuildProbeDefaults();
          camera_rx_target_alt = camera_vs_alt;
          camera_set_alt_stage = 0U;
          camera_req_state = CAMERA_REQ_UVC_SET_PROBE;
          USBPD_TRACE_Add(USBPD_TRACE_DEBUG, 0, 0, (uint8_t*)"UVC timeout next", 16);
        }
      }
    }
  }

  return USBH_OK;
}

/**
  * @brief  Function implementing the UCPD_Host_App_Thread.
  * @param  argument: Not used
  * @retval None
  */
void UCPD_Host_App_Thread(void *argument)
{
  while (1)
  {
    /* wait for message queue from callback event */
    if (xQueueReceive(UCPD_Host_MsgQueue, &USB_DRD_State_Msg, portMAX_DELAY) != pdPASS)
    {
      Error_Handler();
    }

    /* Check if received message equal to START_USB_HOST */
    if (USB_DRD_State_Msg.HostState == START_USB_HOST)
    {
      /* Start USB Host */
      USBH_EnsureStarted();
    }
    /* Check if received message equal to STOP_USB_HOST */
    else if (USB_DRD_State_Msg.HostState == STOP_USB_HOST)
    {
      /* Host-only mode: ignore stop/switch requests to keep USB1 camera alive. */
      USBH_EnsureStarted();
    }
    /* Else Error */
    else
    {
      /*Error*/
      Error_Handler();
    }
  }
}

/* USER CODE BEGIN Header__USBH_Task */
/**
  * @brief  Function implementing the USBH_Task thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header__USBH_Task */
void USBH_Task(void *argument)
{
  /* USER CODE BEGIN 5 */
  uint32_t last_vbus_poll = 0U;
  uint32_t last_vbus_force = 0U;
  uint8_t vbus_state = 0U;
  uint32_t vbus_mv = 0U;

  while (1)
  {
    if ((HAL_GetTick() - last_vbus_poll) >= 500U)
    {
      last_vbus_poll = HAL_GetTick();
      g_usb1_vbus_is_on_rc = BSP_USBPD_PWR_VBUSIsOn(USBPD_PWR_TYPE_C_PORT_1, &vbus_state);
      g_usb1_vbus_state = (uint32_t)vbus_state;
      g_usb1_vbus_get_mv_rc = BSP_USBPD_PWR_VBUSGetVoltage(USBPD_PWR_TYPE_C_PORT_1, &vbus_mv);
      g_usb1_vbus_mv = vbus_mv;
    }

    if ((HAL_GetTick() - last_vbus_force) >= 100U)
    {
      last_vbus_force = HAL_GetTick();
      TCPP0203_PORT0_ENABLE_GPIO_SET();
      g_usb1_vbus_keepalive_role_rc = BSP_USBPD_PWR_SetRole(USBPD_PWR_TYPE_C_PORT_1, POWER_ROLE_SOURCE);
      g_usb1_vbus_keepalive_on_rc = BSP_USBPD_PWR_VBUSOn(USBPD_PWR_TYPE_C_PORT_1);
    }

    if ((Appli_state == APPLICATION_READY) && (host_class_app_state == HOST_CLASS_APP_CAMERA_VIDEO))
    {
      /* Webcam interface detected on USB1. UVC streaming integration is pending. */
    }
    osDelay(1);
  }
  /* USER CODE END 5 */
}

void USB_HOST_RTOS_Init(void)
{
  USB_DRD_ModeMsg_TypeDef boot_msg = {0};

  /* Create queue before starting tasks that use it. */
  UCPD_Host_MsgQueue = osMessageQueueNew(30, sizeof(USB_DRD_ModeMsg_TypeDef), NULL);
  if (UCPD_Host_MsgQueue == NULL)
  {
    Error_Handler();
  }

  USBH_EnsureStarted();

  USBH_TaskHandle = osThreadNew(USBH_Task, NULL, &USBH_Task_attributes);
  UCPD_Host_App_TaskHandle = osThreadNew(UCPD_Host_App_Thread, NULL, &UCPD_Host_App_attributes);

  /* Trigger host start path once at boot. */
  boot_msg.HostState = START_USB_HOST;
  if (xQueueSend(UCPD_Host_MsgQueue, &boot_msg, 0) != pdPASS)
  {
    Error_Handler();
  }
}
/* USER CODE END 2 */

/**
  * @}
  */

/**
  * @}
  */

