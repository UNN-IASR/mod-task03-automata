using namespace std;
class Automata
{
private:
    enum State
    {
        OFF,
        WAIT,
        ACCEPT,
        CHECK,
        COOK
    };
    int cash = 0;
    const char* menu[3] = { "Black coffee","Cappuccino","Caffe latte" };
    int prices[3] = { 100, 200, 300 };
    State st = OFF;
    bool check(int val);
    void cook(int val);
    void finish(int val);

public:
    void on();
    State getState() { return st; };
    int off();
    void coin(int money);
    int choice(int val);
    const char** etMenu();
    int cancel();
};
