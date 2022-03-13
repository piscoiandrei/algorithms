#include <fstream>
#include <deque>
using namespace std;
ifstream in("deque.in");
ofstream out("deque.out");


// PAIR IS of int32_t because with int64_t the memory limit is exceeded
struct PAIR {
	int32_t value;
	int32_t pos;
};

deque<PAIR> dq;
int64_t sum = 0;

void putIn(PAIR p)
{
	while (!dq.empty() && dq.back().value > p.value)
		dq.pop_back();
	dq.push_back(p);
}

void check(int64_t seq_left_index)
{
	// add the current minimum if it's still in the current sequence of len k
	// otherwise remove it
	if (!dq.empty())
	{
		auto front = dq.front();
		if (front.pos > seq_left_index)
			sum += front.value;
		else if (front.pos == seq_left_index)
			sum += front.value, dq.pop_front();
		else
			dq.pop_front();
	}
}

int main()
{
	int32_t n, k, val, i;
	in >> n >> k;

	for (i = 1; i <= k; i++)
	{
		in >> val;
		putIn({ val, i });
	}
	// adding the minimum for the first sequence of len k
	check(1);
	for (; i <= n; i++)
	{
		in >> val;
		putIn({ val, i });
		check(i - k + 1);
	}
	out << sum;
}
