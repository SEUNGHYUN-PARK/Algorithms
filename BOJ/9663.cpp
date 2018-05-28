#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>

int N;
int arr[14]; // i번째 레벨에 퀸을 놓는 좌표를 적는 배열
int cnt;
bool check(int level)
{
	for (int i = 0; i < level; i++) 
	{
		// 각 LEVEL에 놓은 좌표값과 i번째와 동일하다면  
		// 바로 한줄 아래를 의미
		//또는 
		if (arr[i] == arr[level] || abs(level - i) == abs(arr[level] - arr[i]))
			return false;
	}
	return true;
}
void go(int level)
{
	if (level == N) // 한줄씩 체크할거
	{
		cnt++;
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			arr[level] = i; // LEVEL별로 시작지점을 다 잡아줌 arr[0] =0 1 2 3
			if (check(level))//체크를 통해서 리턴되는 값이 트루면
				go(level + 1);
		}
	}
	

}

int main(void)
{
	scanf("%d", &N);
	go(0);
	printf("%d\n", cnt);
}