#include "Automata.h"
int main()
{
    Automata aut = Automata();
    int change = 0;
    //start
    aut.on();
    //ferst person
    aut.coin(150);
    aut.choice(1);
    change = aut.cancel();
    //second person
    aut.coin(150);
    aut.choice(1);
    aut.coin(150);
    aut.choice(2);
    change = aut.cancel();
    //end
    aut.off();
}