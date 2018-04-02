#include <iostream>
using namespace std;
int d[1000001];
int go(int num)
{
	if (num == 1) return 0;
	if (d[num] > 0) return d[num];
	d[num] =go(num-1) + 1;
	if (num % 2==0)
	{
		int tmp = go(num / 2) + 1;
		if (d[num] > tmp) d[num] = tmp;
	}
	if (num % 3 == 0)
	{
		int tmp = go(num / 3) + 1;
		if (d[num] > tmp) d[num] = tmp;
	}
	return d[num];
}

int main(void)
{
	int n; 
	scanf("%d", &n);
	printf("%d", go(n));
}