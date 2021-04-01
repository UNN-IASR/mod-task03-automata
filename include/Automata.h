#include <string>

enum STATES
{
	OFF,
	WAIT,
	ACCEPT,
	CHECK,
	COOK
};

class Automata
{
	static const unsigned int menuSize = 3;
	unsigned int cash;
	std::string menu[menuSize];
	unsigned int prices[menuSize];
	STATES state;
	bool cooked;

	void on();
	void off();
	void coin(unsigned int money);
	const std::string* etMenu();
	STATES getState();
	void choise(unsigned int num);
	void check(unsigned int num);
	void cancel();
	void cook();
	void finish();



public:
	Automata(const std::string& input);

	bool result();
};