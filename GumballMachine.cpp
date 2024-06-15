#include "State.h"
#include "GumballMachine.h"
#include "HasQuarterState.h"
#include "NoQuarterState.h"
#include "SoldOutState.h"
#include "SoldState.h"
#include "WinnerState.h"
#include <iostream>

GumballMachine::GumballMachine(int gumballs_): 
            m_state {nullptr},
            m_gumballs {gumballs_},
            m_winner_count {0},
            m_states {}
{
    m_states.reserve(DEFAULT_STATES);
}

void GumballMachine::TransitionTo(int state_)
{
    if (m_state == nullptr) Initialize();

    if (!(m_state->get_name() & state_))
    {
        for (auto state : m_states)
        {
            if (!(state->get_name() & state_)) continue;
            m_state = state;
            m_state->set_context(this);
            break;
        }
    }
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

int GumballMachine::winner_count()
{
    return m_winner_count;
}

void GumballMachine::set_winner_count(int in_)
{
    m_winner_count = in_;    
}

void GumballMachine::init()
{
    m_states.emplace_back(new HasQuarterState());
    m_states.emplace_back(new NoQuarterState());
    m_states.emplace_back(new SoldOutState());
    m_states.emplace_back(new SoldState());
    m_states.emplace_back(new WinnerState());

    if (m_gumballs > 0)
    {
       TransitionTo(States::NO_QUARTER_STATE);
    }
}

void GumballMachine::Initialize()
{
    m_state = m_states[0];
}
