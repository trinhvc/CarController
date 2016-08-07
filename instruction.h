#pragma once
#include <string>
#include <iostream>
using namespace std;
class Instruction
{
    private:
        int _id;
        static int _cid;
        string _action;
        int _distance;
        int _speed;
    public:
    Instruction(){};
        Instruction(int id, string action,int distance, int speed);
        //~Instruction();
        int getID();
        void setID(int id);
        string getAction();
        void setAction(string action);
        int getDistance();
        void setDistance(int distance);
        int getSpeed();
        void setSpeed(int speed);
};

