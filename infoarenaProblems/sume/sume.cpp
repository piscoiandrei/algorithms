#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;
ifstream in("sume.in");
ofstream out("sume.out");


int s[25005], a[300], p, n;

bool check(int k)
{
	int sum = s[0] + s[1] - s[k];
	if (sum % 2)
		return 0;
	a[0] = sum / 2;
	multiset<int> sums;
	sums.insert(s, s + p);
	for (int i = 1; i < n; i++)
	{
		a[i] = *sums.begin() - a[0];
		for (int j = 0; j < i; j++)
		{
			auto it = sums.find(a[i] + a[j]);
			if (it == sums.end())
				return 0;
			sums.erase(it);
		}
	}
	return 1;
}

int main()
{
	in >> p;
	for (int i = 0; i < p; i++)
		in >> s[i];
	sort(s, s + p);
	n = (int)(sqrt(2 * p)) + 1;

	if (n * (n - 1) != 2 * p){
		out << "-1"; return 0;
	}

	bool sol = 0;
	for(int i = 2; i < n && !sol; i++)
		if (check(i))
			sol = 1;
	if (!sol) {
		out << "-1";
		return 0;
	}
	out << n << '\n';
	for (int i = 0; i < n; i++)
		out << a[i] << ' ';
	return 0;
}
