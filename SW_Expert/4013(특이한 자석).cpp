#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

void rotateMagnetic(int magnetic[4][8], int rodir[4], int nth)
{
	int temp;
	if (rodir[nth] == 1)
	{
		temp = magnetic[nth][7];
		for (int i = 6; i >= 0; i--)
		{
			magnetic[nth][i + 1] = magnetic[nth][i];
		}
		magnetic[nth][0] = temp;
	}
	else if (rodir[nth] == -1)
	{
		temp = magnetic[nth][0];
		for (int i = 1; i <= 7; i++)
		{
			magnetic[nth][i - 1] = magnetic[nth][i];
		}
		magnetic[nth][7] = temp;
	}
	else
		return;
}

void checkRotate(int magnetic[4][8], int rodir[4], int nth, int dir)
{
	if (nth >= 0 && nth < 4)
	{
		if(rodir[nth]==2)
			rodir[nth] = dir;
		if (nth - 1 >= 0 && rodir[nth - 1] == 2) // 왼쪽
		{
			if(rodir[nth]==0)
				checkRotate(magnetic, rodir, nth - 1, 0);
			else if (magnetic[nth][6] != magnetic[nth - 1][2])
			{
				if (dir == 1)
					checkRotate(magnetic, rodir, nth - 1, -1);
				else if (dir == -1)
					checkRotate(magnetic, rodir, nth - 1, 1);
			}
			else
			{
				checkRotate(magnetic, rodir, nth - 1, 0);
			}
		}
		if (nth + 1 <= 3 && rodir[nth + 1] == 2) // 오른쪽
		{

			if (rodir[nth] == 0)
				checkRotate(magnetic, rodir, nth - 1, 0);
			else if (magnetic[nth][2] != magnetic[nth + 1][6])
			{
				if (dir == 1)
					checkRotate(magnetic, rodir, nth + 1, -1);
				else if (dir == -1)
					checkRotate(magnetic, rodir, nth + 1, 1);
			}
			else
			{
				checkRotate(magnetic, rodir, nth + 1, 0);
			}
		}
	}
}

int main(void)
{
	int T;
	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; testcase++)
	{
		queue<pair<int, int> > tasks;
		int magnetic[4][8];
		int taskcnt;
		int res = 0;
		scanf("%d", &taskcnt);
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				scanf("%d", &magnetic[i][j]);
			}
		}
		for (int i = 0; i < taskcnt; i++)
		{
			int magnum, dir;
			scanf("%d %d", &magnum, &dir);
			tasks.push(make_pair(magnum, dir));
		}
		// 0->1
		while (!tasks.empty())
		{
			int nth = tasks.front().first - 1;
			int dir = tasks.front().second;
			tasks.pop();
			int rodir[4] = { 2,2,2,2 };
			checkRotate(magnetic, rodir, nth, dir);
			for (int i = 0; i < 4; i++)
			{
				if (rodir[i] != 0)
					rotateMagnetic(magnetic, rodir, i);
				else
					continue;
			}
		}

		for (int i = 0; i < 4; i++)
		{
			if (magnetic[i][0] == 1)
			{
				if (i == 0)
					res += 1;
				else if (i == 1)
					res += 2;
				else if (i == 2)
					res += 4;
				else if (i == 3)
					res += 8;
			}
		}
		printf("#%d %d\n", testcase, res);
	}
}
