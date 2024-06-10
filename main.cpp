#include "main.h"

//enum States
//{
//    SOLD_OUT = 0,
//    NO_QUARTER = 1,
//    HAS_QUARTER = 2,
//    SOLD = 4
//};

class GumballMachine;

class State
{
    protected:
        GumballMachine* m_context;
    public:
        virtual void insertQuarter() = 0;
        virtual void ejectQuarter() = 0;
        virtual void turnCrank() = 0;
        virtual void dispense() = 0;
        void set_context(GumballMachine* machine_)
        {
            m_context = machine_;
        }
        virtual ~State();
};


class GumballMachine
{
    public:
        GumballMachine(int gumballs_, State* state_): 
            m_state {nullptr},
            m_gumballs {gumballs_}
        {
            TransitionTo(state_);
        }
        void TransitionTo(State* state_)
        {
            if (m_state != nullptr) delete state_;
            m_state = state_;
            m_state->set_context(this);
        }
        void insertQuarter()
        {
            m_state->insertQuarter();
        }
        void ejectQuarter()
        {
            m_state->ejectQuarter();
        }
        void turnCrank()
        {
            m_state->turnCrank();
        }
        void dispense()
        {
            m_state->dispense();
        }
    private:
        State* m_state;
        int m_gumballs;
};

class HasQuarterState : public State
{
    public:
        HasQuarterState(GumballMachine* machine_): m_gumball_machine { machine_ } {}
        void insertQuarter()
        {
            std::cout << "You can't insert another quarter: there's already one in the slot\n";
        }
        void ejectQuarter()
        {
            std::cout << "You ejected a quarter\n";
            m_gumball_machine->TransitionTo(new NoQuarterState());
        }
        void turnCrank()
        {
            std::cout << "You turned but there's no quarter\n";
            m_gumball_machine->TransitionTo(new SoldState());
        }
        void dispense()
        {
            std::cout << "No gumball dispensed\n";
        }

    private:
        GumballMachine* m_gumball_machine;


};


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
