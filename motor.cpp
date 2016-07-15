#include "motor.h"

Motor::Motor(int enable, int in1, int in2)
{
    _enable = enable;
    _in1 = in1;
    _in2 = in2;

    gpioSetMode(_enable,PI_OUTPUT);
    gpioSetMode(_in1,   PI_OUTPUT);
    gpioSetMode(_in2,   PI_OUTPUT);

    gpioSetPWMfrequency(_enable,40);
    gpioWrite(_enable, PI_LOW);
}

Motor::~Motor()
{
    gpioWrite(_enable, PI_LOW);
    gpioWrite(_in1, PI_LOW);
    gpioWrite(_in2, PI_LOW);
}

void Motor::forward(int dutycycle)
{
    gpioWrite(_enable, PI_LOW);
    gpioWrite(_in1, PI_HIGH);
    gpioWrite(_in2, PI_LOW);
    gpioPWM(_enable, dutycycle);
}

void Motor::reverse(int dutycycle)
{
    gpioWrite(_enable, PI_LOW);
    gpioWrite(_in1, PI_LOW);
    gpioWrite(_in2, PI_HIGH);
    gpioPWM(_enable, dutycycle);
}

void Motor::stop()
{
    gpioWrite(_enable, PI_LOW);
    gpioWrite(_in1, PI_HIGH);
    gpioWrite(_in2, PI_HIGH);
    gpioWrite(_enable, PI_HIGH);
}

void Motor::free()
{
    gpioWrite(_enable, PI_LOW);
}
