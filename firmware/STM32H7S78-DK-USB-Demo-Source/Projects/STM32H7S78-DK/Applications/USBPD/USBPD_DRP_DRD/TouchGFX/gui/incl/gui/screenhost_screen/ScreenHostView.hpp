#ifndef SCREENHOSTVIEW_HPP
#define SCREENHOSTVIEW_HPP

#include <gui_generated/screenhost_screen/ScreenHostViewBase.hpp>
#include <gui/screenhost_screen/ScreenHostPresenter.hpp>
#include <touchgfx/hal/Types.hpp>

class ScreenHostView : public ScreenHostViewBase
{
public:
    ScreenHostView();
    virtual ~ScreenHostView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent();

    //Screen swap
    void functionPropagateSwappedToDevice();
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

    //drag
    void updateCursorPosition(position pos);

    //clic
    void displayRedCursor();

protected:
    uint16_t interactionSwapToSinkDelayCounter;
    uint16_t interactionSwapToSourceDelayCounter;
    uint32_t lastUsbDiagState = 0xFFFFFFFFUL;
};

#endif // SCREENHOSTVIEW_HPP
