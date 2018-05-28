#include <iostream>
#include <cstdio>
using namespace std;

int n;
long long d[10001];
long long p[10001];
int main(void)
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &p[i]);
	}
	d[1] = p[1];
	d[2] = p[1] + p[2];
	for (int i = 3; i <= n; i++)
	{
		d[i] = d[i - 1]; // i번째 잔을 마시지않은경우
		if (d[i] < d[i - 2] + p[i]) //i번째 잔을 마시고, i-1번째 잔을 마시지않은경우
			d[i] = d[i - 2] + p[i];
		if (d[i] < d[i - 3] + p[i - 1] + p[i]) // i번째,i-1번쨰 잔을 마시고 i-2번째잔을 마시지않은경우
			d[i] = d[i - 3] + p[i - 1] + p[i];

		//이중에서 최대값 산출.
	}

	printf("%lld\n", d[n]);
}