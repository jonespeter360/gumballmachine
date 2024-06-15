#include "State.h"
#include "GumballMachine.h"
#include "SoldState.h"
#include "SoldOutState.h"
#include "NoQuarterState.h"
#include <iostream>

SoldState::SoldState(): m_gumball_machine {nullptr},
                        m_name {States::SOLD_STATE} {}
void SoldState::insertQuarter(data& data_)
{
    std::cout << "You can't insert a quarter until after your gumball is dispensed.\n";
}
void SoldState::ejectQuarter(data& data_)
{
    std::cout << "Sorry, you already turned the crank!\n";
}
void SoldState::turnCrank(data& data_)
{
    std::cout << "Please wait until your gumball is dispensed.\n";
}
void SoldState::dispense(data& data_)
{
    m_gumball_machine->releaseBall();
    if ((data_.gumballs) > 0)
    {
        m_gumball_machine->TransitionTo(States::NO_QUARTER_STATE);
    }
    else
    {
        std::cout << "The machine is now sold out of gumballs\n";
        m_gumball_machine->TransitionTo(States::SOLD_OUT_STATE);
    }
}

void SoldState::set_context(GumballMachine* machine_)
{
    m_gumball_machine = machine_;
}

SoldState::~SoldState()
{
    m_gumball_machine = nullptr;
};

int SoldState::get_name() { return m_name; }
