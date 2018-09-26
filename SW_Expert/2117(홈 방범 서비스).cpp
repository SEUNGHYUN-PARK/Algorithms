#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;

int N, M;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int map[21][21];
int check[21][21];
int cost[22];
int res = 0;
int max_ = 0;

void go(int x, int y)
{
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	int housecnt = 0;
	check[x][y] = 1;
	if (map[x][y] == 1)
		housecnt++;
	for (int K = 1; K <= N + 1; K++)
	{
		while (!q.empty())
		{
			int cx = q.front().first;
			int cy = q.front().second;

			if (check[cx][cy] == K)
				break;
			q.pop();
			for (int k = 0; k < 4; k++)
			{
				int nx = cx + dx[k];
				int ny = cy + dy[k];
				if (0 <= nx&&nx < N && 0 <= ny&&ny < N)
				{
					if (check[nx][ny] == 0)
					{
						if (check[cx][cy] < K)
						{
							if (map[nx][ny] == 1)
								housecnt++;
							check[nx][ny] = check[cx][cy] + 1;
							q.push(make_pair(nx, ny));
						}
					}
				}
			}
		}
		int operate_cost = cost[K];
		if (housecnt*M - operate_cost >= 0)
			res = max(res, housecnt);

	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;

	for (int i = 1; i <= 21; i++)
		cost[i] = i*i + (i - 1)*(i - 1);

	for (int testcase = 1; testcase <= T; testcase++)
	{
		memset(map, 0, sizeof(map));
		cin >> N >> M;
		res = 0;
		max_ = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				memset(check, 0, sizeof(check));
				go(i, j);
			}
		}

		cout << "#" << testcase << " " << res << "\n";
	}
}
