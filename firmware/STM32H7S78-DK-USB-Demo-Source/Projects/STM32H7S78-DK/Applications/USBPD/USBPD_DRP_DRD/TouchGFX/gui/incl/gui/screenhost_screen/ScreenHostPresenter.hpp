#ifndef SCREENHOSTPRESENTER_HPP
#define SCREENHOSTPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class ScreenHostView;

class ScreenHostPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    ScreenHostPresenter(ScreenHostView& v);

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

    virtual ~ScreenHostPresenter() {}

    //screen swap
    void propagateSwappedToDevice();
    void gotoScreenDevice();
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

    //drag
    virtual void updateCursorPosition(position pos);

    //clic
    virtual void displayRedCursor();

private:
    ScreenHostPresenter();

    ScreenHostView& view;
};

#endif // SCREENHOSTPRESENTER_HPP
