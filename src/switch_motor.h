#ifndef SWICHER_MOTOR_H
#define SWICHER_MOTOR_H
#include "switch.h"
#include "motor.h"

#define EVENT_RUNNING_STOP 0
#define EVENT_RUNNING_CONTINUE 1

#define STEP_BACKWARD 0
#define STEP_FORWARD 1

class SwitchMotor{
    private:
        Motor *motor = &Motor();
        Switch *start = &Switch(&Pin(-1, INPUT));
        Switch *end = &Switch(&Pin(-1, INPUT));
        int _runningTime = 0;
        int (*user_onRunning)(int, bool) = [](int, bool) { return EVENT_RUNNING_CONTINUE; };
    public:
        SwitchMotor();
        SwitchMotor(Motor *_motor, Switch* _start, Switch* _end);
        void setup(Motor *_motor, Switch* _start, Switch* _end);
        void setMotor(Motor *_motor);
        void setStart(Switch* _start);
        void setSwitch(Switch* _end);
        /**
         * @return running time
         */
        int forward();
        /**
         * @return running time
         */
        int backward();

        int runningTime();

        void onRunning(int (*)(int, bool));
};
#endif
