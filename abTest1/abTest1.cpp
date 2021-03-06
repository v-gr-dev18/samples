﻿//============================================================================
// Name        : abTests1.cpp
// Author      : vvg
// Version     :
// Copyright   : (c) Victor Grigorovich
// 
// Дано:
// В строке записано несколько слов, разделенных пробелами.
// Требуется:
// Обратить порядок слов в строке за время O(n),
// использовав дополнительно порядка O(1) памяти.
//============================================================================


#include "pch.h"

#include <iostream>

using namespace std;

const int MAX_LENGTH = 2000;
const int length = 200;

int main()
{
	char s[MAX_LENGTH + 1] = "";
	generate_sentence(s, length);
	cout << s << endl;
	invert_words(s);
	cout << s << endl;
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
