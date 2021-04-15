#include <gtest/gtest.h>
#include "Automata.h"

TEST(task, test1)
{
    Automata coffee = Automata();
    coffee.on();
    coffee.coin(20);
    coffee.choice(1);
    int result = coffee.getState();
    EXPECT_EQ(1, result);
}

TEST(task, test2)
{
    Automata coffee= Automata();
    coffee.on();
    coffee.off();
    int result = coffee.getState();
    EXPECT_EQ(0, result);
}

TEST(task, test3)
{
    Automata coffee = Automata();
    coffee.on();
    coffee.coin(20);
    coffee.coin(10);
    int result = coffee.getState();
    EXPECT_EQ(2, result);
}
