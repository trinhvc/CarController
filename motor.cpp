#include "motor.h"

Motor::Motor(int enable, int in1, int in2)
{
    _enable = enable;
    _in1 = in1;
    _in2 = in2;

    _pwmRange = PI_DEFAULT_DUTYCYCLE_RANGE;

    gpioSetMode(_enable,PI_OUTPUT);
    gpioSetMode(_in1,   PI_OUTPUT);
    gpioSetMode(_in2,   PI_OUTPUT);

    gpioWrite(_enable, PI_LOW);
}

Motor::~Motor()
{
    gpioWrite(_enable, PI_LOW);
    gpioWrite(_in1, PI_LOW);
    gpioWrite(_in2, PI_LOW);
}

void Motor::setPWMDutycycleRange(int range)
{
    _pwmRange = range;
    gpioSetPWMrange(_enable, range);
}

void Motor::setPWMFrequence(int frequence)
{
    gpioSetPWMfrequency(_enable, frequence);
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
