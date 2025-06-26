#ifndef __LEDTASK_TRANSPORT_H__
#define __LEDTASK_TRANSPORT_H__

#include <Arduino.h>
#include "config.h"

namespace led
{
    namespace trp
    {
        namespace types
        {
            enum TransportTypes : uint8_t
            {
                NONE,
                SET_LED_OFF,
                SET_LED_ON,
                SET_LED_DELAY
                // add command to suspend and terminal the kernel
            };
        }

        namespace models
        {
            struct Generic
            {
                types::TransportTypes type = types::NONE;
                uint8_t *dataPtr = nullptr;
            };

            struct LedModel
            {
                uint64_t LedDelay;
            };
            
            
        }
        extern QueueHandle_t queue;
    }
}

#endif