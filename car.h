#pragma once
#include "mapping.h"
#include "motor.h"


#define SPEED_1 PI_DEFAULT_DUTYCYCLE_RANGE/8
#define SPEED_2 PI_DEFAULT_DUTYCYCLE_RANGE/8
#define SPEED_3 PI_DEFAULT_DUTYCYCLE_RANGE/4

enum CarSpeed {Low, Medium, High};

class Car
{
    protected:
        Motor* leftMotor ;
        Motor* rightMotor;

    public:
        Car() ;
        ~Car();
        void turnLeft();
        void turnRight();
        void turnAround();
        void moveForward(CarSpeed speed);
        void moveBackward(CarSpeed speed);
        void stop(bool force);
};
