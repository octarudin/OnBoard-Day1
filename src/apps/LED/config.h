#ifndef __LEDTASK_CONFIG_H__
#define __LEDTASK_CONFIG_H__

#include <Arduino.h>

namespace led
{
    namespace cfg
    {
        extern const char *KERNEL_NAME;
        extern const uint32_t KERNEL_STACK_SIZE;
        extern const uint8_t KERNEL_PRIORITY;
        extern const uint8_t KERNEL_CORE;
        extern const uint64_t KERNEL_DELAY_TICKS;
        extern const uint16_t KERNEL_TRANSPORT_QUEUE_LEN;

        extern const uint8_t LED_PIN;
        extern const uint16_t LED_DELAY_ON;
        extern const uint16_t LED_DELAY_OFF;
    }
}

#endif