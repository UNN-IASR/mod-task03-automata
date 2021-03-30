#include <gtest/gtest.h>
#include "Automata.h"
TEST(task1, test1) {
    Automata a = Automata();
    a.on();
    a.coin(100);
    int result = a.getState();
    EXPECT_EQ(2, result);
}

TEST(task1, test2) {
    Automata a = Automata();
    a.on();
    a.coin(100);
    a.choice(5);
    int result = a.getState();
    EXPECT_EQ(2, result);
}

TEST(task2, test3) {
    Automata a = Automata();
    a.on();
    a.coin(100);
    a.choice(2);
    int result = a.getState();
    EXPECT_EQ(2, result);
}

TEST(task2, test4) {
    Automata a = Automata();
    a.on();
    a.coin(100);
    a.choice(2);
    a.coin(20);
    a.choice(2);
    int result = a.getState();
    EXPECT_EQ(4, result);
}

TEST(task3, test5) {
    a.on();
    a.coin(100);
    a.choice(2);
    a.coin(20);
    a.choice(2);
    int result = a.getState();
    a.finish();
    EXPECT_EQ(1, result);
}

TEST(task3, test6) {
    Automata a = Automata();
    a.on();
    a.coin(150);
    a.choice(0);
    a.finish();
    int result=a.cancel();
    EXPECT_EQ(70, result);
}
TEST(task3, test7) {
    Automata a = Automata();
    a.choice(5);
    a.choice(0);
    a.coin(150);
    int result = a.choice(1);
    EXPECT_EQ(0, result);
}
