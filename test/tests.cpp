#include <gtest/gtest.h>
#include "Automata.h"

TEST(task1, test1) {
	std::string s1 = "c10m0";
	Automata a1(s1);
	bool result = a1.result();
	EXPECT_EQ(true, result);
}

TEST(task2, test2) {
	std::string s2 = "c10m";
	Automata a2(s2);
	bool result = a2.result();
	EXPECT_EQ(false, result);
}

TEST(task3, test3) {
	std::string s3 = "c10";
	Automata a3(s3);
	bool result = a3.result();
	EXPECT_EQ(false, result);
}

TEST(task4, test4) {
	std::string s4 = "m0";
	Automata a4(s4);
	bool result = a4.result();
	EXPECT_EQ(false, result);
}

TEST(task5, test5) {
	std::string s5 = "cm0";
	Automata a5(s5);
	bool result = a5.result();
	EXPECT_EQ(false, result);
}

TEST(task6, test6) {
	std::string s6 = "c10m0m0";
	Automata a6(s6);
	bool result = a6.result();
	EXPECT_EQ(true, result);
}
TEST(task7, test7) {
	std::string s7 = "c5m0c10m1";
	Automata a7(s7);
	bool result = a7.result();
	EXPECT_EQ(false, result);
}
TEST(task8, test8) {
	std::string s8 = "c5c10m1";
	Automata a8(s8);
	bool result = a8.result();
	EXPECT_EQ(true, result);
}