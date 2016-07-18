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
    cout << "handle: " << handle << " char: " << result<< endl;
    return result;
}

string Serial::read()
{
    string result;
    char buffer[255];
    int count = serRead(handle,buffer,255);
    if (count > 0)
    {
        for(int i = 0; i< count; i++)
        {
            result += buffer[i];
        }
    }
    return result;
}

int Serial::getDataAvailable()
{
    int result = serDataAvailable(handle);
    return result;
}
