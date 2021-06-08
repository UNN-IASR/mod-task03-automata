// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>

#include "Automata.h"
TEST(task1, test1) {
  Automata aut = Automata();
  aut.cancel();
  int result = aut.getState();
  EXPECT_EQ(0,result);
}

TEST(task1, test2) {
  Automata aut = Automata();
  aut.on();
  aut.coin(0);
  int result = aut.getState();
  EXPECT_EQ(2,result);
}

TEST(task2, test3) {
  Automata aut = Automata();
  aut.on();
  aut.cancel();
  int result = aut.getState();
  EXPECT_EQ(1,result);
}
TEST(task2, test4) {
  Automata aut = Automata();
  aut.on();
  aut.coin(20);
  int result = aut.choice(10);
  EXPECT_EQ(20,result);
}

TEST(task3, test5) {
  Automata aut = Automata();
  aut.on();
  aut.coin(300);
  int result = aut.choice(2);
  EXPECT_EQ(0,result);
}

TEST(task3, test6) {
  Automata aut = Automata();
  aut.on();
  aut.coin(300);
  aut.choice(2);
  int result = aut.cancel();
  EXPECT_EQ(100,result);
}
TEST(task3, test7) {
  Automata aut = Automata();
  aut.on();
  aut.coin(20);
  int result = aut.choice(1);
  EXPECT_EQ(20,result);
}
}
