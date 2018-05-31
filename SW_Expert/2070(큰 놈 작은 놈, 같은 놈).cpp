#include <iostream>
#include <cstdio>
using namespace std;
int t;
int tc = 1;

int main(void)
{
	scanf("%d", &t);
	while (t--)
	{
		char result;
		int a, b;
		scanf("%d %d", &a, &b);
		a == b ? result = '=' : a > b ? result = '>' : result = '<';
		printf("#%d %c\n", tc++, result);
	}
}