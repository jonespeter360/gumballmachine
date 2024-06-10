SoldState::SoldState(GumballMachine* machine_): m_gumball_machine {machine_} {};

void SoldState::insertQuarter()
{
    std::cout << "You can't insert a quarter until after your gumball is dispensed.\n";
}
void SoldState::ejectQuarter()
{
    std::cout << "Sorry, you already turned the crank!\n";
}
void SoldState::turnCrank()
{
    std::cout << "Please wait until your gumball is dispensed.\n";
}
void SoldState::dispense()
{
    m_gumball_machine->releaseBall();
    if (m_gumball_machine->getCount() > 0)
    {
        m_gumball_machine->TransitionTo(new NoQuarterState());
    }
    else
    {
        std::cout << "The machine is now sold out of gumballs\n";
        m_gumball_machine->TransitionTo(new SoldOutState());
    }
}
