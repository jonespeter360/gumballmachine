#ifndef __H_GUMBALL_MACHINE_H 
#define __H_GUMBALL_MACHINE_H

#include <vector>

class State_If;

struct data
{
    int gumballs;
    int winner_count;
};

class GumballMachine
{
    public:
        GumballMachine(int gumballs_);
        ~GumballMachine();
        void Initialize();
        void insertQuarter();
        void ejectQuarter();
        void turnCrank();
        void TransitionTo(int state_);
        void releaseBall();
    private:
        void init();
        State_If* m_state;
        data m_data;
        std::vector<State_If*> m_states;
};

#endif
