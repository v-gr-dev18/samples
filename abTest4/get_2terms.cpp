#include "pch.h"
#include <vector>
using namespace std;

bool get_2terms(vector<int> const &v, int sum, int &term1i, int &term2i)
{
	for (unsigned i = 0; i < (v.size() - 1); ++i)
		for (unsigned j = i + 1; j < v.size(); ++j)
			if (v[i] + v[j] == sum)
			{
				term1i = i; term2i = j;
				return true;
			}
	return false;
}

inline unsigned find_sum_sorted(vector<int> const &v, int wanted, unsigned l, unsigned r)
{
	if (wanted <= v[l]) return l;
	if (v[r] <= wanted) return r;
	while (l < r)
	{
		if (1 == (r - l))
			return ((wanted - v[l]) <= (v[r] - wanted)) ? l : r;
		unsigned m = int((l + r) / 2);
		if (v[m] == wanted) return m;
		if (wanted < v[m]) r = m;
		else l = m;
	}
	return int((l + r) / 2);
}

bool _get_2terms_s(vector<int> const &v, int sum, int &term1i, int &term2i)
{
	for (unsigned i = 0; i < (v.size() - 1); ++i)
	{
		unsigned j = find_sum_sorted(v, sum - v[i], i + 1, v.size() - 1);
		if (v[i] + v[j] == sum)
		{
			term1i = i; term2i = j;
			return true;
		}
	}
	return false;
}

bool find_sum_sorted_diagonal(vector<int> const &v, int sum, int &term1i, int &term2i, unsigned l0, unsigned t0, unsigned r0, unsigned b0)
{
	unsigned l = l0, t = t0, r = r0, b = b0;
	int sum1 = v[l] + v[t];
	if (sum < sum1) return false;
	if (sum == sum1)
	{
		term1i = l; term2i = t;
		return true;
	}
	sum1 = v[r] + v[b];
	if (sum1 < sum) return false;
	if (sum1 == sum)
	{
		term1i = r; term2i = b;
		return true;
	}
	while (true)
	{
		unsigned cm = unsigned((l + r) / 2);
		unsigned rm = unsigned((t + b) / 2);
		sum1 = v[cm] + v[rm];
		if (sum == sum1)
		{
			term1i = cm; term2i = rm;
			return true;
		}
		if (cm == l && rm == t) break;
		if (sum < sum1) { r = cm; b = rm; }
		else { l = cm; t = rm; }
	}
	if (t <= l0 && b0 <= r) if (l0 < r && t < b0) if (find_sum_sorted_diagonal(v, sum, term1i, term2i, l0, t + 1, r - 1, b0)) return true;
	if (l < r0 && t0 < b) return find_sum_sorted_diagonal(v, sum, term1i, term2i, l + 1, t0, r0, b - 1);
	return false;
}


bool get_2terms_s(vector<int> const &v, int sum, int &term1i, int &term2i)
{
	if (v.size() < 2) return false;
	return find_sum_sorted_diagonal(v, sum, term1i, term2i, 2, 1, v.size() - 1, v.size() - 2);
}