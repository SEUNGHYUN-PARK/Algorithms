#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int room[1000000];
int  n;
int  b, c;
long long  res;
void go(int roomNum, int a, int b_cnt, int c_cnt) // a는 방마다 남은 학생수 roomNum은 방번호
{

	if (b_cnt == 0)
	{
		a = a - b;
		b_cnt++;
	}
	if (a > 0)
	{
		c_cnt = a / c;
		if (a%c != 0)
			c_cnt++;
		a = a / c;
	}
	long long temp = b_cnt + c_cnt;
	res += temp;
}

int main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &room[i]);
	}
	scanf("%d %d", &b, &c);
	for (int i = 0; i < n; i++)
	{
		go(i, room[i], 0, 0);
	}
	printf("%lld\n", res);
}