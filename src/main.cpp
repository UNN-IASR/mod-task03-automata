#include "Automata.h"

int main()
{
    Automata aut = Automata();
    int change = 0;
    aut.on();
    aut.coin(80);
    aut.choice(1);
    change = aut.cancel();
    aut.coin(100);
    aut.choice(2);
    aut.coin(120);
    aut.choice(3);
    change = aut.cancel();
    aut.off();
}
