#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int map[20][20];
int zero[20][20];
int first[20][20];
int second[20][20];
int third[20][20];
int fourth[20][20];
int n;
int tmp[20];
int result;
int tarr[30] = { 0, };
int cursor;

void makebackup(int cnt)
{
	if (cnt == 0)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				zero[i][j] = map[i][j];
			}
		}
	}
	if (cnt == 1)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				first[i][j] = map[i][j];
			}
		}
	}
	if (cnt == 2)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				second[i][j] = map[i][j];
			}
		}
	}
	if (cnt == 3)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				third[i][j] = map[i][j];
			}
		}
	}
	if (cnt == 4)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				fourth[i][j] = map[i][j];
			}
		}
	}
}
void recover(int cnt)
{
	if (cnt == 1)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				map[i][j] = zero[i][j];
			}
		}
	}
	if (cnt == 2)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				map[i][j] = first[i][j];
			}
		}
	}
	if (cnt == 3)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				map[i][j] = second[i][j];
			}
		}
	}
	if (cnt == 4)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				map[i][j] = third[i][j];
			}
		}
	}
	if (cnt == 5)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				map[i][j] = fourth[i][j];
			}
		}
	}
}
void calmax()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			result = max(result, map[i][j]);
		}
	}//  최고값구하는 함수
}
void recover_line(int rcNum, int mode)
{
	if (mode == 0)
	{
		for (int i = 0; i < n; i++)
		{
			map[rcNum][i] = tmp[n - 1 - i];
		}
	}
	if (mode == 1)
	{
		for (int i = 0; i < n; i++)
		{
			map[i][rcNum] = tmp[n - 1 - i];
		}
	}
	if (mode == 2)
	{
		for (int i = 0; i < n; i++)
		{
			map[rcNum][i] = tmp[i];
		}
	}
	if (mode == 3)
	{
		for (int i = 0; i < n; i++)
		{
			map[i][rcNum] = tmp[i];
		}
	}
}
void extract(int rcNum,int mode)
{
	if (mode == 0)
	{
		for (int i = 0; i < n; i++)
		{ 
			tmp[i] = map[rcNum][n - 1 - i];
		}
	}
	if (mode == 1)
	{
		for (int i = 0; i < n; i++)
		{
			tmp[i] = map[n-1-i][rcNum];
		}
	}
	if (mode == 2)
	{
		for (int i = 0; i < n; i++)
		{
			tmp[i] = map[rcNum][i];
		}
	}
	if (mode == 3)
	{
		for (int i = 0; i < n; i++)
		{
			tmp[i] = map[i][rcNum];
		}
	}
}
void cal(int cursor)
{
	int temp[30] = { 0, };
	int tempcursor = 0;
	for (int i = 0; i < n; i++)
	{
		if (tmp[i] != 0)
		{
			temp[tempcursor] = tmp[i];
			tempcursor++;
		}
			
	}
	for (int i = 0; i < n; i++)
	{
		if (temp[i] == temp[i + 1])
		{
			tarr[cursor] = temp[i] + temp[i + 1];
			i++; cursor++;
		}
		else
		{
			tarr[cursor] = temp[i];
			cursor++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		tmp[i] = tarr[i];
	}
}

void move(int mode) // n번쨰줄까지 전부다 옮겨줘야 한번의 move
{
	bool check = false;// 
	for (int i = 0; i < n; i++)
	{
		extract(i, mode);  //매 줄tmp로 이용해 추출
		cursor = 0;
		for (int i = 0; i < 30; i++)
			tarr[i] = 0;
		cal(cursor);
		recover_line(i,mode);
	}
}
void go(int dir,int cnt) //cnt번째 시도
{
	if (cnt >5)
	{
		return;
	}
	for (int i = 0; i < 4; i++) // 4방향으로 들어가는루프
	{
		move(i);
		makebackup(cnt); // 들어가면서 현재상태 저장
		calmax();
		go(i,cnt+1);
		recover(cnt);
	}

}
int main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	makebackup(0);
	for (int i = 0; i < 4; i++)
	{
		go(i,1);
		recover(1);
	}
	printf("%d\n", result);
}