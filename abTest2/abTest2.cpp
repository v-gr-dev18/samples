﻿//============================================================================
// Name        : abTests2.cpp
// Author      : vvg
// Version     :
// Copyright   : (c) Victor Grigorovich
// 
// Дано:
// В массиве длины n встречаются все числа 0..n, кроме одного.
// Требуется:
// За время O(n) найти отсутствующее число, используя O(1) памяти.
//============================================================================

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

size_t v_size = 100;

int main(int argc, char** argv) {
	// массив и пропущенное число (будут сгенерированы)
	vector<unsigned> v;
	unsigned skip;

	// сгенерировать и вывести пропущенное число и массив
	generate_one_skip_random_vector(v, v_size, skip);
	cout << "skip=" << skip << endl;
	cout << "v[" << v.size() << "]=";
	for (unsigned i = 0; i < v.size(); ++i)
		cout << v[i] << ((i < (v.size() - 1)) ? "," : "");
	cout << endl;

	// найти и вывести пропущенное число
	unsigned found = find_skipped(v);
	cout << "found=" << found << endl;
	cout << "v[" << v.size() << "]=";
	for (unsigned i = 0; i < v.size(); ++i)
		cout << v[i] << ((i < (v.size() - 1)) ? "," : "");
	cout << endl;

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