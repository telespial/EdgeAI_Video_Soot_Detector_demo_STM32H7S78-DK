#include <gui/screenhost_screen/ScreenHostView.hpp>
#include <gui/screenhost_screen/ScreenHostPresenter.hpp>


//  *****   TouchGFX basics   *****

ScreenHostPresenter::ScreenHostPresenter(ScreenHostView& v)
    : view(v)
{
}

void ScreenHostPresenter::activate()
{
}

void ScreenHostPresenter::deactivate()
{
}


//  *****   Propagate actions on screen to the model to be transfered through USB   *****

void ScreenHostPresenter::propagateSwappedToDevice()
{model->sendSwappedFromHostToDevice();}


//  *****   Propagate actions on screen to the model to be transfered through USB   *****

void ScreenHostPresenter::propagateSwappedToSink()
{model->sendSwappedFromSourceToSink();}

void ScreenHostPresenter::propagateSwappedToSource()
{model->sendSwappedFromSinkToSource();}


//  *****   When receiving order to swap screen (device or waiting)   *****

void ScreenHostPresenter::gotoScreenDevice()
{static_cast<FrontendApplication*>(Application::getInstance())->gotoScreenDeviceScreenNoTransition();}

void ScreenHostPresenter::gotoScreenWaiting()
{static_cast<FrontendApplication*>(Application::getInstance())->gotoScreenWaitingScreenNoTransition();}


//  *****   When receiving order to swap power type (source or sink)   *****

void ScreenHostPresenter::swapToSink()
{view.swapToSink();}

void ScreenHostPresenter::swapToSource()
{view.swapToSource();}


//  *****   When receiving new drag delta   *****

void ScreenHostPresenter::updateCursorPosition(position pos)
{view.updateCursorPosition(pos);}


//  *****   When receiving a clic   *****

void ScreenHostPresenter::displayRedCursor()
{view.displayRedCursor();}