#include "State.h"
#include "GumballMachine.h"
#include "WinnerState.h"
#include "SoldOutState.h"
#include "NoQuarterState.h"
#include <iostream>

WinnerState::WinnerState() : m_gumball_machine {nullptr},
                             m_name {States::WINNER_STATE} {}

void WinnerState::insertQuarter()
{
    std::cout << "Err";
}

void WinnerState::ejectQuarter()
{
    std::cout << "Err";
}

void WinnerState::turnCrank()
{
    std::cout << "Err";
}

void WinnerState::dispense()
{
    if (m_gumball_machine->count() == 0)
    {
        m_gumball_machine->TransitionTo(new SoldOutState());
    }
    else
    {
        if (m_gumball_machine->count() > 0) 
        {
            m_gumball_machine->releaseBall();
            m_gumball_machine->TransitionTo(new NoQuarterState());
        }
        else
        {
            std::cout << "Oops! Out of gumballs!\n";
            m_gumball_machine->TransitionTo(new SoldOutState());
        }
    }
}

void WinnerState::set_context(GumballMachine* machine_)
{
    m_gumball_machine = machine_;
}
