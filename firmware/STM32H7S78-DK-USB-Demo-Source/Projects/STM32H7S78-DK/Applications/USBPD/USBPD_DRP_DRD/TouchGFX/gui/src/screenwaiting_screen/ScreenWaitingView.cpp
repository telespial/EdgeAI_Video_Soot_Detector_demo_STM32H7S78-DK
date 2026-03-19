#include <gui/screenwaiting_screen/ScreenWaitingView.hpp>
#include <cmath>

extern "C" volatile uint32_t g_usb_host_diag_state;

#define IMAGEXPOS 290
#define IMAGEYPOS 170

ScreenWaitingView::ScreenWaitingView()
{

}

void ScreenWaitingView::setupScreen()
{
    ScreenWaitingViewBase::setupScreen();
    invalidate();
    imageArrow.setVisible(false);
    imageArrow.invalidate();
    imageUSB1.setVisible(false);
    imageUSB1.invalidate();
    imageUSB2.setVisible(false);
    imageUSB2.invalidate();
    touchgfx_printf(
    "\t*** Welcome to this menu ***\n\n"
    "(located in ScreenUsbDemoView.cpp, in setupScreen())\n"
    "Here are the keys you can press to simulate interaction :\n"
    "\t- a : disconnect cable (go to waiting screen)\n"
    "\t- q : go to host screen\n"
    "\t- s : go to device screen\n"
    "\t- w : force to source\n"
    "\t- x : force to sink\n"
    "\t- p : receive random drag value\n"
    "\t- m : receive clic\n");
}

void ScreenWaitingView::tearDownScreen()
{
    ScreenWaitingViewBase::tearDownScreen();
}

//  *****   When receiving order to swap power type (source or sink)   *****

void ScreenWaitingView::swapToSink()
{
    presenter->setPowerState(SINKSTATE);
}

void ScreenWaitingView::swapToSource() 
{
    presenter->setPowerState(SOURCESTATE);
}

void ScreenWaitingView::handleTickEvent()
{
    uint32_t diag = g_usb_host_diag_state;
    if (diag != lastUsbDiagState)
    {
        lastUsbDiagState = diag;

        bool usb1Visible = false;
        bool usb2Visible = false;

        /* 0:idle, 1:connected/wait, 2:camera detected, 3:camera active, 4:HID active, 6:unsupported */
        if (diag == 1U)
        {
            usb1Visible = true;
        }
        else if ((diag == 2U) || (diag == 3U))
        {
            usb1Visible = true;
            usb2Visible = true;
        }
        else if (diag == 4U)
        {
            usb2Visible = true;
        }

        imageUSB1.setVisible(usb1Visible);
        imageUSB1.invalidate();
        imageUSB2.setVisible(usb2Visible);
        imageUSB2.invalidate();
    }
}
