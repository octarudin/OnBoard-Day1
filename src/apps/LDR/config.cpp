#include "config.h"

namespace ldr
{
    namespace cfg
    {
        const char *KERNEL_NAME = "SensorTask";
        const uint32_t KERNEL_STACK_SIZE = 4096;
        const uint8_t KERNEL_PRIORITY = 1;
        const uint8_t KERNEL_CORE = 1;
        const uint64_t KERNEL_DELAY_TICKS = 500;
        const uint16_t KERNEL_TRANSPORT_QUEUE_LEN = 16;

        const uint8_t SENSOR_PIN = 34;
    }
}