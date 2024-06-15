#ifndef __H_GUMBALL_MACHINE_H 
#define __H_GUMBALL_MACHINE_H

#include <vector>

class State;

class GumballMachine
{
    public:
        GumballMachine(int gumballs_);
        void TransitionTo(int state_);
        void insertQuarter();
        void ejectQuarter();
        void turnCrank();
        void releaseBall();
        int count();
        int winner_count();
        void set_winner_count(int in_);
        void init();
    private:
        void Initialize();
        State* m_state;
        int m_gumballs;
        int m_winner_count;
        std::vector<State*> m_states;
};

#endif
