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
		d[0] = 1; // �ƹ��͵� �����ʴ� ���... ��� ���� �������߱�???
		d[1] = 1;
		d[2] = 2;

		for (int i = 3; i <= n; i++)
		{
			d[i] = d[i - 1] + d[i - 2] + d[i - 3];
		}
		printf("%d\n", d[n]);
	}
}