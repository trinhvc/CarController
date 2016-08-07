#include "car.h"
#include<unistd.h>
Car::Car():

    _leftMotor(BRIDGE2_ENABLE, BRIDGE2_IN1, BRIDGE2_IN2),
    _rightMotor(BRIDGE1_ENABLE, BRIDGE1_IN1, BRIDGE1_IN2),
    _leftEncoder(ENCODER2),
    _rightEncoder(ENCODER1)
    {

}

void Car::turnLeft()
{
        _leftMotor.setPWMFrequence(40);
    _rightMotor.setPWMFrequence(25);
    int goal = (80 * 40)/22;
    int pulse = 0;
    _rightEncoder.resetPulse();

    _leftMotor.forward(30);
    _rightMotor.forward(180);
        while(pulse < goal)
    {
    pulse  = _rightEncoder.getPulse();
    usleep(10);
    }
    stop(true);
}

void Car::turnRight()
{

}

void Car::rotateLeft(int degree)
{
    //_rotate(true,_speed);
}

void Car::rotateRight(int degree)
{
    _rotate(false);
}

void Car::moveForward(int distance, CarSpeed speed)
{
    _leftMotor.setPWMFrequence(50);
    _rightMotor.setPWMFrequence(50);
    int goal = (distance * 40)/22;
    int pulse = 0;
    _leftEncoder.resetPulse();
    _move(true,180);
    while(pulse < goal)
    {
    pulse  = _leftEncoder.getPulse();
    usleep(10);
    }
    stop(true);
}


void Car::moveBackward(int distance, CarSpeed speed)
{
    _leftMotor.setPWMFrequence(50);
    _rightMotor.setPWMFrequence(50);
    int goal = (distance * 40)/22;
    int pulse = 0;
    _leftEncoder.resetPulse();
    _move(false,180);
    while(pulse < goal)
    {
    pulse  = _leftEncoder.getPulse();
    usleep(10);
    }
    stop(true);
}

void Car::stop(bool force)
{
    if (force)
    {
        _leftMotor .stop();
        _rightMotor.stop();
    }
    else
    {
        _leftMotor.free();
        _rightMotor.free();
    }
}

void Car::_move(bool ahead, int dutycycle)
{
    if (ahead)
    {
        _leftMotor.forward(dutycycle);
        _rightMotor.forward(dutycycle);
    }
    else
    {
        _leftMotor.reverse(dutycycle);
        _rightMotor.reverse(dutycycle);
         }
}

void Car::_turn(bool left, int dutycycle)
{
    if (left)
    {
        _leftMotor.forward(dutycycle/2);
        _rightMotor.forward(dutycycle);
    }
    else
    {
        _leftMotor.forward(dutycycle);
        _rightMotor.forward(dutycycle/2);
    }
}

void Car::_rotate(bool left)
{
    if (left)
    {
        //_leftMotor.reverse(dutycycle);
        //_rightMotor.forward(dutycycle);
    }
    else
    {
        //_leftMotor.forward(dutycycle);
        //_rightMotor.reverse(dutycycle);
    }
}
