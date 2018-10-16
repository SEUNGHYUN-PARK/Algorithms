#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <vector>
using namespace std;
int map[100][100];
int checkmap[100][100];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int N;
int res;

int next_dir[6][4]=
{
	{0,1,2,3},
	{2,3,1,0},
	{1,3,0,2},
	{3,2,0,1},
	{2,0,3,1},
	{2,3,0,1},
};

typedef struct POINT
{
	int x;
	int y;
	bool is_finish;
}POINT;

POINT endpoint;
vector<pair<int, int> > wormhole_list[11];

bool judge(int x, int y)
{
	if (x == endpoint.x && y == endpoint.y)
	{
		return true;
	}
	else
		return false;
}

void go(int x, int y, int dir)
{
	int point = 0;
	while (true)
	{
		if ((x == endpoint.x && y == endpoint.y) || map[x][y]==-1)
		{
			if ((x == endpoint.x && y == endpoint.y) && endpoint.is_finish == true)
			{
				res = max(res, point);
				return;
			}
			else if ((x == endpoint.x && y == endpoint.y) && endpoint.is_finish == false)
			{
				endpoint.is_finish = true;
			}
			else if (map[x][y] == -1)
			{
				res = max(res, point);
				return;
			}
		}
		int nx = x + dx[dir];
		int ny = y + dy[dir];


		if (0 <= nx&&nx < N && 0 <= ny&& ny < N)
		{
			if (map[nx][ny] < 6)
			{
				dir = next_dir[map[nx][ny]][dir];
//				point++;
			}
			else
			{
				int nnx, nny;
				int idx;
				for (int i = 0; i < wormhole_list[map[nx][ny]].size(); i++)
				{
					if (wormhole_list[map[nx][ny]][i].first == nx&&wormhole_list[map[nx][ny]][i].second == ny)
						idx = i;
				}
				if (idx == 0)
				{
					nnx = wormhole_list[map[nx][ny]][1].first;
					nny = wormhole_list[map[nx][ny]][1].second;
				}
				else
				{
					nnx = wormhole_list[map[nx][ny]][0].first;
					nny = wormhole_list[map[nx][ny]][0].second;
				}
				nx = nnx;
				ny = nny;
			}
		}
		else
		{
			if (dir == 0)
				dir = 2;
			else if (dir == 1)
				dir = 3;
			else if (dir == 2)
				dir = 0;
			else if (dir == 3)
				dir = 1;
		}
		x = nx;
		y = ny;
		if (map[nx][ny] != 0 && map[nx][ny] < 6 && map[nx][ny] != -1)
			point++;
		else if (!(0 <= nx&&nx < N && 0 <= ny&& ny < N))
			point++;




	}
}

int main(void)
{
	int T;
	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; testcase++)
	{

		scanf("%d", &N);
		memset(map, 0, sizeof(map));

		for (int i = 0; i <= 10; i++)
		{
			wormhole_list[i].clear();
		}

		for (int i = 0; i <= 5; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				wormhole_list[i].push_back(make_pair(-1, -1));
			}
		}

		res = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf("%d", &map[i][j]);
				if (map[i][j] > 5)
				{
					wormhole_list[map[i][j]].push_back(make_pair(i, j));
				}
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (map[i][j] != 0)
					continue;
				if (map[i][j] == 0)
				{
					for (int k = 0; k < 4; k++)
					{
						endpoint.x = i;
						endpoint.y = j;
						endpoint.is_finish = false;
						go(i, j, k);
					}
				}
			}
		}
		printf("#%d %d\n", testcase, res);
	}
}
