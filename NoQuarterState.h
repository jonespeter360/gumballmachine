#ifndef __H_NO_QUARTER_H
#define __H_NO_QUARTER_H

class State;
class GumballMachine;

class NoQuarterState : public State
{
    private:
        GumballMachine* m_gumball_machine;
    public:
        NoQuarterState();
        void insertQuarter();
        void ejectQuarter();
        void turnCrank();
        void dispense();
};

#endif
