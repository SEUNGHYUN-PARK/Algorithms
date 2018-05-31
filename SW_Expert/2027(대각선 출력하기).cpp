#include <iostream>
#include <cstdio>
using namespace std;
char map[5][5];
int main(void)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i == j)
				map[i][j] = '#';
			else
				map[i][j] = '+';
		}
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
}