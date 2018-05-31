#include <iostream>
#include<cstdio>
using namespace std;
int t, tc=1;

int main(void)
{
	scanf("%d", &t);
	while (t--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		printf("#%d %d %d\n", tc++, a / b, a%b);
	}
}