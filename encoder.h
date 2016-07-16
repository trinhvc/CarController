#pragma once
#include<stdint.h>
#include<pigpio.h>
#define STEADY_MICROS 20
#define TRIGGER_LEVEL PI_LOW

class Encoder
{
    private:
        int _gpio;
        int _pulse;
        static void _pulseEx(int gpio, int level, uint32_t tick, void *data);
    public:
        Encoder(int gpio);
        ~Encoder();
        int getPulse();
        void resetPulse();
};
