#include <iostream>
#include <cstdio>
using namespace std;

int main(void)
{
	int sum = 0;
	int n;
	scanf("%d", &n);
	while (n>0)
	{
		int temp = n % 10;
		sum += temp;
		n /= 10;
	}
	printf("%d", sum);
}