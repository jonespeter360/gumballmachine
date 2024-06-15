#ifndef __H_WINNERSTATE_H
#define __H_WINNERSTATE_H

class State;

class GumballMachine;

class WinnerState : public State
{
    public:
        WinnerState();
        ~WinnerState() {};
        void insertQuarter(data&);
        void ejectQuarter(data&);
        void turnCrank(data&);
        void dispense(data&);
        void set_context(GumballMachine* machine_);
        int get_name();
    private:
        GumballMachine* m_gumball_machine;
        int m_name;
};

#endif
