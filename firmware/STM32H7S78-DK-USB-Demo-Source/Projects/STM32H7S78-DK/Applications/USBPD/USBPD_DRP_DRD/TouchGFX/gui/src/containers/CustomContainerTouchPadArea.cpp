#include <gui/containers/CustomContainerTouchPadArea.hpp>
#include <touchgfx/events/clickEvent.hpp>

CustomContainerTouchPadArea::CustomContainerTouchPadArea()
{

}

void CustomContainerTouchPadArea::initialize()
{
    CustomContainerTouchPadAreaBase::initialize();

    setTouchable(true); //have to add that to set the container as touchable to fetch the drag
}

void CustomContainerTouchPadArea::handleDragEvent(const DragEvent& evt)
{
    if( ( (evt.getNewX() >=0) && (evt.getNewX() <= this->getWidth()) )
     && ( (evt.getNewY() >=0) && (evt.getNewY() <= this->getHeight()) )) //if dragged in touchpad area
    {
        position pos;
        pos.xPos = evt.getDeltaX();
        pos.yPos = evt.getDeltaY();
        actionContainerDragged(pos);
    }
}

void CustomContainerTouchPadArea::handleClickEvent(const ClickEvent& evt)
{
    if(evt.getType() == ClickEvent::PRESSED)
    {
        position pos;
        pos.xPos = evt.getX();
        pos.yPos = evt.getY();
        actionContainerClicked(pos);
    }
    if(evt.getType() == ClickEvent::RELEASED)
    {
        position pos;
        pos.xPos = evt.getX();
        pos.yPos = evt.getY();
        actionContainerReleased(pos);
    }
}