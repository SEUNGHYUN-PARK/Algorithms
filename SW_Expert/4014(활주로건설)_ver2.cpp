#include <iostream>
#include <cstdio>
using namespace std;
int N, X;
int res = 0;

void go(int temp[100], int can[100], int idx, int N,int X)
{
	can[idx] = 2;
	if (idx >= N-1)
	{
		res++;
		return;
	}
	else
	{
		if (temp[idx] == temp[idx + 1])
		{
			go(temp, can, idx + 1, N, X);
		}
		else if (temp[idx]-temp[idx+1]==1)
		{
			int cnt = 0;
			if (idx >= N)
				return;
			for (int i = idx + 1; i <= idx+X; i++)
			{
				if (temp[idx] - temp[i] == 1 && can[i]!=1)
					cnt++;
			}
			if (cnt == X)
			{
				int k;
				for (k = idx + 1; k <= idx + X; k++)
				{
					can[k] = 1;
				}
				go(temp, can, k-1, N, X);
			}
			else
			{
				return;
			}
		}
		else if (temp[idx]-temp[idx+1]==-1)
		{
			int cnt = 0;
			if (idx < 0)
				return;
			for (int i = idx + 1 - 1; i >= idx + 1 - X; i--)
			{
				if (temp[i] - temp[idx + 1] == -1 && can[i]!=1)
					cnt++;
			}
			if (cnt == X)
			{
				int k;
				for (k = idx + 1 - 1; k >= idx + 1 - X; k--)
				{
					can[k] = 1;
				}
				go(temp, can, idx + 1, N, X);
			}
			else
			{
				return;
			}
		}
		else
			return;


	}
}
void maketemp(int map[100][100],int temp[100], int i,int j)
{
	if (i == 0)
	{
		for (int k = 0; k < N; k++)
		{
			temp[k] = map[j][k];
		}
	}
	else
	{
		for (int k = 0; k < N; k++)
		{
			temp[k] = map[k][j];
		}
	}

}
int main(void)
{
	int T;
	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; testcase++)
	{
		int map[100][100];

		res = 0;
		scanf("%d %d", &N, &X);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j< N; j++)
			{
				int temp[100] = {0,};
				int can[100] = {0,};
				maketemp(map, temp, i, j);

				go(temp, can, 0, N,X);
			}
		}

		printf("#%d %d\n", testcase, res);

	}
}
