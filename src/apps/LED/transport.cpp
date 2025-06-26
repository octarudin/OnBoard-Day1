#include "transport.h"

namespace led
{
    namespace trp
    {
        QueueHandle_t queue = xQueueCreate(
            cfg::KERNEL_TRANSPORT_QUEUE_LEN,
            sizeof(uint8_t));
    }
}