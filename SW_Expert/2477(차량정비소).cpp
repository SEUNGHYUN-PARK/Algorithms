#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int res = 0;
int N, M, K, A, B; // 접수창구 정비창구 고객번호 지갑을 두고간 고객이 이용했던 접수창구와 수리창구
int guest_reception[1001] = { 0, }; // 손님이 이용한 리셉션 데스크번호배열
int guest_repair[1001] = { 0, }; // 손님이 이용한 리페어 데스크번호배열
int total = 0;
queue<pair<int,int> > guest_arrive_time; //t대신에 한거 쓰게 편하려고
queue<int> receptionqueue;
queue<int> repairqueue;

int checkRepair(pair<int, int> repairdesk[10], int b[10], int time)
{
	int cnt = 0;
	for (int i = 1; i <= M; i++)
	{
		if (repairdesk[i].first > 0 && repairdesk[i].second == b[i]) // 용무를 다 마쳤으니 해당 위치를 초기화 시켜줘야함
		{
			guest_repair[repairdesk[i].first] = i;
			repairdesk[i].first = 0;
			repairdesk[i].second = 0;
			total++;
		}
	}

	for (int i = 1; i <= M; i++)
	{
		if (repairdesk[i].first == 0 && repairdesk[i].second == 0)
		{
			cnt++;
		}
	}
	return cnt;
}



int checkReception(pair<int, int> receptiondesk[10], int a[10], int time)
{
	int cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		if (receptiondesk[i].first > 0 && receptiondesk[i].second == a[i]) // 용무를 다 마쳤으니 해당 위치를 초기화 시켜줘야함
		{
			guest_reception[receptiondesk[i].first] = i;
			repairqueue.push(receptiondesk[i].first);
			receptiondesk[i].first = 0;
			receptiondesk[i].second = 0;
		}
	}
	for (int i = 1; i <= N; i++)
	{
		if (receptiondesk[i].first == 0 && receptiondesk[i].second == 0)
		{
			cnt++;
		}
	}
	return cnt;
}

void go(pair<int, int> repairdesk[10], pair<int, int> receptiondesk[10], int a[10], int b[10], int time)
{
	//시간을 추가해줘야지
	for (int i = 1; i <= N; i++)
	{
		if (receptiondesk[i].first > 0)
			receptiondesk[i].second++;
	}
	for (int i = 1; i <= M; i++)
	{
		if (repairdesk[i].first > 0)
			repairdesk[i].second++;
	}

	int receptionRemain = checkReception(receptiondesk, a, time);

	// 공석만큼의 손님을 뽑아내기
	while (!guest_arrive_time.empty()&&receptionRemain>0 && guest_arrive_time.front().second < time)
	{
		receptionqueue.push(guest_arrive_time.front().first);
		guest_arrive_time.pop();
		receptionRemain--;
	}
	int k = 1;
	while (!receptionqueue.empty())
	{
		if (receptiondesk[k].first == 0)
		{
			receptiondesk[k].first = receptionqueue.front();
			receptionqueue.pop();
		}
		k++;
	}
	k = 1;
	int repairRemain = checkRepair(repairdesk, b, time);
	while (!repairqueue.empty() && repairRemain > 0)
	{
		if (repairdesk[k].first == 0)
		{
			repairdesk[k].first = repairqueue.front();
			repairRemain--;
			repairqueue.pop();
		}
		k++;
	}
}


int main(void)
{
	int T;
	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; testcase++)
	{
		//창구번호와 고객번호는 1로 시작
		int a[10]; // i번째 접수창구에서 걸리는 소모시간
		int b[10]; // i번째 정비창구에서 걸리는 소모시간

		pair<int, int> receptiondesk[10] = { { 0,0 }, }; // first : 고객번호, second : 고객이 오고나서 시간경과
		pair<int, int> repairdesk[10] = { { 0,0 }, }; // first : 고객번호, second : 고객이 오고나서 시간경과

		res = 0;
		total = 0;

		while (!guest_arrive_time.empty())
			guest_arrive_time.pop();
		while (!receptionqueue.empty())
			receptionqueue.pop();
		while (!repairqueue.empty())
			repairqueue.pop();
		scanf("%d %d %d %d %d", &N, &M, &K, &A, &B);
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &a[i]);
		}
		for (int i = 1; i <= M; i++)
		{
			scanf("%d", &b[i]);
		}
		for (int i = 1; i <= K; i++)
		{
			int temp;
			scanf("%d", &temp);
			guest_arrive_time.push(make_pair(i,temp));
		}
		int time = 0;
		while (total < K)
		{
			go(repairdesk, receptiondesk, a, b, time);
			time++;
		}
		for (int i = 1; i <= K; i++)
		{
			if (guest_reception[i] == A && guest_repair[i] == B)
				res += i;
		}
		if (res <= 0)
			res = -1;
		printf("#%d %d\n", testcase, res);

	}

}
