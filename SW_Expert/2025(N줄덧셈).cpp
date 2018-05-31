#include <iostream>
#include <cstdio>
using namespace std;

int main(void)
{
	int sum = 0;
	int n = 0;
	scanf("%d", &n);

	for (int i = 0; i <= n; i++)
	{
		sum += i;
	}
	printf("%d", sum);
}