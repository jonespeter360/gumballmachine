#include "State.h"
#include "GumballMachine.h"
#include "NoQuarterState.h"
#include "SoldState.h"
#include "HasQuarterState.h"
#include "WinnerState.h"
#include <iostream>

HasQuarterState::HasQuarterState(): m_gumball_machine { nullptr },
                                    m_name {States::HAS_QUARTER_STATE} {}

void HasQuarterState::insertQuarter(data& data_)
{
    std::cout << "You can't insert another quarter: there's already one in the slot\n";
}

void HasQuarterState::ejectQuarter(data& data_)
{
    std::cout << "You ejected a quarter\n";
    m_gumball_machine->TransitionTo(States::NO_QUARTER_STATE);
}

void HasQuarterState::turnCrank(data& data_)
{
    std::cout << "Turned the crank...\n";
    if (data_.winner_count == 10)
    {
        std::cout << "You are a winner! If there are enough gumballs, you'll get two for the price of one!\n";
        if (data_.gumballs > 1)
        {
            std::cout << "Because there are at least two gumballs, you'll get two!";
            data_.winner_count = 0;
            m_gumball_machine->TransitionTo(States::WINNER_STATE);
        }
        else
        {
            std::cout << "There aren't two gumballs: you only get one :<( Try again next time!\n";
            ++data_.winner_count;
            m_gumball_machine->TransitionTo(States::SOLD_STATE);
        }
    }
    else
    {
        ++data_.winner_count;
        m_gumball_machine->TransitionTo(States::SOLD_STATE);
    }
}

void HasQuarterState::dispense(data& data_)
{
    std::cout << "No gumball dispensed\n";
}

void HasQuarterState::set_context(GumballMachine* machine_)
{
    m_gumball_machine = machine_;
}

HasQuarterState::~HasQuarterState()
{
    m_gumball_machine = nullptr;
};

int HasQuarterState::get_name() { return m_name; };
