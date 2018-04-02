#include <iostream>
#include <cstdio>
using namespace std;
int d[1001][10];
int mod = 10007;
int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i <= 9; i++) d[1][i] = 1;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				d[i][j] += d[i-1][k];
				d[i][j] %= mod;
			}
		}
	}
	long long ans=0;
	for (int i = 0; i <= 9; i++)
		ans += d[n][i];
	ans %= 10007;
	printf("%ld", ans);
}