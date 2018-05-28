#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int N, M;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int ex[4][3] = { {-1,0,1},{0,1,0},{1,0,-1},{0,-1,0} };
int ey[4][3] = { {0,1,0},{1,0,-1},{0,-1,0},{-1,0,1} };
int arr[501][501];
bool check[501][501];
int result;
void go(int cnt, int iidx, int jidx, int value)
{
	if (cnt == 4)
	{
		result = max(result, value);
		return;
	}
	for (int k = 0; k < 4; k++)
	{
		int nx = iidx + dx[k];
		int ny = jidx + dy[k];
		if (nx < 0 || nx >= N || ny < 0 || ny >= M)
			continue;
		if (check[nx][ny])
			continue;
		check[nx][ny] = true;
		go(cnt + 1, nx, ny, value + arr[nx][ny]);
		check[nx][ny] = false;
	}
}
void except(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int temp = arr[x][y];
		int k = 0;
		for (int j = 0; j < 3; j++)
		{
			int nx = x + ex[i][j];
			int ny = y + ey[i][j];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				break;
			temp += arr[nx][ny];
			k++;
		}
		if (k == 3)
		{
			result = max(temp, result);
		}
	}

}
int main(void)
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			check[i][j] = true;
			go(1, i, j, arr[i][j]);
			except(i,j);
			check[i][j] = false;
		}
	}
	printf("%d\n", result);
}