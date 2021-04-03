#include "Automata.h"

int main()
{
    Automata a = Automata();
    a.on();
    a.coin(100);
    int result = a.getState();
}
