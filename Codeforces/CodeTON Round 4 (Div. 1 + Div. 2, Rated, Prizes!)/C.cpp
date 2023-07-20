#include <bits/stdc++.h>
using namespace std;

int t, n, m, c, d, a[100100];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d %d", &n, &c, &d);
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
		sort(a + 1, a + n + 1);
		m = unique(a + 1, a + n + 1) - a - 1;
		long long addi = 1ll * c * (n - m);
		long long ans = 1ll * c * m + d;
		for (int i = 1; i <= m; i ++) {
			ans = min(ans, 1ll * c * (m - i) + 1ll * d * (a[i] - i));
		}
		ans += addi;
		printf("%I64d\n", ans);
	}
	return 0;
}
