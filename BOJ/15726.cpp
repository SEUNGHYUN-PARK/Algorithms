#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int arr[3];
int ret = -987654321;
void go(int idx, double current,int m,int d)
{
	double temp;
	if (idx == 2)
	{
		int cur = int(current);
		ret = max(ret, cur);
		return;
	}

	if (m < 1)
	{
		temp = current*arr[idx + 1];
		go(idx + 1, temp, m + 1, d);
	}
	if(d<1)
	{
		temp = current/arr[idx + 1];
		go(idx + 1, temp, m, d + 1);
	}

}
int main(void)
{
	for (int i = 0; i < 3; i++)
	{
		scanf("%d", &arr[i]);
	}
	go(0,arr[0],0,0);
	printf("%d\n", ret);
}