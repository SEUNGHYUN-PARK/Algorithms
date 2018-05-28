#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, l;
int map[100][100];
int result = 0;
int cnt;
void copyline(int temp[100], int line, int mode)
{
	if (mode == 0)
	{
		for (int i = 0; i < n; i++)
			temp[i] = map[line][i];
	}
	if (mode == 1)
	{
		for (int i = 0; i < n; i++)
			temp[i] = map[i][line];
	}
}
void go(int arr[100], int start, bool cover[100])
{
	if (start >= n - 1)
	{
		result++;
		return;
	}
	if (arr[start] == arr[start + 1])
	{
		go(arr, start + 1, cover);
	}
	else
	{
		if (arr[start] > arr[start + 1])
		{
			for (int i = start + 1; i <= start + l; i++)
			{
				if (i >= n || i < 0) return;
				if (arr[start] - arr[i] != 1 || cover[i] != false)
				{
					return;
				}
			}
			for (int i = start + 1; i <= start + l; i++)
			{
				cover[i] = true;
			}
			go(arr, start + l, cover);
		}
		else if (arr[start] < arr[start + 1])
		{
			for (int i = start; i >= start + 1 - l; i--)
			{
				if (i >= n || i < 0) return;
				if (arr[start + 1] - arr[i] != 1 || cover[i] != false)
				{
					return;
				}
			}
			for (int i = start; i >= start + 1 - l; i--)
			{
				cover[i] = true;
			}
			go(arr, start + 1, cover);
		}
	}
}
int main(void)
{
	scanf("%d %d", &n, &l);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	for (int i = 0; i <= 1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			bool cover[100] = { false, };
			int tmp[100];
			copyline(tmp, j, i);
			go(tmp, 0, cover);
		}
	}
	printf("%d\n", result);
}