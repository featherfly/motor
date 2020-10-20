#ifndef SWICHER_MOTOR_H
#define SWICHER_MOTOR_H
#include "switch.h"
#include "motor.h"

class SwitchMotor{
    private:
        Motor *motor = &Motor();
        Switch *start = &Switch(&Pin(-1, INPUT));
        Switch *end = &Switch(&Pin(-1, INPUT));
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
