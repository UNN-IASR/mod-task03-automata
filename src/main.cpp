#include "Automata.h"

int main(int argv, char** argc)
{
    std::vector<std::pair<std::string, unsigned int>> products{ {"Tea",10},{"Cofe", 20},{"Milk",15} };
    Automata automata = Automata(products);
    automata.on();
    automata.coin(10);
    automata.choice(2);
    automata.coin(5);
    automata.choice(3);
    int oddMoney = automata.finish();
}