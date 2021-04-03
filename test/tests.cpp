#include <gtest/gtest.h>
#include "Automata.h"

// остальные кейсы я рассмотрел в main

TEST(task, test1)
{
	Automata hot_drinks_machine = Automata();
	hot_drinks_machine.on();
	hot_drinks_machine.coin(100);
	int result = hot_drinks_machine.choice(4);
	EXPECT_EQ(0, result);
}
