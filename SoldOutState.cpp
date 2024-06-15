#include "State.h"
#include "GumballMachine.h"
#include "SoldOutState.h"
#include <iostream>

SoldOutState::SoldOutState(): m_gumball_machine {nullptr },
                              m_name {States::SOLD_OUT_STATE} {}

void SoldOutState::insertQuarter(data& data_)
{
    std::cout << "This machine is sold out: you can't insert a quarter\n";
}
void SoldOutState::ejectQuarter(data& data_)
{
    std::cout << "You can't eject a quarter that isn't there!\n";
}
void SoldOutState::turnCrank(data& data_)
{
    std::cout << "You turn the crank but nothing happens\n";
}
void SoldOutState::dispense(data& data_)
{
    std::cout << "There are no gumballs to dispense\n";
}

void SoldOutState::set_context(GumballMachine* machine_)
{
    m_gumball_machine = machine_;
}

SoldOutState::~SoldOutState()
{
    m_gumball_machine = nullptr;
};


int SoldOutState::get_name() { return m_name; };
