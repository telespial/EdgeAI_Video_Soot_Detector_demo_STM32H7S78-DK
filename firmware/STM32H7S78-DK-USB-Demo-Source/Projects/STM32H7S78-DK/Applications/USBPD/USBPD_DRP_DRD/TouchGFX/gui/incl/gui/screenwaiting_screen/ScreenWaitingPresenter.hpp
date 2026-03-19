#ifndef SCREENWAITINGPRESENTER_HPP
#define SCREENWAITINGPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class ScreenWaitingView;

class ScreenWaitingPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    ScreenWaitingPresenter(ScreenWaitingView& v);

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

    virtual ~ScreenWaitingPresenter() {}

    void gotoScreenDevice();
    void gotoScreenHost();

    //get and set
    int getPowerState()
    {return model->getPowerState();}

    int getCurrentScreen()
    {return model->getCurrentScreen();}

    void setPowerState(int val)
    {model->setPowerState(val);}

    void setCurrentScreen(int val)
    {model->setCurrentScreen(val);}

    //power
    virtual void swapToSink();
    virtual void swapToSource();

private:
    ScreenWaitingPresenter();

    ScreenWaitingView& view;
};

#endif // SCREENWAITINGPRESENTER_HPP
