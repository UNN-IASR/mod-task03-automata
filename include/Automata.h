#pragma once
#include <string>
using namespace std;

class Automata
{
private:
    enum State
    {
        OFF,
        WAIT,
        ACCEPT,
        CHECK,
        COOK
    };
    int cash = 0;
    const char* menu[3] = { "Кофе","Чай","Горячий шоколад" };
    int prices[3] = { 20, 10, 30 };
    State state = OFF;
    bool check(int nom);
    void cook();
    void finish();
public:
    void on();
    void off();
    void coin(int Money);
    const char** etMenu();
    State getState() { return state; };
    void choice(int nom);
    void cancel();
};
