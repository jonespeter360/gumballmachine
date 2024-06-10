#ifndef __H_SOLD_OUT_H
#define __H_SOLD_OUT_H

class State;
class GumballMachine;

class SoldOutState : public State
{
    private:
        GumballMachine* m_gumball_machine;
    public:
        SoldOutState();
        void insertQuarter();
        void ejectQuarter();
        void turnCrank();
        void dispense();
        void set_context(GumballMachine* machine_);
};

#endif
