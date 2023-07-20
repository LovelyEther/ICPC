#include <bits/stdc++.h>
using namespace std;

#define N 200200

int t, n, a[N], b[N], cnt[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), b[i] = a[i];
		if (n == 2) {
			puts("1"); continue;
		}
		sort(b + 1, b + n + 1);
		if (b[1] == b[n]) {
			printf("%d\n", n / 2); continue;
		}
		int m = unique(b + 1, b + n + 1) - b;
		for (int i = 1; i <= m; i ++) cnt[i] = 0;
		for (int i = 1; i <= n; i ++) {
			int p = lower_bound(b + 1, b + m + 1, a[i]) - b;
			cnt[p] ++;
		}
		long long ans = 0;
		int sum = 0;
		for (int i = 1; i <= m; i ++) {
			sum += cnt[i];
			ans = max(ans, 1ll * sum * (n - sum));
		}
		printf("%I64d\n", ans);
	}
	return 0;
}
