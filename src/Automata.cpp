#pragma once
#include "Automata.h"

void Automata::check(unsigned int sure) {
	if (cash >= prices[sure]) {
		cash -= prices[sure];
		cook();
	}
	else {
		cancel();
	}
}

void Automata::off() {
	state = OFF;
}

void Automata::on() {
	state = WAIT; cash = 0;
}

void Automata::coin(unsigned int dengi) {
	state = ACCEPT; cash += dengi;
}

const string* Automata::etMenu()
{
	return menu;
}

const STATES Automata::getState()
{
	return state;
}

void Automata::choice(unsigned int choose) {
	if (choose - 1 < 4) {
		state = CHECK;
		check(choose);
	}
}

void Automata::cancel() {
	state = WAIT; cash = 0;
}

void Automata::finish() {
	state = WAIT; cooking = false;
	
}

void Automata::cook() {
	state = COOK; cooking = true;
	finish();
}

