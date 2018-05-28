#include <iostream>
#include <cstdio>
using namespace std;
int d[1000001];
int main(void)
{
	int n;
	scanf("%d", &n);
	d[0] = 0;
	d[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		d[i] = d[i - 1] + 1;
		if (i % 2 == 0)
		{
			int temp = d[i / 2] + 1;
			if (d[i] > temp)
				d[i] = temp;
		}
		if (i % 3 == 0)
		{
			int temp = d[i / 3] + 1;
			if (d[i] > temp)
				d[i] = temp;
		}
	}
	printf("%d", d[n]);
}