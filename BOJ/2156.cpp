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
		d[i] = d[i - 1]; // i��° ���� �������������
		if (d[i] < d[i - 2] + p[i]) //i��° ���� ���ð�, i-1��° ���� �������������
			d[i] = d[i - 2] + p[i];
		if (d[i] < d[i - 3] + p[i - 1] + p[i]) // i��°,i-1���� ���� ���ð� i-2��°���� �������������
			d[i] = d[i - 3] + p[i - 1] + p[i];

		//���߿��� �ִ밪 ����.
	}

	printf("%lld\n", d[n]);
}