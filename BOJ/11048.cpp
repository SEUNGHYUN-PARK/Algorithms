#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int map[1001][1001];
int dp[1001][1001];

int max3(int a, int b, int c)
{
	return max(a,max(b,c));
}

int main(void)
{
	int r, c;
	scanf("%d %d", &r, &c);
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			dp[i][j] = max3(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + map[i][j];
		}
	}

	printf("%d\n", dp[r][c]);
}
