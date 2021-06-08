#include <iostream>
#include "Automata.h"
#include <string>

using namespace std;

int main() 
{
	Automata A = Automata();
	A.on();
	A.coin(50);
	A.choice(1);
	A.coin(70);
	A.choice(1);
	A.coin(30);
	A.choice(3);
	A.choice(4);
	A.off();
	return 0;
}