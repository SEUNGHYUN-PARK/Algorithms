#include <iostream>
#include <cstdio>
using namespace std;

int table[11][1000001];

int main(void)
{

	for (int i = 1; i < 11; i++)
	{
		table[i][1] = i % 10;
	}

	for (int i = 1; i < 11; i++)
	{
		for (int j = 2; j < 1000001; j++)
		{
			table[i][j] = (table[i][j - 1] * i )% 10;
		}
	}

	int testcase=0;
	scanf("%d", &testcase);
	for (int tc = 0; tc < testcase; tc++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		a = a % 10;

		if (table[a][b] == 0)
			printf("10\n");
		else
			printf("%d\n", table[a][b]);
	}
}
