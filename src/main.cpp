#include "Automata.h"
#include <iostream>

int main() {
    automata coffe("../../coffe.txt");
    std::cout << coffe.on();
    coffe.etMenu();
    std::cout << coffe.coin(70);
    std::cout << coffe.choice("milk chocolate");
    std::cout << coffe.check();
    std::cout << coffe.coin(100);
    std::cout << coffe.choice("milk chocolate");
    std::cout << coffe.check();
    std::cout << coffe.finish();
    std::cout << coffe.off();
    std::cout << coffe.coin(10);
    std::cout << coffe.on();
    std::cout << coffe.choice("milk chocolate");
    std::cout << coffe.choice("milk chocolate");
}