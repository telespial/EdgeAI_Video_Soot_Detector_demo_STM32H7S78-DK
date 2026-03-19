#ifndef SCREENWAITINGVIEW_HPP
#define SCREENWAITINGVIEW_HPP

#include <gui_generated/screenwaiting_screen/ScreenWaitingViewBase.hpp>
#include <gui/screenwaiting_screen/ScreenWaitingPresenter.hpp>

class ScreenWaitingView : public ScreenWaitingViewBase
{
public:
    ScreenWaitingView();
    virtual ~ScreenWaitingView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    //get and set
    int getPowerState()
    {return presenter->getPowerState();}

    int getCurrentScreen()
    {return presenter->getCurrentScreen();}

    void setPowerState(int val)
    {presenter->setPowerState(val);}

    void setCurrentScreen(int val)
    {presenter->setCurrentScreen(val);}

    //power
    void swapToSink();
    void swapToSource();

    void handleTickEvent();
    
protected:
    int tickCount = 0;
    uint32_t lastUsbDiagState = 0xFFFFFFFFUL;
};

#endif // SCREENWAITINGVIEW_HPP
