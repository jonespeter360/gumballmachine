#ifndef __H_STATE_H
#define __H_STATE_H

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

template<typename T>
class StateTemp
{
    public:
        StateTemp() {};
        void insertQuarter(data&) {};
        void ejectQuarter(data&) {};
        void turnCrank(data&) {};
        void dispense(data&) {};
        void set_context(T* context_) {m_ptr = context_; };
        int get_name() {return m_name;};
        ~StateTemp() {};
    private:
        int m_name;
        T* m_ptr;
};

StateTemp<GumballMachine*> HasQuarterStateTemp;

HasQuarterStateTemp::HasQuarterStateTemp() { m_name = HAS_QUARTER_STATE; };

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
