#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
int map[102][102]; //����� ������ 1 ������ 0 ���� 2 ���� �Ϻΰ� ������ 3
int n, k;
int l;
int result = 0;
queue<pair<int, char> > q;
queue<pair<int, int> > tail;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int setting_next(int dir, char tgo)
{
	if (dir == 0)
	{
		if (tgo == 'L')
		{
			return 3;
		}
		if (tgo == 'D')
		{
			return 1;
		}
	}
	if (dir == 1)
	{
		if (tgo == 'L')
		{
			return 0;
		}
		if (tgo == 'D')
		{
			return 2;
		}
	}
	if (dir == 2)
	{
		if (tgo == 'L')
		{
			return 1;
		}
		if (tgo == 'D')
		{
			return 3;
		}
	}
	if (dir == 3)
	{
		if (tgo == 'L')
		{
			return 2;
		}
		if (tgo == 'D')
		{
			return 0;
		}
	}
}
bool time_compare(int time)
{
	if (q.size() > 0)
	{
		if (time == q.front().first)
			return true;
		else
			return false;
	}
}
void go(int x, int y, int dir, int time) // x,y�� �Ӹ���ġ dir�� �������, time�� ����ð�
{
	map[x][y] = 3;
	tail.push(make_pair(x, y)); // ���� ��ġ �־���
	int nx = x + dx[dir];
	int ny = y + dy[dir];
	if (time_compare(time)) // time�� ���� �ð��� �ǹ��ϸ� ���� �ð��� �����ϸ�
	{
		int tdir = setting_next(dir, q.front().second); // ������ �����ְ�
		int nnx = x + dx[tdir];
		int nny = y + dy[tdir];
		q.pop(); // ť�� ����
		if (map[nnx][nny] == 0)
		{
			map[nnx][nny] = 3;
			map[tail.front().first][tail.front().second] = 0;
			tail.pop();
		}
		else if (map[nnx][nny] == 3 || map[nnx][nny] == 2)
		{
			time += 1;
			result += time;
			return;
		}
		go(nnx, nny, tdir, time + 1); // �� ����� �ð� 1�� ����
	}
	else // �⺻������ ������Ÿ
	{
		if (map[nx][ny] == 0)
		{
			map[nx][ny] = 3;
			map[tail.front().first][tail.front().second] = 0;
			tail.pop();
		}
		else if (map[nx][ny] == 3 || map[nx][ny] == 2)
		{
			time += 1;
			result += time;
			return;
		}
		go(nx, ny, dir, time + 1);
	}
}
void map_setting()
{
	for (int i = 0; i <= n + 1; i++)
	{
		map[0][i] = 2;
	}
	for (int i = 0; i <= n + 1; i++)
	{
		map[i][0] = 2;
	}
	for (int i = 0; i <= n + 1; i++)
	{
		map[n + 1][i] = 2;
	}
	for (int i = 0; i <= n + 1; i++)
	{
		map[i][n + 1] = 2;
	}

}
int main(void)
{
	scanf("%d", &n);
	scanf("%d", &k);
	map_setting();
	for (int i = 0; i < k; i++)
	{
		int apple_x, apple_y;
		scanf("%d %d", &apple_x, &apple_y);
		map[apple_x][apple_y] = 1;
	}
	scanf("%d", &l);
	for (int i = 0; i < l; i++)
	{
		int tn; char tc;
		scanf(" %d %c", &tn, &tc);
		q.push(make_pair(tn, tc));
	}
	go(1, 1, 0, 0);
	printf("%d", result);

}