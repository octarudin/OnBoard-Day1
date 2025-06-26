#include "kernel.h"

void ldr::kernelInit()
{
    pinMode(ldr::cfg::SENSOR_PIN, INPUT); // inisialisasi pin analog
}

void ldr::kernelLoop()
{
    // read analog pin 34
    reg.analogValue = map(analogRead(ldr::cfg::SENSOR_PIN), 1, 4095, 50, 100);
    led::reg.LedDelay = reg.analogValue * 10; // in ms, max. 1s
    // Serial.printf("LDR Value: %d \n", led::reg.LedDelay);

    led::utl::setLedDelay(led::reg.LedDelay);
}

void ldr::kernelTask(void *pvParameters)
{
    ldr::kernelInit();
    while (1)
    {
        ldr::kernelLoop();
        vTaskDelay(pdMS_TO_TICKS(ldr::cfg::KERNEL_DELAY_TICKS));
    }
}

void ldr::startKernel()
{
    xTaskCreatePinnedToCore(
        ldr::kernelTask,
        ldr::cfg::KERNEL_NAME,
        ldr::cfg::KERNEL_STACK_SIZE,
        NULL,
        ldr::cfg::KERNEL_PRIORITY,
        &ldr::reg.kernelHandle,
        ldr::cfg::KERNEL_CORE);
}