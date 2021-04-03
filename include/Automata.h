#include <string>
using namespace std;
class Automata {

private:
	enum State
	{
		OFF,
		WAIT,
		ACCEPT,
		CHECK,
		COOK
	};
	int cash;
	int ch;
	string menu[4] = { "Latte" ,"Cappuccino","Espresso","Americano" };
	int prices[4] = { 80,100,120,140 };
	State state;
	void cook();
	void check();

public:
	Automata();
	void on();
	void off();
	int coin(int cash);
	string* etMenu();
	State getState();
	void choice(int ch);
	int cancel();
	string finish();
};
