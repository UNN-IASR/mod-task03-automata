#include <iostream>
#include "Automata.h"
#include<string>

using namespace std;

int main()
{
	Automata hot_drinks_machine = Automata();
	hot_drinks_machine.on(); //тут значит работник включил машину
	// подходит первый паренек и кидает 4 раза по 10 рублей
	hot_drinks_machine.coin(10);
	hot_drinks_machine.coin(10);
	hot_drinks_machine.coin(10);
	hot_drinks_machine.coin(10);
	hot_drinks_machine.choice(3);
	// вот он получает свою горячую воду и сдачу
	
	//подходит второй клиентик и кидает 2 раза по 10 рублей
	hot_drinks_machine.coin(10);
	hot_drinks_machine.coin(10);
	// а теперь решает отменить и пойти купить шоколадку на эти деньги, получает кеш обратно
	hot_drinks_machine.cancel();
	
	//тут приходит девушка и думает надурить систему, кидает один раз 10 рублей и выбирает кофе
	hot_drinks_machine.coin(10);
	hot_drinks_machine.choice(1);
	//система видит что нехватает и выбрасывает на отмену, возвращает ей 10 рублей и она уходит
	
	//рабочий день заканчивается, приходит работник и выключает машину
	hot_drinks_machine.off();
	return 0;
}
