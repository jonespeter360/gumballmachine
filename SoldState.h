#ifndef __H_SOLD_STATE_H
#define __H_SOLD_STATE_H

class State;
class GumballMachine;

class SoldState : public State
{
    private:
        GumballMachine* m_gumball_machine;
    public:
        SoldState(GumballMachine* machine_);
        void insertQuarter();
        void ejectQuarter();
        void turnCrank();
        void dispense();
};

#endif
