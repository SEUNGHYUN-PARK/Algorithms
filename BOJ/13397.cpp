#include <iostream>
#include <vector>
using namespace std;
int go(vector<int> &a, int mid) {
	int n = a.size();
	int t1 = a[0];
	int t2 = a[0];
	int ans = 1;
	for (int i = 1; i<n; i++) {
		if (t1 > a[i]) {
			t1 = a[i];
		}
		if (t2 < a[i]) {
			t2 = a[i];
		}
		if (t2 - t1 > mid) {
			ans += 1;
			t1 = a[i];
			t2 = a[i];
		}
	}
	return ans;
}
int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	int l = 0;
	int r = 0;
	for (int i = 0; i<n; i++) {
		cin >> a[i];
		if (r < a[i]) {
			r = a[i];
		}
	}
	int ans = r;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (go(a, mid) <= k) {
			r = mid - 1;
			if (ans > mid) {
				ans = mid;
			}
		}
		else {
			l = mid + 1;
		}
	}
	cout << ans << '\n';
	return 0;
}