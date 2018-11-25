#include "pch.h"
#include <vector>
#include <random>
#include <ctime>

using namespace std;
void generate_one_skip_random_vector(vector<unsigned> &v, size_t v_size, unsigned &skip)
{
	vector<bool> exists(v_size + 1, false);
	default_random_engine generator;
	uniform_int_distribution<unsigned> distribution(0, v_size);
	generator.seed(time(0)); generator();
	skip = distribution(generator);
	for (unsigned i = 0; i < v_size; ++i)
	{
		unsigned next;
		while (true)
		{
			next = distribution(generator);
			if (skip != next && !exists[next])
			{
				exists[next] = true;
				break;
			}
		}
		v.push_back(next);
	}
}
