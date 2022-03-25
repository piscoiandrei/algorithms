#include <fstream>
#include <iostream>
#include <cmath>
#include <climits>
#include <queue>
using namespace std;
ifstream in("sum2.in");
ofstream out("sum2.out");


long long s[100005], m[100005];
int n, l, u;

struct Pair {
	int pos;
	long long value;
};

deque<Pair> dq;

void insert(Pair p)
{
	while (!dq.empty() && dq.back().value > p.value)
		dq.pop_back();
	if (!dq.empty() && dq.front().pos < p.pos - u + 1)
		dq.pop_front();
	dq.push_back(p);
}

int main()
{
	in >> n >> l >> u;
	int x;
	for (int i = 1; i <= n; i++)
	{
		in >> x;
		s[i] = x + s[i - 1];
	}
	long long MAX = LLONG_MIN;
	for (int j = l; j <= n; j++)
	{
		int i = j - l + 1;
		insert({ i, s[i] });
		long long sum = s[j] - dq.front().value;
		if (sum > MAX)
			MAX = sum;
	}
	out << MAX;
}
