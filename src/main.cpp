#include <iostream>
#include "Automata.h"

using namespace std;

int main()
{
    Automata coffee = Automata();

    coffee.on();
    coffee.coin(10);
    coffee.coin(20);
    coffee.choise(2);
    int change = coffee.finish();

    coffee.coin(30);
    change = coffee.cancel();
    coffee.off();
    return 0;
}