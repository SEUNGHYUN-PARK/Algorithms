#include <iostream>
#include <cstdio>
using namespace std;
int d[12];

int main(void)
{
	int n;
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		d[0] = 1; // 아무것도 놓지않는 경우... 어떻게 보면 끼워맞추기???
		d[1] = 1;
		d[2] = 2;

		for (int i = 3; i <= n; i++)
		{
			d[i] = d[i - 1] + d[i - 2] + d[i - 3];
		}
		printf("%d\n", d[n]);
	}
}