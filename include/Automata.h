#include <string>

using namespace std;

enum Status
{
	on,
	off,
	Wait,
	cook,
	control, //CHEK
	accept
};

class Automata
{
private:
	int money;
	int* price;
	string* menu;
	Status NowStatus;
	bool proof(int checkup);
	void cook();

public:
	Automata();
	~Automata();
	const string* etMenu();
	Status getStatus();
	void on();
	void cash(int inMoney);
	void check(int checkup);
	void off();
	int cancel();
	int finish();
};