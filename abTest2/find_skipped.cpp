#include "pch.h"
#include <vector>
using namespace std;

inline void swap(unsigned &a, unsigned &b) { unsigned t; t = a; a = b; b = t; }
unsigned find_skipped(vector<unsigned> &v)
{
	if (!v.size()) return -1;
	unsigned l0 = 0, r0 = v.size() - 1;
	while (l0 < r0)
	{
		unsigned m = int((l0 + r0) / 2);
		unsigned l = l0, r = r0;
		while (true)
		{
			while (v[l] <= m && l <= r0) ++l;
			while (m < v[r] && l0 <= r) --r;
			if (l < r) swap(v[l++], v[r--]);
			else break;
		}
		if (r == m) l0 = l; else r0 = r;
	}
	return ((l0 != v[l0]) ? l0 : l0 + 1);
}
