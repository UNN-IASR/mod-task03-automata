#include <gtest/gtest.h>
#include "Automata.h"

std::vector<std::pair<std::string,unsigned long>> generate_menu()
{
    std::vector<std::string> product_names{"Late","Cappuccino","Expresso","Snikers"};
    std::vector<unsigned long> product_prices{80,60,35,30};
    std::vector<std::pair<std::string,unsigned long>> products;
    for(int i=0;i<product_names.size();i++){
        products.push_back(std::pair<std::string,int>(product_names[i],product_prices[i]));
    }
    return products;
}
TEST(Automata,on)
{
    Automata machine(generate_menu());
    machine.on();
    EXPECT_EQ(machine.get_state(),STATES::WAIT);
}
TEST(Automata,off)
{
    Automata machine(generate_menu());
    machine.on();
    machine.off();
    EXPECT_EQ(machine.get_state(),STATES::OFF);
}
TEST(Automata,coin)
{
    Automata machine(generate_menu());
    machine.on();
    machine.coin(10);
    EXPECT_EQ(machine.balance(),10);
    EXPECT_EQ(machine.get_state(),STATES::ACCEPT);
}
TEST(Automata,cancel)
{
    Automata machine(generate_menu());
    machine.on();
    machine.coin(10);
    EXPECT_EQ(machine.cancel(),10);
    EXPECT_EQ(machine.get_state(),STATES::WAIT);
}
TEST(Automata,cook)
{
    Automata machine(generate_menu());
    machine.on();
    machine.coin(35);
    machine.choice(2);
    EXPECT_EQ(machine.get_state(),STATES::COOK);
}
TEST(Automata,fail_check)
{
    Automata machine(generate_menu());
    machine.on();
    machine.coin(35);
    machine.choice(0);
    EXPECT_EQ(machine.get_state(),STATES::ACCEPT);
}
TEST(Automata,finish)
{
    Automata machine(generate_menu());
    machine.on();
    machine.coin(35);
    machine.choice(2);
    EXPECT_EQ(machine.finish(),0);
    EXPECT_EQ(machine.get_state(),STATES::WAIT);
}