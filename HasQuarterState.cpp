#include "State.h"
#include "GumballMachine.h"
#include "NoQuarterState.h"
#include "SoldState.h"
#include "HasQuarterState.h"
#include <iostream>

HasQuarterState::HasQuarterState(GumballMachine* machine_): m_gumball_machine { machine_ } {}

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
    std::cout << "You turned but there's no quarter\n";
    m_gumball_machine->TransitionTo(new SoldState());
}

void HasQuarterState::dispense()
{
    std::cout << "No gumball dispensed\n";
}
