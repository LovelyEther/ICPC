#include <bits/stdc++.h>
using namespace std;

int t, n, a[100100];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
		int ans = a[n] - a[1];
		for (int i = 1; i < n; i ++) ans = max(ans, a[n] - a[i]);
		for (int i = 2; i <= n; i ++) ans = max(ans, a[i] - a[1]);
		for (int i = 1; i < n; i ++) ans = max(ans, a[i] - a[i+1]);
		printf("%d\n", ans);
	}
	return 0;
}
