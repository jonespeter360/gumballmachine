#ifndef __H_SOLD_STATE_H
#define __H_SOLD_STATE_H

class State;
class GumballMachine;

class SoldState : public State
{
    public:
        SoldState();
        ~SoldState();
        void insertQuarter();
        void ejectQuarter();
        void turnCrank();
        void dispense();
        void set_context(GumballMachine* machine_);
    private:
        GumballMachine* m_gumball_machine;
};

#endif
