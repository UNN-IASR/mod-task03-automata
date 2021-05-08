#include "Automata.h"
#include <string>
using namespace std;

void Automata::on()
{
	if (state == OFF)
	{
		state = WAIT;
		cash = 0;
	}
}

void Automata::off()
{
	if (state == WAIT)
	{
		state = OFF;
		cash = 0;
	}
}

void Automata::coin(int Money)
{
	if ((state == WAIT) || (state == ACCEPT))
	{
		cash += Money;
		state = ACCEPT;
	}
}

const char** Automata::etMenu()
{
	return menu;
}

void Automata::choice(int nom)
{
	if (state == ACCEPT)
	{
		if (nom - 1 < 3)
		{
			state = CHECK;
			if (check(nom) == true)
			{
				cook();
			}
			else
			{
				cancel();
			}
		}
	}
}

bool Automata::check(int nom)
{
	if (state == CHECK)
	{
		if (cash >= prices[nom - 1])
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

void Automata::cancel()
{
	if ((state == ACCEPT) || (state == CHECK))
	{
		state = WAIT;
		cash = 0;
	}
}

void Automata::cook()
{
	if (state == CHECK)
	{
		state = COOK;
		finish();
	}
}

void Automata::finish()
{
	if (state == COOK)
	{
		state = WAIT;
		cash = 0;
	}
}
