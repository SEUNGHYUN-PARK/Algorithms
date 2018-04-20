#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, m;
char map[10][10];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int gx, gy, bx, by, rx, ry;
int result_p = 11;
int result_n;
void move_B(int dir)
{
	int nbx = bx + dx[dir];
	int nby = by + dy[dir];
	if (0 <= nbx&&nbx < n && 0 <= nby&&nby < m)
	{
		if (map[nbx][nby] == 'R' || map[nbx][nby] == '#')
			return;
		//아니면 한칸전진
		else if (map[nbx][nby] == '.')
		{
			map[nbx][nby] = 'B';
			map[bx][by] = '.';
			bx = nbx;
			by = nby;
			move_B(dir);
		}
		else if (map[nbx][nby] == 'O')
		{
			map[bx][by] = '.';
			bx = nbx;
			by = nby;
			return;
		}
	}
}
void move_R(int dir)
{
	int nrx = rx + dx[dir];
	int nry = ry + dy[dir];
	if (0 <= nrx&&nrx < n && 0 <= nry&&nry < m)
	{
		if (map[nrx][nry] == 'B' || map[nrx][nry] == '#')
			return;
		//아니면 한칸전진
		else if (map[nrx][nry] == '.')
		{
			map[nrx][nry] = 'R';
			map[rx][ry] = '.';
			rx = nrx;
			ry = nry;
			move_R(dir);
		}
		else if (map[nrx][nry] == 'O')
		{
			map[rx][ry] = '.';
			rx = nrx;
			ry = nry;
			return;
		}
	}
}
bool is_r_first(int dir)
{
	if (dir == 0)
	{
		if (ry > by)
			return true;
	}
	if (dir == 1)
	{
		if (rx > bx)
			return true;
	}
	if (dir == 2)
	{
		if (ry < by)
			return true;
	}
	if (dir == 3)
	{
		if (rx < bx)
			return true;
	}
	return false;
}
void move(int dir)
{
	if (is_r_first(dir))
	{
		move_R(dir);
		move_B(dir);
	}
	else
	{
		move_B(dir);
		move_R(dir);
	}

}
void maketmp(char tmp[][10])
{
	for (int i = 0; i<n; i++)
		for (int j = 0; j < m; j++)
		{
			tmp[i][j] = map[i][j];
		}
}
void recover(char tmp[][10])
{
	for (int i = 0; i<n; i++)
		for (int j = 0; j < m; j++)
		{
			map[i][j] = tmp[i][j];
			if (map[i][j] == 'B') { bx = i; by = j; }
			if (map[i][j] == 'R') { rx = i; ry = j; }
		}
}
void go(int dir, int cnt)
{
	char tmp[10][10];
	if (cnt > 10)
	{
		return;
	}

	if (bx == gx&&by == gy)
	{
		result_n = -1;
		return;
	}
	if (rx == gx&&ry == gy)
	{
		result_p = min(result_p, cnt);
		return;
	}
	maketmp(tmp);
	for (int i = 0; i < 4; i++)
	{
		if (i != dir)
		{
			move(i);
			go(i, cnt + 1);
			recover(tmp);
		}

	}
}

int main(void)
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i<n; i++)
		for (int j = 0; j < m; j++)
		{
			scanf(" %c", &map[i][j]);
			if (map[i][j] == 'O') { gx = i; gy = j; }
			if (map[i][j] == 'R') { rx = i; ry = j; }
			if (map[i][j] == 'B') { bx = i; by = j; }
		}

	go(-1, 0);
	//printf("%d\n%d\n", result_p, result_n);

	if (result_p < 11)
		printf("%d\n", result_p);
	else if (result_p >= 11 || result_n == 0)
		printf("-1");

}