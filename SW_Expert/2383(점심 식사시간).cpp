#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <math.h>
using namespace std;

int main(void)
{
	int T;
	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; testcase++)
	{
		int N;
		scanf("%d", &N);
		int map[10][10];
		int time = 987654321;
		vector<pair<int, int > > people;
		vector<pair<int, int> > stair;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf("%d", &map[i][j]);
				if(map[i][j]==1)
					people.push_back(make_pair(i, j));
				if(map[i][j]>=2)
					stair.push_back(make_pair(i, j));
			}
		}
		int zeroneed = map[stair[0].first][stair[0].second];
		int oneneed = map[stair[1].first][stair[1].second];
		for (int ZEROCNT = N-1; ZEROCNT >= 1; ZEROCNT--)
		{
			vector<int> selectstair;
			for (int i = 0; i <= ZEROCNT; i++)
			{
				selectstair.push_back(0);
			}
			for (int i = 0; i < N - ZEROCNT; i++)
			{
				selectstair.push_back(1);
			}
			do {
				int temp = 0;
				vector<int> entertime;
				vector<bool> check;
				for (int i = 0; i < people.size(); i++)
				{
					if (selectstair[i] == 0)
					{
						entertime.push_back(abs(people[i].first - stair[0].first) + abs(people[i].second - stair[0].second) + 1);
					}
					else
					{
						entertime.push_back(abs(people[i].first - stair[1].first) + abs(people[i].second - stair[1].second) + 1);
					}
					check.push_back(false);
				}
				queue<int> zero;
				queue<int> one;

				while (true)
				{
					while (!zero.empty() && zero.front() == temp)
						zero.pop();
					while (!one.empty() && one.front() == temp)
						one.pop();

					for (int i = 0; i < entertime.size(); i++)
					{
						if (check[i] == true)
							continue;

						if (entertime[i] <= temp)
						{
							if (selectstair[i] == 0 && zero.size() < 3)
							{
								zero.push(temp+zeroneed);
								check[i] = true;
							}

							else if (selectstair[i] == 1 && one.size() < 3)
							{
								one.push(temp+oneneed);
								check[i] = true;
							}
						}
					}
					int cnt = 0;
					for (int i = 0; i < check.size(); i++)
					{
						if (check[i] == true)
							cnt++;
						else
							break;
					}
					if (cnt == check.size() && zero.empty() && one.empty())
					{
						time = min(time, temp);
						break;
					}
					else
					{
						temp++;
					}
				}
			}
			while (next_permutation(selectstair.begin(), selectstair.end()));
		}
		printf("#%d %d\n", testcase, time);
	}
}
