#include "State.h"
#include "GumballMachine.h"
#include "SoldState.h"
#include "SoldOutState.h"
#include "NoQuarterState.h"
#include <iostream>



SoldState::SoldState(): m_gumball_machine {nullptr} {};

void SoldState::insertQuarter()
{
    std::cout << "You can't insert a quarter until after your gumball is dispensed.\n";
}
void SoldState::ejectQuarter()
{
    std::cout << "Sorry, you already turned the crank!\n";
}
void SoldState::turnCrank()
{
    std::cout << "Please wait until your gumball is dispensed.\n";
}
void SoldState::dispense()
{
    m_gumball_machine->releaseBall();
    if (m_gumball_machine->count() > 0)
    {
        m_gumball_machine->TransitionTo(new NoQuarterState());
    }
    else
    {
        std::cout << "The machine is now sold out of gumballs\n";
        m_gumball_machine->TransitionTo(new SoldOutState());
    }
}

void SoldState::set_context(GumballMachine* machine_)
{
    m_gumball_machine = machine_;
}
