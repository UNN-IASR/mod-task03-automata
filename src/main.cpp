#include <string>
#include "Automata.h"

int main()
{
	std::string s1 = "c10m0";
	Automata a1(s1);
	bool result = a1.result();
}
