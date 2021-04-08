#include "Automata.h"

Automata::Automata(const std::vector<std::pair<std::string, unsigned int>>& products) {
    state = State::OFF;
    cash = 0;
    this->products = products;
}
void Automata::on() {
    if (state == State::OFF)
        state = State::WAIT;
}
void Automata::off() {
    if (state == State::WAIT)
        state = State::OFF;
}
void Automata::coin(unsigned int count) {
    if (state == State::WAIT || state == State::ACCEPT) {
        state = State::ACCEPT;
        cash += count;
    }
}
std::vector<std::pair<std::string, unsigned int>> Automata::getMenu() {
    return products;
}
State Automata::getState() {
    return state;
}
bool Automata::choice(unsigned int index) {
    if (state != State::ACCEPT || products.size() < index) {
        return false;
    }
    state = State::CHECK;
    if (check(index)) {
        cash -= products[index].second;
        cook();
        return true;
    }
    return false;
}
bool Automata::check(unsigned int index) {
    if (cash >= products[index].second)
        return true;
    else
        return false;
}
unsigned int Automata::cancel() {
    if (state == State::ACCEPT || state == State::CHECK) {
        state = State::WAIT;
        unsigned int oddMoney = cash;
        cash = 0;
        return oddMoney;
    }
    return 0;
}
void Automata::cook() {
    state = State::COOK;
}
unsigned int Automata::finish() {
    if (state == State::COOK) {
        state = State::WAIT;
        unsigned int oddMoney = cash;
        cash = 0;
        return oddMoney;
    }
    return 0;
}
