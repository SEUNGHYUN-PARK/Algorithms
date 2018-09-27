#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int T;
int D, W, K;
int min_cnt;

void makecopy(int film[13][20],int copy[13][20])
{
	for (int i = 0; i < D; i++)
	{
		for (int j = 0; j < W; j++)
		{
			copy[i][j] = film[i][j];
		}
	}

}
void checking(int copy[13][20],int changecnt)
{
	int correctcnt = 0;
	for (int i = 0; i < W; i++) // 여러 줄 중에
	{
		int temp[13];
		for (int j = 0; j < D; j++)
		{
			temp[j] = copy[j][i];
		} //한줄을 긁어왔고

		for (int i = 0; i <= D - K; i++)
		{
			int zerocnt = 0;
			int onecnt = 0;
			for (int j = i; j < i + K; j++)
			{
				if (temp[j] == 0)
					zerocnt++;
				else if (temp[j] == 1)
					onecnt++;
			}
			if (zerocnt == K || onecnt == K)
			{
				correctcnt++;
				break;
			}
		}
	}
	if (correctcnt == W)
	{
		min_cnt = min(min_cnt, changecnt);
	}
}
void spread(int copy[13][20], vector<bool> check, vector<int> a_or_b)
{
	int k = 0;
	int changecnt = 0;
	for (int i = 0; i < check.size(); i++)
	{
		if (check[i] == true)
		{
			for (int j = 0; j < W; j++)
			{
				copy[i][j] = a_or_b[k];
			}
			k++;
			changecnt++;
		}
	}
	checking(copy,changecnt);
}


void go(int film[13][20], vector<bool> check, int truecnt)
{
	vector<int> a_or_b;
	int copy[13][20];

	for (int abcnt = 0; abcnt <= truecnt; abcnt++)
	{
		for (int a = truecnt - abcnt; a > 0; a--)
		{
			a_or_b.push_back(0);
		}
		for (int b = 0; b < abcnt; b++)
		{
			a_or_b.push_back(1);
		}

		do
		{
			makecopy(film,copy);
			spread(copy,check, a_or_b);
			a_or_b.clear();
		} while (next_permutation(a_or_b.begin(), a_or_b.end()));
	}
}


int main(void)
{
	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; testcase++)
	{
		int film[13][20];
		scanf("%d %d %d", &D, &W, &K);
		min_cnt = 2100000000;
		for (int i = 0; i < D; i++)
		{
			for (int j = 0; j < W; j++)
			{
				scanf("%d", &film[i][j]);
			}
		}

		for (int D_cnt = 0; D_cnt <= D; D_cnt++)
		{
			int truecnt = D_cnt;
			vector<bool> check; // 0,1은 칠할지 안칠할지
			for (int i = D-D_cnt; i > 0; i--)
			{
				check.push_back(false);
			}
			for (int i = 0; i < D_cnt; i++)
			{
				check.push_back(true);
			}
			do
			{
				go(film, check,truecnt);
				if (min_cnt != 2100000000)
					break;
			} while (next_permutation(check.begin(),check.end()));
		}

		printf("#%d %d\n", testcase, min_cnt);

	}
}
