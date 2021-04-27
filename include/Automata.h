#pragma once

#include <string>
#include <vector>

#define GREEN_TEA     "green tea"
#define BLACK_TEA     "black tea"
#define LATTE         "latte"
#define CAPPUCCINO    "cappuccino"
#define ESPRESSO      "espresso"

enum etState
{
	eOFF,		// machine is off
	eACCEPT,    // accepting money and choice of the drink
	eWAIT,      // waiting for action
	eCHECK,     // checking money
	eCOOK       // cooking the drink
};

class Automata
{
public:

	Automata();

	void On();

	void Off();

	void Coin(int nCash);

	void GetMenu();

	etState GetState() { return m_eState; }

	bool Choice(std::string sDrink);

	int Cancel();

	int Cook();

private:

	bool Check(std::string sDrink);

	void Finish();

	int m_nCash;
	
	std::vector<std::string> m_sMenu;

	std::vector<int> m_nPrices;

	etState m_eState;

};

