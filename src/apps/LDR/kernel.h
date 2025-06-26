#ifndef __SENSORTASK_KERNEL_H__
#define __SENSORTASK_KERNEL_H__

#include <Arduino.h>
#include "utils.h"
#include "../LED/utils.h"

namespace ldr
{
    void kernelInit();
    void kernelLoop();
    void kernelTask(void *pvParameters);
    void startKernel();

}

#endif