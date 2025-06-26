#include "kernel.h"

void led::kernelInit()
{
    led::utl::setKernelStatus(led::KERNEL_STATUS_INIT);
    pinMode(led::cfg::LED_PIN, OUTPUT);
    led::utl::setKernelStatus(KERNEL_STATUS_RUNNING);
    led::utl::onLedOff();
}

void led::kernelLoop(Instance *inst)
{
    // there are only 2 events, turning ON or OFF the LED
    static led::trp::models::Generic buf;
    static led::trp::models::LedModel *ledBuf = nullptr;
    
    if (xQueueReceive(led::trp::queue, &buf, 0) == pdTRUE)
    {
        switch (buf.type)
        {
        case led::trp::types::SET_LED_OFF:
            // ledBuf = (led::trp::models::LedModel *)buf.dataPtr;
            led::utl::setLedStatus(led::LED_STATUS_OFF);
            digitalWrite(led::cfg::LED_PIN, led::LED_STATUS_OFF);
            vTaskDelay(pdMS_TO_TICKS(reg.LedDelay));
            delete ledBuf;
            led::utl::onLedOn();
            break;

        case led::trp::types::SET_LED_ON:
            // ledBuf = (led::trp::models::LedModel *)buf.dataPtr;
            led::utl::setLedStatus(led::LED_STATUS_ON);
            digitalWrite(led::cfg::LED_PIN, led::LED_STATUS_ON);
            vTaskDelay(pdMS_TO_TICKS(reg.LedDelay));
            delete ledBuf;
            led::utl::onLedOff();
            break;

        // another case: get/set the LED delay
        case led::trp::types::SET_LED_DELAY:
            // ledBuf = (led::trp::models::LedModel *)buf.dataPtr;
            // led::utl::setLedDelay(ledBuf->LedDelay); // the new value based on receivedValue
            inst->ser.printf("Success. Current Delay: %d\n", led::utl::getLedDelay());
            break;

        default:
            inst->ser.printf("there is no command, %d command pending.\n", uxQueueMessagesWaiting(trp::queue));
            break;
        }
        
    }
}

void led::kernelTask(void *pvParameters)
{
    led::Instance *inst = new led::Instance;
    led::kernelInit();
    while (1)
    {
        led::kernelLoop(inst);
        vTaskDelay(pdMS_TO_TICKS(cfg::KERNEL_DELAY_TICKS));
    }
}

void led::startKernel()
{
    xTaskCreatePinnedToCore(
        led::kernelTask,
        led::cfg::KERNEL_NAME,
        led::cfg::KERNEL_STACK_SIZE,
        NULL,
        led::cfg::KERNEL_PRIORITY,
        &reg.kernelHandle,
        led::cfg::KERNEL_CORE);
}
