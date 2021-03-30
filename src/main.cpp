#include "Automata.h"
#include <iostream>

using namespace std;
int main()
{

    Automata a = Automata();
    a.on();
    cout << a.getState() << endl;

    a.coin(100);
    cout << a.getState() << endl;

    a.choice(5);
    cout << a.getState() << endl;

    a.choice(2);
    cout << a.getState() << endl;

    a.coin(20);
    cout << a.getState() << endl;

    a.choice(2);
    cout << a.getState() << endl;

    cout << a.finish() << endl;
    cout << a.getState() << endl;


    a.coin(150);
    cout << a.getState() << endl;

    a.choice(0);
    cout << a.getState() << endl;

    cout << a.finish() << endl;
    cout << a.getState() << endl;

    cout << a.cancel() << endl;
    cout << a.getState() << endl;

    a.off();
    cout << a.getState() << endl;
}