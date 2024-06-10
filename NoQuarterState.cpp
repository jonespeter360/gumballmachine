#include "State.h"
#include "GumballMachine.h"
#include "NoQuarterState.h"
#include "HasQuarterState.h"
#include <iostream>

NoQuarterState::NoQuarterState(): m_gumball_machine { nullptr } {}

void NoQuarterState::insertQuarter()
{
    std::cout << "You inserted a quarter\n";
    m_gumball_machine->TransitionTo(new HasQuarterState());
}

void NoQuarterState::ejectQuarter()
{
    std::cout << "You haven't inserted a quarter\n";
}

void NoQuarterState::turnCrank()
{
    std::cout << "You turned but there's no quarter\n";
}

void NoQuarterState::dispense()
{
    std::cout << "You need to pay first\n";
}
