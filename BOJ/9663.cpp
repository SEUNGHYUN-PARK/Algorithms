#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>

int N;
int arr[14]; // i��° ������ ���� ���� ��ǥ�� ���� �迭
int cnt;
bool check(int level)
{
	for (int i = 0; i < level; i++) 
	{
		// �� LEVEL�� ���� ��ǥ���� i��°�� �����ϴٸ�  
		// �ٷ� ���� �Ʒ��� �ǹ�
		//�Ǵ� 
		if (arr[i] == arr[level] || abs(level - i) == abs(arr[level] - arr[i]))
			return false;
	}
	return true;
}
void go(int level)
{
	if (level == N) // ���پ� üũ�Ұ�
	{
		cnt++;
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			arr[level] = i; // LEVEL���� ���������� �� ����� arr[0] =0 1 2 3
			if (check(level))//üũ�� ���ؼ� ���ϵǴ� ���� Ʈ���
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