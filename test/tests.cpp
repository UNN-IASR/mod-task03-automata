

#include <gtest/gtest.h>
#include "Automata.h"

TEST(task1, test1) {
	Automata CoffeeMachine;
	CoffeeMachine.Coin(25);
	bool bEnoughCash = CoffeeMachine.Choice(ESPRESSO);
	EXPECT_EQ(true, bEnoughCash);
}

TEST(task1, test2) {
	Automata CoffeeMachine;
	CoffeeMachine.Coin(5);
	bool bEnoughCash = CoffeeMachine.Choice(ESPRESSO);
	EXPECT_EQ(false, bEnoughCash);
}

TEST(task2, test3) {
	Automata CoffeeMachine;
	CoffeeMachine.Coin(20);
	CoffeeMachine.Choice(BLACK_TEA);
	int cash = CoffeeMachine.Cook();
	EXPECT_EQ(9, cash);
}

TEST(task2, test4) {
	Automata CoffeeMachine;
	CoffeeMachine.Coin(2);
	CoffeeMachine.Choice(ESPRESSO);
	etState eState = CoffeeMachine.GetState();
	EXPECT_EQ(eACCEPT, eState);
}

TEST(task2, test5) {
	Automata CoffeeMachine;
	CoffeeMachine.Coin(20);
	CoffeeMachine.Choice(BLACK_TEA);
	CoffeeMachine.Cook();
	etState eState = CoffeeMachine.GetState();
	EXPECT_EQ(eWAIT, eState);
}