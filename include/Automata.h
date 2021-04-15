#pragma once
#include <string>
using namespace std;

enum STATE {
	OFF,
	WAIT,
	ACCEPT,
	CHECK,
	COOK
};

class Automata {
	unsigned int cash = 0;
	string menu[4] = { "Coffe", "Tea", "Juice", "Water"};
	unsigned int prices[4] = {25, 30, 15, 10 };
	STATE state = OFF;
	bool is_coocking = false;
	void check(unsigned int ch);
	void cancel();
	void cook();
	void finish();
public:
	void on();
	void off();
	void coin(unsigned int money);
	const string* etMenu();
	const STATE getState();
	void choice(unsigned int ch);
};
