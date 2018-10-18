#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int N;
int X, Y, DIR, K;

typedef struct ATOM
{
	int x;
	int y;
	int dir;
	int k;
}ATOM;
ATOM atom_arr[1001];
int map[4005][4005];

int main(void)
{
	int T;
	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; testcase++)
	{
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			scanf("%d %d %d %d", &X, &Y, &DIR, &K);
			X += 1000;
			Y += 1000;
			X *= 2;
			Y *= 2;
			atom_arr[i].x = 4000 - Y;
			atom_arr[i].y = X;
			atom_arr[i].dir = DIR;
			atom_arr[i].k = K;
			map[atom_arr[i].x][atom_arr[i].y] += atom_arr[i].k;
		}

		int res = 0;
		for (int t = 1; t <= 4005; t++)
		{
			register int i, j;
			for (i = 0; i < N; i++) // move_atom
			{
				if (atom_arr[i].k > 0)
				{
					map[atom_arr[i].x][atom_arr[i].y] = 0;
					switch (atom_arr[i].dir)
					{
						//상하좌우
					case 0:
						atom_arr[i].x--;
						break;
					case 1:
						atom_arr[i].x++;
						break;
					case 2:
						atom_arr[i].y--;
						break;
					case 3:
						atom_arr[i].y++;
						break;
					}
					if (0 <= atom_arr[i].x && atom_arr[i].x < 4005 && 0 <= atom_arr[i].y &&atom_arr[i].y < 4005)
						map[atom_arr[i].x][atom_arr[i].y] += atom_arr[i].k;
					else
						atom_arr[i].k = 0;
				}
			}

			for (i = 0; i < N; i++)
			{
				if (atom_arr[i].k > 0)
				{
					if (atom_arr[i].k < map[atom_arr[i].x][atom_arr[i].y])
					{
						atom_arr[i].k = 0;
						for (j = i + 1; j < N; j++)
						{
							if (atom_arr[i].x == atom_arr[j].x && atom_arr[i].y == atom_arr[j].y)
								atom_arr[j].k = 0;
						}
						res += map[atom_arr[i].x][atom_arr[i].y];
						map[atom_arr[i].x][atom_arr[i].y] = 0;
					}
				}
			}
		}
		printf("#%d %d\n", testcase, res);
	}
}
