#include <iostream>
#include <cstdio>
using namespace std;
int MAX;


int power(int cnt)
{
	int temp = 1;
	for (int i = 0; i < cnt; i++)
		temp *= 10;

	return temp;
}

int maxret(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}


void shuffle(int _numArr[], int numlength, int cnt,int targetcnt)
{

	if (cnt > targetcnt)
	{
		int res=0;
		int digit = 0;
		for (int i = 5; i >= 6-numlength; i--)
		{
			res += _numArr[i] * power(digit++);
		}
		MAX = maxret(res, MAX);
		return;
	}
	int arr[6] = {0,};

	for (int i = 6-numlength; i <= 3; i++)
	{
		for (int j = i+1; j < 6; j++)
		{
			for (int k = 6 - numlength; k < 6; k++)
			{
				arr[k] = _numArr[k];
			}

			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;

			shuffle(arr, numlength, cnt + 1, targetcnt);
		}
	}
}


int main(void)
{
	int T;
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++)
	{
		MAX = -1;
		int numArr[6] = {0,};
		int numidx;
		int temp;
		int num, changecnt,numlength=0;
		scanf("%d %d", &num, &changecnt);

		temp = num;
		while (temp > 0)
		{
			temp /= 10;
			numlength++;
		}
		numidx = 5;

		temp = num;
		while (temp > 0)
		{
			numArr[numidx--] = temp % 10;
			temp /= 10;
		}

		shuffle(numArr,numlength,0,changecnt/2);
		printf("#%d %d\n", test_case, MAX);
	}
}
