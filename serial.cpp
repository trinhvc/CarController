#include "serial.h"
#include <iostream>
using namespace std;
Serial::Serial(char* device, int baudrate)
{
    handle = serOpen(device, baudrate, 0);
}

Serial::~Serial()
{
    if (handle>=0)
    {
        serClose(handle);
    }
}

int Serial::readByte()
{
    int result = serReadByte(handle);
    return result;
}

void Serial::sendByte(int c)
{
    serWriteByte(handle, c);
}

int Serial::getDataAvailable()
{
    int result = serDataAvailable(handle);
    return result;
}
