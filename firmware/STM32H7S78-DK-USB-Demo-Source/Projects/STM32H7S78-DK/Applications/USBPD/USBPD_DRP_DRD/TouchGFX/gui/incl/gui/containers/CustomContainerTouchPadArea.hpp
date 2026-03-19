#ifndef CUSTOMCONTAINERTOUCHPADAREA_HPP
#define CUSTOMCONTAINERTOUCHPADAREA_HPP

#include <gui_generated/containers/CustomContainerTouchPadAreaBase.hpp>

class CustomContainerTouchPadArea : public CustomContainerTouchPadAreaBase
{
public:
    CustomContainerTouchPadArea();
    virtual ~CustomContainerTouchPadArea() {}

    virtual void handleDragEvent(const DragEvent& evt);
    virtual void handleClickEvent(const ClickEvent& evt);

    virtual void initialize();
protected:
};

#endif // CUSTOMCONTAINERTOUCHPADAREA_HPP