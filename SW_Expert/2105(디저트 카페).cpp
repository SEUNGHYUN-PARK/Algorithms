#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int dx[] = { -1, -1, 1, 1 };
int dy[] = { -1, 1, 1, -1 };
int T,N;
int res;
int map[20][20];

void go(int x, int y, bool check_de[101], int check_map[20][20], int dir,int cnt,int rect_cnt)
{
	if (cnt>=4 && check_map[x][y] == 1)
	{
		if(rect_cnt==3)
			res = max(cnt, res);
		return;
	}
	for (int k = 0; k < 4; k++)
	{
		if ((dir == 0 && k == 2) || (dir == 1 && k == 3) || (dir == 2 && k == 0) || (dir == 3 && k == 1))
			continue;

		int nx = x + dx[k];
		int ny = y + dy[k];

		if (0 <= nx&&nx < N && 0 <= ny&&ny < N)
		{
			if (dir == 0 || dir == 2)
			{
				if (k == 1 || k == 3)
				{
					rect_cnt = rect_cnt + 1;
				}
			}
			else if(dir==1 || dir==3)
			{
				if (k == 0 || k == 2)
				{
					rect_cnt = rect_cnt + 1;
				}
			}

			if (rect_cnt > 3)
				return;

			if (check_map[nx][ny] == 0 && check_de[map[nx][ny]] == false)
			{
				check_map[nx][ny] = 2;
				check_de[map[nx][ny]] = true;
				go(nx, ny, check_de, check_map, k, cnt + 1,rect_cnt);
				check_map[nx][ny] = 0;
				check_de[map[nx][ny]] = false;
			}
			else if(cnt>=3 && check_map[nx][ny] == 1 && check_de[map[nx][ny]] == true)
			{
				go(nx, ny, check_de, check_map, k, cnt + 1,rect_cnt);
			}

			if (dir == 0 || dir == 2)
			{
				if (k == 1 || k == 3)
				{
					rect_cnt = rect_cnt - 1;
				}
			}
			else if (dir == 1 || dir == 3)
			{
				if (k == 0 || k == 2)
				{
					rect_cnt = rect_cnt - 1;
				}
			}

		}
	}

}
int main(void)
{
	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; testcase++)
	{

		memset(map, 0, sizeof(map));
		scanf("%d", &N);
		res = -1;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N;j++)
			{
				scanf("%d", &map[i][j]);
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				bool check_de[101] = { false, };
				int check_map[20][20] = { { 0, }, };
				check_map[i][j] = 1;
				check_de[map[i][j]] = true;
				go(i, j, check_de, check_map, -1,0,0);
				check_map[i][j] = 0;
				check_de[map[i][j]] = false;
			}
		}
		printf("#%d %d\n", testcase, res);
	}

}
