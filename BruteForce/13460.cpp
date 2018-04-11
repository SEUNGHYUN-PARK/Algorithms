//이미 기울어진 방향으로 기울어봤자 무의미하므로 그 부분 수정이 필요함
//몇 가지 로직을 좀 수정해야할 필요가있음
//미완성
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, m;
char map[10][10];
int result_p = 11;
int result_n;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int rx, ry, gx, gy, bx, by;
bool rcheck = false, bcheck = false;
bool red_arrived = false;
bool blue_arrived = false;
void makebackup(char backup[10][10])
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			backup[i][j] = map[i][j];
}
void recover(char backup[10][10])
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			map[i][j] = backup[i][j];
			if (map[i][j] == 'R')
				rx = i, ry = j;
			if (map[i][j] == 'B')
				bx = i, by = j;
		}
}
void move_B(int cnt, int dir)
{
	if (bx == gx&&by == gy)
		return;
	int nbx = bx + dx[dir], nby = by + dy[dir];
	if (map[nbx][nby] == '#' || map[nbx][nby] == 'R')
		return;
	if (1 <= nbx&&nbx <= n - 2 && 1 <= nby&&nby <= m - 2)
	{
		if (map[nbx][nby] == '.' || map[nbx][nby] == 'O')
		{
			if (map[nbx][nby] == 'O')
			{
				map[bx][by] = '.';
				bx = nbx, by = nby;
				//blue_arrived = true;
			}
			if (map[nbx][nby] == '.')//&&blue_arrived == false)
			{
				map[bx][by] = '.';
				map[nbx][nby] = 'B';
				bx = nbx, by = nby;
			}
		}
	}
	move_B(cnt, dir);
}
void move_R(int cnt, int dir)
{
	if (rx == gx&&ry == gy)
		return;
	int nrx = rx + dx[dir], nry = ry + dy[dir];
	if (map[nrx][nry] == '#' || map[nrx][nry] == 'B')
	{
		return;
	}
	if (1 <= nrx&&nrx <= n - 2 && 1 <= nry&&nry <= m - 2)
	{
		if (map[nrx][nry] == '.' || map[nrx][nry] == 'O') // . 이거나 O일떄 갈수 있음
		{
			if (map[nrx][nry] == 'O')
			{
				map[rx][ry] = '.';
				rx = nrx, ry = nry;
				//red_arrived = true;
			}
			if (map[nrx][nry] == '.')//&&red_arrived == false)
			{
				map[rx][ry] = '.';
				map[nrx][nry] = 'R';
				rx = nrx, ry = nry;
			}
		}
	}
	move_R(cnt, dir);
}
bool is_oneline(int dir)
{
	if ((dir == 0)||(dir == 2))
	{
		if (gx == bx&&gx == rx)
		{
			return true;
		}
	}
	if ((dir == 1)||(dir == 3))
	{
		if (gy == by&&gy == ry)
		{
			return true;
		}
	}
	return false;
}
bool is_bgf()
{
	int bd_square = (bx-gx)*(bx-gx)+(by-gy)*(by-gy);
	int rd_square = (rx-gx)*(rx - gx)+(ry-gy)*(rx - gx);
	if (bd_square > rd_square)
		return true;
	return false;

}
bool is_bpf(int dir)
{
	int bp_square;
	int rp_square;
	int px, py; // 인접점의 x,y
	if (dir == 0)
	{
		for (int i = m; i >=0; i--)
		{
			if (map[rx][i] == '.')
			{
				if (ry < i&&by < i)
				{
					px = rx;
					py = i;
				}
				
			}
		}

	}
	if (dir == 1)
	{
		for (int i = 0; i < n; i++)
		{
			if (map[i][ry] = '.')
			{
				if (i > rx&&i > bx)
				{
					px = i;
					py = ry;
				}
			}

		}
	}
	if (dir == 2)
	{
		for (int i =0; i <m; i++)
		{
			if (map[rx][i] == '.')
			{
				if (ry > i&&by > i)
				{
					px = rx;
					py = i;
				}
			}
		}
	}
	if (dir == 3)
	{
		for (int i = n; i >= 0; i--)
		{
			if (map[i][ry] = '.')
			{
				if (i < rx&&i < bx)
				{
					px = i;
					py = ry;
				}
			}
		}
	}
	bp_square = (bx - px)*(bx - px) + (by - py)*(by - py);
	rp_square = (rx - px)*(rx - px) + (ry - py)*(ry - py);

	if (bp_square > rp_square)
		return true;
	else
		return false;
}
bool is_onlyrb(int dir)
{

	if ((rx == bx && gx != rx)|| (ry == by&&gy != ry))
	{
		return true;
	}
	return false;
}
void go(int cnt)
{
	char backup[10][10] = { 0, };
	if (cnt >= 10)
		return;
	if (rx == gx&&ry == gy)
	{
		result_p = min(cnt, result_p);
		if (bx == gx&&by == gy)
			result_p = -1;
		return;
	}
	if (bx == gx&&by == gy)
	{
		result_n = -1;
		return;
	}
	makebackup(backup);
	for (int i = 0; i < 4; i++)
	{
		if (is_oneline(i))
		{
			if (is_bgf())
			{
				move_R(cnt + 1, i);
				move_B(cnt + 1, i);
			}
			else
			{
				move_B(cnt + 1, i);
				move_R(cnt + 1, i);
			}
			
		}
		else if (is_onlyrb(i))
		{
			if (is_bpf(i))
			{
				move_R(cnt + 1, i);
				move_B(cnt + 1, i);
			}
			else
			{
				move_B(cnt + 1, i);
				move_R(cnt + 1, i);

			}
		}
		else
		{
			move_B(cnt + 1, i);
			move_R(cnt + 1, i);
		}
		go(cnt + 1);
		recover(backup);
	}
}
int main(void)
{
	scanf(" %d %d", &n, &m);
	for (int i = 0; i<n; i++)
		for (int j = 0; j < m; j++)
		{
			scanf(" %c", &map[i][j]);
			if (map[i][j] == 'R')
				rx = i, ry = j;
			if (map[i][j] == 'B')
				bx = i, by = j;
			if (map[i][j] == 'O')
				gx = i, gy = j;
		}
	go(0);

	if (result_p > 0 && result_p < 11)
		printf("%d\n", result_p);
	else
	{
		result_n = -1;
		printf("%d\n", result_n);
	}

}