#ifndef __SENSORTASK_UTILS_H__
#define __SENSORTASK_UTILS_H__

#include <Arduino.h>
#include "config.h"
#include "registry.h"
#include "transport.h"

namespace ldr
{
    namespace utl
    {
        void setKernelStatus(KernelStatus status);
        KernelStatus getKernelStatus();
        void suspendKernel();
        void resumeKernel();
        void terminateKernel();
    }
}

#endif