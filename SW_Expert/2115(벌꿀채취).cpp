#include <iostream>
#include <cstdio>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <functional>
using namespace std;
int T;
int N, M, C;
int map[10][10];
bool check[10][10];
vector<int> a, b;
int res;
int max_a, max_b;
void calculate_B(int idx,int remain,int total, bool check_B[10])
{
	if (idx >= b.size())
	{
		max_b = max(max_b, total);
		return;
	}
	for (int i = idx; i < b.size(); i++)
	{
		int temp = 0;
		if (check_B[i] == false && b[i] <= remain)
		{
			check_B[i] = true;
			temp += (b[i] * b[i]);
			calculate_B(idx + 1, remain - b[i], total + temp, check_B);
			check_B[i] = false;
		}
		else
			calculate_B(idx + 1, remain, total, check_B);

	}
}

void calculate_A(int idx,int remain,int total,bool check_A[10])
{
	if (idx >= a.size())
	{
		max_a = max(max_a, total);
		return;
	}
	for (int i = idx; i < a.size(); i++)
	{
		int temp = 0;
		if (check_A[i]==false&&a[i] <= remain)
		{
			temp += (a[i] * a[i]);
			check_A[i] = true;
			calculate_A(idx + 1, remain - a[i], total + temp, check_A);
			check_A[i] = false;
		}
		else
			calculate_A(idx + 1, remain, total, check_A);

	}
}

void select_B_honey(int x, int y)
{
	for (int i = x; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == x)
				if (j <= y)
					continue;
			if (j + M-1 < N)
			{
				int k;
				for (k = j; k < j + M; k++)
				{
					if (check[i][k] == false)
					{
						check[i][k] = true;
						b.push_back(map[i][k]);
					}
				}
				int remain = C;

				bool check_B[10] = {false,};

				calculate_B(0,remain,0,check_B);
				res = max(res, max_a + max_b);
				max_b = 0;


				for (k = j; k < j + M; k++)
				{
					if (check[i][k] == true)
					{
						check[i][k] = false;
						b.pop_back();
					}
				}

			}
		}
	}
}
void select_A_honey()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (j + M-1 < N)
			{
				int k;
				for (k = j; k < j + M; k++)
				{
					if (check[i][k] == false)
					{
						check[i][k] = true;
						a.push_back(map[i][k]);
					}
				}
				int remain = C;
				bool check_A[10] = {false,};
				calculate_A(0, remain, 0,check_A);
				select_B_honey(i, k-1);

				for (k = j; k < j + M; k++)
				{
					if (check[i][k] == true)
					{
						check[i][k] = false;
						a.pop_back();
					}
				}
				max_a = 0;


			}
		}
	}
}
int main(void)
{

	scanf("%d", &T);

	for (int testcase = 1; testcase <= T; testcase++)
	{
		res = 0;
		max_a = 0, max_b=0;
		memset(map, 0, sizeof(map));
		memset(check, false, sizeof(check));
		scanf("%d %d %d", &N, &M, &C);

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}
		select_A_honey();
		printf("#%d %d\n", testcase, res);

	}
}
