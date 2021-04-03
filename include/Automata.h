#include <string>
using namespace std;
class Automata
{
	private:
	
	enum State 
	{OFF, WAIT, ACCEPT, CHECK, COOK};
	
	
	public:
	
	int cash = 0; //для хранения текущей суммы
	string menu[2] = { "1" ,"2"}; //массив строк названий напитков
	int prices[2] = {100,200}; // массив цен напитков
	State state = OFF; //текущее состояние автомата
	int choice_p;
	
	void on(); //включение автомата;
	void off();//выключение автомата;
	void coin(int m); //занесение денег на счёт пользователем
	string* etMenu(); // считывание меню с напитками и ценами для пользователя;
	State getState(){return state;};//считывание текущего состояния для пользователя;
    void choice(int ch);//выбор напитка пользователем;
    void check();//проверка наличия необходимой суммы;
    int cancel();//отмена сеанса обслуживания пользователем;
    void cook();//имитация процесса приготовления напитка;
    void finish(int f);//завершение обслуживания пользователя.
	
};
