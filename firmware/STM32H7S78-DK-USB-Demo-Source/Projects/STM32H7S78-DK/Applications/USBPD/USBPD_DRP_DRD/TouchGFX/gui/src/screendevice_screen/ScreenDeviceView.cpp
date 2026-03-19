#include <gui/screendevice_screen/ScreenDeviceView.hpp>
#include <touchgfx/Utils.hpp>
#include <touchgfx/Color.hpp>

extern "C" volatile uint32_t g_usb_host_diag_state;

//  *****   TouchGFX basics   *****

ScreenDeviceView::ScreenDeviceView() : interactionSwapToSinkDelayCounter(0), interactionSwapToSourceDelayCounter(0)
{
}

void ScreenDeviceView::setupScreen()
{
    ScreenDeviceViewBase::setupScreen();
    imageUSB1.setVisible(false);
    imageUSB1.invalidate();
    imageUSB2.setVisible(false);
    imageUSB2.invalidate();
    animatedImageInput.setVisible(false);
    animatedImageInput.invalidate();
    animatedImageOutput.setVisible(false);
    animatedImageOutput.invalidate();

    usbDiagBox.setPosition(12, 12, 42, 42);
    usbDiagBox.setColor(touchgfx::Color::getColorFromRGB(96, 0, 0)); /* idle/offline = dark red */
    add(usbDiagBox);
    usbDiagBox.invalidate();
}

void ScreenDeviceView::tearDownScreen()
{ScreenDeviceViewBase::tearDownScreen();}


//  *****   Propagate actions on screen to the model to be transfered through USB   *****

void ScreenDeviceView::functionPropagateSwappedToHost()
{presenter->propagateSwappedToHost();}

void ScreenDeviceView::functionPropagateSwapToSink()
{presenter->propagateSwappedToSink();}

void ScreenDeviceView::functionPropagateSwapToSource()
{presenter->propagateSwappedToSource();}


//  *****   Get and set of power state and screen   *****

int ScreenDeviceView::getPowerState()
{return presenter->getPowerState();}

int ScreenDeviceView::getCurrentScreen()
{return presenter->getCurrentScreen();}

void ScreenDeviceView::setPowerState(int val)
{presenter->setPowerState(val);}

void ScreenDeviceView::setCurrentScreen(int val)
{presenter->setCurrentScreen(val);}


//  *****   When receiving order to swap power type (source or sink)   *****

void ScreenDeviceView::swapToSink()
{
    if(presenter->getPowerState() == SOURCESTATE)	//previously in source state
    {
        imageSource.setVisible(false);
        imageSource.invalidate();
        imageSink.setVisible(false);
        imageSink.invalidate();
        animatedImagePower.setVisible(true);
        animatedImagePower.invalidate();
        animatedImagePower.startAnimation(true, true, false);
        animatedImageOutput.setVisible(false);
        animatedImageOutput.invalidate();
        animatedImageInput.setVisible(true);
        animatedImageInput.invalidate();
        imageCharging.setVisible(true);
        imageCharging.invalidate();
        presenter->setPowerState(SINKSTATE);
        flexButtonSwapToSink.setTouchable(false);
        flexButtonSwapToSource.setTouchable(true);
    }

    if(presenter->getPowerState() == UNKNOWNPOWERSTATE)	//previously in UNKNOWNPOWERSTATE
    {
        imageSource.setVisible(false);
        imageSource.invalidate();
        imageSink.setVisible(true);
        imageSink.invalidate();
        animatedImagePower.setVisible(false);
        animatedImagePower.invalidate();
        animatedImageOutput.setVisible(false);
        animatedImageOutput.invalidate();
        animatedImageInput.setVisible(true);
        animatedImageInput.invalidate();
        imageCharging.setVisible(true);
        imageCharging.invalidate();
        presenter->setPowerState(SINKSTATE);
        flexButtonSwapToSink.setTouchable(false);
        flexButtonSwapToSource.setTouchable(true);
    }
}

void ScreenDeviceView::swapToSource()
{
    if(presenter->getPowerState() == SINKSTATE)	//previously in sink state
    {
        imageSource.setVisible(false);
        imageSource.invalidate();
        imageSink.setVisible(false);
        imageSink.invalidate();
        animatedImagePower.setVisible(true);
        animatedImagePower.invalidate();
        animatedImagePower.startAnimation(false, true, false);
        animatedImageOutput.setVisible(true);
        animatedImageOutput.invalidate();
        animatedImageInput.setVisible(false);
        animatedImageInput.invalidate();
        imageCharging.setVisible(false);
        imageCharging.invalidate();
        presenter->setPowerState(SOURCESTATE);
        flexButtonSwapToSink.setTouchable(true);
        flexButtonSwapToSource.setTouchable(false);
    }

    if(presenter->getPowerState() == UNKNOWNPOWERSTATE)	//previously in UNKNOWNPOWERSTATE
    {
        imageSource.setVisible(true);
        imageSource.invalidate();
        imageSink.setVisible(false);
        imageSink.invalidate();
        animatedImagePower.setVisible(false);
        animatedImagePower.invalidate();
        animatedImageOutput.setVisible(true);
        animatedImageOutput.invalidate();
        animatedImageInput.setVisible(false);
        animatedImageInput.invalidate();
        imageCharging.setVisible(false);
        imageCharging.invalidate();
        presenter->setPowerState(SOURCESTATE);
        flexButtonSwapToSink.setTouchable(true);
        flexButtonSwapToSource.setTouchable(false);
    }
}


//  *****   Propagate positions dragged on screen to the model to be transfered through USB   *****

void ScreenDeviceView::functionPropagateDragDelta(position value)
{presenter->propagateDragDelta(value);}

void ScreenDeviceView::functionPropagateClicked(position value)
{presenter->propagateClicked(value);}

void ScreenDeviceView::functionPropagateReleased(position value)
{presenter->propagateReleased(value);}

void ScreenDeviceView::handleTickEvent()
{
    uint32_t diag = g_usb_host_diag_state;
    if (diag != lastUsbDiagState)
    {
        lastUsbDiagState = diag;

        uint8_t r = 96U;
        uint8_t g = 0U;
        uint8_t b = 0U;

        /* 0:idle, 1:connected/wait, 2:camera detected, 3:camera active, 4:HID active, 6:unsupported */
        if (diag == 1U)
        {
            r = 180U; g = 130U; b = 0U;   /* amber */
        }
        else if (diag == 2U)
        {
            r = 0U; g = 70U; b = 170U;    /* blue */
        }
        else if (diag == 3U)
        {
            r = 0U; g = 170U; b = 0U;     /* green */
        }
        else if (diag == 4U)
        {
            r = 220U; g = 220U; b = 220U; /* white/gray = HID active */
        }
        else if (diag == 6U)
        {
            r = 170U; g = 0U; b = 170U;   /* magenta = unsupported class */
        }

        usbDiagBox.setColor(touchgfx::Color::getColorFromRGB(r, g, b));
        usbDiagBox.invalidate();
    }
}
