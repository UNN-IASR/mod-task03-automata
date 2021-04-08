#pragma once
#include <string>
#include <vector>

enum class State {
	OFF,
	WAIT,
	ACCEPT,
	CHECK,
	COOK
};

class Automata {
public:
	Automata(const std::vector<std::pair<std::string, unsigned int>>& products);
	void on(); 
	void off(); 
	void coin(unsigned int); 
	std::vector<std::pair<std::string, unsigned int>> getMenu(); 
	State getState(); 
	bool choice(unsigned int);
	bool check(unsigned int);
	unsigned int cancel();
	void cook(); 
	unsigned int finish(); 
private:
	State state;
	std::vector<std::pair<std::string, unsigned int>> products;
	unsigned int cash;
};