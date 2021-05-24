#include "Automata.h"


int main()
{
    Automata AVT = Automata();
    AVT.on();
    AVT.coin(20);
    AVT.choice(1);
    AVT.coin(60);
    AVT.cancel();
    AVT.coin(10);
    AVT.choice(2);
    AVT.coin(15);
    AVT.coin(25);
    AVT.choice(3);
    AVT.off();
    return 0;
}
