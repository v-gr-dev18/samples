#include "pch.h"
#include <string.h>
#include <string>
#include <random>
#include <ctime>
using namespace std;

void generate_sentence(char* s, int length)
{
	char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
	string blank = " ";
	string generated;
	uniform_int_distribution<unsigned> a_distribution(0, strlen(alphabet) - 1);
	uniform_int_distribution<unsigned> w_distribution(1, 12);
	default_random_engine generator;
	generator.seed(time(0)); generator();
	int w_count = w_distribution(generator);
	for (int i = 0; i <= length; ++i)
		if (w_count--) generated += alphabet[a_distribution(generator)];
		else
		{
			if (i < length) generated += blank;
			w_count = w_distribution(generator);
		}
	strcpy_s(s, generated.size()+1, generated.c_str());
}
