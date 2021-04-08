#include <gtest/gtest.h>
#include "Automata.h"

std::vector<std::pair<std::string, unsigned int>> products(){
    std::vector<std::pair<std::string, unsigned int>> products{ {"Tea",10},{"Cofe", 20},{"Milk",15} };
    return products;
}

TEST(Automata, on){
    Automata automata = Automata(products());
    automata.on();
    EXPECT_EQ(automata.getState(), State::WAIT);
}
TEST(Automata, off) {
    Automata automata = Automata(products());
    automata.on();
    automata.off();
    EXPECT_EQ(automata.getState(), State::OFF);
}
TEST(Automata, coin) {
    Automata automata = Automata(products());
    automata.on();
    automata.coin(10);
    EXPECT_EQ(automata.getState(), State::ACCEPT);
}
TEST(Automata, cancel) {
    Automata automata = Automata(products());
    automata.on();
    automata.coin(10);
    automata.cancel();
    EXPECT_EQ(automata.getState(), State::WAIT);
}
TEST(Automata, checkTrue) {
    Automata automata = Automata(products());
    automata.on();
    automata.coin(10);
    automata.choice(0);
    EXPECT_EQ(automata.getState(), State::COOK);
}
TEST(Automata, checkFail) {
    Automata automata = Automata(products());
    automata.on();
    automata.coin(5);
    automata.choice(0);
    EXPECT_EQ(automata.getState(), State::CHECK);
}
TEST(Automata, finish) {
    Automata automata = Automata(products());
    automata.on();
    automata.coin(10);
    automata.choice(0);
    automata.finish();
    EXPECT_EQ(automata.getState(), State::WAIT);
}
TEST(Automata, oddMoneyFinish) {
    Automata automata = Automata(products());
    automata.on();
    automata.coin(15);
    automata.choice(0);
    int money = automata.finish();
    EXPECT_EQ(money, 5);
}
TEST(Automata, oddMoneyAccept) {
    Automata automata = Automata(products());
    automata.on();
    automata.coin(15);
    int money = automata.cancel();
    EXPECT_EQ(money, 15);
}
TEST(Automata, oddMoney) {
    Automata automata = Automata(products());
    automata.on();
    automata.coin(15);
    automata.choice(1);
    int money = automata.cancel();
    EXPECT_EQ(money, 15);
}