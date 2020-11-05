#ifndef MOTOR_H
#define MOTOR_H

#define STATE_STOP 0;
#define STATE_FORWARD 1;
#define STATE_BACKWARD 2;


class Motor
{
protected:
    int state = 0;
    bool forwardState = true;
public:
    Motor();
    Motor(bool forwardState);
    virtual void go(bool direction);
    virtual void forward();
    virtual void backward();
    virtual void stop();
    virtual void brake();
    virtual bool isRunning();
};

#endif