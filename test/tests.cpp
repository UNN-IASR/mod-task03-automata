#include <gtest/gtest.h>
#include "Automata.h"

TEST(task1, test1) {
    Automata A = Automata();
    int result = A.getState();
    EXPECT_EQ(0, result);
}

TEST(task2, test2) {
    Automata A = Automata();
    A.on();
    int result = A.getState();
    EXPECT_EQ(1, result);
}

TEST(task3, test3) {
    Automata A = Automata();
    A.on();
    A.coin(100);
    int result = A.getState();
    EXPECT_EQ(2, result);
}