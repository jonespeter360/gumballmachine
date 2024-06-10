#ifndef __H_HAS_QUARTER_H
#define __H_HAS_QUARTER_H

class State;
class GumballMachine;

class HasQuarterState : public State
{
    public:
        HasQuarterState();
        void insertQuarter();
        void ejectQuarter();
        void turnCrank();
        void dispense();
        void set_context(GumballMachine* machine_);
    private:
        GumballMachine* m_gumball_machine;
};

#endif
