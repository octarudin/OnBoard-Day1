#include "utils.h"

void ldr::utl::setKernelStatus(ldr::KernelStatus status)
{
    if (xSemaphoreTake(ldr::reg.mtx, portMAX_DELAY) == pdTRUE)
    {
        ldr::reg.kernelStatus = status;
        xSemaphoreGive(ldr::reg.mtx);
    }
}

ldr::KernelStatus ldr::utl::getKernelStatus()
{
    ldr::KernelStatus status = ldr::KERNEL_STATUS_NONE;
    if (xSemaphoreTake(ldr::reg.mtx, portMAX_DELAY) == pdTRUE)
    {
        status = ldr::reg.kernelStatus;
        xSemaphoreGive(ldr::reg.mtx);
    }
    return status;
}

void ldr::utl::suspendKernel()
{
    if (xSemaphoreTake(ldr::reg.mtx, portMAX_DELAY) == pdTRUE)
    {
        vTaskSuspend(ldr::reg.kernelHandle);
        ldr::reg.kernelStatus = ldr::KERNEL_STATUS_SUSPENDED;
        xSemaphoreGive(ldr::reg.mtx);
    }
}

void ldr::utl::resumeKernel()
{
    if (xSemaphoreTake(ldr::reg.mtx, portMAX_DELAY) == pdTRUE)
    {
        vTaskResume(ldr::reg.kernelHandle);
        ldr::reg.kernelStatus = ldr::KERNEL_STATUS_RUNNING;
        xSemaphoreGive(ldr::reg.mtx);
    }
    vTaskResume(ldr::reg.kernelHandle);
}

void ldr::utl::terminateKernel()
{
    if (xSemaphoreTake(ldr::reg.mtx, portMAX_DELAY) == pdTRUE)
    {
        vTaskDelete(ldr::reg.kernelHandle);
        ldr::reg.kernelStatus = ldr::KERNEL_STATUS_TERMINATED;
        xSemaphoreGive(ldr::reg.mtx);
    }
}
