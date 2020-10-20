#include "switch_motor.h"

SwitchMotor::SwitchMotor() {}

SwitchMotor::SwitchMotor(Motor *_motor, Switch* _start, Switch* _end)
{
    motor = _motor;
    start = _start;
    end = _end;
}

void SwitchMotor::setup(Motor *_motor, Switch* _start, Switch* _end)
{
    motor = _motor;
    start = _start;
    end = _end;
}
void SwitchMotor::setMotor(Motor *_motor)
{
    motor = _motor;
}
void SwitchMotor::setStart(Switch *_start)
{
    start = _start;
}
void SwitchMotor::setSwitch(Switch *_end)
{
    end = _end;
}
void SwitchMotor::forward()
{
    motor->forward();
    while (end->isClose())
    {
        motor->stop();
    }
}
void SwitchMotor::backward()
{
    motor->backward();
    while (start->isClose())
    {
        motor->stop();
    }
}