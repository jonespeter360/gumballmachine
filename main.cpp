#include <iostream>

class NoQuarterState : public State
{
    private:
        GumballMachine* m_gumball_machine;
    public:
        NoQuarterState(GumballMachine* machine_): m_gumball_machine { nullptr}
        {
            m_gumball_machine = machine_;
        }
        void insertQuarter()
        {
            std::cout << "You inserted a quarter\n";
            m_gumball_machine->TransitionTo(new HasQuarterState());
        }
        void ejectQuarter()
        {
            std::cout << "You haven't inserted a quarter\n";
        }
        void turnCrank()
        {
            std::cout << "You turned but there's no quarter\n";
        }
        void dispense()
        {
            std::cout << "You need to pay first\n";
        }
};


int main()
{	
	return 0;
}
