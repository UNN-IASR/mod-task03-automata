#pragma once
using namespace std;
#include <string>
class Automata
{

    enum STATES
    {
        OFF, WAIT, ACCEPT, CHECK, COOK,
    };
    int cash = 0;
    const char * menu[3] = { "Классический кофе","Капучино","Горячий шоколад" };
    int prices[3] = { 45, 70, 60 };
    STATES state = OFF;

public :
    void on();
    int off();
    void coin(int money);
    const char** etMenu() { return menu; };
    STATES getState() { return state; };

    void choice(int drink);
    bool check(int drink);
    void cancel();
    void cook(int drink);
    void finish(int drink);       
};