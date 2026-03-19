#ifndef SCREENDEVICEVIEW_HPP
#define SCREENDEVICEVIEW_HPP

#include <gui_generated/screendevice_screen/ScreenDeviceViewBase.hpp>
#include <gui/screendevice_screen/ScreenDevicePresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/hal/Types.hpp>

class ScreenDeviceView : public ScreenDeviceViewBase
{
public:
    ScreenDeviceView();
    virtual ~ScreenDeviceView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent();

    //Screen swap
    void functionPropagateSwappedToHost();
    void goToScreenWaiting();

    //Power swap
    void functionPropagateSwapToSink();
    void functionPropagateSwapToSource();
    void swapToSink();
    void swapToSource();

    //get and set
    int getPowerState();
    int getCurrentScreen();
    void setPowerState(int val);
    void setCurrentScreen(int val);

    // propagate drag
    void functionPropagateDragDelta(position value);
    void functionPropagateClicked(position value);
    void functionPropagateReleased(position value);

protected:
    uint16_t interactionSwapToSinkDelayCounter;
    uint16_t interactionSwapToSourceDelayCounter;
    touchgfx::Box usbDiagBox;
    uint32_t lastUsbDiagState = 0xFFFFFFFFUL;
};

#endif // SCREENDEVICEVIEW_HPP
