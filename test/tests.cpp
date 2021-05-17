#include <gtest/gtest.h>
#include "Automat.h"

TEST(Coffe_tests, Nice_coffe) {
    automat coffe;
    std::cout << coffe.on();
    EXPECT_EQ(WAIT, coffe.get_state());
    EXPECT_EQ("Automat has 120 grubs\n",coffe.coin(120));
    std::cout << "Automat has 120 grubs\n";
    EXPECT_EQ(ACCEPT, coffe.get_state());
    std::cout << coffe.choice("milk chocolate");
    EXPECT_EQ(CHECK, coffe.get_state());
    std::cout << coffe.check();
    EXPECT_EQ(COOK, coffe.get_state());
    std::cout << coffe.finish();
    EXPECT_EQ(WAIT, coffe.get_state());
    std::cout << coffe.off();
    EXPECT_EQ(OFF, coffe.get_state());
}

TEST(Coffe_tests, Not_nice_coffe) {
    automat coffe;
    std::cout << coffe.check();
    EXPECT_EQ(OFF, coffe.get_state());
    std::cout << coffe.cancel();
    EXPECT_EQ(OFF, coffe.get_state());
    std::cout << coffe.on();
    std::cout << coffe.coin(120);
    EXPECT_EQ("Please take your 120 grubs..\n", coffe.cancel());
    std::cout << "Please take your 120 grubs..\n";
    std::cout << coffe.choice("milk chocolate");
    std::cout << coffe.choice("milk chocolate");
    EXPECT_EQ(DEAD, coffe.get_state());
}

TEST(Coffe_tests, Bad_coffe) {
    automat coffe("coffee.txt");
    EXPECT_EQ(DEAD, coffe.get_state());
    coffe = automat();
    std::cout << coffe.on();
    std::cout << coffe.coin(120);
    std::cout << coffe.choice("milk chocolate");
    std::cout << coffe.check();
    std::cout << coffe.cancel();
    EXPECT_EQ(DEAD, coffe.get_state());
    coffe = automat();
    std::cout << coffe.on();
    std::cout << coffe.coin(120);
    std::cout << coffe.choice("milk chocolate");
    std::cout << coffe.check();
    std::cout << coffe.coin(120);
    EXPECT_EQ(DEAD, coffe.get_state());
}