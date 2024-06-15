#ifndef __H_STATE_H
#define __H_STATE_H

#include <iostream>
#include "GumballMachine.h"

constexpr short int DEFAULT_STATES {5};

enum States
{
    HAS_QUARTER_STATE = 1,
    NO_QUARTER_STATE = 2,
    SOLD_OUT_STATE = 4,
    SOLD_STATE = 8,
    WINNER_STATE = 16
};

class State_If
{
    public:
        State_If() {};
        virtual void insertQuarter(data&) = 0;
        virtual void ejectQuarter(data&)  = 0;
        virtual void turnCrank(data&)  =  0;
        virtual void dispense(data&)  = 0;
        virtual void restock(data&,int)  = 0;
        virtual void set_context(GumballMachine* context_) = 0;
        virtual int get_name() = 0;
        virtual ~State_If() {};
};


template <const int STATE>
class State : public State_If
{
    public:
        State() { m_name = STATE; };
        virtual void insertQuarter(data&) {};
        virtual void ejectQuarter(data&) {};
        virtual void turnCrank(data&)  {};
        virtual void dispense(data&)  {};
        virtual void restock(data&,int)  {};
        virtual void set_context(GumballMachine* context_) { m_gumball_machine = context_; };
        virtual int get_name() { return m_name; };
        ~State() { m_gumball_machine = nullptr; }
    private:
        int m_name;
        GumballMachine* m_gumball_machine;
};


template<>
void State<WINNER_STATE>::dispense(data& data_)
{
    if (data_.gumballs == 0)
    {
        m_gumball_machine->TransitionTo(States::SOLD_OUT_STATE);
    }
    else
    {
        if (data_.gumballs > 0) 
        {
            m_gumball_machine->releaseBall();
            m_gumball_machine->TransitionTo(States::NO_QUARTER_STATE);
        }
        else
        {
            std::cout << "Oops! Out of gumballs!\n";
            m_gumball_machine->TransitionTo(States::SOLD_OUT_STATE);
        }
    }
}

template<>
void State<SOLD_OUT_STATE>::insertQuarter(data& data_)
{
    std::cout << "This machine is sold out: you can't insert a quarter\n";
}

template<>
void State<SOLD_OUT_STATE>::ejectQuarter(data& data_)
{
    std::cout << "You can't eject a quarter that isn't there!\n";
}

template<>
void State<SOLD_OUT_STATE>::turnCrank(data& data_)
{
    std::cout << "You turn the crank but nothing happens\n";
}

template<>
void State<SOLD_OUT_STATE>::dispense(data& data_)
{
    std::cout << "There are no gumballs to dispense\n";
}

template<>
void State<SOLD_OUT_STATE>::restock(data& data_, int gumballs_)
{
    std::cout << "You're adding " << gumballs_ << " to the (empty) machine.\n";
    m_gumball_machine->reload(gumballs_);
    m_gumball_machine->TransitionTo(States::NO_QUARTER_STATE);
}

template<>
void State<NO_QUARTER_STATE>::restock(data& data_, int gumballs_)
{
    std::cout << "You're adding " << gumballs_ << " to the non-empty machine.\n";
    m_gumball_machine->reload(gumballs_);
}
template<>
void State<NO_QUARTER_STATE>::insertQuarter(data& data_)
{
    std::cout << "You inserted a quarter\n";
    m_gumball_machine->TransitionTo(States::HAS_QUARTER_STATE);
}

template<>
void State<NO_QUARTER_STATE>::ejectQuarter(data& data_)
{
    std::cout << "You haven't inserted a quarter\n";
}

template<>
void State<NO_QUARTER_STATE>::turnCrank(data& data_)
{
    std::cout << "You turned but there's no quarter\n";
}

template<>
void State<NO_QUARTER_STATE>::dispense(data& data_)
{
    std::cout << "You need to pay first\n";
}

template<>
void State<HAS_QUARTER_STATE>::insertQuarter(data& data_)
{
    std::cout << "You can't insert another quarter: there's already one in the slot\n";
}

template<>
void State<HAS_QUARTER_STATE>::ejectQuarter(data& data_)
{
    std::cout << "You ejected a quarter\n";
    m_gumball_machine->TransitionTo(States::NO_QUARTER_STATE);
}

template<>
void State<HAS_QUARTER_STATE>::turnCrank(data& data_)
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

template<>
void State<HAS_QUARTER_STATE>::dispense(data& data_)
{
    std::cout << "No gumball dispensed\n";
}


template<>
void State<SOLD_STATE>::insertQuarter(data& data_)
{
    std::cout << "You can't insert a quarter until after your gumball is dispensed.\n";
}

template<>
void State<SOLD_STATE>::ejectQuarter(data& data_)
{
    std::cout << "Sorry, you already turned the crank!\n";
}

template<>
void State<SOLD_STATE>::turnCrank(data& data_)
{
    std::cout << "Please wait until your gumball is dispensed.\n";
}

template<>
void State<SOLD_STATE>::dispense(data& data_)
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


#endif
