#pragma once
#include <string>

using namespace std;
class Instruction
{
    private:
        int _id;
        string _action;
        int _distance;
        int _speed;
    public:
        Instruction(int id, string action,int distance, int speed);
        ~Instruction();
        int getID();
        void setID(int id);
        string getAction();
        void setAction(string action);
        int getDistance();
        void setDistance(int distance);
        int getSpeed();
        void setSpeed(int speed);
};

