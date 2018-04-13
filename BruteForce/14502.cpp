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
	queue<pair<int, int> > q; // ť�� �������
	for (int i = 0; i < v.size(); i++)
	{
		q.push(v[i]); //ť�����Ͱ��� �ִ����� : ���� �������� ť�� �̿��Ѵٸ� ���� �����۾���������ϱ⶧���� ���� ť�� ��
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
		makebackup(tmp); //���̷����� ��Ʈ������ �̸� �迭 ����
		bfs(); // ���̷����� ��Ʈ����
		result = max(result, scoring()); // 0�� �����ִ� �ִ뿵�� ����
		recover(tmp); // ��Ʈ���� ���� �����迭�̱⶧���� ���� ������ �������
		map[x][y] = 0; // �湮�ߴ��͵� �����������
		visited[x][y] = false; // �湮�ߴ��͵� �����������
		return;

	}
	for (int i = x; i<n; i++) // ������ �������� �� ���� ���� ������ n������� ��ġ (�ߺ�����) 1,4,5/ 4,5,1/ 5,4,1�� ���ΰ��� ���
	{
		for (int j = 0; j < m; j++)
		{
			if (visited[i][j] || map[i][j] != 0) continue;
			go(i, j, cnt + 1);
		}
	}
	map[x][y] = 0; //�湮�ߴ��͵� �����������
	visited[x][y] = false; //�湮�ߴ��͵� �����������

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

	for (int i = 0; i<n; i++) // ��� ������ Ž���� �õ�
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 0)
				go(i, j, 1);
		}

	printf("%d\n", result);
}