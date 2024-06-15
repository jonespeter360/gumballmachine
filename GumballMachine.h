#ifndef __H_GUMBALL_MACHINE_H 
#define __H_GUMBALL_MACHINE_H

#include <vector>

class BaseState;

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
        void releaseBall();
        void TransitionTo(int state_);
    private:
        void init();
        BaseState* m_state;
        data m_data;
        std::vector<BaseState*> m_states;
};

#endif
