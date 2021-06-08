#include "Automata.h"
using namespace std;

bool Automata::check(int val)
{
    st = CHECK;
    bool F = false;
    if (val <= 3)
        if (prices[val - 1] <= cash) F = true;
    return F;
}
void Automata::cook(int val)
{
    st = COOK;
    int k = 0;
    for (int i = 0; i < 10000; i++) k++;//simulated cooking
    finish(val);
}
void Automata::finish(int val)
{
    st = WAIT;
    cash = cash - prices[val - 1];
    int k = 0;
    for (int i = 0; i < 10000; i++) k++;//Simulated dispensing of a drink
}
void Automata::on()
{
    if (st == OFF)
    {
        st = WAIT;
    }
}
int Automata::off()
{
    if (st == COOK || st == CHECK)
    {
        int k = 0;
        for (int i = 0; i < 100000; i++) k++;//pause
    }
    st = OFF;
    int change = cash;
    cash = 0;
    return change;
}
void Automata::coin(int money)
{
    if (st != OFF)
    {
        cash = cash + money;
        if (st == WAIT) st = ACCEPT;
    }
}
int Automata::choice(int val)
{
    if (st == ACCEPT)
    {
        if (check(val)) cook(val);
        else return cancel();
    }
    return 0;
}
const char** Automata::etMenu()
{
    return menu;
}
int Automata::cancel()
{
    if (st == ACCEPT || st == CHECK || st == WAIT)
    {
        st = WAIT;
        int change = cash;
        cash = 0;
        return change;
    }
}
