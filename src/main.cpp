#include "Automata.h"

int main()
{
    Automata aut = Automata();
    int change = 0;
    aut.on();
    aut.coin(70);
    aut.choice(1);
    change = aut.cancel();
    aut.coin(100);
    aut.choice(2);
    aut.coin(180);
    aut.choice(2);
    change = aut.cancel();
    aut.off();
}
