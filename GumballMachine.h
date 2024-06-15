#ifndef __H_GUMBALL_MACHINE_H 
#define __H_GUMBALL_MACHINE_H

#include <vector>

class State_If;

struct data
{
    int gumballs;
    int winner_count;
};

class GumballMachine_API
{
    public:
        virtual void Initialize() = 0;
        virtual void insertQuarter() = 0;
        virtual void ejectQuarter() = 0;
        virtual void turnCrank() = 0;
        virtual void restock(int) = 0;
        virtual ~GumballMachine_API() {};
};

class GumballMachine : public GumballMachine_API
{
    public:
        GumballMachine(int gumballs_);
        ~GumballMachine();
        void Initialize();
        void insertQuarter();
        void ejectQuarter();
        void turnCrank();
        void restock(int);
        void reload(int);
        void TransitionTo(int state_);
        void releaseBall();
    private:
        void init();
        State_If* m_state;
        data m_data;
        std::vector<State_If*> m_states;
};

#endif
