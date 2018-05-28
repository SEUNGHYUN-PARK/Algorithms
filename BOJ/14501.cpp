#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

int t[16]; // 걸리는 날
int p[16]; // 받는 금액
int N; // 날짜
int result;
void go(int day, int price)
{
	if (day == N+1)
	{
		result = max(price, result);
		return;
	}
	if (day + 1 <= N + 1)
		go(day + 1, price);
	if (day + t[day] <= N + 1)
		go(day + t[day], price + p[day]);

}
int main(void)
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d %d", &t[i], &p[i]);
	}
	go(1, 0);
	printf("%d\n", result);
}