#include <gui/screendevice_screen/ScreenDeviceView.hpp>
#include <gui/screendevice_screen/ScreenDevicePresenter.hpp>


//  *****   TouchGFX basics   *****

ScreenDevicePresenter::ScreenDevicePresenter(ScreenDeviceView& v)
    : view(v)
{
}

void ScreenDevicePresenter::activate()
{
}

void ScreenDevicePresenter::deactivate()
{
}


//  *****   Propagate actions on screen to the model to be transfered through USB   *****

void ScreenDevicePresenter::propagateSwappedToHost()
{model->sendSwappedFromDeviceToHost();}


//  *****   Propagate actions on screen to the model to be transfered through USB   *****

void ScreenDevicePresenter::propagateSwappedToSink()
{model->sendSwappedFromSourceToSink();}

void ScreenDevicePresenter::propagateSwappedToSource()
{model->sendSwappedFromSinkToSource();}


//  *****   When receiving order to swap screen (host or waiting)   *****

void ScreenDevicePresenter::gotoScreenHost()
{static_cast<FrontendApplication*>(Application::getInstance())->gotoScreenHostScreenNoTransition();}

void ScreenDevicePresenter::gotoScreenWaiting()
{static_cast<FrontendApplication*>(Application::getInstance())->gotoScreenWaitingScreenNoTransition();}


//  *****   When receiving order to swap power type (source or sink)   *****

void ScreenDevicePresenter::swapToSink()
{view.swapToSink();}

void ScreenDevicePresenter::swapToSource()
{view.swapToSource();}


//  *****   Propagate positions dragged on screen to the model to be transfered through USB   *****

void ScreenDevicePresenter::propagateDragDelta(position value)
{model->sendDragDelta(value);}

void ScreenDevicePresenter::propagateClicked(position value)
{model->sendClicked(value);}

void ScreenDevicePresenter::propagateReleased(position value)
{model->sendReleased(value);}

