#ifndef __H_SOLD_STATE_H
#define __H_SOLD_STATE_H

class State;
class GumballMachine;

class SoldState : public State
{
    public:
        SoldState();
        ~SoldState();
        void insertQuarter(data&);
        void ejectQuarter(data&);
        void turnCrank(data&);
        void dispense(data&);
        void set_context(GumballMachine* machine_);
        int get_name();
    private:
        GumballMachine* m_gumball_machine;
        int m_name;
};

#endif
