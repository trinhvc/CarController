#pragma once

class EnhancedCar: Car
{
    private:
        Encoder _leftEncoder;
        Encoder _rightEncoder;
    public:
        EnhancedCar();
        ~EnhancedCar();
        void moveForward(int distance);
        void moveBackward(int distance);


}
