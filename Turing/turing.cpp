#include "turing.h"
#include <fstream>
#include <iostream>
// получение из строки числа
int str_to_int(std::string s, int i, int j)
{
	int k = 1, num = 0;
	while (i <= j)
	{
		num += k * (s[j] - '0');
		k *= 10;
		--j;
	}
	return num;
}

std::vector<int> input_tape()
{
	std::vector <int> v;
	char c;
	v.push_back(2);
	v.push_back(2);
	std::cout << "Ввод ленты. Введите q для остановки ввода" << std::endl;
	while (std::cin >> c && c != 'q')
	{
		if (c == '*')
			v.push_back(3);
		else if (c == 'P')
			v.push_back(2);
		else
			v.push_back(c - '0');
	}
	v.push_back(2);
	v.push_back(2);
	return v;
}

Turing::Turing()
{
	tape = input_tape();
	matrix();

}
Turing::Turing(std::vector<int> & v) : tape(v)
{
	matrix();
}
// вывод ленты
void Turing::output()
{
	for (unsigned int i = 0; i < tape.size(); ++i)
	{
		if (tape.at(i) == 2)
			std::cout << 'P' << " ";
		else if (tape.at(i) == 3)
			std::cout << '*' << " ";
		else
			std::cout << tape.at(i) << " ";
	}
	std::cout << std::endl;
}

void Turing::shift()
{
	std::vector<int> v;
	v.push_back(2);
	v.push_back(2);
	v.insert(v.end(), tape.begin(), tape.end());
	tape = v;
}
void Turing::function()
{
	std::size_t i = 0, j = -1, i1, j1;
	unsigned int k;
	for (k = 0; k < tape.size() && j == -1; ++k)
		if (tape.at(k) != 2)
		{
			j = tape.at(k);
		}
	--k;
	while (i < state.size())
	{
		if (tape[1] != 2)
		{
			shift();
			++k;
		}
		j = tape[k];
		i1 = state[i][j];
		if (i1 == state.size())
			break;
		j1 = values[i][j];
		tape[k] = j1;
		if (move_tape[i][j] == 'L')
		{
			if (k > 1)
				--k;
			else
				shift();
		}
		else if (move_tape[i][j] == 'R')
		{
			if (k < tape.size() - 2)
				++k;
			else
			{
				tape.push_back(2);
				tape.push_back(2);
				++k;
			}

		}
	//	output();
		i = i1;
	}
}
std::vector<int> Turing::get_tape()
{
	return tape;
}
void Turing::matrix()
{
	int n, m;
	std::ifstream fin("matrix.txt");
	std::string c;
	fin >> n >> m;
	table.resize(n);
	state.resize(n);
	values.resize(n);
	move_tape.resize(n);
	for (int i = 0; i < n; ++i)
	{
		table[i].resize(m);
		state[i].resize(m);
		values[i].resize(m);
		move_tape[i].resize(m);
		for (int j = 0; j < m; ++j)
			fin >> table[i][j];
	}
	for (unsigned int i = 0; i < table.size(); ++i)
		for (unsigned int j = 0; j < table[i].size(); ++j)
		{
			c = table[i][j];
			if (c[0] != '*' && c[0] != 'P')
				values[i][j] = c[0] - '0';
			else if (c[0] == '*')
				values[i][j] = 3;
			else if (c[0] != 'P')
				values[i][j] = 2;
			state[i][j] = str_to_int(c, 2, c.length() - 2);
			move_tape[i][j] = c[c.length() - 1];
		}
}
