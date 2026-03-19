#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <touchgfx/Utils.hpp>
#include "main.h"
#include "usbpd.h"
#include "usbpd_trace.h"
#include "queue.h"
#include "cmsis_os2.h"

//  *****   TouchGFX basics   *****

Model::Model() : modelListener(0), powerState(UNKNOWNPOWERSTATE), currentScreen(WAITINGSCREEN)
{}

void Model::tick()
{
  uint8_t Demo_Message;
  if (DPM_Params[0].PE_IsConnected ==1) // we can receive USBPD updated data role from distant
  {
    while (osMessageQueueGetCount(demoQueue_USBPD_Event) >0)  // if we got a request to update USBPD role
    {
      osMessageQueueGet(demoQueue_USBPD_Event, &Demo_Message, NULL, 0);
      
      switch (Demo_Message) {
      case DATA_CHANGE_TO_UFP : // USBPD data role switch to Device
        {
          modelListener->gotoScreenDevice();
          USBPD_TRACE_Add(USBPD_TRACE_DEBUG, 0U, 0U, (uint8_t*)"UFP notif change    ", 20U);
          break;
        }
        
      case DATA_CHANGE_TO_DFP :  // USBPD data role switch to Host
        {
          modelListener->gotoScreenHost();
          USBPD_TRACE_Add(USBPD_TRACE_DEBUG, 0U, 0U, (uint8_t*)"DFP notif change    ", 20U);
          break;
        }
        
      case POWER_CHANGE_TO_SRC :  // we get an update to switch to source
        {
          modelListener->swapToSource(); // need to update graphical power role (without sending PD message)
          USBPD_TRACE_Add(USBPD_TRACE_DEBUG, 0U, 0U, (uint8_t*)"swap to SRC notif   ", 20U);
          break;
        }
        
      case POWER_CHANGE_TO_SNK :  // we get a request to switch to sink
        {
          modelListener->swapToSink(); // need to update graphical power role (without sending PD message)
          USBPD_TRACE_Add(USBPD_TRACE_DEBUG, 0U, 0U, (uint8_t*)"swap to SNK notif   ", 20U);
          break;
        }
        
      case UPDATE_SCREEN :              // we finalised USBPD contract, we can now do Data Role Swap, or Power Role Swap
        {
          explicit_contract_reached = 1;
          if (DPM_Params[0].PE_PowerRole == USBPD_PORTPOWERROLE_SNK) 
          {
            modelListener->swapToSink(); // need to update graphical power role (without sending PD message)
            USBPD_TRACE_Add(USBPD_TRACE_DEBUG, 0U, 0U, (uint8_t*)"Explicit sink       ", 20U);
          }
          else if (DPM_Params[0].PE_PowerRole == USBPD_PORTPOWERROLE_SRC)
          {
            modelListener->swapToSource(); // need to update graphical power role (without sending PD message)
            USBPD_TRACE_Add(USBPD_TRACE_DEBUG, 0U, 0U, (uint8_t*)"Explicit source    ", 20U);
          }
          else
          {
            USBPD_TRACE_Add(USBPD_TRACE_DEBUG, 0U, 0U, (uint8_t*)"Error power          ", 20U);
          }
          
          if (DPM_Params[0].PE_DataRole == USBPD_PORTDATAROLE_DFP)
          {
            modelListener->gotoScreenHost();
            USBPD_TRACE_Add(USBPD_TRACE_DEBUG, 0U, 0U, (uint8_t*)"Explicit Host       ", 20U);
          }
          else if (DPM_Params[0].PE_DataRole == USBPD_PORTDATAROLE_UFP)
          {
            modelListener->gotoScreenDevice();
            USBPD_TRACE_Add(USBPD_TRACE_DEBUG, 0U, 0U, (uint8_t*)"Explicit Device     ", 20U);
          }
          else
          {
            USBPD_TRACE_Add(USBPD_TRACE_DEBUG, 0U, 0U, (uint8_t*)"Error data          ", 20U);
          }
          break;
        }
      case NO_PD : 
        {
          if (DPM_Params[0].PE_PowerRole == USBPD_PORTPOWERROLE_SNK) 
          {
            modelListener->swapToSink(); 
            modelListener->gotoScreenDevice(); /* Default and only USB role is Device */
            USBPD_TRACE_Add(USBPD_TRACE_DEBUG, 0U, 0U, (uint8_t*)"No PD sink       ", 17U);
          }
          else if (DPM_Params[0].PE_PowerRole == USBPD_PORTPOWERROLE_SRC)
          {
            modelListener->swapToSource(); 
            modelListener->gotoScreenHost(); /* Default and only USB role is Host */
            USBPD_TRACE_Add(USBPD_TRACE_DEBUG, 0U, 0U, (uint8_t*)"No PD source    ", 16U);
          }
          else
          {
            USBPD_TRACE_Add(USBPD_TRACE_DEBUG, 0U, 0U, (uint8_t*)"Error power          ", 20U);
          }
          break;
        }
      } /* end case */
    } /*  while osMessageQueueGetCount(demoQueue_USBPD_Event) >0 */
    
  }
  else /* we are not connected */
  {
    powerState = UNKNOWNPOWERSTATE;
    currentScreen = WAITINGSCREEN;
    modelListener->gotoScreenWaiting();
    explicit_contract_reached = 0;
  }
}


//  *****   Send info to the other board throught USB   *****
// These functions are called when the user clicks on the toggle buttons
// You should implement the code (or call functions) to send that data throught USB

void Model::sendSwappedFromHostToDevice()
{
    /*Implement your code here*/
    if (explicit_contract_reached == 1)
    {
      USBPD_TRACE_Add(USBPD_TRACE_DEBUG, 0U, 0U, (uint8_t*)"DR swap H2D TGFX req", 20U);
      USBPD_PE_Request_CtrlMessage(0, USBPD_CONTROLMSG_DR_SWAP, USBPD_SOPTYPE_SOP);
    }
    else
    {
      USBPD_TRACE_Add(USBPD_TRACE_DEBUG, 0U, 0U, (uint8_t*)"DR swap not possible", 20U);
      //modelListener->gotoScreenHost(); /* stay on host screen */
      Demo_Message = NO_PD;
      osMessageQueuePut(demoQueue_USBPD_Event, &Demo_Message, 0,0);
    }
}

void Model::sendSwappedFromDeviceToHost()
{
    /*Implement your code here*/
    if (explicit_contract_reached == 1)
    {
      USBPD_PE_Request_CtrlMessage(0, USBPD_CONTROLMSG_DR_SWAP, USBPD_SOPTYPE_SOP);
      USBPD_TRACE_Add(USBPD_TRACE_DEBUG, 0U, 0U, (uint8_t*)"DR swap D2H TGFX req", 20U);
    }
    else
    {
      USBPD_TRACE_Add(USBPD_TRACE_DEBUG, 0U, 0U, (uint8_t*)"DR swap not possible", 20U);
      Demo_Message = NO_PD;
      osMessageQueuePut(demoQueue_USBPD_Event, &Demo_Message, 0,0);
    }
}

void Model::sendSwappedFromSourceToSink()
{
  /*Implement your code here*/
  if (explicit_contract_reached == 1)
  {
    USBPD_TRACE_Add(USBPD_TRACE_DEBUG, 0U, 0U, (uint8_t*)"PR swap to sink TGFX req", 24U);
    USBPD_StatusTypeDef _status = USBPD_PE_Request_CtrlMessage(0, USBPD_CONTROLMSG_PR_SWAP, USBPD_SOPTYPE_SOP);
  }
  else
  {
    USBPD_TRACE_Add(USBPD_TRACE_DEBUG, 0U, 0U, (uint8_t*)"PR swap not possible", 20U);
    Demo_Message = NO_PD;
    osMessageQueuePut(demoQueue_USBPD_Event, &Demo_Message, 0,0);
  }
}

void Model::sendSwappedFromSinkToSource()
{
  /*Implement your code here*/
  if (explicit_contract_reached == 1)
  {
    USBPD_TRACE_Add(USBPD_TRACE_DEBUG, 0U, 0U, (uint8_t*)"PR swap to src TGFX req", 23U);
    USBPD_StatusTypeDef _status = USBPD_PE_Request_CtrlMessage(0, USBPD_CONTROLMSG_PR_SWAP, USBPD_SOPTYPE_SOP);
  }
  else
  {
    USBPD_TRACE_Add(USBPD_TRACE_DEBUG, 0U, 0U, (uint8_t*)"PR swap not possible", 20U);
    Demo_Message = NO_PD;
    osMessageQueuePut(demoQueue_USBPD_Event, &Demo_Message, 0,0);
  }
}

void Model::sendDragDelta(position value)
{
  (void)value;
}


//  *****   Receive info from the other board throught USB   *****
// When we receive data from the USB we should call these functions
// These functions when called change the display
void Model::receiveDrag(position pos)
{
    (void)pos;
}


void Model::sendClicked(position pos)
{
  (void)pos;
}

void Model::sendReleased(position pos)
{
  (void)pos;
}

void Model::receivedUsbDisconnected()
{
}

void Model::receivedSwapToDeviceOrder()
{
}

void Model::receivedSwapToHostOrder()
{
}

void Model::receivedSwapToSinkOrder()
{
}

void Model::receivedSwapToSourceOrder()
{
}

void Model::receiveClic()
{
}


//  *****   Get and set   *****

int Model::getPowerState()
{return powerState;}

int Model::getCurrentScreen()
{return currentScreen;}

void Model::setPowerState(int val)
{powerState = val;}

void Model::setCurrentScreen(int val)
{currentScreen = val;}
