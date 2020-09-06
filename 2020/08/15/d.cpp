#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int k;
	priority_queue<long long, vector<long long>, less<> > q;
	scanf("%d", &k);

	for (int i = 0; i < k; i++)
	{
		long long num;
		scanf("%lld", &num);
		q.push(num);
	}

	while (q.size() != 1)
	{
		long long num01, num02;
		num01 = q.top();
		q.pop();
		num02 = q.top();
		q.pop();

		q.push(num01 - num02);
	}

	printf("%lld", q.top());
}