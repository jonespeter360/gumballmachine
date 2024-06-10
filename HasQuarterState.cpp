#include "State.h"
#include "GumballMachine.h"
#include "NoQuarterState.h"
#include "SoldState.h"
#include "HasQuarterState.h"
#include <iostream>

HasQuarterState::HasQuarterState(): m_gumball_machine { nullptr } {}

void HasQuarterState::insertQuarter()
{
    std::cout << "You can't insert another quarter: there's already one in the slot\n";
}

void HasQuarterState::ejectQuarter()
{
    std::cout << "You ejected a quarter\n";
    m_gumball_machine->TransitionTo(new NoQuarterState());
}

void HasQuarterState::turnCrank()
{
    std::cout << "Turned the crank...\n";
    m_gumball_machine->TransitionTo(new SoldState());
}

void HasQuarterState::dispense()
{
    std::cout << "No gumball dispensed\n";
}

void HasQuarterState::set_context(GumballMachine* machine_)
{
    m_gumball_machine = machine_;
}
