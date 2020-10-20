#include <Arduino.h>
#include <ArduinoLog.h>
#include "motor.h"

Motor::Motor()
{
}

void Motor::forward()
{
    Log.notice(F("Motor.forward" CR));
    state = STATE_FORWARD;
}

void Motor::backward()
{
    Log.notice(F("Motor.backward" CR));
    state = STATE_BACKWARD;
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