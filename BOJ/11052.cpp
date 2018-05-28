#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int d[1001];
int p[1001];
int main(void)
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &p[i]);

	for(int i=1;i<=n;i++)
		for (int j = 1; j <= i; j++)
		{
			d[i] = max(d[i], p[j] + d[i - j]);
		}

	printf("%d\n", d[n]);
}