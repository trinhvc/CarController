#include <iostream>
#include <sstream>
#include <queue>
#include <unistd.h>
#include "main.h"
//#include "queue.h"
#include "serial.h"
#include "car.h"
//#include "enhan"
#include "encoder.h"
#include "instruction.h"
//#include "sonar.h"
#define MAGIC_NUM       22/20 // 22 cm per 20 pulse
using namespace std;

void *driveCar(void *arg);

int main()
{
    if (gpioInitialise() >= 0)
    {
        Serial serial("/dev/ttyAMA0",9600);
        queue<Instruction> cmdQueue;
        pthread_t t1;
        pthread_create(&t1,NULL,&driveCar,&cmdQueue);

        while (true)
        {
            static string message;
            static string instruction;

            if (serial.getDataAvailable()>0)
            {
                static bool accepted = false;
                char readChar = (char) serial.readByte();
                cout << readChar << endl;
                if (accepted)
                {
                    if (readChar == ']')
                    {
                        accepted = false;
                        instruction = message;
                        cout << message << endl;
                        cout << &cmdQueue << endl;
                        message.clear();
                    }
                    else if (readChar == ',')
                    {
                        message += ' ';
                    }
                    else
                    {
                        message += readChar;
                    }
                }
                else
                {
                    if (readChar == '[')
                    {
                        accepted = true;
                    }
                }

                // parse instruction
                if  (!instruction.empty())
                {
                cout << instruction << endl;
                    int id = -1;
                    string action;
                    int distance = -1;
                    int speed = -1;
                    bool error = false;

                    istringstream ss(instruction);
                    ss >> id >> action >> distance >> speed;

                    if (id == -1 || distance == -1 ||speed == -1 || action.empty())
                    {
                        error = true;
                    }



                    if (!error)
                    {
                        Instruction ins(id, action, distance, speed);
                        serial.sendByte(id);
                        cmdQueue.push(ins);

                        //instructions.enqueue(ins);
                    }
                    instruction.clear();
                }
            }

            usleep(1000); // 1ms
        }


//gpioDelay(1000000*10)
//cout << encoder1->getCount() << endl;
//cout << encoder2->getCount() << endl;



        cout << "main thread end" << endl;
    }
    gpioTerminate();
    return 0;
}

void* driveCar(void* arg)
{
    queue<Instruction>* cmdQueue = (queue<Instruction>*) arg;
    //queue<Instruction>* instructions = (queue<Instruction>*) arg;
    if (cmdQueue!=NULL)
    {

        //queue<Instruction> cmdQueue = *ptrQueue;
        cout << &cmdQueue << endl;
        Car car;
        //queue<Instruction> cmdQueue = *instructions;
        cout << "thread started" << endl;
        while(true)
        {
            if (!cmdQueue->empty())
            {
                Instruction cmd = cmdQueue->front();
                cout << cmd.getID() << endl;
                cout << cmd.getAction() << endl;
                cout << cmd.getDistance() << endl;
                cout << cmd.getSpeed() << endl;
                if ("ahead"== cmd.getAction())
                {
                car.moveForward(cmd.getDistance(), CarSpeed::slow);
                } else
                if ("back"== cmd.getAction())
                {
                car.moveBackward(cmd.getDistance(), CarSpeed::slow);
                }
                else
                if ("left"== cmd.getAction())
                {
                car.turnLeft();
                car.moveForward(cmd.getDistance(), CarSpeed::slow);
                }
                cmdQueue->pop();
            }
            usleep(100);
        }
    }


}

