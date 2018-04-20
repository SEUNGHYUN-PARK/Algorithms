#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int numarr[12];
int MIN = 1000000000;
int MAX = -1000000000;
int p, s, m, d;
int numcnt;
int index;
void go(int index, int plus, int sub, int mul, int div, int value)
{
	if (index == numcnt)
	{
		MAX = max(value, MAX);
		MIN = min(value, MIN);
		return;
	}
	if (plus < p)
		go(index + 1, plus + 1, sub, mul, div, value + numarr[index]);
	if (sub < s)
		go(index + 1, plus, sub + 1, mul, div, value - numarr[index]);
	if (mul<m)
		go(index + 1, plus, sub, mul + 1, div, value * numarr[index]);
	if (div < d)
		go(index + 1, plus, sub, mul, div + 1, value / numarr[index]);
}

int main(void)
{

	scanf("%d", &numcnt);
	for (int i = 0; i < numcnt; i++)
	{
		scanf("%d", &numarr[i]);
	}
	scanf("%d %d %d %d", &p, &s, &m, &d);
	go(1, 0, 0, 0, 0, numarr[0]);
	printf("%d\n%d\n", MAX, MIN);

}