#include <cstdio>
int a[1000];
int d[1000]; // a[i]까지의 수열이 있을때, a[i]를 마지막으로 하는 가장 긴 증가하는 부분수열의 길이
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i<n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i<n; i++) {
		d[i] = 1;
		for (int j = 0; j<i; j++) {
			if (a[j] < a[i] && d[i] < d[j] + 1) {
				d[i] = d[j] + 1; 
			}
		}
	}
	int ans = d[0];
	for (int i = 0; i<n; i++) {
		if (ans < d[i]) {
			ans = d[i];
		}
	}
	printf("%d\n", ans);
	return 0;
}