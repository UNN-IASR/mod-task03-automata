#include "Automata.h"
#include <iostream>
using namespace std;

Automata::Automata()
{
	menu = new string[5];

	menu[0] = "tea";
	menu[1] = "juice";
	menu[2] = "cola";
	menu[3] = "pepsi";
	menu[4] = "fanta";

	prices = new int[5];

	cash = 0;

	for (int i = 0; i < 5; i++)
	{
		prices[i] = 10 * (i + 1);
	}
	currstate = OFF;
}
void Automata::on()
{
	currstate = WAIT;
	cash = 0;
}
void Automata::off()
{
	currstate = OFF;
}
void Automata::coin(int money)
{
	if (getState() == ACCEPT || getState() == WAIT)
	{
		if (getState() == WAIT)
			currstate = ACCEPT;
		cash += money;
	}
}
const string* Automata::etMenu()
{
	return menu;
}
States Automata::getState()
{
	return currstate;
}
void Automata::choice(int _choice)
{
	if (getState() == ACCEPT)
	{
		currstate = CHECK;
		if (check(_choice - 1) && (_choice < 6) && (_choice > 0))
		{
			cash -= prices[_choice - 1];
			cook();
		}
		else
			cancel();
	}
}
bool Automata::check(int _choice)
{
	if (getState() == CHECK)
	{
		if (cash - prices[_choice] >= 0)
			return true;
		else
			return false;
	}
}
int Automata::cancel()
{
	if (getState() == ACCEPT || getState() == CHECK)
	{
		currstate = WAIT;
		int temp = cash;
		cash = 0;
		return temp;
	}
	else
		return 0;
}
void Automata::cook()
{
	if (getState() == CHECK)
	{
		currstate = COOK;
		if (cash == 0)
			finish();
	}
}
int Automata::finish()
{
	if (getState() == COOK)
	{
		currstate = WAIT;
		int temp = cash;
		cash = 0;
		return temp;
	}
}
Automata::~Automata()
{
	delete[] menu;
	delete[] prices;
}