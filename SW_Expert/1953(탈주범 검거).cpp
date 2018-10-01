#include <iostream>
#include <cstdio>
#include <queue>
#include <memory.h>
using namespace std;
int N, M; // 맵의 세로 가로
int R, C; // 맨홀뚜껑의 위치
int L; // 도둑이 튀고 경과된 시간
// 상하좌우 컨셉
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int map[50][50];
bool check[50][50];
int distance_map[50][50];

int go(int r, int c)
{
	int cnt = 1;
	queue<pair<int, int> > q;
	q.push(make_pair(r, c));
	distance_map[r][c] = 1;
	check[r][c] = true;

	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++)
		{
			int nx = cx + dx[k];
			int ny = cy + dy[k];
			if (0 <= nx&&nx < N && 0 <= ny&&ny < M)
			{
				if (map[nx][ny] > 0)
				{
					if (map[cx][cy] == 1)
					{
						if (k == 0)
						{
							if (map[nx][ny] == 1 || map[nx][ny] == 2 || map[nx][ny] == 5 || map[nx][ny] == 6)
							{
								if (check[nx][ny] == false && distance_map[cx][cy]<L)
								{
									distance_map[nx][ny] = distance_map[cx][cy] + 1;
									check[nx][ny] = true;
									q.push(make_pair(nx, ny));
									cnt++;
								}
							}
						}
						else if (k == 1)
						{
							if (map[nx][ny] == 1 || map[nx][ny] == 2 || map[nx][ny] == 4 || map[nx][ny] == 7)
							{
								if (check[nx][ny] == false && distance_map[cx][cy]<L)
								{
									distance_map[nx][ny] = distance_map[cx][cy] + 1;
									check[nx][ny] = true;
									q.push(make_pair(nx, ny));
									cnt++;
								}
							}
						}
						else if (k == 2)
						{
							if (map[nx][ny] == 1 || map[nx][ny] == 3 || map[nx][ny] == 4 || map[nx][ny] == 5)
							{
								if (check[nx][ny] == false && distance_map[cx][cy]<L)
								{
									distance_map[nx][ny] = distance_map[cx][cy] + 1;
									check[nx][ny] = true;
									q.push(make_pair(nx, ny));
									cnt++;
								}
							}
						}
						else if (k == 3)
						{
							if (map[nx][ny] == 1 || map[nx][ny] == 3 || map[nx][ny] == 6 || map[nx][ny] == 7)
							{
								if (check[nx][ny] == false && distance_map[cx][cy]<L)
								{
									distance_map[nx][ny] = distance_map[cx][cy] + 1;
									check[nx][ny] = true;
									q.push(make_pair(nx, ny));
									cnt++;
								}
							}
						}
					}
					else if (map[cx][cy] == 2)
					{
						if (k == 0)
						{
							if (map[nx][ny] == 1 || map[nx][ny] == 2 || map[nx][ny] == 5 || map[nx][ny] == 6)
							{
								if (check[nx][ny] == false && distance_map[cx][cy]<L)
								{
									distance_map[nx][ny] = distance_map[cx][cy] + 1;
									check[nx][ny] = true;
									q.push(make_pair(nx, ny));
									cnt++;
								}
							}
						}
						else if (k == 1)
						{
							if (map[nx][ny] == 1 || map[nx][ny] == 2 || map[nx][ny] == 4 || map[nx][ny] == 7)
							{
								if (check[nx][ny] == false && distance_map[cx][cy]<L)
								{
									distance_map[nx][ny] = distance_map[cx][cy] + 1;
									check[nx][ny] = true;
									q.push(make_pair(nx, ny));
									cnt++;
								}
							}
						}

					}
					else if (map[cx][cy] == 3)
					{
						if (k == 2)
						{
							if (map[nx][ny] == 1 || map[nx][ny] == 3 || map[nx][ny] == 4 || map[nx][ny] == 5)
							{
								if (check[nx][ny] == false && distance_map[cx][cy]<L)
								{
									distance_map[nx][ny] = distance_map[cx][cy] + 1;
									check[nx][ny] = true;
									q.push(make_pair(nx, ny));
									cnt++;
								}
							}
						}
						else if (k == 3)
						{
							if (map[nx][ny] == 1 || map[nx][ny] == 3 || map[nx][ny] == 6 || map[nx][ny] == 7)
							{
								if (check[nx][ny] == false && distance_map[cx][cy]<L)
								{
									distance_map[nx][ny] = distance_map[cx][cy] + 1;
									check[nx][ny] = true;
									q.push(make_pair(nx, ny));
									cnt++;
								}
							}
						}
					}
					else if (map[cx][cy] == 4)
					{
						if (k == 0)
						{
							if (map[nx][ny] == 1 || map[nx][ny] == 2 || map[nx][ny] == 5 || map[nx][ny] == 6)
							{
								if (check[nx][ny] == false && distance_map[cx][cy]<L)
								{
									distance_map[nx][ny] = distance_map[cx][cy] + 1;
									check[nx][ny] = true;
									q.push(make_pair(nx, ny));
									cnt++;
								}
							}
						}
						else if (k == 3)
						{
							if (map[nx][ny] == 1 || map[nx][ny] == 3 || map[nx][ny] == 6 || map[nx][ny] == 7)
							{
								if (check[nx][ny] == false && distance_map[cx][cy]<L)
								{
									distance_map[nx][ny] = distance_map[cx][cy] + 1;
									check[nx][ny] = true;
									q.push(make_pair(nx, ny));
									cnt++;
								}
							}
						}
					}
					else if (map[cx][cy] == 5)
					{

						if (k == 1)
						{
							if (map[nx][ny] == 1 || map[nx][ny] == 2 || map[nx][ny] == 4 || map[nx][ny] == 7)
							{
								if (check[nx][ny] == false && distance_map[cx][cy]<L)
								{
									distance_map[nx][ny] = distance_map[cx][cy] + 1;
									check[nx][ny] = true;
									q.push(make_pair(nx, ny));
									cnt++;
								}
							}
						}
						else if (k == 3)
						{
							if (map[nx][ny] == 1 || map[nx][ny] == 3 || map[nx][ny] == 6 || map[nx][ny] == 7)
							{
								if (check[nx][ny] == false && distance_map[cx][cy]<L)
								{
									distance_map[nx][ny] = distance_map[cx][cy] + 1;
									check[nx][ny] = true;
									q.push(make_pair(nx, ny));
									cnt++;
								}
							}
						}
					}
					else if (map[cx][cy] == 6)
					{
						if (k == 1)
						{
							if (map[nx][ny] == 1 || map[nx][ny] == 2 || map[nx][ny] == 4 || map[nx][ny] == 7)
							{
								if (check[nx][ny] == false && distance_map[cx][cy]<L)
								{
									distance_map[nx][ny] = distance_map[cx][cy] + 1;
									check[nx][ny] = true;
									q.push(make_pair(nx, ny));
									cnt++;
								}
							}
						}
						else if (k == 2)
						{
							if (map[nx][ny] == 1 || map[nx][ny] == 3 || map[nx][ny] == 4 || map[nx][ny] == 5)
							{
								if (check[nx][ny] == false && distance_map[cx][cy]<L)
								{
									distance_map[nx][ny] = distance_map[cx][cy] + 1;
									check[nx][ny] = true;
									q.push(make_pair(nx, ny));
									cnt++;
								}
							}
						}

					}
					else if (map[cx][cy] == 7)
					{
						if (k == 0)
						{
							if (map[nx][ny] == 1 || map[nx][ny] == 2 || map[nx][ny] == 5 || map[nx][ny] == 6)
							{
								if (check[nx][ny] == false && distance_map[cx][cy]<L)
								{
									distance_map[nx][ny] = distance_map[cx][cy] + 1;
									check[nx][ny] = true;
									q.push(make_pair(nx, ny));
									cnt++;
								}
							}
						}
						else if (k == 2)
						{
							if (map[nx][ny] == 1 || map[nx][ny] == 3 || map[nx][ny] == 4 || map[nx][ny] == 5)
							{
								if (check[nx][ny] == false && distance_map[cx][cy]<L)
								{
									distance_map[nx][ny] = distance_map[cx][cy] + 1;
									check[nx][ny] = true;
									q.push(make_pair(nx, ny));
									cnt++;
								}
							}
						}
					}
				}
			}
		}
	}
	return cnt;
}

int main(void)
{
	int T;
	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; testcase++)
	{
		memset(map, 0, sizeof(map));
		memset(check, false, sizeof(check));
		memset(distance_map, 0, sizeof(distance_map));

		scanf("%d %d %d %d %d", &N, &M, &R, &C, &L);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}

		printf("#%d %d\n", testcase, go(R, C));
	}
}
