#include "Automata.h"
using namespace std;

void Automata::returnMoney()
{
	cash = 0;
}

void Automata::cancel()
{
	state = WAIT;
	returnMoney();
}

void Automata::finish()
{
	state = WAIT;
	returnMoney();
}

void Automata::cook()
{
	state = COOK;
	finish();
}

void Automata::on()
{
	if (state == OFF)
	{
		state = WAIT;
		cash = 0;
		menu = new string[3];
		menu[0] = "coffee";
		menu[1] = "tea";
		menu[2] = "water";
		prices = new int[3];
		prices[0] = 99;
		prices[1] = 59;
		prices[2] = 39;
	}
}
void Automata::off()
{
	state = OFF;
}

void Automata::coin(unsigned int CASH)
{
	state = ACCEPT;
	cash+= CASH;
}

bool Automata::check(int CHOICE)
{
	if (cash < prices[CHOICE-1])
	{
		cancel();
	}
	else
		cash -= prices[CHOICE-1];
		cook();
}

int Automata::choice(unsigned int CHOICE)
{
	try
	{   
		if (CHOICE < 1 || CHOICE > 3)
		{
			throw 0;
		}
		else
		{
			state = CHECK;
			check(CHOICE);
			return 1;
		}
	}
	catch(int i)
	{
		return i;
	}
	
}
