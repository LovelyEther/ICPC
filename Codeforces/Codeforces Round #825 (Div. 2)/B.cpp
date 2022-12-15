#include <bits/stdc++.h>
using namespace std;

int t, n, a[100100];

void solve() {
	for (int i = 2; i < n; i ++) {
		int x = a[i-1] * a[i] / __gcd(a[i-1], a[i]);
		int y = a[i] * a[i+1] / __gcd(a[i], a[i+1]);
		if (__gcd(x, y) != a[i]) {
			puts("NO"); return;
		}
	}
	puts("YES");
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
		solve();
	}
	return 0;
}
