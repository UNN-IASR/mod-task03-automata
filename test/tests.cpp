#include <gtest/gtest.h>
#include "Automata.h"

TEST(task1, test1) {
    Automata CoffeMachine = Automata();
    int result = CoffeMachine.getState();
    EXPECT_EQ(0, result);
}

TEST(task2, test2) {
    Automata CoffeMachine = Automata();
    CoffeMachine.on();
    int result = CoffeMachine.getState();
    EXPECT_EQ(1, result);
}

TEST(task3, test3) {
    Automata CoffeMachine = Automata();
    CoffeMachine.on();
    CoffeMachine.coin(100);
    int result = CoffeMachine.getState();
    EXPECT_EQ(2, result);
}