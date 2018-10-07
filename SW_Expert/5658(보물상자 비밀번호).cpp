#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;
vector<int> candidate;
void go(int *arr,int idx, int pow_num, int current, bool *mark)
{
	if (pow_num < 0)
	{
		for (int i = 0; i < candidate.size(); i++)
		{
			if (candidate[i] == current)
				return;
		}
		candidate.push_back(current);
		return;
	}
	int temp = (arr[idx] * pow(16, pow_num));
	current += temp;
	go(arr, idx + 1, pow_num - 1, current, mark);
}

int main(void)
{
	int T;
	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; testcase++)
	{
		int N, K;
		int arr[28];
		//bool mark[270000000] = {0,};
		bool mark[10] = { false, };
		candidate.clear();
		scanf("%d %d ", &N, &K);
		for (int i = 0; i < N; i++)
		{
			char temp;
			scanf("%1c", &temp);
			if ('0' <= temp&&temp <= '9')
				arr[i] = temp-'0';
			else if ('A' <= temp&&temp <= 'F')
				arr[i] = temp - 'A' + 10;
		}

		int cnt = N / 4;
		int divideidx = cnt;
		int max_pow_num = cnt-1;
		while (cnt--)//돌려주는 횟수
		{
			for (int i = 0; i <= N - divideidx; i = i + divideidx)
			{
				go(arr, i, max_pow_num,0,mark);
			}
			int temp = arr[N - 1];
			for (int i = N - 2; i >= 0; i--)
			{
				arr[i + 1] = arr[i];
			}
			arr[0] = temp;
		}
		sort(candidate.begin(), candidate.end(),greater<int>());
		printf("#%d %d\n", testcase, candidate[K - 1]);
	}
}
