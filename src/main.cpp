
#include <iostream>
#include "Automata.h"

int OrderEspresso(int nCash, Automata* CoffeeMachine)
{
    CoffeeMachine->Coin(nCash);
    CoffeeMachine->Choice(ESPRESSO);
    if (CoffeeMachine->GetState() == eACCEPT)
    {
        CoffeeMachine->Choice(BLACK_TEA);
    }
    nCash = CoffeeMachine->Cook();

    return nCash;
}


int main()
{
    Automata* CoffeeMachine = new Automata();
    int nCash = 15;

    CoffeeMachine->On();
    CoffeeMachine->GetMenu();
    if (CoffeeMachine != NULL)
    {
        nCash = OrderEspresso(nCash, CoffeeMachine);
    }
    
    CoffeeMachine->Off();

    std::cin.get();
}
