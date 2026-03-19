#ifndef SCREENDEVICEVIEW_HPP
#define SCREENDEVICEVIEW_HPP

#include <gui_generated/screendevice_screen/ScreenDeviceViewBase.hpp>
#include <gui/screendevice_screen/ScreenDevicePresenter.hpp>

class ScreenDeviceView : public ScreenDeviceViewBase
{
public:
    ScreenDeviceView();
    virtual ~ScreenDeviceView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SCREENDEVICEVIEW_HPP
