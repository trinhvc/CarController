#include "car.h"

Car::Car()
{
    _leftMotor  = new Motor(BRIDGE1_ENABLE, BRIDGE1_IN1, BRIDGE1_IN2);
    _rightMotor = new Motor(BRIDGE2_ENABLE, BRIDGE2_IN1, BRIDGE2_IN2);
}

Car::~Car()
{
    delete _leftMotor;
    delete _rightMotor;
}

void Car::turnLeft()
{
    _leftMotor ->forward(SPEED_1);
    _rightMotor->forward(SPEED_2);
}

void Car::turnRight()
{
    _leftMotor ->forward(SPEED_2);
    _rightMotor->forward(SPEED_1);
}

void Car::rotateLeft()
{
    _leftMotor ->reverse(SPEED_1);
    _rightMotor->forward(SPEED_1);
}

void Car::rotateRight()
{
    _leftMotor ->forward(SPEED_1);
    _rightMotor->reverse(SPEED_1);
}

void Car::moveForward(CarSpeed speed)
{
    if(speed == Low)
    {
        _leftMotor ->forward(SPEED_1);
        _rightMotor->forward(SPEED_1);
    }

}

void Car::moveBackward(CarSpeed speed)
{
    if(speed == Low)
    {
        _leftMotor ->reverse(SPEED_1);
        _rightMotor->reverse(SPEED_1);
    }
    else if (speed == Medium)
    {
        _leftMotor ->reverse(SPEED_2);
        _rightMotor->reverse(SPEED_2);
    }
    else if (speed == High)
    {
        _leftMotor ->reverse(SPEED_3);
        _rightMotor->reverse(SPEED_3);
    }
}

void Car::stop(bool force)
{
    if (force)
    {
        _leftMotor ->stop();
        _rightMotor->stop();
    }
    else
    {
        _leftMotor ->free();
        _rightMotor->free();
    }
}

