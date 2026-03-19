#include <touchgfx/hal/types.hpp>
#include <string.h>

#ifndef MODEL_HPP
#define MODEL_HPP

//Power state source / Sink
#define UNKNOWNPOWERSTATE -1
#define SOURCESTATE 1
#define SINKSTATE 0

//Current Screen
#define WAITINGSCREEN 0
#define DEVICESCREEN 1
#define HOSTSCREEN 2

#define POWER_CHANGE_ATTACH     1
#define POWER_CHANGE_DETACH     2
#define POWER_CHANGE_TO_SRC     3
#define POWER_CHANGE_TO_SNK     4
#define DATA_CHANGE_TO_UFP      5
#define DATA_CHANGE_TO_DFP      6
#define UPDATE_SCREEN           7
#define NO_PD                   8

struct position
{
    int8_t xPos;
    int8_t yPos;
};

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();

    //  *****   Send info to the other board throught USB   *****
    void sendSwappedFromHostToDevice();
    void sendSwappedFromDeviceToHost();
    void sendSwappedFromSourceToSink();
    void sendSwappedFromSinkToSource();

    //  *****   Receive info from the other board throught USB   *****
    void receivedUsbDisconnected();
    void receivedSwapToDeviceOrder();
    void receivedSwapToHostOrder();
    void receivedSwapToSinkOrder();
    void receivedSwapToSourceOrder();
    void receiveDrag(position pos);

    //get and set
    int getPowerState();
    int getCurrentScreen();
    void setPowerState(int val);
    void setCurrentScreen(int val);

    //  *****   Send drag info to the other board throught USB   *****
    void sendDragDelta(position value);
    void sendClicked(position pos);
    void sendReleased(position pos);
    void receiveClic();
    position pos;

protected:
    ModelListener* modelListener;

    int powerState = SOURCESTATE;
    int currentScreen = WAITINGSCREEN;
    int explicit_contract_reached = 0;
    uint8_t Demo_Message;
};

#endif // MODEL_HPP
