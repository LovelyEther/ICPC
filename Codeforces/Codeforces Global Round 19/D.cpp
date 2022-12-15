#include <bits/stdc++.h>
using namespace std;

#define N 111

int t, n, a[N], b[N], f[N*N], g[N*N];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		int ans = 0, sa = 0, sb = 0;
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), ans += a[i] * a[i], sa += a[i];
		for (int i = 1; i <= n; i ++) scanf("%d", &b[i]), ans += b[i] * b[i], sb += b[i];
		ans *= n - 2;
		memset(f, 0, sizeof f);
		f[0] = 1;
		for (int i = 1; i <= n; i ++) {
			memset(g, 0, sizeof g);
			for (int j = 0; j <= 10000; j ++) if (f[j]) g[j+a[i]] = g[j+b[i]] = 1;
			memcpy(f, g, sizeof f);
		}
		for (int j = 0; j <= 10000; j ++) if (f[j]) {
			if (abs(sa + sb - j - j) < abs(sa - sb)) sa = sa + sb - j, sb = j;
		}
		ans += sa * sa + sb * sb;
		printf("%d\n", ans);
	}
	return 0;
}
