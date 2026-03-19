#include <gui/screenwaiting_screen/ScreenWaitingView.hpp>
#include <gui/screenwaiting_screen/ScreenWaitingPresenter.hpp>

ScreenWaitingPresenter::ScreenWaitingPresenter(ScreenWaitingView& v)
    : view(v)
{

}

void ScreenWaitingPresenter::activate()
{

}

void ScreenWaitingPresenter::deactivate()
{

}

void ScreenWaitingPresenter::gotoScreenDevice()
{
    static_cast<FrontendApplication*>(Application::getInstance())->gotoScreenDeviceScreenNoTransition();
}

void ScreenWaitingPresenter::gotoScreenHost()
{
    static_cast<FrontendApplication*>(Application::getInstance())->gotoScreenHostScreenNoTransition();
}

//  *****   When receiving order to swap power type (source or sink)   *****

void ScreenWaitingPresenter::swapToSink()
{view.swapToSink();}

void ScreenWaitingPresenter::swapToSource()
{view.swapToSource();}