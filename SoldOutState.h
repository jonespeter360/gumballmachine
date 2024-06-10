#ifndef __H_SOLD_OUT_H
#define __H_SOLD_OUT_H

class State;
class GumballMachine;

class SoldOutState : public State
{
    private:
        GumballMachine* m_gumball_machine;
    public:
        SoldOutState(GumballMachine* machine_);
        void insertQuarter();
        void ejectQuarter();
        void turnCrank();
        void dispense()
};

#endif
