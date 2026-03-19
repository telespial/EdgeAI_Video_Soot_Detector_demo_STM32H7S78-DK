#ifndef SCREENHOSTVIEW_HPP
#define SCREENHOSTVIEW_HPP

#include <gui_generated/screenhost_screen/ScreenHostViewBase.hpp>
#include <gui/screenhost_screen/ScreenHostPresenter.hpp>

class ScreenHostView : public ScreenHostViewBase
{
public:
    ScreenHostView();
    virtual ~ScreenHostView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SCREENHOSTVIEW_HPP
