#ifndef __H_HAS_QUARTER_H
#define __H_HAS_QUARTER_H

class State;

class HasQuarterState : public State
{
    public:
        HasQuarterState(GumballMachine* machine_);
        void insertQuarter();
        void ejectQuarter();
        void turnCrank();
        void dispense();
    private:
        GumballMachine* m_gumball_machine;
};

#endif
