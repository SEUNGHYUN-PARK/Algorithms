#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	vector<int> v;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int temp;
		scanf("%d", &temp);
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	printf("%d\n", v[n / 2]);
}