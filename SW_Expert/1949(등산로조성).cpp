#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int map[8][8];
int N, K;
int res;
int max_height;
void go(int x, int y, int copy[8][8], int length)
{
	//check[x][y] = true;
	if (copy[x][y] == max_height)
	{
		res = max(res, length);
		return;
	}
	else
	{
		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx&&nx < N && 0 <= ny&&ny < N)
			{
				if (copy[x][y] < copy[nx][ny])
					go(nx, ny, copy, length + 1);
			}
		}
	}
}

void start(int copy[8][8])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			go(i, j, copy, 1);
		}
	}
}


void copymap(int copymap[8][8])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			copymap[i][j] = map[i][j];
		}
	}
}


int main(void)
{
	int T;
	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; testcase++)
	{
		memset(map, 0, sizeof(map));
		res = -2100000000;
		scanf("%d %d", &N, &K);
		max_height = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf("%d", &map[i][j]);
				if (max_height < map[i][j])
					max_height = map[i][j];
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				int copy[8][8];
				copymap(copy);
				for (int remove = 1; remove <= K; remove++)
				{
					copy[i][j]--;
					start(copy);
				}
			}
		}
		printf("#%d %d\n", testcase, res);
	}
}
