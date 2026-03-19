#ifndef FRONTENDAPPLICATION_HPP
#define FRONTENDAPPLICATION_HPP

#include <gui_generated/common/FrontendApplicationBase.hpp>
#include <touchgfx/Utils.hpp>
#include <stdlib.h>
#include <time.h>

class FrontendHeap;

using namespace touchgfx;

class FrontendApplication : public FrontendApplicationBase
{
public:
    FrontendApplication(Model& m, FrontendHeap& heap);
    virtual ~FrontendApplication() { }

    virtual void handleTickEvent()
    {
        #ifdef SIMULATOR
            srand(time(NULL));
        #endif
        model.tick();
        uint8_t myChar;
        if(HAL::getInstance()->sampleKey(myChar))
        {
            touchgfx_printf("\nEntered get instance sample key from application %c : %d\n", myChar, myChar);

            //switch case
            switch (myChar)
            {
                case 'a':
                    model.receivedUsbDisconnected();
                    break;
                case 'q':
                    model.receivedSwapToHostOrder();
                    break;
                case 's':
                    model.receivedSwapToDeviceOrder();
                    break;
                case 'w':
                    model.receivedSwapToSourceOrder();
                    break;
                case 'x':
                    model.receivedSwapToSinkOrder();
                    break;
                case 'p':
                    position pos;
                    pos.xPos = rand()%50-25;
                    pos.yPos = rand()%50-25;
                    model.receiveDrag(pos);
                    break;
                case 'm':
                    model.receiveClic();
                    break;
                default :
                    break;
            }
        }
        FrontendApplicationBase::handleTickEvent();
    }

private:
};

#endif // FRONTENDAPPLICATION_HPP
