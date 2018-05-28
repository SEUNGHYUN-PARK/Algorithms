#include <iostream>
using namespace std;
long long d[91][2];
int main(void)
{
	int n;
	d[1][0] = 0;
	d[1][1] = 1;
	scanf("%d", &n);

	for (int i = 2; i <= n; i++)
	{
		d[i][0] = d[i - 1][0] + d[i - 1][1];
		d[i][1] = d[i - 1][0];
	}
	long long ans = d[n][0] + d[n][1];
	printf("%lld\n", ans);
}