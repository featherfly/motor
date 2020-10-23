#include <ArduinoLog.h>
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
    if (end->isClose())
    {
        motor->forward();
    }
    while(end->isOpen())
    {
    }
    motor->stop();
}
void SwitchMotor::backward()
{
    if (end->isClose())
    {
        motor->backward();
    }
    while (start->isOpen())
    {
    }
    motor->stop();
}
