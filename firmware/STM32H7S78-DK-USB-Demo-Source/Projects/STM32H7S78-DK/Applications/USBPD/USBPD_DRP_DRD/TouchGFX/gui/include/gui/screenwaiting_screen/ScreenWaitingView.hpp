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
protected:
};

#endif // SCREENWAITINGVIEW_HPP
