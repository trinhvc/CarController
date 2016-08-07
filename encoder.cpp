#include "encoder.h"
Encoder::Encoder(int gpio)
{
    _gpio = gpio;
    gpioSetMode(_gpio, PI_INPUT);

    // debounce input signal
    gpioGlitchFilter(_gpio, STEADY_MICROS);

    // register function to be called when input pin change state
    gpioSetAlertFuncEx(_gpio, _pulseEx, this);
}

Encoder::~Encoder()
{
    gpioSetAlertFunc(_gpio, NULL);
}

int Encoder::getPulse()
{
    return _pulse;
}

void Encoder::resetPulse()
{
    _pulse = 0;
}

void Encoder::_pulseEx(int gpio, int level, uint32_t tick, void *data)
{
        Encoder* me = (Encoder*) data;
        me->_pulse++;
}


