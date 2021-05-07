#include <gtest/gtest.h>
#include "Automata.h"

include <gtest/gtest.h>
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
    a.choice(2);
    int result = a.getState();
    EXPECT_EQ(2, result);
}
