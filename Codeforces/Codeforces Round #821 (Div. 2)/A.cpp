#include <bits/stdc++.h>
using namespace std;

int t, n, k, mx[100100];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &n, &k);
		for (int i = 0; i < k; i ++) mx[i] = 0;
		for (int i = 1; i <= n; i ++) {
			int x;
			scanf("%d", &x);
			mx[i%k] = max(mx[i%k], x);
		}
		long long ans = 0;
		for (int i = 0; i < k; i ++) ans += mx[i];
		printf("%I64d\n", ans);
	}
	return 0;
}
