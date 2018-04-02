#include <iostream>
#include <cstdio>
using namespace std;
int d[101][10];
int mod = 1000000000;
int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < 10; i++) d[0][i] = 0; //0자리 수는 없으니까.
	for (int i = 1; i < 10; i++)  d[1][i] = 1; //1자리수는 전부 계단수로 취급

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (j - 1 >= 0)
				d[i][j] += d[i - 1][j - 1];
			if (j + 1 <= 9)
				d[i][j] += d[i - 1][j + 1];
			d[i][j] %= mod;
		}
	}
	long long ans=0;
	for (int i = 0; i <= 9; i++)
		ans += d[n][i];
	ans %= mod;
	printf("%ld\n", ans);

}