#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <memory.h>
using namespace std;

int T;
int N, W, H;
int dx[] = {-1,0,1,0};
int dy[] = { 0,1,0,-1 };
vector<pair<int, int> > toplist;
int res;

void restoremap(int map[15][12], int map_copy[15][12])
{
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			map[i][j] = map_copy[i][j];
		}
	}
}

void copymap(int map[15][12], int map_copy[15][12])
{
	for (int i = 0;i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			map_copy[i][j] = map[i][j];
		}
	}
}


void align(int map_copy[15][12])
{
	for (int i = 0; i < W; i++)
	{
		int temp[15] = {0,};
		int k = H - 1;
		for (int j = H - 1; j >= 0; j--)
		{
			if (map_copy[j][i] > 0)
				temp[k--] = map_copy[j][i];
		}

		for (int j = H - 1; j >= 0; j--)
		{
			map_copy[j][i] = temp[j];
		}
	}
}


void hit(int map_copy[15][12], int x, int y, int dis, int dir)
{
	if (dis == 0)
	{
		return;
	}
	else
	{
		if (dir == -1)
		{
			map_copy[x][y] = 0;
			for (int k = 0; k < 4; k++)
			{
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (0 <= nx&&nx < H && 0 <= ny&&ny < W)
				{
					if (map_copy[nx][ny]>0 && dis>1)
					{
						hit(map_copy, nx, ny, map_copy[nx][ny], -1);
					}
					hit(map_copy, nx, ny, dis - 1, k);
				}
			}
		}
		else
		{
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (0 <= nx&&nx < H && 0 <= ny&&ny < W)
			{
				if (map_copy[nx][ny]>0 && dis>1)
				{
					hit(map_copy, nx, ny, map_copy[nx][ny], -1);
				}
				hit(map_copy, nx, ny, dis - 1, dir);
			}
		}
	}
}

int countingblock(int copy[15][12])
{
	int ret = 0;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (copy[i][j] > 0)
				ret++;
		}
	}
	return ret;
}

void make_toplist(int copy[15][12],int Ncnt)
{

	if (Ncnt == N)
	{
		int temp = countingblock(copy);
		res = min(temp, res);
		return;
	}

	int map_copy[15][12];
	copymap(copy,map_copy);

	vector<pair<int, int> > toplist;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (map_copy[i][j] >= 1)
			{
				int ui = i + dx[0];
				int uj = j + dy[0];
				if (0 <= ui&&ui < H && 0 <= uj&&uj < W)
				{
					if (map_copy[ui][uj] == 0)
						toplist.push_back(make_pair(i, j));
				}
				else
				{
					toplist.push_back(make_pair(i, j));
				}
			}
		}
	}

	if (toplist.size() == 0)
	{
		res = 0;
		return;
	}


	for (int i = 0; i < toplist.size(); i++)
	{
		hit(map_copy,toplist[i].first, toplist[i].second,map_copy[toplist[i].first][toplist[i].second],-1);
		align(map_copy);
		make_toplist(map_copy, Ncnt + 1);
		restoremap(map_copy, copy);
		//printf("\n");
	}
}

int main(void)
{

	scanf("%d", &T);
	for (int testcase = 1; testcase <= T;testcase++)
	{
		int map[15][12];
		scanf("%d %d %d", &N, &W, &H);
		memset(map, 0, sizeof(map));
		res = 2100000000;
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				scanf("%d", &map[i][j]);
				int ui = i + dx[0];
				int uj = j + dy[0];
				if (map[i][j] == 1)
				{
					if (0 <= ui&&ui < H && 0 <= uj&&uj < W)
					{
						if (map[ui][uj] == 0)
							toplist.push_back(make_pair(i, j));

					}
					else
					{
						toplist.push_back(make_pair(i, j));
					}
				}

			}
		}
		int map_copy[15][12];
		copymap(map,map_copy);
		make_toplist(map_copy,0);
		printf("#%d %d\n", testcase, res);
	}
}
