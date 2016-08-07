#pragma once
#include "mapping.h"
#include "motor.h"
#include "encoder.h"

#define SPEED_1 PI_DEFAULT_DUTYCYCLE_RANGE/8
#define SPEED_2 PI_DEFAULT_DUTYCYCLE_RANGE/8
#define SPEED_3 PI_DEFAULT_DUTYCYCLE_RANGE/4


enum class CarSpeed {slow=0, medium=127, fast=255};
class Car
{
    protected:
        Motor _leftMotor;
        Motor _rightMotor;

        Encoder _leftEncoder;
        Encoder _rightEncoder;

        int _dutycycle;

        void _move(bool ahead,int dutycycle);
        void _turn(bool left,int dutycycle);
        void _rotate(bool left);
    public:
        Car();
        void turnLeft();
        void turnRight();
        void turnAround();
        void rotateLeft(int degree);
        void rotateRight(int degree);
        void moveForward(int distance, CarSpeed speed);
        void moveBackward(int distance, CarSpeed speed);
        void stop(bool force);
};
