#include <iostream>
#include "main.h"
#include "queue.h"
#include "serial.h"
#include "car.h"
#include "encoder.h"
//#include "sonar.h"
#define MAGIC_NUM       22/20 // 22 cm per 20 pulse
using namespace std;

int counter1 = 0;
int counter2 = 0;



void encoderCallback1();
void encoderCallback2();
void *getInstruction(void *arg);
void *driveCar(void *arg);
void *demo();

int main()
{
    gpioCfgClock(1,PI_DEFAULT_CLK_PERIPHERAL,0);
    gpioInitialise();
    /*
        Queue* ins = new Queue();
        pthread_t p1,p2;
        gpioStartThread(getInstruction,ins);
        gpioStartThread(driveCar,ins);
        while(1){
        gpioSleep(PI_TIME_RELATIVE,0,10000);
        }

        Serial serial = new Serial("/dev/ttyAMA0",9600);
        while (1)
        {
            static string msg;
            msg = serial->read();
            if  (!msg.empty())
            {
                cout<< msg << endl;
            }
            gpioSleep(PI_TIME_RELATIVE,0,10000);
        }*/

    Encoder *leftEncoder = new Encoder(21,encoderCallback1);
    Encoder *rightEncoder = new Encoder(18,encoderCallback2);


    Car *car = new Car();

    for(int i=0; i<3; i++)
    {

        car->moveBackward(Low);
        while (counter1 < 20);
        car->stop(true);
        gpioDelay(2000000);


        car->moveForward(Low);
        while (counter1 < 20);
        car->stop(true);

        cout << counter1 << endl;
        cout << counter2 << endl;
        counter1 = 0;
        gpioDelay(2000000);


}


        //gpioDelay(1000000*10);

        cout << counter1 << endl;
        cout << counter2 << endl;
        //cout << encoder1->getCount() << endl;
        //cout << encoder2->getCount() << endl;


    delete leftEncoder;
    delete rightEncoder;
    delete car;

    //delete serial;
    //delete queue;
    gpioTerminate();

    return 0;
}

void encoderCallback1()
{
    ++counter1;
}

void encoderCallback2()
{
    ++counter2;
}

void * getInstruction(void *arg)
{
    Queue* instructions = (Queue*) arg;
    Serial serial("/dev/ttyAMA0",9600);
    if (serial.getDataAvailable() > 0)
    {
        string ins = serial.read();
        instructions->enqueue(ins);
    }
    gpioSleep(PI_TIME_RELATIVE,0,1000); // 0m1ms
}
void *driveCar(void *arg)
{
    Queue* instructions = (Queue*) arg;
    Car car;
    string ins = instructions->dequeue();
    cout << ins << endl;
    gpioSleep(PI_TIME_RELATIVE,0,1000);
}
