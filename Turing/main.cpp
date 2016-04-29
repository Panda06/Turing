#include "turing.h"
#include <clocale>
int main()
{
	setlocale(LC_ALL, "Rus");
	Turing t;
	t.function();
	t.output();
	return 0;
}