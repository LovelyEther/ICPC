#include <bits/stdc++.h>
using namespace std;

int t, n, a[111];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
		int ans = 0;
		for (int i = 2; i <= n; i ++) ans += (a[i] + a[1] * 2 - 2) / (a[1] * 2 - 1) - 1;
		printf("%d\n", ans);
	}
	return 0;
}
