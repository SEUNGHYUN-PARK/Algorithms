#include <iostream>
#include <cstdio>
using namespace std;
int map[5000];
int checkList[10][7] = {
	{ 0,0,0,1,1,0,1 }, //0
	{ 0,0,1,1,0,0,1 }, //1
	{ 0,0,1,0,0,1,1 }, //2
	{ 0,1,1,1,1,0,1 }, //3
	{ 0,1,0,0,0,1,1 }, //4
	{ 0,1,1,0,0,0,1 }, //5
	{ 0,1,0,1,1,1,1 }, //6
	{ 0,1,1,1,0,1,1 }, //7
	{ 0,1,1,0,1,1,1 }, //8
	{ 0,0,0,1,0,1,1 }, //9
};
void makemap(int row, int col)
{
	int length = row*col;
	for (int i = 0; i < length; i++)
	{
		scanf("%1d ", &map[i]);
	}
}
bool parsecheck(int start)
{
	int temp[7];
	int count = 0;
	int idx = 0;
	int k = start;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			temp[j] = map[k++];
		}


		for (int i = 0; i < 10; i++)
		{
			int cnt = 0;
			for (int j = 0; j < 7; j++)
			{
				if (checkList[i][j] == temp[j])
					cnt++;
				if (cnt == 7)
					count++;
			}
		}

	}
	if (count == 8)
		return true;
	else
		return false;
}
int is_normal_code(int start)
{
	int temp[7];
	int after[8];
	int idx = 0;
	int k = start;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			temp[j] = map[k++];
		}


		for (int i = 0; i < 10; i++)
		{
			int cnt = 0;
			for (int j = 0; j < 7; j++)
			{
				if (checkList[i][j] == temp[j])
					cnt++;
				if (cnt == 7)
					after[idx++] = i;
			}
		}
	}

	if (((after[0] + after[2] + after[4] + after[6]) * 3 + after[1] + after[3] + after[5] + after[7]) % 10 == 0)
		return after[0] + after[2] + after[4] + after[6] + after[1] + after[3] + after[5] + after[7];
	else
		return 0;
}

int main(void)
{
	int T;
	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; testcase++)
	{

		int res = 0;
		int row, col;
		for (int i = 0; i < 5000; i++)
		{
			map[i] = -1;
		}
		scanf("%d %d", &row, &col);
		makemap(row, col);
		for (int i = 0; i < row*col - 56; i++)
		{
			if (parsecheck(i))
			{
				res = is_normal_code(i);
				printf("#%d %d\n", testcase, res);
				break;
			}
		}
	}
}
