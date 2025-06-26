#ifndef __LEDTASK_KERNEL_H__
#define __LEDTASK_KERNEL_H__

#include <Arduino.h>
#include "utils.h"



namespace led
{
    
    struct Instance
    {
        HardwareSerial ser = Serial;
    };

    // func about kernel
    void kernelInit();
    void kernelLoop(Instance *inst);
    void kernelTask(void *pvParameters);
    void startKernel();

    // void setKernelStatus(KernelStatus status);   // already defined in utils.cpp
    // KernelStatus getKernelStatus();              // already defined in utils.cpp
    
    
    // private func in kernel
    namespace func
    {
        
    }
}

#endif