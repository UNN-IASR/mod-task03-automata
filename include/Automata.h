#pragma once
#include <string>

using namespace std;

enum STATES {
	OFF,
	WAIT,
	ACCEPT,
	CHECK,
	COOK
};

class Automata {
	unsigned int cash = 0;
	string menu[4] = { "Чай", "Кофу", "Молоко","Пустой стакан" };
	unsigned int prices[4] = {25, 45, 15 , 5};
	STATES state = OFF;
	bool cooking = false;

	void check(unsigned int ch);
	void cancel();
	void cook();
	void finish();

public:
	void on();
	void off();
	void coin(unsigned int money);
	const string* etMenu();
	const STATES getState();
	void choice(unsigned int ch);
};