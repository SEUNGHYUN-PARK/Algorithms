#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <memory.h>
#include <algorithm>
#include <functional>
using namespace std;

vector<int> person_A_movelist;
vector<int> person_B_movelist;
vector<pair<int,int> > map[10][10]; // power,id

// 제자리,상 우 하 좌
int dy[] = {0,-1,0,1,0};
int dx[] = {0,0,1,0,-1};

typedef struct PersonInfo
{
	int x;
	int y;
	int curr_charge;
}PersonInfo;

void judge(PersonInfo &p1,PersonInfo &p2)
{
	int p1_select_id=0; //idx
	int p2_select_id=0; //idx
	if (map[p1.x][p1.y].size() >= 1)
	{
		p1_select_id = map[p1.x][p1.y][0].second;
	}
	if (map[p2.x][p2.y].size() >= 1)
	{
		p2_select_id = map[p2.x][p2.y][0].second;
	}
	if (p1_select_id > 0 || p2_select_id > 0)
	{
		if (p1_select_id != p2_select_id)
		{
			if (p1_select_id > 0 && p2_select_id == 0)
			{
				p1.curr_charge += map[p1.x][p1.y][0].first;
			}
			if (p2_select_id > 0 && p1_select_id == 0)
			{
				p2.curr_charge += map[p2.x][p2.y][0].first;
			}
			if (p1_select_id > 0 && p2_select_id > 0)
			{
				p1.curr_charge += map[p1.x][p1.y][0].first;
				p2.curr_charge += map[p2.x][p2.y][0].first;
			}
		}
		else if (p1_select_id == p2_select_id)
		{
			if (map[p1.x][p1.y].size() == 1 && map[p2.x][p2.y].size() == 1)
			{
				p1.curr_charge += map[p1.x][p1.y][0].first / 2;
				p2.curr_charge += map[p2.x][p2.y][0].first / 2;
			}
			else
			{
				int tmp = (map[p1.x][p1.y][0].first + map[p2.x][p2.y][0].first) / 2;
				if (map[p1.x][p1.y].size() > 1 && map[p2.x][p2.y].size() == 1)
				{
					int temp = map[p1.x][p1.y][1].first + map[p2.x][p2.y][0].first;
					if (temp > tmp)
					{
						p1.curr_charge += map[p1.x][p1.y][1].first;
						p2.curr_charge += map[p2.x][p2.y][0].first;
					}
				}
				else if (map[p1.x][p1.y].size() == 1 && map[p2.x][p2.y].size() > 1)
				{
					int temp = map[p1.x][p1.y][0].first + map[p2.x][p2.y][1].first;
					if (temp > tmp)
					{
						p1.curr_charge += map[p1.x][p1.y][0].first;
						p2.curr_charge += map[p2.x][p2.y][1].first;
					}
				}
				else // 전부다 두개 이상 있을경우
				{
					int temp1 = map[p1.x][p1.y][0].first + map[p2.x][p2.y][1].first;
					int temp2 = map[p1.x][p1.y][1].first + map[p2.x][p2.y][0].first;
					if (temp1 >= temp2)
					{
						if (temp1 > tmp)
						{
							p1.curr_charge += map[p1.x][p1.y][0].first;
							p2.curr_charge += map[p2.x][p2.y][1].first;
						}
					}
					if (temp2 > temp1)
					{
						if (temp2 > tmp)
						{
							p1.curr_charge += map[p1.x][p1.y][1].first;
							p2.curr_charge += map[p2.x][p2.y][0].first;
						}
					}
				}
			}
		}
	}


}


void move(PersonInfo &p, int dir)
{
	p.x = p.x + dy[dir];
	p.y = p.y + dx[dir];
}

void bfs(int X, int Y, int C, int P, int id)
{
	int dis[10][10];
	bool check[10][10];
	memset(dis, -1, sizeof(dis));
	memset(check, false, sizeof(check));
	queue<pair<int, int> > q; // y,x
	q.push(make_pair(Y, X));
	dis[Y][X] = C;
	map[Y][X].push_back(make_pair(P, id));
	check[Y][X] = true;
	while (!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		for (int k = 1; k < 5; k++)
		{
			int nx = cx + dx[k];
			int ny = cy + dy[k];
			if (0 <= nx&&nx < 10 && 0 <= ny&&ny < 10)
			{
				if (dis[cy][cx] > 0 && check[ny][nx]==false)
				{
					check[ny][nx] = true;
					dis[ny][nx] = dis[cy][cx] - 1;
					q.push(make_pair(ny, nx));
					map[ny][nx].push_back(make_pair(P, id));
				}
			}

		}
	}



}

void init()
{
	person_A_movelist.clear();
	person_B_movelist.clear();
	person_A_movelist.push_back(0);
	person_B_movelist.push_back(0);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			map[i][j].clear();
		}
	}
}


int main(void)
{
	int T;
	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; testcase++)
	{
		int M, A;
		scanf("%d %d ", &M, &A);
		init();
		PersonInfo p1, p2;
		p1.x = 0;
		p1.y = 0;
		p2.x = 9;
		p2.y = 9;
		p1.curr_charge = 0;
		p2.curr_charge = 0;

		for (int i = 0; i < M; i++)
		{
			int temp;
			scanf("%d", &temp);
			person_A_movelist.push_back(temp);
		}
		for (int i = 0; i < M; i++)
		{
			int temp;
			scanf("%d", &temp);
			person_B_movelist.push_back(temp);
		}
		for (int id = 1; id <= A; id++)
		{
			int X, Y, C, P;
			scanf("%d %d %d %d", &X, &Y, &C, &P);
			bfs(X-1, Y-1, C, P, id);
		}

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				sort(map[i][j].begin(), map[i][j].end(),greater<pair<int,int> >());
			}
		}

		for (int i = 0; i <= M; i++)
		{
			move(p1,person_A_movelist[i]);
			move(p2,person_B_movelist[i]);
			judge(p1,p2);
		}

		int res = p1.curr_charge + p2.curr_charge;
		printf("#%d %d\n", testcase, res);
	}
}
