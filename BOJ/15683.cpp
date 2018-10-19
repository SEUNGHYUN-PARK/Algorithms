#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <memory.h>
using namespace std;
int map[8][8];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int N, M;
typedef struct CAMERA
{
	int x;
	int y;
	int mode;
	int camera_type;
}camera;
vector<camera> v;
int res;

void mapcopy(bool copy[8][8], bool is_check[8][8])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			copy[i][j] = is_check[i][j];
		}
	}
}

int counting(bool is_check[8][8])
{
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (is_check[i][j] == false)
			{
				cnt++;
			}
		}
	}
	return cnt;
}

void check(int x, int y,int dir,bool is_check[8][8])
{
	is_check[x][y] = true;
	int nx = x + dx[dir];
	int ny = y + dy[dir];
	if (0 <= nx&&nx < N && 0 <= ny&&ny < M)
	{
		if (map[nx][ny] == 6)
			return;
		else
			check(nx, ny, dir, is_check);
	}
	else
		return;
}


void check_map(int camera_num, bool is_check[8][8])
{
	if (camera_num >= v.size())
	{
		int temp = counting(is_check);
		res = min(temp, res);
		return;
	}

	int mode = v[camera_num].mode;
	int x = v[camera_num].x;
	int y = v[camera_num].y;

	if (v[camera_num].camera_type == 1)
	{
		check(x, y, mode, is_check);
	}
	else if (v[camera_num].camera_type == 2)
	{
		if (mode == 0 || mode == 2)
		{
			check(x, y, 3, is_check);
			check(x, y, 1, is_check);
		}
		else if (mode == 1 || mode == 4)
		{
			check(x, y, 0, is_check);
			check(x, y, 2, is_check);
		}
	}
	else if (v[camera_num].camera_type == 3)
	{
		if (mode == 0)
		{
			check(x, y, 0, is_check);
			check(x, y, 1, is_check);
		}
		else if (mode == 1)
		{
			check(x, y, 1, is_check);
			check(x, y, 2, is_check);
		}
		else if (mode == 2)
		{
			check(x, y, 2, is_check);
			check(x, y, 3, is_check);
		}
		else if (mode == 3)
		{
			check(x, y, 3, is_check);
			check(x, y, 0, is_check);
		}
	}
	else if (v[camera_num].camera_type == 4)
	{
		if (mode == 0)
		{
			check(x, y, 0, is_check);
			check(x, y, 1, is_check);
			check(x, y, 3, is_check);
		}
		else if (mode == 1)
		{
			check(x, y, 0, is_check);
			check(x, y, 1, is_check);
			check(x, y, 2, is_check);
		}
		else if (mode == 2)
		{
			check(x, y, 1, is_check);
			check(x, y, 2, is_check);
			check(x, y, 3, is_check);
		}
		else if (mode == 3)
		{
			check(x, y, 0, is_check);
			check(x, y, 2, is_check);
			check(x, y, 3, is_check);
		}
	}
	else if (v[camera_num].camera_type == 5)
	{
		check(x, y, 0, is_check);
		check(x, y, 1, is_check);
		check(x, y, 2, is_check);
		check(x, y, 3, is_check);
	}
	check_map(camera_num + 1, is_check);

}

void choose_Camera_dir(int camera_num, bool is_check[8][8])
{
	bool copy[8][8];

	if (camera_num >= v.size())
	{
		check_map(0,is_check);
		return;
	}
	for (int k = 0; k < 4; k++)
	{
		mapcopy(copy, is_check);
		v[camera_num].mode = k;
		choose_Camera_dir(camera_num + 1,copy);
	}
}

int main(void)
{
	res = 65;
	scanf("%d %d", &N, &M);
	bool is_check[8][8];
	memset(is_check, false, sizeof(is_check));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &map[i][j]);
			if (1 <= map[i][j] && map[i][j] < 6)
			{
				camera t;
				t.camera_type = map[i][j];
				t.mode = 0;
				t.x = i;
				t.y = j;
				v.push_back(t);
				is_check[i][j] = true;
			}
			if (map[i][j] == 6)
				is_check[i][j] = true;
		}
	}

	choose_Camera_dir(0,is_check);
	printf("%d\n", res);


}
