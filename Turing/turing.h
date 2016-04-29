/*
–аспознает только алфавит A={0, 1, E, *}
	P - пустой символ 
	* - раздел€ющий символ
—двиги задаютс€ L, R и E
	L - влево
	R - вправо
	E - рассмотреть данную €чейку
*/


#ifndef TURING_H                   
#define TURING_H
#include <vector>
#include <string>
class Turing
{
	// таблица переходов
	std::vector<std::vector <std::string>> table;
	//множество сост€ний
	std::vector <std::vector <int>> state;
	// значени€ дл€ ленты
	std::vector <std::vector <int>> values;
	// сдвиги
	std::vector <std::vector <char>> move_tape;
	//лента
	std::vector <int> tape;
public:
	Turing();					
	Turing(std::vector <int> &);
	void output();				
	void matrix();              
	void function();            
	std::vector<int> get_tape();
	void shift();
};

#endif