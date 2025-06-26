#include "utils.h"

void led::utl::setKernelStatus(KernelStatus status)
{
    if (xSemaphoreTake(led::reg.mtx, portMAX_DELAY) == pdTRUE)
    {
        led::reg.kernelStatus = status;
        xSemaphoreGive(led::reg.mtx);
    }
}

led::KernelStatus led::utl::getKernelStatus()
{
    led::KernelStatus status = led::KERNEL_STATUS_NONE;
    if (xSemaphoreTake(led::reg.mtx, portMAX_DELAY) == pdTRUE)
    {
        status = led::reg.kernelStatus;
        xSemaphoreGive(led::reg.mtx);
    }
    return status;
}

void suspendKernel()
{
    if (xSemaphoreTake(led::reg.mtx, portMAX_DELAY) == pdTRUE)
    {
        vTaskSuspend(led::reg.kernelHandle);
        led::reg.kernelStatus = led::KERNEL_STATUS_SUSPENDED;
        xSemaphoreGive(led::reg.mtx);
    }
}

void led::utl::resumeKernel()
{
    if (xSemaphoreTake(led::reg.mtx, portMAX_DELAY) == pdTRUE)
    {
        vTaskResume(led::reg.kernelHandle);
        led::reg.kernelStatus = led::KERNEL_STATUS_RUNNING;
        xSemaphoreGive(led::reg.mtx);
    }
    vTaskResume(led::reg.kernelHandle);
}

void led::utl::terminateKernel()
{
    if (xSemaphoreTake(led::reg.mtx, portMAX_DELAY) == pdTRUE)
    {
        vTaskDelete(led::reg.kernelHandle);
        led::reg.kernelStatus = led::KERNEL_STATUS_TERMINATED;
        xSemaphoreGive(led::reg.mtx);
    }
}





void led::utl::setLedStatus(LedStatus LED_Status) 
{
    if (xSemaphoreTake(led::reg.mtx, portMAX_DELAY) == pdTRUE)
    {
        led::reg.LED_Status = LED_Status;
        xSemaphoreGive(led::reg.mtx);
    }

    
}

led::LedStatus led::utl::getLedStatus(void) 
{
    if (xSemaphoreTake(led::reg.mtx, portMAX_DELAY) == pdTRUE)
    {
        led::LedStatus ret = led::reg.LED_Status;
        xSemaphoreGive(led::reg.mtx);
        return ret;
    }
    return led::LED_STATUS_OFF;
}

void led::utl::setLedDelay(uint64_t LED_Delay)
{
    if (xSemaphoreTake(led::reg.mtx, portMAX_DELAY) == pdTRUE)
    {
        led::reg.LedDelay = LED_Delay;
        xSemaphoreGive(led::reg.mtx);
    }

    led::trp::models::LedModel *data = new led::trp::models::LedModel;
    data->LedDelay = LED_Delay;

    led::trp::models::Generic q;
    q.type = led::trp::types::SET_LED_DELAY;
    q.dataPtr = (uint8_t *)data;
    xQueueSend(led::trp::queue, &q, 0);
}

uint64_t led::utl::getLedDelay(void)
{
    if (xSemaphoreTake(led::reg.mtx, portMAX_DELAY) == pdTRUE)
    {
        uint64_t ret = led::reg.LedDelay;
        xSemaphoreGive(led::reg.mtx);
        return ret;
    }
    return 0;
}

// send command to queue, received at kernel.cpp, read the status and digitalWrite
void led::utl::onLedOn(void)
{
    // led::trp::models::LedModel *data = new led::trp::models::LedModel;
    // data->LED_Status = LED_STATUS_ON;
    led::trp::models::Generic q;
    q.type = led::trp::types::SET_LED_ON;
    // q.dataPtr = (uint8_t *)data;
    xQueueSend(led::trp::queue, &q, 0);
}

// send command to queue, received at kernel.cpp, read the status and digitalWrite
void led::utl::onLedOff(void)
{
    // led::trp::models::LedModel *data = new led::trp::models::LedModel;
    // data->LED_Status = LED_STATUS_OFF;
    led::trp::models::Generic q;
    q.type = led::trp::types::SET_LED_OFF;
    // q.dataPtr = (uint8_t *)data;
    xQueueSend(led::trp::queue, &q, 0);
}