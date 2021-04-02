#include "Automata.h"

int main()
{
	vector<string> menu{ "capuchino","latte","mokko" };
	vector<int> ceny{ 25,20,30 };
	int sdacha = 0;
	Automata cofe(menu,ceny);
	cofe.on();
	cofe.coin(20);
	bool status=cofe.vibor(2);
	if (status == true)
	{
		sdacha=cofe.finish();
	}
	else
	{
		sdacha=cofe.otmena();

	}
	return 0;
}