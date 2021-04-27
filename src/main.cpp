#include <iostream>
#include "Automata.h"
using namespace std;

//const char* menu[N] = { "Чай","Кофе","Молоко" };
//const int price[N] = { 70,100,50 };

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
