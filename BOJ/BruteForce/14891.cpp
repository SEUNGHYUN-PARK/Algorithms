#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int result;
int gear[5][8]; // 0번 톱나바퀴는 없으니께 거른다
int cmd[101][2];
int cmd_cnt;
void right_go(int gearNum, int dir, int before[8], int energy);
void left_go(int gearNum, int dir, int before[8], int energy);
void go(int gearNum, int dir, int togo, int energy); //에너지1이면 돌릴수있는 힘이 있고 없으면 0
void rotate(int gearNum, int dir);
void gearcopy(int temp[8], int gearNum);
void scoring();
int main(void)
{

	for (int i = 1; i <= 4; i++)
		for (int j = 0; j < 8; j++)
			scanf("%1d", &gear[i][j]);
	scanf("%d", &cmd_cnt);
	for (int i = 1; i <= cmd_cnt; i++)
	{
		scanf("%d %d", &cmd[i][0], &cmd[i][1]);
	} // 명령어 입력받음

	for (int i = 1; i <= cmd_cnt; i++)
		go(cmd[i][0], cmd[i][1], 0, 1);
	scoring();
	printf("%d\n", result);

}
void scoring()
{
	if (gear[1][0] == 1) // s극은 1
		result += 1;
	if (gear[2][0] == 1) // s극은 1
		result += 2;
	if (gear[3][0] == 1) // s극은 1
		result += 4;
	if (gear[4][0] == 1) // s극은 1
		result += 8;
}
void gearcopy(int temp[8], int gearNum)
{
	for (int i = 0; i < 8; i++)
	{
		temp[i] = gear[gearNum][i];
	}
}
void rotate(int gearNum, int dir)
{
	if (dir == 1) // 정방향
	{
		for (int i = 7; i >= 1; i--)
		{
			swap(gear[gearNum][i], gear[gearNum][i - 1]);
		}
	}
	if (dir == -1) // 역방향
	{
		for (int i = 0; i < 7; i++)
			swap(gear[gearNum][i], gear[gearNum][i + 1]);
	}
}

void go(int gearNum, int dir, int togo, int energy) // gearNum을 dir 방향으로 돌린다. //1 시계 -1 반시계 0 돌리지않음 move가 0일경우 양쪽으로 움직이는거고 1이면 왼쪽으로만 2면 오른쪽으로만
{
	int before[8];
	if (gearNum <= 0 || gearNum >= 5) // 돌리는걸 멈추는 시점
		return;
	gearcopy(before, gearNum); // 비교할 놈 만듦
	if (energy>0 && (dir == 1 || dir == -1))
		rotate(gearNum, dir);

	if (togo == 0) //초기돌렸을때는 양방향으로 움직일 수 있으니까
	{
		left_go(gearNum, dir, before, energy);
		right_go(gearNum, dir, before, energy);
	}
	if (togo == 1)
	{
		left_go(gearNum, dir, before, energy);
	}
	if (togo == 2)
	{
		right_go(gearNum, dir, before, energy);
	}
}
void left_go(int gearNum, int dir, int before[8], int energy)
{
	if (before[6] == gear[gearNum - 1][2])
	{
		go(gearNum - 1, 0, 1, 0);
	}
	if (before[6] != gear[gearNum - 1][2])
	{
		if (dir == 1)
			go(gearNum - 1, -1, 1, energy);
		else
			go(gearNum - 1, 1, 1, energy);
	}
}
void right_go(int gearNum, int dir, int before[8], int energy)
{
	if (before[2] == gear[gearNum + 1][6])
	{
		go(gearNum + 1, 0, 2, 0);
	}
	if (before[2] != gear[gearNum + 1][6])
	{
		if (dir == 1)
			go(gearNum + 1, -1, 2, energy);
		else
			go(gearNum + 1, 1, 2, energy);
	}
}