#include "car.h"

Car::Car()
{
    leftMotor  = new Motor(BRIDGE1_ENABLE, BRIDGE1_IN1, BRIDGE1_IN2);
    rightMotor = new Motor(BRIDGE2_ENABLE, BRIDGE2_IN1, BRIDGE2_IN2);
}

Car::~Car()
{
    delete leftMotor ;
    delete rightMotor;
}

void Car::turnLeft()
{
    leftMotor ->forward(SPEED_1);
    rightMotor->forward(SPEED_2);
}

void Car::turnRight()
{
    leftMotor ->forward(SPEED_2);
    rightMotor->forward(SPEED_1);
}

void Car::turnAround()
{
    leftMotor ->reverse(SPEED_1);
    rightMotor->forward(SPEED_1);
}

void Car::moveForward(CarSpeed speed)
{
    if(speed == Low)
    {
        leftMotor ->forward(SPEED_1);
        rightMotor->forward(SPEED_1);
    }
    else if (speed == Medium)
    {
        leftMotor ->forward(SPEED_2);
        rightMotor->forward(SPEED_2);
    }
    else if (speed == High)
    {
        leftMotor ->forward(SPEED_3);
        rightMotor->forward(SPEED_3);
    }
}

void Car::moveBackward(CarSpeed speed)
{
    if(speed == Low)
    {
        leftMotor ->reverse(SPEED_1);
        rightMotor->reverse(SPEED_1);
    }
    else if (speed == Medium)
    {
        leftMotor ->reverse(SPEED_2);
        rightMotor->reverse(SPEED_2);
    }
    else if (speed == High)
    {
        leftMotor ->reverse(SPEED_3);
        rightMotor->reverse(SPEED_3);
    }
}

void Car::stop(bool force)
{
    if (force)
    {
        leftMotor ->stop();
        rightMotor->stop();
    }
    else
    {
        leftMotor ->free();
        rightMotor->free();
    }
}

