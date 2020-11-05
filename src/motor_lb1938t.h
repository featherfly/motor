#ifndef MOTOR_LB1938T_H
#define MOTOR_LB1938T_H
#include "motor.h"

class MotorLb1938t : public Motor
{
private:
    int pin1;
    int pin2;
public:
    MotorLb1938t(int pin1, int pin2);
    MotorLb1938t(int pin1, int pin2, bool forwardState);
    void go(bool direction);
    void forward();
    void backward();
    void stop();
    void brake();
};

#endif