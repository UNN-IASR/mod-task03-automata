#include "Automata.h"


int main()
{
    Automata AVT = Automata();
    AVT.on();
    AVT.coin(10);
    AVT.choice(1);
    AVT.coin(50);
    AVT.cancel();
    AVT.coin(20);
    AVT.choice(2);
    AVT.coin(10);
    AVT.coin(20);
    AVT.choice(3);
    AVT.off();
    return 0;
}
