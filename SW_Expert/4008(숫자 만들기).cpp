#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int maxnum = -2100000000;
int minnum = 2100000000;

void go(int num[12], int index, int p, int s, int m, int d, int current, int n)
{
	if (index >= n-1)
	{
		minnum = min(minnum, current);
		maxnum = max(maxnum, current);
		return;
	}
	if (p > 0)
		go(num, index + 1, p - 1, s, m, d, current + num[index+1], n);
	if (s > 0)
		go(num, index + 1, p, s - 1, m, d, current - num[index+1], n);
	if (m > 0)
		go(num, index + 1, p, s, m - 1, d, current * num[index+1], n);
	if (d > 0)
		go(num, index + 1, p, s, m, d - 1, current / num[index+1], n);
}

int main(void)
{
	int T;
	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; testcase++)
	{
		int numarr[12];
		int n;
		int p, s, m, d;
		maxnum = -2100000000;
		minnum = 2100000000;
		scanf("%d", &n);
		scanf("%d%d%d%d", &p, &s, &m, &d);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &numarr[i]);
		}
		go(numarr, 0, p, s, m, d, numarr[0],n);

		printf("#%d %d\n", testcase, maxnum - minnum);
	}
}