#include "State.h"
#include "GumballMachine.h"
#include <iostream>

GumballMachine::GumballMachine(int gumballs_, State* state_): 
            m_state {nullptr},
            m_gumballs {gumballs_}
{
    TransitionTo(state_);
}
void GumballMachine::TransitionTo(State* state_)
{
    if (m_state != nullptr) delete state_;
    m_state = state_;
    m_state->set_context(this);
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
}
void GumballMachine::dispense()
{
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
