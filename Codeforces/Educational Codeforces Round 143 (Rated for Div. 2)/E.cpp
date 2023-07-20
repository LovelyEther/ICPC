#include <bits/stdc++.h>
using namespace std;

#define N 300300

int t, n, mn[N], a[N], b[N];
long long f[N], g[N];

void add(int x, int val) {
	while (x <= n) mn[x] = min(mn[x], val), x += x & -x;
}

int calc(int x) {
	int rlt = 1e9;
	while (x) rlt = min(rlt, mn[x]), x -= x & -x;
	return rlt;
}

void solve(int* a, long long *f) {
	for (int i = 1; i <= n; i ++) b[i] = a[i] + i, mn[i] = 1e9;
	for (int i = n; i >= 1; i --) {
		add(i, b[i]);
		if (calc(n) == b[i]) {
			int cnt = min(a[i], n - i + 1);
			f[i] = 1ll * cnt * (a[i] + a[i] - cnt + 1) / 2;
			continue;
		}
		int st = i, en = n;
		while (en - st > 1) {
			int md = st + en >> 1;
			if (calc(md) == b[i]) st = md;
			else en = md;
		}
		int j = st;
		f[i] = 1ll * (j - i + 1) * (a[i] + a[i] - (j - i + 1) + 1) / 2 + f[j+1];
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
		solve(a, f);
		reverse(a + 1, a + n + 1);
		solve(a, g);
		reverse(a + 1, a + n + 1);
		reverse(g + 1, g + n + 1);
		long long sum = 0;
		for (int i = 1; i <= n; i ++) sum += a[i];
		long long ans = 1ll << 60;
		for (int i = 1; i <= n; i ++) {
			ans = min(ans, sum - f[i] - g[i] + 2ll * a[i]);
		}
		printf("%I64d\n", ans);
	}
	return 0;
}
