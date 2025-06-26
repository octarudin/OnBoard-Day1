#include "config.h"

namespace led
{
    namespace cfg
    {
        const char *KERNEL_NAME = "LedTask";
        const uint32_t KERNEL_STACK_SIZE = 4096;
        const uint8_t KERNEL_PRIORITY = 2;
        const uint8_t KERNEL_CORE = 1;
        const uint64_t KERNEL_DELAY_TICKS = 1; // we dont use this one
        const uint16_t KERNEL_TRANSPORT_QUEUE_LEN = 32;

        const uint8_t LED_PIN = 2;
        const uint16_t LED_DELAY_ON = 1000;
        const uint16_t LED_DELAY_OFF = 800;
    }
}