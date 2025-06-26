#ifndef __LEDTASK_UTILS_H__
#define __LEDTASK_UTILS_H__

#include <Arduino.h>
#include "config.h"
#include "registry.h"
#include "transport.h"

namespace led
{
    namespace utl
    {
        void setKernelStatus(KernelStatus status);
        KernelStatus getKernelStatus();
        void suspendKernel();
        void resumeKernel();
        void terminateKernel();

        // Define any required utility function for the kernel below!

        void setLedStatus(LedStatus LED_Status);
        LedStatus getLedStatus(void);

        void setLedDelay(uint64_t LED_Delay);
        uint64_t getLedDelay(void);

        void onLedOn(void);
        void onLedOff(void);
    }
}

#endif