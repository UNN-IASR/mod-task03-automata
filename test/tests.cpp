#include <gtest/gtest.h>
#include "Automata.h"
TEST(task, test1)
{
    Automata coffee = Automata();
    coffee.on();
    coffee.coin(20);
    coffee.choise(1);
    States result = coffee.getState();
    EXPECT_EQ(WAIT, result);
}

TEST(task, test2)
{
    Automata coffee = Automata();
    coffee.on();
    coffee.choise(1);
    States result = coffee.getState();
    EXPECT_EQ(WAIT, result);
}

TEST(task, test3)
{
    Automata coffee = Automata();
    coffee.on();
    coffee.coin(120);
    coffee.choice(1);
    int result = coffee.getState();
    EXPECT_EQ(1, result);
}
