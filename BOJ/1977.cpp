#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int pow_num[101];
int MINNUM = 100001;
int main(void)
{ 
	for (int i = 0; i <= 100; i++)
	{
		pow_num[i] = pow(i, 2);
	}
	int a, b,sum=0;
	scanf("%d", &a);
	scanf("%d", &b);
	for (int i = 0; i <= 100; i++)
	{
		if (a <= pow_num[i] && pow_num[i] <= b)
		{
			MINNUM = min(MINNUM, pow_num[i]);
			sum += pow_num[i];
		}
	}
	if (sum == 0)
	{
		sum = -1;
		printf("%d", sum);
	}
	else
		printf("%d\n%d\n", sum, MINNUM);
}