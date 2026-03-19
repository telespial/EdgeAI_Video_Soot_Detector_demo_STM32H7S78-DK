#include <gui/screenhost_screen/ScreenHostView.hpp>
#include <touchgfx/Utils.hpp>

extern "C" volatile uint32_t g_usb_host_diag_state;

//  *****   TouchGFX basics   *****

ScreenHostView::ScreenHostView() : interactionSwapToSinkDelayCounter(0), interactionSwapToSourceDelayCounter(0)
{
}

void ScreenHostView::setupScreen()
{
    ScreenHostViewBase::setupScreen();
    imageUSB1.setVisible(false);
    imageUSB1.invalidate();
    imageUSB2.setVisible(false);
    imageUSB2.invalidate();
    animatedImageInput.setVisible(false);
    animatedImageInput.invalidate();
    animatedImageOutput.setVisible(false);
    animatedImageOutput.invalidate();
}

void ScreenHostView::tearDownScreen()
{ScreenHostViewBase::tearDownScreen();}


//  *****   Propagate actions on screen to the model to be transfered through USB   *****

void ScreenHostView::functionPropagateSwappedToDevice()
{presenter->propagateSwappedToDevice();}

void ScreenHostView::functionPropagateSwapToSink()
{presenter->propagateSwappedToSink();}

void ScreenHostView::functionPropagateSwapToSource()
{presenter->propagateSwappedToSource();}


//  *****   Get and set of power state and screen   *****

int ScreenHostView::getPowerState()
{return presenter->getPowerState();}

int ScreenHostView::getCurrentScreen()
{return presenter->getCurrentScreen();}

void ScreenHostView::setPowerState(int val)
{presenter->setPowerState(val);}

void ScreenHostView::setCurrentScreen(int val)
{presenter->setCurrentScreen(val);}


//  *****   When receiving order to swap power type (source or sink)   *****

void ScreenHostView::swapToSink()
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
        //animatedImagePower.startAnimation(true, true, false);
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

void ScreenHostView::swapToSource() 
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
        //animatedImagePower.startAnimation(false, true, false);
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


//  *****   When receiving new drag delta   *****

void ScreenHostView::updateCursorPosition(position pos)
{
    (void)pos;
}


//  *****   When receiving a clic   *****

void ScreenHostView::displayRedCursor()
{
}


//  *****   handle tick event   *****

void ScreenHostView::handleTickEvent()
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
