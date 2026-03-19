#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}

    void bind(Model* m)
    {
        model = m;
    }

    virtual void gotoScreenHost() {}
    virtual void gotoScreenDevice() {}
    virtual void gotoScreenWaiting() {}
    virtual void swapToSink() {}
    virtual void swapToSource() {}
    virtual void updateCursorPosition(position pos) {}
    virtual void displayRedCursor() {}
    
protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
