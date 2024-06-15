#ifndef __H_STATE_H
#define __H_STATE_H

#include <iostream>

constexpr short int DEFAULT_STATES {5};

enum States
{
    HAS_QUARTER_STATE = 1,
    NO_QUARTER_STATE = 2,
    SOLD_OUT_STATE = 4,
    SOLD_STATE = 8,
    WINNER_STATE = 16
};

struct data;
class GumballMachine;

template<const int STATE>
class StateTemp
{
    public:
        StateTemp() { m_name = STATE; };
        virtual void insertQuarter(data&) = 0;
        virtual void ejectQuarter(data&)  = 0;
        virtual void turnCrank(data&)  =  0;
        virtual void dispense(data&)  = 0;
        void set_context(GumballMachine* context_) { m_ptr = context_; };
        int get_name() {return m_name;};
        virtual ~StateTemp() {};
    private:
        int m_name;
        GumballMachine* m_ptr;
};

template<>
void StateTemp<SOLD_STATE>::insertQuarter(data& data_)
{
    std::cout << "You can't insert a quarter until after your gumball is dispensed.\n";
}

class SoldStateTemp : public StateTemp<SOLD_STATE> {};

class State
{
    public:
        virtual void insertQuarter(data&) = 0;
        virtual void ejectQuarter(data&) = 0;
        virtual void turnCrank(data&) = 0;
        virtual void dispense(data&) = 0;
        virtual void set_context(GumballMachine* machine_) = 0;
        virtual int get_name() = 0;
        virtual ~State() {};
};

#endif
