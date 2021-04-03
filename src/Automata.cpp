#include "Automata.h"
#include <iostream>

automata::automata(const std::string& file) : _state(OFF), _cash(0) {
    std::ifstream f(file);
    if (!f.is_open()) {
        _state = DEAD;
        _error = "can't open file with menu:(";
        return;
    }
    std::string line;
    while (std::getline(f, line)) {
        std::string cost;
        std::getline(f, cost);
        _menu[line] = std::stoi(cost);
    }
}

automata::automata() : _state(OFF), _cash(0), 
    _menu ({
        {"latte", 112},
        {"coffe", 80},
        {"chocolate", 90},
        {"milk chocolate", 110},
        {"hot milk", 70}
    })
{}

std::string automata::on() {
    switch (_state)
    {
    case OFF:
        _state = WAIT;
        return "Automata9000 is on...\n";
        break;
    case DEAD:
        return "Automat9000 is br..\nbroken...\n"+_error+"\n";
        break;
    default:
        return "Automata9000 alrady on...\n";
        break;
    }
}

std::string automata::off() {
    switch (_state)
    {
    case WAIT:
    case ACCEPT:
    case CHECK:
        _state = OFF;
        return "Automata9000 is offzzzzzzzzz...\n";
        break;
    case OFF:
        return "zzzzzz\n";
        break; 
    case DEAD:
        return "Automat9000 is br..\nbroken...\n"+_error+"\n";
    default:
        _state=DEAD;
        _error = "Automata9000 was turned off before finishing task\n";
        return "Automat9000 is br..\nbroken...\n"+_error+"\n";
        break;
    }
}

std::string automata::coin(int amount) {
    switch (_state)
    {
    case ACCEPT:
    case CHECK:
    case WAIT:
        _state = ACCEPT;
        _cash += amount;
        return "Automata9000 has "+std::to_string(_cash)+" grubs\n";
        break;
    case OFF:
        return "zzzzzz\n";
        break;
    case DEAD:
        return "Automat9000 is br..\nbroken...\n"+_error+"\n"; 
    default:
        _state=DEAD;
        _error = "Automata9000 can't take in coins now\n";
        return "Automat9000 is br..\nbroken...\n"+_error+"\n";
        break;
    }
}

void automata::etMenu() {
    std::cout << "\n____________MENU____________\n";
    for(auto& elm : _menu) {
        std::cout << "\t" << elm.first << ".......\t"<<elm.second<<" grubs\n";
    }
}

std::string automata::choice(const std::string& drink) {
    switch (_state)
    {
    case WAIT:
    case ACCEPT:
        if(_menu.find(drink) != _menu.end()) {
            _state=CHECK;
            _drink = drink;
            return "Automat9000 needs to check cash ...\n";
        } else {
            return "There is no sach drink...\n";
        }
        break;
    case DEAD:
        return "Automat9000 is br..\nbroken...\n"+_error+"\n";
    default:
        _state=DEAD;
        _error = "Automat9000 can't take orders from states other then ACCEPT or WAIT\n";
        return "Automat9000 is br..\nbroken...\n"+_error+"\n";
        break;
    }
}

std::string automata::check() {
    switch (_state)
    {
    case CHECK:
        if (_menu[_drink] <= _cash){
            _state = COOK;
            return "Automata9000 has started cooking "+_drink+" ...\n";
        } else {
            _state = WAIT;
            return "There is not enough cash...\n";
        }
        break;
    case DEAD:
        return "Automat9000 is br..\nbroken...\n"+_error+"\n";
    default:
        return "There is nothing to check...\n";
        break;
    }

}

std::string automata::cancel() {
    int cash = _cash;
    switch (_state)
    {
    case WAIT:
    case CHECK:
    case ACCEPT:
        _cash = 0;
        _state = WAIT;
        return "Please take your "+std::to_string(cash)+ " grubs..\n";
        break;
    case OFF:
        return "zzzzzz\n";
        break;
    case DEAD:
        return "Automat9000 is br..\nbroken...\n"+_error+"\n"; 
    default:
        _state=DEAD;
        _error = "Cannot stop while cooking\n";
        return "Automat9000 is br..\nbroken...\n"+_error+"\n"; 
        break;
    }
}

std::string automata::finish() {
    switch (_state)
    {
    case COOK:
        _cash -= _menu[_drink];
        _state = WAIT;
        return "Please take yor " + _drink+ " you have "+std::to_string(_cash)+" left....\n";
        break;
    case OFF:
        return "zzzzzz\n";
        break;
    case DEAD:
        return "Automat9000 is br..\nbroken...\n"+_error+"\n"; 
    default:
        return "You cannot finish whithout cooking, cancel if you want...\n";
        break;
    }
}

STATES automata::get_state() {
    return _state;
}