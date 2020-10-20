#ifndef SWICHER_MOTOR_H
#define SWICHER_MOTOR_H
#include "switch.h"
#include "motor.h"

class SwitchMotor{
    private:
        Motor *motor = &Motor();
        Switch *start = &Switch(-1);
        Switch *end = &Switch(-1);
    public:
        SwitchMotor();
        SwitchMotor(Motor *_motor, Switch* _start, Switch* _end);
        void setup(Motor *_motor, Switch* _start, Switch* _end);
        void setMotor(Motor *_motor);
        void setStart(Switch* _start);
        void setSwitch(Switch* _end);
        void forward();
        void backward();
};
#endif
