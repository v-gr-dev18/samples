﻿//============================================================================
// Name        : abTests4.cpp
// Author      : vvg
// Version     :
// Copyright   : (c) Victor Grigorovich
// 
// Дано:
// Массив чисел и число x:
// a) массив отсортирован,
// b) массив не отсортирован.
// Требуется:
// Найти индексы пары чисел, сумма которых составляет x, либо вернуть false.
//============================================================================

#include "pch.h"
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

const size_t v_size = 100;

int main(int argc, char *argv[])
{
	vector<int> v;
	const int sum = 200;
	int term1i, term2i;
	if (1 == argc)
		generate_unsort_vector(v, v_size);
	else if (0 == strcmp(argv[1], "-s"))
		generate_sort_vector(v, v_size);
	cout << "v[" << v.size() << "]={";
	for (unsigned i = 0; i < v.size(); ++i)
		cout << v[i] << ((i < (v.size() - 1)) ? "," : "");
	cout << "}" << endl;

	bool ret = false;
	if (1 == argc)
		ret = get_2terms(v, sum, term1i, term2i);
	else if (0 == strcmp(argv[1], "-s"))
		ret = get_2terms_s(v, sum, term1i, term2i);
	if (ret) cout << term1i << ", " << term2i << endl;
	else cout << (ret ? "true" : "false") << endl;
	return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.