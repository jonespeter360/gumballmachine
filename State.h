#ifndef __H_STATE_H
#define __H_STATE_H

class GumballMachine;

class State
{
    public:
        virtual void insertQuarter() = 0;
        virtual void ejectQuarter() = 0;
        virtual void turnCrank() = 0;
        virtual void dispense() = 0;
        virtual void set_context(GumballMachine* machine_) = 0;
        virtual ~State();
};

#endif
