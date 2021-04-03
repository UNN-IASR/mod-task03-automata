#include <string>
#include <unordered_map>
#include <fstream>

enum STATES {
    OFF,
    WAIT,
    ACCEPT,
    CHECK,
    COOK,
    DEAD
};
 
class automata {

public:
    automata(const std::string& file);
    automata();
    std::string on();
    std::string off();
    std::string coin(int amount);
    void etMenu();
    std::string choice(const std::string& drink);
    std::string check();
    std::string cancel();
    std::string finish(); 
    STATES get_state();

private:
    int _cash;
    std::unordered_map<std::string, int> _menu;
    STATES _state;
    std::string _error;
    std::string _drink;
};