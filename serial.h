#pragma once
#include <pigpio.h>
#include <string>
using namespace std;

class Serial
{
    private:
        int handle;
    public:
        Serial(char* device, int baudrate);
        ~Serial();
        int readByte();
        void sendByte(int c);
        int getDataAvailable();
};
