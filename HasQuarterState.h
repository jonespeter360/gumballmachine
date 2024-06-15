#ifndef __H_HAS_QUARTER_H
#define __H_HAS_QUARTER_H

class State;
class GumballMachine;

class HasQuarterState : public State
{
    public:
        HasQuarterState();
        ~HasQuarterState();
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
