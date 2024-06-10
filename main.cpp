#include "main.h"

enum States
{
    SOLD_OUT = 0,
    NO_QUARTER = 1,
    HAS_QUARTER = 2,
    SOLD = 4
};

class NaiveGumballMachine
{
    public:
        NaiveGumballMachine(int count);
        void insertQuarter();
        void ejectQuarter();
        void turnCrank();
        void dispense();
    private:
        int state;
        int count; //of gumballs
};

NaiveGumballMachine::NaiveGumballMachine(int count_)
{
    count = count_;
    if (count > 0)
    {
        state = NO_QUARTER;
    }
}

void NaiveGumballMachine::insertQuarter()
{
    switch (state)
    {
    case HAS_QUARTER:
        std::cout << "You can't insert another quarter\n";
        break;
    case NO_QUARTER:
        std::cout << "You inserted a quarter\n";
        state = HAS_QUARTER;
        break;
    case SOLD_OUT:
            std::cout << "You can't insert a quarter; the machine is sold out\n";
        break;
    case SOLD:
        std::cout << "Please wait, we're getting your gumball ready now\n";
        break;
    }
}

void NaiveGumballMachine::ejectQuarter()
{
    switch (state)
    {
    case HAS_QUARTER:
        std::cout << "Quarter returned\n";
        state = NO_QUARTER;
        break;
    case NO_QUARTER:
            std::cout << "You haven't inserted a quarter\n";
        break;
    case SOLD_OUT:
            std::cout << "You can't eject, you haven't inserted a quarter yet\n";
        break;
    case SOLD:
        std::cout << "Sorry you already turned the crank\n";
        break;
    } 
}

void NaiveGumballMachine::turnCrank()
{
    switch (state)
    {
    case SOLD:
        std::cout << "Turning twice doesn't get you another gumball\n";
        break;
    case NO_QUARTER:
        std::cout << "You've turned but there's no quarter\n";
        break;
    case SOLD_OUT:
        std::cout << "You turned but there are no gumballs.\n";
        break;
    case HAS_QUARTER:
        std::cout << "You've turned the crank...\n";
        state = SOLD;
        dispense();
        break;
    } 
}

void NaiveGumballMachine::dispense()
{
    switch (state)
    {
    case SOLD:
        std::cout << "A gumball comes rolling out of the slot.\n";
        count -= 1;
        if (count == 0) 
        {
            std::cout << "The machine is now out of gumballs!\n";
            state = SOLD_OUT;
        }
        else
        {
            state = NO_QUARTER;
        }
        break;
    case NO_QUARTER:
        std::cout << "You need to pay first\n";
        break;
    case SOLD_OUT:
        std::cout << "No gumball dispensed\n";
        break;
    case HAS_QUARTER:
        std::cout << "No gumball dispensed\n";
        break;
    } 
}


int main()
{	

    NaiveGumballMachine simple(3);
    simple.insertQuarter();
    simple.ejectQuarter();
	return 0;

};
