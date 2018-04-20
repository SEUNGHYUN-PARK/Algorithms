#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int n, m;
int x, y;
int k;
int map[20][20];
int dx[] = { 0,0,0,-1,1 }; //0은 아무 의미없고
int dy[] = { 0,1,-1,0,0 }; // 1동 2서 3북 4남
queue <int> q;
int top, down, front, back, lef, rig;
void go(int xpos, int ypos, int dir) //xpos,ypos는 주사위의 위치
{
	int tmp1 = top, tmp2 = down, tmp3 = front, tmp4 = back, tmp5 = lef, tmp6 = rig;
	if (dir == 1)
	{
		rig = tmp1;
		lef = tmp2;
		top = tmp5;
		down = tmp6;
	}
	else if (dir == 2)
	{
		lef = tmp1;
		rig = tmp2;
		down = tmp5;
		top = tmp6;
	}
	else if (dir == 3)
	{
		back = tmp1;
		front = tmp2;
		top = tmp3;
		down = tmp4;
	}
	else if (dir == 4)
	{
		down = tmp3;
		top = tmp4;
		front = tmp1;
		back = tmp2;
	}


	if (map[xpos][ypos] == 0)
		map[xpos][ypos] = down;
	else if (map[xpos][ypos] != 0)
	{
		down = map[xpos][ypos];
		map[xpos][ypos] = 0;
	}
	printf("%d\n", top);
}
int main(void)
{
	scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);
	for (int i = 0; i<n; i++)
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &map[i][j]);
		}

	for (int i = 0; i < k; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		q.push(tmp);
	}
	while (!q.empty())
	{
		int nx = x + dx[q.front()];
		int ny = y + dy[q.front()];
		if (0 <= nx&&nx < n && 0 <= ny&&ny < m)
		{
			go(nx, ny, q.front());
			x = nx;
			y = ny;
		}
		q.pop();
	}
}