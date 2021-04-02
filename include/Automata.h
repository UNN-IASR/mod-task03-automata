#pragma once
#include <string>
#include <vector>

using namespace std;

enum class states { off, wait, accept, check, cook };
class Automata
{
public:
	Automata(const std::vector<std::string> menu_list, const std::vector<int> prices_list);
	void on();
	void off();
	void coin(int m);
	vector<string> get_menu();
	vector<int> get_ceny();
	int otmena();
	bool vibor(int pos);
	int finish();
	states get_state();
private:
	states state{ states::off };
	int money = 0;
	vector<string> menu;
	vector<int> ceny;
	void cook();
};
