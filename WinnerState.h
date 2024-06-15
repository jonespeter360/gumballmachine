#ifndef __H_WINNERSTATE_H
#define __H_WINNERSTATE_H

class State;

class GumballMachine;

class WinnerState : public State
{
    public:
        WinnerState();
        void insertQuarter();
        void ejectQuarter();
        void turnCrank();
        void dispense();
        void set_context(GumballMachine* machine_);
        ~WinnerState() {};
        int m_name;
    private:
        GumballMachine* m_gumball_machine;
};

#endif
