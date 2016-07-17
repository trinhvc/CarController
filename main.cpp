#include <iostream>
#include "main.h"
#include "queue.h"
#include "serial.h"
#include "car.h"
#include "encoder.h"
//#include "sonar.h"
#define MAGIC_NUM       22/20 // 22 cm per 20 pulse
using namespace std;

void *driveCar(void *arg);
void *demo();

int main()
{
    //gpioCfgClock(1,PI_DEFAULT_CLK_PERIPHERAL,0);
    gpioInitialise();
    Queue* ins = new Queue();
    Serial* serial = new Serial("/dev/ttyAMA0",9600);
    pthread_t p1,p2;
    gpioStartThread(driveCar,ins);


    while (true)
    {
        static string message;
        static string instructionStr;
        static char readChar;
        static bool accepted = false;

        if (serial->getDataAvailable()>0)
        {
            readChar = serial->readByte();
            cout << readChar << endl;
            // reassemble an instruction;
            if (readChar == '[')
            {
                accepted = true;
                // handle error
            }
            else if (readChar == ']')
            {
                accepted = false;
                instructionStr = message;
                message.clear();
            }
            else
            {
                if (accepted == true)
                {
                    message+=readChar;
                }
            }

            // parse instruction
            if  (!message.empty())
            {
                int id;
                string action;
                int distance;
                int speed;


                //Instruction ins(id,action,distance,speed);
                cout<< message << endl;
                message.clear();
            }
        }

        gpioSleep(PI_TIME_RELATIVE,0,10000);
    }
    string s = "[1,ahead,0,0]";


//gpioDelay(1000000*10)
//cout << encoder1->getCount() << endl;
//cout << encoder2->getCount() << endl;


    delete serial;
    delete ins;
    gpioTerminate();

    return 0;
}

void *driveCar(void *arg)
{
    Queue* instructions = (Queue*) arg;
    Car car;
    string ins = instructions->dequeue();
    cout << ins << endl;
    gpioSleep(PI_TIME_RELATIVE,0,1000);
}
