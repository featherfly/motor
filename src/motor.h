#ifndef MOTOR_H
#define MOTOR_H

#define STATE_STOP 0;
#define STATE_FORWARD 1;
#define STATE_BACKWARD 2;


class Motor
{
private:

protected:
    int state = 0;
public:
    Motor();
    virtual void forward();
    virtual void backward();
    virtual void stop();
    virtual void brake();
    bool isRunning();
};

#endif