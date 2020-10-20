#ifndef MOTOR_RELAY_H
#define MOTOR_RELAY_H
#include "motor.h"

class MotorRelay : public Motor
{
private:
    int pin1;
    int pin2;
    int pin3;
    int pin4;
    bool openState;

public:
    MotorRelay(int pin1, int pin2,int pin3, int pin4);
    MotorRelay(int pin1, int pin2,int pin3, int pin4, bool openState);
    void forward();
    void backward();
    void stop();
    void brake();
};

#endif