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

class Automata
{
private:
	int cash;
	string* menu;
	int* prices;
	STATES state = OFF;
public:
	void on();
	void off();
	void coin(unsigned int CASH);
	string* etMenu();
	STATES getState();
	int choice(unsigned int CHOICE);
	bool check(int CHOICE);
	void cancel();
	void returnMoney();
	void cook();
	void finish();
};
