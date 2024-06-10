#ifndef __H_STATE_H
#define __H_STATE_H

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

#endif
