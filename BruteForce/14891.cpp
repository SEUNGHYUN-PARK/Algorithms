#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int result;
int gear[5][8]; // 0�� �鳪������ �����ϲ� �Ÿ���
int cmd[101][2];
int cmd_cnt;
void right_go(int gearNum, int dir, int before[8], int energy);
void left_go(int gearNum, int dir, int before[8], int energy);
void go(int gearNum, int dir, int togo, int energy); //������1�̸� �������ִ� ���� �ְ� ������ 0
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
	} // ��ɾ� �Է¹���

	for (int i = 1; i <= cmd_cnt; i++)
		go(cmd[i][0], cmd[i][1], 0, 1);
	scoring();
	printf("%d\n", result);

}
void scoring()
{
	if (gear[1][0] == 1) // s���� 1
		result += 1;
	if (gear[2][0] == 1) // s���� 1
		result += 2;
	if (gear[3][0] == 1) // s���� 1
		result += 4;
	if (gear[4][0] == 1) // s���� 1
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
	if (dir == 1) // ������
	{
		for (int i = 7; i >= 1; i--)
		{
			swap(gear[gearNum][i], gear[gearNum][i - 1]);
		}
	}
	if (dir == -1) // ������
	{
		for (int i = 0; i < 7; i++)
			swap(gear[gearNum][i], gear[gearNum][i + 1]);
	}
}

void go(int gearNum, int dir, int togo, int energy) // gearNum�� dir �������� ������. //1 �ð� -1 �ݽð� 0 ���������� move�� 0�ϰ�� �������� �����̴°Ű� 1�̸� �������θ� 2�� ���������θ�
{
	int before[8];
	if (gearNum <= 0 || gearNum >= 5) // �����°� ���ߴ� ����
		return;
	gearcopy(before, gearNum); // ���� �� ����
	if (energy>0 && (dir == 1 || dir == -1))
		rotate(gearNum, dir);

	if (togo == 0) //�ʱ⵹�������� ��������� ������ �� �����ϱ�
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