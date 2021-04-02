#include "Automata.h"

Automata::Automata(const std::vector<std::string> menu_list, const std::vector<int> prices_list)
{
	menu = menu_list;
	ceny = prices_list;
}
void Automata::on()
{
	state = states::wait;
}
void Automata::off()
{
	state = states::off;
}
void Automata::coin(int m)
{
	state = states::accept;
	money = money + m;
}
vector<string> Automata::get_menu()
{
	return menu;
}
vector<int> Automata::get_ceny()
{
	return ceny;
}
int Automata::otmena()
{
	state = states::wait;
	return money;
}
bool Automata::vibor(int pos)
{
	state = states::check;
	if (money>=ceny[pos])
	{
		money = money - ceny[pos];
		cook();
		return true;
	}
	else
	{
		state = states::accept;
		return false;
		
	}
}
void Automata::cook()
{
	state = states::cook;
}
int Automata::finish()
{
	state = states::wait;
	return money;
}
states Automata::get_state()
{
	return state;
}
