#include <ArduinoLog.h>
#include "switch_motor.h"

SwitchMotor::SwitchMotor() {}

SwitchMotor::SwitchMotor(Motor *_motor, Switch* _start, Switch* _end)
{
    setup(_motor, _start, _end);
}

void SwitchMotor::setup(Motor *_motor, Switch* _start, Switch* _end)
{
    motor = _motor;
    start = _start;
    end = _end;
    Log.notice(F("setup motor start end" CR));
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
    Log.notice(F("switch_motor.forward end->is_on() %T" CR), end->is_on());
    if (end->is_on())
    {
        Log.notice(F("switch_motor.forward motor->forward()" CR));
        motor->forward();
    }
    while(end->is_on())
    {
    }
    Log.notice(F("switch_motor.forward motor->stop(), end->is_on() %T" CR), end->is_on());
    motor->stop();
}
void SwitchMotor::backward()
{
    Log.notice(F("switch_motor.backward start->is_on() %T" CR), start->is_on());
    if (start->is_on())
    {
        Log.notice(F("switch_motor.backward motor->backward()" CR));
        motor->backward();
    }
    while (start->is_on())
    {
    }
    Log.notice(F("switch_motor.backward motor->stop(), start->is_on() %T" CR), start->is_on());
    motor->stop();
}
