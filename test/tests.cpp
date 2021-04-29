#include <gtest/gtest.h>
#include "Automata.h"

TEST(task1, test1) 
{
  Automata A;
  A.cancel();
  int result = A.getState();
  EXPECT_EQ(0, result);
}

TEST(task1, test2) 
{
  Automata A;
  A.on();
  A.coin(0);
  int result = A.getState();
  EXPECT_EQ(2, result);
}

TEST(task2, test3) 
{
  Automata A;
  A.on();
  A.cancel();
  int result = A.getState();
  EXPECT_EQ(1, result);
}

TEST(task2, test4) 
{
  Automata A;
  A.on();
  A.coin(100);
  int result = A.choice(-1);
  EXPECT_EQ(0, result);
}

TEST(task3, test5) 
{
  Automata A;
  A.on();
  A.coin(100);
  int result = A.choice(2);
  EXPECT_EQ(0, result);
}

TEST(task3, test6) 
{
  Automata A;
	A.on();
	A.coin(100);
	int result = A.cancel();
  EXPECT_EQ(100, result);
}

TEST(task3, test7) 
{
  Automata A;
  A.on();
  A.coin(100);
  int result = A.choice(1);
  EXPECT_EQ(30, result);
}
