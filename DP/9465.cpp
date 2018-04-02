#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long d[100001][3]; //0떼지않은경우 1위쪽 땐경우 2 아래땐경우
int p[100001][2];
int t,n;

int main(void)
{
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &p[i][0]);
		for (int i = 1; i <= n; i++)
			scanf("%d", &p[i][1]);
		d[0][0] = d[0][1] = d[0][2] = 0;
		for (int i = 1; i <= n; i++)
		{
			d[i][0] = max(max(d[i - 1][0], d[i - 1][1]), d[i - 1][2]);
			d[i][1] = max(d[i - 1][0], d[i - 1][2]) + p[i][0];
			d[i][2] = max(d[i - 1][0], d[i - 1][1]) + p[i][1];
		}
		long long ans = 0;
		for(int i=1;i<=n;i++)
			ans = max(max(ans, d[i][0]), max(d[i][1], d[i][2]));
		printf("%lld\n", ans);
	}
}