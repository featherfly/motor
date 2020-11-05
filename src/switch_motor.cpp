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
int SwitchMotor::forward()
{
    _runningTime = 0;
    unsigned long startTime = millis();
    Log.notice(F("switch_motor.forward end->is_on() %T" CR), end->is_on());
    if (end->is_on())
    {
        Log.notice(F("switch_motor.forward motor->forward()" CR));
        motor->forward();
    }
    while(end->is_on())
    {
        _runningTime = millis() - startTime;
        if (user_onRunning(_runningTime , STEP_FORWARD) == EVENT_RUNNING_STOP)
        {
            break;
        }
    }
    Log.notice(F("switch_motor.forward motor->stop(), end->is_on() %T, runningTime %d" CR), end->is_on(), _runningTime);
    motor->stop();
    _runningTime = millis() - startTime;
    return _runningTime;
}
int SwitchMotor::backward()
{
    _runningTime = 0;
    unsigned long startTime = millis();
    Log.notice(F("switch_motor.backward start->is_on() %T" CR), start->is_on());
    if (start->is_on())
    {
        Log.notice(F("switch_motor.backward motor->backward()" CR));
        motor->backward();
    }
    while (start->is_on())
    {
        _runningTime = millis() - startTime;
        if (user_onRunning(_runningTime , STEP_BACKWARD) == EVENT_RUNNING_STOP)
        {
            break;
        }
    }
    Log.notice(F("switch_motor.backward motor->stop(), start->is_on() %T, runningTime %d" CR), start->is_on(), _runningTime);
    motor->stop();
    _runningTime = millis() - startTime;
    return _runningTime;
}

int SwitchMotor::runningTime()
{
    return _runningTime;
}

void SwitchMotor::onRunning(int (*function)(int, bool))
{
    user_onRunning = function;
}