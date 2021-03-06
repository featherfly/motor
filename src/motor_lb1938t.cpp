#include <Arduino.h>
#include <ArduinoLog.h>
#include "motor_lb1938t.h"

MotorLb1938t::MotorLb1938t(int _pin1, int _pin2) : MotorLb1938t(_pin1, _pin2, true)
{
    // pin1 = _pin1;
    // pin2 = _pin2;

    // Log.notice(F("MotorLb1938t pin1 %d, pin2 %d," CR), pin1, pin2);

    // pinMode(pin1, OUTPUT);
    // pinMode(pin2, OUTPUT);
}
MotorLb1938t::MotorLb1938t(int _pin1, int _pin2, bool _forwardState) : Motor(_forwardState)
{
    pin1 = _pin1;
    pin2 = _pin2;
    forwardState = _forwardState;

    Log.notice(F("MotorLb1938t pin1 %d, pin2 %d, forwardState %T" CR), pin1, pin2, forwardState);

    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
}

void MotorLb1938t::go(bool direction)
{
    if (direction) 
    {
        Log.notice(F("MotorLb1938t.forward forwardState %T" CR), forwardState);
        digitalWrite(pin1, HIGH);
        digitalWrite(pin2, LOW);
        state = STATE_FORWARD;
    } 
    else 
    {
        Log.notice(F("MotorLb1938t.backward forwardState %T" CR), forwardState);
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, HIGH);
        state = STATE_BACKWARD;
    }
}

void MotorLb1938t::forward()
{
    go(forwardState);
}

void MotorLb1938t::backward()
{
    go(!forwardState);
}    

void MotorLb1938t::stop()
{
    Log.notice(F("MotorLb1938t.stop" CR));
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
    state = STATE_STOP;
}

void MotorLb1938t::brake()
{
    Log.notice(F("MotorLb1938t.brake" CR));
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, HIGH);
    state = STATE_STOP;
}