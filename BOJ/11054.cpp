#include <cstdio>
int a[1000];
int d[1000]; // 가장 긴 증가하는 부분 수열
int d2[1000]; // 가장 긴 감소하는 부분 수열
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i<n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i<n; i++) {
		d[i] = 1;
		for (int j = 0; j<i; j++) {
			if (a[j] < a[i] && d[j] + 1 > d[i]) {
				d[i] = d[j] + 1;
			}
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		d2[i] = 1;
		for (int j = i + 1; j<n; j++) {
			if (a[i] > a[j] && d2[j] + 1 > d2[i]) {
				d2[i] = d2[j] + 1;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i<n; i++) {
		if (ans < d[i] + d2[i] - 1) {
			ans = d[i] + d2[i] - 1;
		}
	}

	printf("%d\n", ans);
	return 0;
}