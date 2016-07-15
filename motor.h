#pragma once
#include <pigpio.h>
#include "mapping.h"
class Motor
{
    private:
        int _enable,_in1,_in2;
        //int speed;
    public:
        Motor();
        Motor(int enable, int in1, int in2);
        ~Motor();
        void forward(int dutycycle);
        void reverse(int dutycycle);
        void stop(); /* break */
        void free();
};


