#include "Automata.h"


Automata::Automata() {
	state = OFF;
	cash = 0;
	ch = -1;
}
void Automata::on()
{
	if (state == OFF) {
		state = WAIT;
	}
}

void Automata::off() {
	if (state == WAIT)
	{
		state = OFF;
	}
}

int Automata::coin(int cash) {
	if (state == WAIT || state == ACCEPT)
	{
		this->cash += cash;
		state = ACCEPT;
		return 0;
	}
	else return cash;
}

void Automata::choice(int ch) {
	if (state == ACCEPT)
	{
		if (ch <= 4) {
			this->ch = ch;
			state = CHECK;
			check();
		}
	}
}

void Automata::check() {
	if (state == CHECK) {
		if (cash - prices[ch] >= 0)
			cook();
		else state = ACCEPT;
	}
}

int Automata::cancel() {
	if (state == ACCEPT || state == CHECK || state == WAIT)
	{
		state = WAIT;
		int refund = cash;
		cash = 0;
		return refund;
	}
	else return 0;
}

void Automata::cook() {
	if (state == CHECK) {
		state = COOK;
	}
}

string Automata::finish() {
	if (state == COOK) {
		cash -= prices[ch];
		state = WAIT;
		string drink = menu[ch];
		ch = -1;
		return drink;
	}
	return "";

}

string* Automata::etMenu() {
	return menu;
}

Automata::State Automata::getState() {
	return state;
}
