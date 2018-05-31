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
		int result = 0;
		for (int i = 0; i<10; i++)
		{
			int temp;
			scanf("%d", &temp);
			if (temp>result) result = temp;
		}
		printf("#%d %d\n", tc++, result);
	}
}