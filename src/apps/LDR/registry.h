#ifndef __SENSORTASK_REGISTRY_H__
#define __SENSORTASK_REGISTRY_H__

#include <Arduino.h>

namespace ldr
{
    enum KernelStatus : uint8_t
    {
        KERNEL_STATUS_NONE,
        KERNEL_STATUS_INIT,
        KERNEL_STATUS_RUNNING,
        KERNEL_STATUS_SUSPENDED,
        KERNEL_STATUS_TERMINATED
    };
    
    struct SensorRegistry
    {
        SemaphoreHandle_t mtx = xSemaphoreCreateMutex();
        TaskHandle_t kernelHandle = NULL;
        KernelStatus kernelStatus = KERNEL_STATUS_INIT;

        uint64_t analogValue;
    };

    extern SensorRegistry reg;
}

#endif