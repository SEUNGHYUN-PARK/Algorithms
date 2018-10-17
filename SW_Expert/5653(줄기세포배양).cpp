#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;

typedef struct CELL
{
	bool is_lock;
	int hp;
	int dead_time;
	int active_time;
	int condition; //없는세포0 죽은세포1 활성 2 비활성 3;
}CELL;

CELL map[355][355]; // 최대 300초 + CELL처음 크기 50을 설정(넉넉한 맵사이즈)

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

int main(void)
{
	int T;
	scanf("%d", &T);

	for (int testcase = 1; testcase <= T; testcase++)
	{
		int N, M, K;
		scanf("%d %d %d", &N, &M, &K);
		memset(map, 0, sizeof(map));
		for (int i = 0 + K / 2 + 1; i < N + K / 2 + 1; i++)
		{
			for (int j = 0 + K / 2 + 1; j < M + K / 2 + 1; j++)
			{
				scanf("%d", &map[i][j].hp);
				if (map[i][j].hp > 0)
				{
					map[i][j].active_time = map[i][j].hp;
					map[i][j].dead_time = map[i][j].active_time + map[i][j].hp;
					map[i][j].condition = 3;
					map[i][j].is_lock = true;
				}
			}
		}

		int map_N = N + K;
		int map_M = M + K;
		for (int k = 0; k <= K; k++)
		{
			for (int i = 0; i < map_N; i++)
			{
				for (int j = 0; j < map_M; j++)
				{
					if (map[i][j].hp == 0)
						continue;
					if (map[i][j].condition == 1)
						continue;
					if (map[i][j].hp > 0)
					{
						if (map[i][j].condition == 3 && k == map[i][j].active_time)
						{
							map[i][j].condition = 2;
						}
						if (map[i][j].condition == 2 && k == map[i][j].active_time + 1)
						{
							//퍼트려주자
							for (int dir = 0; dir < 4; dir++)
							{
								int nx = i + dx[dir];
								int ny = j + dy[dir];
								if (map[nx][ny].hp == 0 || (map[nx][ny].is_lock == false && map[nx][ny].condition == 3))
								{
									if (map[nx][ny].hp < map[i][j].hp)
									{
										map[nx][ny].hp = map[i][j].hp;
										map[nx][ny].active_time = k + map[nx][ny].hp;
										map[nx][ny].dead_time = map[nx][ny].active_time + map[nx][ny].hp;
										map[nx][ny].is_lock = false;
										map[nx][ny].condition = 3;
									}
								}
							}
						}
						if (map[i][j].condition == 2 && k == map[i][j].dead_time)
						{
							map[i][j].condition = 1;
						}
					}
				}
			}

			//모든 셀 락은 여기서 걸어주자
			for (int i = 0; i < map_N; i++)
			{
				for (int j = 0; j < map_M; j++)
				{
					if (map[i][j].hp > 0 && map[i][j].is_lock == false)
						map[i][j].is_lock = true;
				}
			}
		}

		int res = 0;
		for (int i = 0; i <= map_N; i++)
		{
			for (int j = 0; j <= map_M; j++)
			{
				if (map[i][j].condition == 2 || map[i][j].condition == 3)
					res++;
			}
		}

		printf("#%d %d\n", testcase, res);
	}
}
