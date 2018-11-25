#include "pch.h"
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

void generate_unsort_vector(vector<int>& v, size_t v_size, int min, int max)
{
	if (min >= max) { max = 3 * v_size; min = -max; }
	default_random_engine generator;
	uniform_int_distribution<int> distribution(min, max);
	generator.seed(time(0)); generator();
	for (int i = 0; i < v_size; ++i)
	{
		int next = distribution(generator);
		v.push_back(next);
	}
}

void generate_sort_vector(vector<int>& v, size_t v_size, int min, int max)
{
	generate_unsort_vector(v, v_size, min, max);
	sort(v.begin(), v.end());
}
