#include "instruction.h"


void Instruction::setSpeed(int speed)
{
    _speed = speed;
}

int Instruction::getSpeed()
{
    return _speed;
}

void Instruction::setDistance(int distance)
{
    _distance = distance;
}

int Instruction::getDistance()
{
    return _distance;
}

void Instruction::setAction(string action)
{
    _action = action;
}

string Instruction::getAction()
{
    return _action;
}

void Instruction::setID(int id)
{
    _id = id;
}

int Instruction::getID()
{
    return _id;
}


 Instruction::Instruction(int id, string action,int distance, int speed)
{
    _id = id;
    _action = action;
    _distance = distance;
    _speed = speed;
}

