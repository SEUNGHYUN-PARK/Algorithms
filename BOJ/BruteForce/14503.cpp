#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
using namespace std;
int N, M;
int map[50][50];
int check[50][50]; // 청소 안함 0 청소 함 1 벽 2
int n, m, l;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int cnt;
void go(int n, int m, int l);
void search(int n, int m, int l);
void count();
bool is_back(int n, int m, int l);
bool checking(int n, int m);
int main(void)
{
	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &n, &m, &l);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1)
			{
				check[i][j] = 2;
			}
		}
	}
	go(n, m, l);
	count();
	printf("%d\n", cnt);

}
void go(int n, int m, int l)
{
	check[n][m] = 1;
	search(n, m, l);

}
void search(int n, int m, int l)
{
	int nx = n + dx[(l + 3) % 4];
	int ny = m + dy[(l + 3) % 4];
	if (check[nx][ny] == 0)
	{
		go(nx, ny, (l + 3) % 4);
	}
	else if (check[nx][ny] == 1 || check[nx][ny] == 2)
	{
		if (checking(n, m))
		{
			int tx, ty;
			if (l == 0)
			{
				tx = n + dx[2];
				ty = m + dy[2];
			}
			else if (l == 1)
			{
				tx = n + dx[3];
				ty = m + dy[3];
			}
			else if (l == 2)
			{
				tx = n + dx[0];
				ty = m + dy[0];
			}
			else if (l == 3)
			{
				tx = n + dx[1];
				ty = m + dy[1];
			}
			if (is_back(n, m, l))
			{

				if (check[tx][ty] == 2)
					return;
				else
					search(tx, ty, l % 4);
			}
			else
			{
				if (check[tx][ty] == 2)
					return;
				else
					search(n, m, (l + 3) % 4);
			}

		}
		else
			search(n, m, (l + 3) % 4);
		//그자리에서 돌기만하면됨
	}
}
bool is_back(int n, int m, int l)
{
	if (l == 0)
	{
		int nx = n + dx[2];
		int ny = m + dy[2];
		if (check[nx][ny] == 2)
			return false;
	}
	else if (l == 1)
	{
		int nx = n + dx[3];
		int ny = m + dy[3];
		if (check[nx][ny] == 2)
			return false;
	}
	else if (l == 2)
	{
		int nx = n + dx[0];
		int ny = m + dy[0];
		if (check[nx][ny] == 2)
			return false;
	}
	else if (l == 3)
	{
		int nx = n + dx[1];
		int ny = m + dy[1];
		if (check[nx][ny] == 2)
			return false;
	}
	return true;
}
bool checking(int n, int m)
{
	int temp = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = n + dx[i];
		int ny = m + dy[i];
		if (check[nx][ny] == 1 || check[nx][ny] == 2)
			temp++;
	}
	if (temp == 4)
		return true;
	else
		return false;
}
void count()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (check[i][j] == 1)
			{
				cnt++;
			}
		}
	}

}