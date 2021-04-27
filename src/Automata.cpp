
#include "Automata.h"
#include <iostream>

const int n = 5;
const int timer = 10000;

Automata::Automata()
{
	m_nCash = 0;
	m_eState = eOFF;
	m_nPrices.resize(n);

	m_sMenu.push_back(GREEN_TEA);
	m_sMenu.push_back(BLACK_TEA);
	m_sMenu.push_back(LATTE);
	m_sMenu.push_back(CAPPUCCINO);
	m_sMenu.push_back(ESPRESSO);

	for (int i = 0; i < n; i++)
	{
		m_nPrices[i] = (i + 1) * n + i % 2;
	}
}

void Automata::On()
{
	m_eState = eWAIT;
}

void Automata::Off()
{
	m_eState = eOFF;
}

void Automata::Coin(int nCash)
{
	m_eState = eACCEPT;
	m_nCash = nCash;
}

void Automata::GetMenu()
{
	for (int i = 0; i < n; i++)
	{
		std::cout << m_sMenu[i] << "	" << m_nPrices[i] << std::endl;
	}
}

bool Automata::Choice(std::string sDrink)
{
	m_eState = eCHECK;
	bool bEnoughCash = Check(sDrink);
	std::cout << "Chosen " << sDrink << std::endl;

	if (!bEnoughCash)
	{
		m_eState = eACCEPT;
		std::cout << "Not enough cash." << std::endl;
	}
	else
	{
		std::cout << "Ready to cook " << sDrink << std::endl;
	}

	return bEnoughCash;
}

bool Automata::Check(std::string sDrink)
{
	bool bEnoughCash = false;

	for (int i = 0; i < n; i++)
	{
		if ((m_sMenu[i] == sDrink) &&
			(m_nPrices[i] <= m_nCash))
		{
			bEnoughCash = true;
			m_nCash -= m_nPrices[i];
		}
	}

	return bEnoughCash;
}

int Automata::Cancel()
{
	m_eState = eWAIT;
	return m_nCash;
}

int Automata::Cook()
{
	m_eState = eCOOK;

	std::cout << "Cooking, please wait.." << std::endl;
	for (int i = 0; i < timer; i++)
	{

	}
	std::cout << "Done" << std::endl;
	Finish();

	return m_nCash;
}

void Automata::Finish()
{
	m_eState = eWAIT;
}
