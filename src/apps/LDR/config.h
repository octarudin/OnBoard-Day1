#ifndef __SENSORTASK_CONFIG_H__
#define __SENSORTASK_CONFIG_H__

#include <Arduino.h>

namespace ldr
{
    namespace cfg
    {
        const extern char *KERNEL_NAME;
        const extern uint32_t KERNEL_STACK_SIZE;
        const extern uint8_t KERNEL_PRIORITY;
        const extern uint8_t KERNEL_CORE;
        const extern uint64_t KERNEL_DELAY_TICKS;
        const extern uint16_t KERNEL_TRANSPORT_QUEUE_LEN;

        const extern uint8_t SENSOR_PIN;
    }
}

#endif