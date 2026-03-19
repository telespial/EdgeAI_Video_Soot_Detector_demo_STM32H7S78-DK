#ifndef SCREENDEVICEPRESENTER_HPP
#define SCREENDEVICEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class ScreenDeviceView;

class ScreenDevicePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    ScreenDevicePresenter(ScreenDeviceView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~ScreenDevicePresenter() {}

    //screen swap
    void propagateSwappedToHost();
    void gotoScreenHost();
    void gotoScreenWaiting();

    //power swap
    void propagateSwappedToSink();
    void propagateSwappedToSource();
    virtual void swapToSink();
    virtual void swapToSource();

    //get and set
    int getPowerState()
    {return model->getPowerState();}

    int getCurrentScreen()
    {return model->getCurrentScreen();}

    void setPowerState(int val)
    {model->setPowerState(val);}

    void setCurrentScreen(int val)
    {model->setCurrentScreen(val);}

    // propagate drag, click and release
    void propagateDragDelta(position value);
    void propagateClicked(position value);
    void propagateReleased(position value);

private:
    ScreenDevicePresenter();

    ScreenDeviceView& view;
};

#endif // SCREENDEVICEPRESENTER_HPP
