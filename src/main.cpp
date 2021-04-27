#include "Automata.h"

int main()
{
	Automata A;
	int change = 0;
	A.on();
	A.coin(30);
	A.coin(20);
	change += A.choice(1);
	A.coin(30);
	change += A.choice(1);
	A.coin(50);
	change += A.cancel();
	A.coin(100);
	change += A.choice(2);
	A.off();
	return change;
}
