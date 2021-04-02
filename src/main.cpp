#include "Automata.h"

int main(int argv, char** argc)
{
    std::vector<std::string> product_names{"Late","Cappuccino","Expresso","Snikers"};
    std::vector<unsigned long> product_prices{80,60,35,30};
    std::vector<std::pair<std::string,unsigned long>> products;
    for(int i=0;i<product_names.size();i++){
        products.push_back(std::pair<std::string,int>(product_names[i],product_prices[i]));
    }
    Automata machine(products);
    machine.on();
    machine.coin(30);
    machine.choice(2);
    machine.coin(35);
    machine.choice(2);
    int money=machine.finish();
}