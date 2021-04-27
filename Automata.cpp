#include "Automata.h"
#include <Windows.h>

Automata::Automata()
{
	cash = 0;
	state = OFF;
}

void Automata::on()
{
	if (state == OFF)
	{
		state = WAIT;
	}
}

void Automata::off()
{
	if (state == WAIT)
	{
		state = OFF;
	}
}

void Automata::coin(unsigned int amount)
{
	if (state == ACCEPT) cash += amount;
	if (state == WAIT || state == CHECK)
	{
		if(state == WAIT) state = ACCEPT;
		cash += amount;
	}
}

const char** Automata::etMenu()
{
	return menu;
}

Automata::STATES Automata::getState()
{
	return state;
}

int Automata::choice(unsigned int choice)
{
	if (state == ACCEPT || state == CHECK)
		if (choice <= N && choice > 0)
		{
			state = CHECK;
			if (check(choice))
			{
				cash -= price[choice - 1];
				cook();
				int change = cash;
				cash = 0;
				return change;
			}
		}
	return 0;
}

bool Automata::check(unsigned int num)
{
	if (state == CHECK)
		return cash >= price[num - 1];
	return false;
}

int Automata::cancel()
{
	if (state == ACCEPT || state == CHECK)
	{
		state = WAIT;
		int change = cash;
		cash = 0;
		return change;
	}
	return 0;
}

void Automata::cook()
{
	if (state == CHECK)
	{
		state = COOK;
		Sleep(3000);
		finish();
	}
}

void Automata::finish()
{
	if (state == COOK)
	{
		state = WAIT;
		Sleep(3000);
	}
}
