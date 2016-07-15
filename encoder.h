#pragma once
#include<stdint.h>
#include<pigpio.h>
#define STEADY_MICROS 20
#define TRIGGER_LEVEL PI_LOW
typedef void (*encoderCB_t)();
class Encoder
{
    private:
        int _pin;
        encoderCB_t _callback;
        static void pulseEx(int gpio, int level, uint32_t tick, void *data);
        void pulse(int gpio, int level, uint32_t tick);
        Encoder();
    public:
        Encoder(int gpio, encoderCB_t callback);
        ~Encoder();
};
