#include <bits/stdc++.h>
using namespace std;

#define N 100100

const long long inf = 1ll << 60;

int t, n, a[N];
long long f[N], g[N];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), f[i] = inf, g[i] = inf;
		f[1] = 0;
		for (int i = 2; i < n; i ++) {
			f[i] = f[i-1];
			if (i % 2 == 0) {
				int add = 0;
				add = max(add, a[i-1] - a[i] + 1);
				add = max(add, a[i+1] - a[i] + 1);
				f[i] += add;
			}
		}
		if (n & 1) {
			printf("%I64d\n", f[n-1]); continue;
		}
		g[n] = 0;
		for (int i = n - 1; i >= 1; i --) {
			g[i] = g[i+1];
			if (i % 2 != n % 2) {
				int add = 0;
				add = max(add, a[i-1] - a[i] + 1);
				add = max(add, a[i+1] - a[i] + 1);
				g[i] += add;
			}
		}
		long long ans = inf;
		for (int i = 1; i < n; i += 2) {
			ans = min(ans, f[i] + g[i+1]);
		}
		printf("%I64d\n", ans);
	}
	return 0;
}
