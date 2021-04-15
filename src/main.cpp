#include <iostream>
#include "Automata.h"
#include <string>
using namespace std;

int main() {
	Automata CoffeeMachine = Automata();
	CoffeeMachine.on();
	CoffeeMachine.coin(30);
	CoffeeMachine.choice(2);
	CoffeeMachine.coin(15);
	CoffeeMachine.choice(4);
	CoffeeMachine.coin(50);
	CoffeeMachine.choice(1);
	CoffeeMachine.coin(25);
	CoffeeMachine.choice(3);
	CoffeeMachine.off();
	return 0;
}
