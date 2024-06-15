#include "State.h"
#include "GumballMachine.h"
#include <iostream>

GumballMachine::GumballMachine(int gumballs_): 
            m_state {nullptr},
            m_data {gumballs_,0},
            m_states {}
{
    m_states.reserve(DEFAULT_STATES);
}

GumballMachine::~GumballMachine()
{
    if (m_state != nullptr) m_state = nullptr;
}

void GumballMachine::TransitionTo(int state_)
{
    if (m_state == nullptr) init();

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
    m_state->insertQuarter(m_data);
}
void GumballMachine::ejectQuarter()
{
    m_state->ejectQuarter(m_data);
}
void GumballMachine::turnCrank()
{
    m_state->turnCrank(m_data);
    m_state->dispense(m_data);
}

void GumballMachine::releaseBall()
{
    std::cout << "A ball comes rolling out the slot!\n";
    if (m_data.gumballs != 0)
    {
        m_data.gumballs -= 1;
    }
}


void GumballMachine::Initialize()
{
    m_states.emplace_back(new State<HAS_QUARTER_STATE>());
    m_states.emplace_back(new State<NO_QUARTER_STATE>());
    m_states.emplace_back(new State<SOLD_OUT_STATE>());
    m_states.emplace_back(new State<SOLD_STATE>());
    m_states.emplace_back(new State<WINNER_STATE>());

    if (m_data.gumballs > 0)
    {
       TransitionTo(States::NO_QUARTER_STATE);
    }
}

void GumballMachine::init()
{
    m_state = m_states[0];
}

void GumballMachine::restock(int gumballs_)
{
    m_state->restock(m_data,gumballs_);
}

void GumballMachine::reload(int gumballs_)
{
    m_data.gumballs += gumballs_;
}
