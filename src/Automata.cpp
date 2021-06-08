#include <iostream>
#include <string>
#include "Automata.h"
using namespace std;

void Automata::on()
{
    if (state == OFF)
        state = WAIT;
}

int Automata::off()
{
    if (state == WAIT)
        state = OFF;
}

void Automata::coin(int money)
{
    if (state == WAIT)
    {
        state = ACCEPT;
        cash = cash + money;
    }
}

void Automata::choice(int drink)
{
    if (state == ACCEPT)
    {
        state = CHECK;
        check(drink);
        if (check(drink) == true)
            cook(drink);
        else
            cancel();
    }

}

bool Automata::check(int drink)
{

    bool status = false;
    if (drink > 0 && drink < 4)
        if (prices[drink - 1] <= cash)
            status = true;
        else state = WAIT;
    return status;
}

void Automata::cancel()
{
    if (state == ACCEPT || state == CHECK)
    {
        state = WAIT;
    }
}

void Automata::cook(int drink)
{
    state = COOK;
    int weight = 0;
    if (drink==0)
    {
        for (int i = 0; i < 1000; i++)
            weight++;
        weight = 0;
    }
    if (drink == 1)
    {
        for (int i = 0; i < 800; i++)
            weight++;
        weight = 0;
    }
    if (drink == 2)
    {
        for (int i = 0; i < 670; i++)
            weight++;
        weight = 0;
    }
    finish(drink);
}

void Automata::finish(int drink)
{
    cash = cash - prices[drink - 1];
    state = WAIT;
}

