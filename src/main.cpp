#include <iostream>
#include "Automata.h"

using namespace std;

int main()
{
    Automata machine = Automata();

    machine.on();
    machine.etMenu();
    machine.coin(118);
    machine.choice(1);
    machine.finish();
    machine.coin(108);
    machine.coin(118);
    machine.choice(3);
    machine.finish();
    machine.off();

    return 0;
}
