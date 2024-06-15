#ifndef __H_SOLD_OUT_H
#define __H_SOLD_OUT_H

class State;
class GumballMachine;

class SoldOutState : public State
{
    public:
        SoldOutState();
        ~SoldOutState();
        void insertQuarter();
        void ejectQuarter();
        void turnCrank();
        void dispense();
        void set_context(GumballMachine* machine_);
        int m_name;
    private:
        GumballMachine* m_gumball_machine;
};

#endif
