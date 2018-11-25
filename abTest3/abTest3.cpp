﻿//============================================================================
// Name        : abTests[3].cpp
// Author      : vvg
// Version     :
// Copyright   : (c) Victor Grigorovich
// 
// Дано:
// Требуется:
// Написать программу, печатающую либо число от 1..n, либо
// - "Knock" вместо кратных 3 или "Bang" вместо кратных 5,
// либо "KnockBang" вместо кратных и 3, и 5.
//============================================================================

#include "pch.h"

#include <iostream>
using namespace std;

const int n = 100;
struct { int val; char const * const str; } subst_a[] =
{ {3, "Knock"}
, {5, "Bang"}
//, {7, "Boom"}
//, {11, "Hit"}
};

int main()
{
	for (int i = 1; i <= n; ++i)
	{
		bool flag = false;
		for (int j = 0; j < sizeof(subst_a) / sizeof(subst_a[0]); ++j)
			if (0 == i % subst_a[j].val)
			{
				cout << subst_a[j].str;
				flag = true;
			}
		if (!flag) cout << i;
		cout << endl;
	}
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
