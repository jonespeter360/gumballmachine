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

struct data;

class State
{
    public:
        virtual void insertQuarter(data&) = 0;
        virtual void ejectQuarter(data&) = 0;
        virtual void turnCrank(data&) = 0;
        virtual void dispense(data&) = 0;
        virtual void set_context(GumballMachine* machine_) = 0;
        virtual int get_name() = 0;
        virtual ~State() {};
};

#endif
