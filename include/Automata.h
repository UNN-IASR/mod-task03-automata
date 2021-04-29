#pragma once
const int N = 3;
class Automata
{
	enum STATES
	{
		OFF,
		WAIT,
		ACCEPT,
		CHECK,
		COOK
	};
	unsigned int cash;
	const char* menu[N] = { "Чай","Кофе","Молоко" };
	const unsigned int price[N] = { 70,100,50 };
	STATES state;
	
	bool check(unsigned int num);
	void cook();
	void finish();
public:
	Automata();
	void on();
	void off();
	void coin(unsigned int);
	const char** etMenu();
	STATES getState();
	int choice(unsigned int);
	int cancel();
};
