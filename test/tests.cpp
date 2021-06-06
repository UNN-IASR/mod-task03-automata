#include <gtest/gtest.h>
#include "../include/Automata.h"

TEST(task, test1)
{
    Automata cofeem = Automata();
    cofeem.on();
    cofeem.cash(0);
    cofeem.check(1);
    Status result = cofeem.getStatus();
    EXPECT_EQ(Status::Wait, result);
}
TEST(task, test2)
{
    Automata cofeem = Automata();
    cofeem.on();
    cofeem.check(1);
    Status result = cofeem.getStatus();
    EXPECT_EQ(Status::Wait, result);
}

TEST(task, test3)
{
    Automata cofeem = Automata();
    Status result = cofeem.getStatus();
    EXPECT_EQ(Status::off, result);
}
TEST(task, test4)
{
    Automata cofeem = Automata();
    cofeem.on();
    cofeem.cash(55);
    cofeem.check(1);
    Status result = cofeem.getStatus();
    EXPECT_EQ(Status::cook, result);
}