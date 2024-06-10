#ifndef __H_SOLD_STATE_H
#define __H_SOLD_STATE_H

class State;
class GumballMachine;

class SoldState : public State
{
    private:
        GumballMachine* m_gumball_machine;
    public:
        SoldState();
        void insertQuarter();
        void ejectQuarter();
        void turnCrank();
        void dispense();
        void set_context(GumballMachine* machine_);
};

#endif
