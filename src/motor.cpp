#include <Arduino.h>
#include <ArduinoLog.h>
#include "motor.h"

Motor::Motor()
{
}
Motor::Motor(bool _forwardState)
{
    forwardState = _forwardState;
}

void Motor::go(bool direction)
{
    if (direction == forwardState) 
    {
        Log.notice(F("Motor.forward forwardState %T" CR), forwardState);
        state = STATE_FORWARD;
    } 
    else 
    {
        Log.notice(F("Motor.backward forwardState %T" CR), forwardState);
        state = STATE_BACKWARD;
    }
}

void Motor::forward()
{
    go(forwardState);
}

void Motor::backward()
{
    go(!forwardState);
}

void Motor::stop()
{
    Log.notice(F("Motor.stop" CR));
    state = STATE_STOP;
}

void Motor::brake()
{
    Log.notice(F("Motor.brake" CR));
    state = STATE_STOP;
}

bool Motor::isRunning()
{
    return state != STATE_STOP;
}