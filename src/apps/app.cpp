#include "app.h"

void app::start()
{
    Serial.begin(115200);
    ldr::startKernel(); // sensor task
    led::startKernel(); // led task
}