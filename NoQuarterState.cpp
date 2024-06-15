#include "State.h"
#include "GumballMachine.h"
#include "NoQuarterState.h"
#include "HasQuarterState.h"
#include <iostream>

NoQuarterState::NoQuarterState(): m_gumball_machine { nullptr },
                                  m_name {States::NO_QUARTER_STATE} {}

void NoQuarterState::insertQuarter(data& data_)
{
    std::cout << "You inserted a quarter\n";
    m_gumball_machine->TransitionTo(States::HAS_QUARTER_STATE);
}

void NoQuarterState::ejectQuarter(data& data_)
{
    std::cout << "You haven't inserted a quarter\n";
}

void NoQuarterState::turnCrank(data& data_)
{
    std::cout << "You turned but there's no quarter\n";
}

void NoQuarterState::dispense(data& data_)
{
    std::cout << "You need to pay first\n";
}

void NoQuarterState::set_context(GumballMachine* machine_)
{
    m_gumball_machine = machine_;
}

NoQuarterState::~NoQuarterState()
{
    m_gumball_machine = nullptr;
};

int NoQuarterState::get_name() { return m_name; };
