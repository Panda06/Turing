/*
���������� ������ ������� A={0, 1, E, *}
	P - ������ ������ 
	* - ����������� ������
������ �������� L, R � E
	L - �����
	R - ������
	E - ����������� ������ ������
*/


#ifndef TURING_H                   
#define TURING_H
#include <vector>
#include <string>
class Turing
{
	// ������� ���������
	std::vector<std::vector <std::string>> table;
	//��������� ��������
	std::vector <std::vector <int>> state;
	// �������� ��� �����
	std::vector <std::vector <int>> values;
	// ������
	std::vector <std::vector <char>> move_tape;
	//�����
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