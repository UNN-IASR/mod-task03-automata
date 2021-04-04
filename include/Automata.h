#include <string>

using namespace std;
enum States
{
	OFF,
	WAIT,
	ACCEPT,
	CHECK,
	COOK
};

class Automata
{
private:
	int cash;
	string* menu;
	int* prices;
	States currstate;
	bool check(int _choice);
	void cook();

public:
	Automata();
	void on();
	void off();
	void coin(int money);
	void choice(int _choice);
	const string* etMenu();
	States getState();
	int cancel();
	int finish();
	~Automata();
}; 