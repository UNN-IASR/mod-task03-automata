#include <iostream>
#include "Automata.h"
#include <string>

using namespace std;

int main() {
	Automata CoffeeMachine = Automata();
	CoffeeMachine.on();
CoffeeMachine.coin(20);
	CoffeeMachine.choice(1);

	
	CoffeeMachine.coin(10);
	CoffeeMachine.choice(1);


	CoffeeMachine.coin(30);
	CoffeeMachine.choice(4);


CoffeeMachine.coin(30);
	CoffeeMachine.choice(2);

	

	CoffeeMachine.off();
	return 0;
}