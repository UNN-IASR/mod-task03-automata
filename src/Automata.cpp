#include "Automata.h"
Automata::Automata(const std::vector<std::pair<std::string,unsigned long>>& menu_list) : menu(menu_list){}
void Automata::on(){
    if(state==STATES::OFF)
        state=STATES::WAIT;
}
void Automata::off(){
    if(state==STATES::WAIT)
        state=STATES::OFF;
}
void Automata::coin(unsigned long count){
    if(state==STATES::WAIT || state==STATES::ACCEPT){
        state=STATES::ACCEPT;
        cash+=count;
    }
}
std::vector<std::pair<std::string,unsigned long>> Automata::get_menu(){
    return menu;
}
STATES Automata::get_state(){
    return state;
}
bool Automata::choice(unsigned int position){
    if(state==STATES::ACCEPT){
        state=STATES::CHECK;
        if(cash>=menu[position].second){
            cash-=menu[position].second;
            cook();
            return true;
        }else{
            state=STATES::ACCEPT;
            return false;
        }
    }
}
unsigned long Automata::cancel(){
    if(state==STATES::ACCEPT){
        state=STATES::WAIT;
        unsigned long money=cash;
        cash=0;
        return money;
    }
    return 0;
}
unsigned long Automata::finish(){
    if(state==STATES::COOK){
        state=STATES::WAIT;
        unsigned long money=cash;
        cash=0;
        return money;
    }
    return 0;
}
unsigned long Automata::balance(){
    return cash;
}
void Automata::cook(){
    state=STATES::COOK;
}