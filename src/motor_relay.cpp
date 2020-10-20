#include <Arduino.h>
#include <ArduinoLog.h>
#include "motor_relay.h"

MotorRelay::MotorRelay(int _pin1, int _pin2, int _pin3, int _pin4) : MotorRelay(_pin1, _pin2, _pin3, _pin4, false) {}

MotorRelay::MotorRelay(int _pin1, int _pin2, int _pin3, int _pin4, bool _openState) : Motor()
{
    pin1 = _pin1;
    pin2 = _pin2;
    pin3 = _pin3;
    pin4 = _pin4;
    openState = _openState;

    Log.notice(F("MotorRelay pin1 %d, pin2 %d, pin3 %d, pin4 %d, openState %d" CR), pin1, pin2, pin3, pin4, openState);

    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
    pinMode(pin3, OUTPUT);
    pinMode(pin4, OUTPUT);
}

void MotorRelay::forward()
{
    Log.notice(F("MotorRelay.forward" CR));
    digitalWrite(pin1, openState);
    digitalWrite(pin2, openState);
    state = STATE_FORWARD;
}

void MotorRelay::backward()
{
    Log.notice(F("MotorRelay.backward" CR));
    digitalWrite(pin3, openState);
    digitalWrite(pin4, openState);
    state = STATE_BACKWARD;
}

void MotorRelay::stop()
{
    Log.notice(F("MotorRelay.stop" CR));
    digitalWrite(pin1, !openState);
    digitalWrite(pin2, !openState);
    digitalWrite(pin3, !openState);
    digitalWrite(pin4, !openState);
    state = STATE_STOP;
}

void MotorRelay::brake()
{
    Log.notice(F("MotorRelay.brake" CR));
    digitalWrite(pin1, !openState);
    digitalWrite(pin2, !openState);
    digitalWrite(pin3, !openState);
    digitalWrite(pin4, !openState);
    state = STATE_STOP;
}