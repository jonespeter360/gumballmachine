#ifndef __H_GUMBALL_MACHINE_H 
#define __H_GUMBALL_MACHINE_H

class State;

class GumballMachine
{
    public:
        GumballMachine(int gumballs_, State* state_);
        void TransitionTo(State* state_);
        void insertQuarter();
        void ejectQuarter();
        void turnCrank();
        void dispense();
        void releaseBall();
        int count();
    private:
        State* m_state;
        int m_gumballs;
};

#endif
