#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main(void)
{
	int T;
	scanf("%d", &T);

	for (int testcase = 1; testcase <= T; testcase++)
	{
		int N;
		int map[20][20];
		int res = 999999;
		scanf("%d", &N);

		vector<int> v;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}
		for (int i = 0; i < N / 2; i++)
		{
			v.push_back(0);
		}
		for (int i = 0; i < N / 2; i++)
		{
			v.push_back(1);
		}

		do {
			vector<int> zeroidx;
			vector<int> oneidx;
			int zerosum = 0;
			int onesum = 0;
			for (int i = 0; i < v.size(); i++)
			{
				if (v[i] == 0)
					zeroidx.push_back(i);
				else
					oneidx.push_back(i);
			}
			for (int i = 0; i < zeroidx.size(); i++)
			{
				for (int j = 0; j < zeroidx.size(); j++)
				{
					zerosum += map[zeroidx[i]][zeroidx[j]];
				}
			}

			for (int i = 0; i < oneidx.size(); i++)
			{
				for (int j = 0; j < oneidx.size(); j++)
				{
					onesum += map[oneidx[i]][oneidx[j]];
				}
			}

			res = min(res, abs(zerosum - onesum));

		} while (next_permutation(v.begin(),v.end()));

		printf("#%d %d\n", testcase, res);
	}
}
