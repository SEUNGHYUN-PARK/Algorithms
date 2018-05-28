#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int map[8][8];
bool visited[8][8];
int result;
vector<pair<int, int> > v;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int scoring()
{
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 0) res++;
		}
	}
	return res;
}
void makebackup(int arr[][8])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = map[i][j];
		}
	}
}
void recover(int arr[][8])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			map[i][j] = arr[i][j];
		}
	}
}

void bfs()
{
	queue<pair<int, int> > q; // 큐를 만들어줌
	for (int i = 0; i < v.size(); i++)
	{
		q.push(v[i]); //큐에벡터값을 넣는이유 : 만약 전역으로 큐를 이용한다면 따로 복원작업을해줘야하기때문에 지역 큐를 씀
	}
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx&&nx < n && 0 <= ny&&ny < m)
			{
				if (map[nx][ny] == 0)
				{
					map[nx][ny] = 2;
					q.push(make_pair(nx, ny));
				}
			}

		}

	}
}
void go(int x, int y, int cnt)
{
	map[x][y] = 1;
	visited[x][y] = true;
	if (cnt == 3)
	{
		int tmp[8][8];
		makebackup(tmp); //바이러스를 퍼트리기전 미리 배열 저장
		bfs(); // 바이러스를 퍼트려줌
		result = max(result, scoring()); // 0이 남아있는 최대영역 산출
		recover(tmp); // 퍼트려준 맵은 전역배열이기때문에 따로 복원을 해줘야함
		map[x][y] = 0; // 방문했던것들 리턴해줘야함
		visited[x][y] = false; // 방문했던것들 리턴해줘야함
		return;

	}
	for (int i = x; i<n; i++) // 한점을 정했으면 그 점의 행을 포함해 n행까지만 서치 (중복방지) 1,4,5/ 4,5,1/ 5,4,1은 전부같은 경우
	{
		for (int j = 0; j < m; j++)
		{
			if (visited[i][j] || map[i][j] != 0) continue;
			go(i, j, cnt + 1);
		}
	}
	map[x][y] = 0; //방문했던것들 리턴해줘야함
	visited[x][y] = false; //방문했던것들 리턴해줘야함

}
int main(void)
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i<n; i++)
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2)
			{
				v.push_back(make_pair(i, j));
			}
		}

	for (int i = 0; i<n; i++) // 모든 점에서 탐색을 시도
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 0)
				go(i, j, 1);
		}

	printf("%d\n", result);
}