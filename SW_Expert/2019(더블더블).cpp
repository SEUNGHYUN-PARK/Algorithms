#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i <= n; i++)
	{
		int temp = pow(2, i);
		printf("%d ", temp);
	}
	printf("\n");
}
