#pragma once
#include <pigpio.h>
#include "mapping.h"
class Motor
{
    private:
        int _enable;
        int _in1;
        int _in2;
        int _pwmRange;
        //int speed;
    public:
        Motor();
        Motor(int enable, int in1, int in2);
        ~Motor();
        void setPWMDutycycleRange(int range);
        void setPWMFrequence(int frequence);
        void forward(int dutycycle);
        void reverse(int dutycycle);
        void stop(); /* break */
        void free();
};


