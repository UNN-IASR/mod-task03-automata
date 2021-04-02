#include <string>
#include <vector>

    enum class STATES{OFF,WAIT,ACCEPT,CHECK,COOK};

class Automata{
public:
    Automata(const std::vector<std::pair<std::string,unsigned long>>& menu_list);
    void on();
    void off();
    void coin(unsigned long count);
    std::vector<std::pair<std::string,unsigned long>> get_menu();
    STATES get_state();
    bool choice(unsigned int position); // How to get state CHECK with method getState, if this state is CHECK only when choice() is running?
    unsigned long cancel(); // see next comment
    unsigned long finish(); // method finish seems similar to cancel. Do we need its both?
    unsigned long balance();
private:
    void cook(); // We can't simulate COOK state with only method cook. I mean we will never get state COOK. We can get it only in parallel
    STATES state{STATES::OFF};
    unsigned long cash=0;
    std::vector<std::pair<std::string,unsigned long>> menu;
};