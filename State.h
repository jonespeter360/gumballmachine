#ifndef __H_STATE_H
#define __H_STATE_H

constexpr short int DEFAULT_STATES {5};

enum States
{
    HAS_QUARTER_STATE = 1,
    NO_QUARTER_STATE = 2,
    SOLD_OUT_STATE = 4,
    SOLD_STATE = 8,
    WINNER_STATE = 16
};

class GumballMachine;

class State
{
    public:
        virtual void insertQuarter() = 0;
        virtual void ejectQuarter() = 0;
        virtual void turnCrank() = 0;
        virtual void dispense() = 0;
        virtual void set_context(GumballMachine* machine_) = 0;
        virtual int get_name() = 0;
        virtual ~State() {};
};

#endif
