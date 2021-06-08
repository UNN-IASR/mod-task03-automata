#include "Automata.h"
#include "Automata.cpp"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	Automata CoffeMachine = Automata();
	CoffeMachine.on();
	CoffeMachine.coin(80);
    CoffeMachine.choice(2);
	CoffeMachine.coin(50);
	CoffeMachine.choice(1);
	CoffeMachine.off();
}
