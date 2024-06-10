#include "State.h"
#include "GumballMachine.h"
#include "NoQuarterState.h"
#include <iostream>

GumballMachine::GumballMachine(int gumballs_): 
            m_state {nullptr},
            m_gumballs {gumballs_}
{
    if (m_gumballs > 0)
    {
       TransitionTo(new NoQuarterState());
    }
}

void GumballMachine::TransitionTo(State* state_)
{
    if (m_state != nullptr) delete m_state;
    m_state = state_;
    state_->set_context(this);
}
void GumballMachine::insertQuarter()
{
    m_state->insertQuarter();
}
void GumballMachine::ejectQuarter()
{
    m_state->ejectQuarter();
}
void GumballMachine::turnCrank()
{
    m_state->turnCrank();
    m_state->dispense();
}

void GumballMachine::releaseBall()
{
    std::cout << "A ball comes rolling out the slot!\n";
    if (count() != 0)
    {
        m_gumballs -= 1;
    }
}

int GumballMachine::count()
{
    return m_gumballs;
}
