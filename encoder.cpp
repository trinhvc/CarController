#include "encoder.h"
Encoder::Encoder() {}
Encoder::Encoder(int gpio, encoderCB_t callback)
{
    _pin = gpio;
    _callback = callback;
    gpioSetMode(_pin,PI_INPUT);
    gpioGlitchFilter(_pin,STEADY_MICROS);
    gpioSetAlertFuncEx(_pin, pulseEx,this);
}

Encoder::~Encoder()
{
    _callback = NULL;
    gpioSetAlertFunc(_pin, NULL);
}

void Encoder::pulse(int gpio, int level, uint32_t tick)
{
    _callback();
}

void Encoder::pulseEx(int gpio, int level, uint32_t tick, void *data)
{
    if (level == TRIGGER_LEVEL)
    {
        Encoder *me = (Encoder*) data;
        me->pulse(gpio, level, tick);
    }
}

