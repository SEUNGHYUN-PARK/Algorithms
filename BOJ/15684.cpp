#include <iostream>
#include <queue>
#include <cstdio>
#include <memory.h>
using namespace std;
int N, M, H;
int res;
int map[30][15];
int dx[] = { 0,0 };
int dy[] = { -1,1 };

bool check(int line) //라인체크
{
	bool ret = false;
	int temp = line;
	int level = 0;
	while (level<H)
	{
		if (map[level][temp] == map[level][temp + 1] && map[level][temp] > 0 && map[level][temp + 1] > 0)
			temp++;
		else if (map[level][temp] == map[level][temp - 1] && map[level][temp] > 0 && map[level][temp - 1] > 0)
			temp--;
		level++;
	}
	if (temp == line)
		ret = true;
	return ret;
}

void set_ladder(int curr, int ladder_cnt, int start, int bridge_num, int before_x, int before_y) // 사다리 설정
{
	if (curr == ladder_cnt)
	{
		//go();
		int correct = 0;
		for (int i = 0; i < N; i++)
		{
			if (check(i))
				correct++;
			else
				return;
		}
		if (correct == N)
		{
			res = min(res, curr);
		}
		return;
	}
	else
	{
		for (int i = start; i < H; i++)
		{
			for (int j = 0; j <= N - 2; j++)
			{
				if (map[i][j] == 0 && map[i][j + 1] == 0)
				{
					if (i == before_x)
					{
						if (j < before_y)
							continue;
					}
					map[i][j] = bridge_num;
					map[i][j + 1] = bridge_num;
					set_ladder(curr + 1, ladder_cnt, i, bridge_num + 1, i, j);
					map[i][j] = 0;
					map[i][j + 1] = 0;
				}
			}
		}
	}

}

int main(void)
{
	res = 987654321;
	scanf("%d %d %d", &N, &M, &H);
	int bridge_num = 1;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		map[a - 1][b] = bridge_num;
		map[a - 1][b - 1] = bridge_num;
		bridge_num++;
	}

	for (int ladder_cnt = 0; ladder_cnt <= 3; ladder_cnt++)
	{
		set_ladder(0, ladder_cnt, 0, bridge_num, 0, 0);
		if (0 <= res&&res <= 3)
			break;

	}
	if (res == 987654321)
		res = -1;
	printf("%d\n", res);
}
