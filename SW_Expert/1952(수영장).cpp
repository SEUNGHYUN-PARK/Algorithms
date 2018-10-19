#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int res;
int daily_price;
int monthly_price;
int threemonth_price;
int yearly_price;

void go(int plan[12], int current_month, int total)
{
	if (current_month >= 12)
	{
		if(total>0 && total<res)
			res = min(total, res);
		return;
	}
	if (plan[current_month] == 0)
		go(plan,current_month + 1, total);

	if (plan[current_month] > 0)
	{
		int temp = daily_price*plan[current_month];
		go(plan, current_month + 1, total + temp);
		go(plan, current_month + 1, total + monthly_price);
	}
	if (current_month == 0 && plan[current_month] > 0)
	{
		go(plan, current_month + 12, total + yearly_price);
	}
	if (current_month<10)
	{
		go(plan, current_month + 3, total + threemonth_price);
	}
}

int main(void)
{
	int T;
	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; testcase++)
	{
		res = 987654321;

		int plan[12] = { 0, };
		scanf("%d %d %d %d", &daily_price, &monthly_price, &threemonth_price, &yearly_price);
		for (int i = 0; i < 12; i++)
		{
			scanf("%d", &plan[i]);
		}
		go(plan,0, 0);
		printf("#%d %d\n", testcase, res);
	}
}
