#include <iostream>
#include "GumballMachine.h"

int main()
{	
    GumballMachine g1 {5};

    std::cout << "TEST #1:\n\n\n";
    g1.insertQuarter();
    g1.turnCrank();

    std::cout << "TEST #2:\n\n\n";
    g1.insertQuarter();
    g1.ejectQuarter();
    g1.turnCrank();

    std::cout << "TEST #3:\n\n\n";
    g1.insertQuarter();
    g1.turnCrank();
    g1.insertQuarter();
    g1.turnCrank();
    g1.ejectQuarter();

    std::cout << "TEST #4:\n\n\n";
    g1.insertQuarter();
    g1.insertQuarter();
    g1.turnCrank();
    g1.insertQuarter();
    g1.turnCrank();
    g1.insertQuarter();
    g1.turnCrank();

    GumballMachine g2 {14};

    for (int i = 0; i < 12; i++)
    {
        g2.insertQuarter();
        g2.turnCrank();
    }

    g2.insertQuarter();
    g2.turnCrank();
    g2.insertQuarter();
    g2.turnCrank();


	return 0;
}
