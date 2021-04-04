#include <vector>
#include <string>

enum States {
	OFF,
	WAIT,
	ACCEPT,
	CHECK,
	COOK
};

class Automata {
	private:
		int cash;
		std::vector<std::string> menu{"Americano","Cappuccino","Latte","Espresso"};
		std::vector<int> prices {80,100,120,90};
		States state;
		bool check(int choice);
		void cook();
	public:
		Automata();
		void on();
		void off();
		void coin(int numb);
		std::vector<std::string> etMenu();
		States getState();
		void choice(int choice);
		int cancel();
		int finish();
		~Automata();
};