#ifndef __H_NO_QUARTER_H
#define __H_NO_QUARTER_H

class State;
class GumballMachine;

class NoQuarterState : public State
{
    public:
        NoQuarterState();
        ~NoQuarterState();
        void insertQuarter();
        void ejectQuarter();
        void turnCrank();
        void dispense();
        void set_context(GumballMachine* machine_);
        int get_name();
    private:
        GumballMachine* m_gumball_machine;
        int m_name;
};

#endif
