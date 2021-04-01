#include "Automata.h"

	void Automata::on()
	{
		cash = 0;
		state = WAIT;
		cooked = false;
	}

	void Automata::off()
	{
		cash = 0;
		state = OFF;
	}

	void Automata::coin(unsigned int money)
	{
		cash += money;
		state = ACCEPT;
		cooked = false;
	}

	const std::string* Automata::etMenu()
	{
		return menu;
	}

	STATES Automata::getState()
	{
		return state;
	}

	void Automata::choise(unsigned int num)
	{
		if (num >= menuSize)
		{
			return;
		}
		state = CHECK;
		check(num);
	}

	void Automata::check(unsigned int num)
	{
		if (prices[num] > cash)
		{
			cancel();
		}
		else
		{
			state = COOK;
			cash -= prices[num];
			cook();
		}
	}

	void Automata::cancel()
	{
		cash = 0;
		state = WAIT;
	}

	void Automata::cook()
	{
		finish();
	}

	void Automata::finish()
	{
		state = WAIT;
		cooked = true;
	}

	Automata::Automata(const std::string& input)
	{
		cash = 0;
		menu[0] = "чай";
		menu[1] = "кофе";
		menu[2] = "кофе с молоком";
		prices[0] = 10;
		prices[1] = 15;
		prices[2] = 20;
		state = OFF;
		on();

		std::string cashAsStr = "";
		int sum, i;
		char st = 'a';
		for (i = 0; i < input.size(); ++i)
		{
			if (st == 'a')
			{
				if (input[i] == 'c')
				{
					st = 'c';
				}
				else if (input[i] == 'm')
				{
					st = 'm';
				}
			}
			else if ((st == 'c') || (st == 'm'))
			{
				if ((input[i] >= '0') and (input[i] <= '9'))
				{
					cashAsStr += input[i];
				}
				else
				{
					try
					{
						if (std::stoi(cashAsStr) < 0)
						{
							cooked = false;
							break;
						}
						if (st == 'c')
						{
							coin(std::stoi(cashAsStr));
						}
						if (st == 'm')
						{
							choise(std::stoi(cashAsStr));
						}
					}
					catch (...)
					{
						cooked = false;
						break;
					}
					cashAsStr = "";
					st = 'a';
					--i;
				}
			}
		}
		if ((st == 'c') || (st == 'm'))
		{
			try
			{
				if (std::stoi(cashAsStr) < 0)
				{
					cooked = false;
					return;
				}
				if (st == 'c')
				{
					coin(std::stoi(cashAsStr));
				}
				if (st == 'm')
				{
					choise(std::stoi(cashAsStr));
				}
			}
			catch (...)
			{
				cooked = false;
			}
		}
	}

	bool Automata::result()
	{
		return cooked;
	}
