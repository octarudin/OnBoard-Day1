#ifndef __SENSORTASK_TRANSPORT_H__
#define __SENSORTASK_TRANSPORT_H__

#include <Arduino.h>
#include "config.h"

namespace ldr
{
    namespace trp
    {
        namespace types
        {
            enum TransportTypes : uint8_t
            {
                NONE,
                SET_DELAY
            };
        }

        namespace models
        {
            struct Generic
            {
                types::TransportTypes type = types::NONE;
                void *dataPtr = nullptr;
            };

        }

        extern QueueHandle_t queue;
    }
}

#endif