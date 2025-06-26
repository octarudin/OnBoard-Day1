#ifndef __LEDTASK_REGISTRY_H__
#define __LEDTASK_REGISTRY_H__

#include <Arduino.h>

namespace led
{
    enum KernelStatus : uint8_t
    {
        KERNEL_STATUS_NONE,
        KERNEL_STATUS_INIT,
        KERNEL_STATUS_RUNNING,
        KERNEL_STATUS_SUSPENDED,
        KERNEL_STATUS_TERMINATED
    };

    enum LedStatus : uint8_t
    {
        LED_STATUS_OFF,
        LED_STATUS_ON
    };

    struct LedRegistry
    {
        SemaphoreHandle_t mtx = xSemaphoreCreateMutex();
        TaskHandle_t kernelHandle = NULL;
        KernelStatus kernelStatus = KERNEL_STATUS_NONE;
        
        // Put any required variable below!
        LedStatus LED_Status = LED_STATUS_OFF;
        uint64_t LedDelay = 500;
    };

    extern LedRegistry reg;
}

#endif