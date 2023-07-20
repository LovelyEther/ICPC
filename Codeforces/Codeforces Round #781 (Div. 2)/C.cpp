#include <bits/stdc++.h>
using namespace std;

#define N 200200

int t, n, m, deg[N], f[N];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) deg[i] = 0;
		for (int i = 2, j; i <= n; i ++) {
			scanf("%d", &j);
			deg[j] ++;
		}
		m = 0;
		f[++m] = 1;
		for (int i = 1; i <= n; i ++) if (deg[i] > 0) f[++m] = deg[i];
		sort(f + 1, f + m + 1);
		int ans = m;
		for (int i = 1; i <= m; i ++) f[i] -= i;
		int r = 0;
		for (int i = 1; i <= m; i ++) if (f[i] > 0) r += f[i];
		if (!r) {
			printf("%d\n", ans);
			continue;
		}
		int st = 0, en = r;
		while (en - st > 1) {
			int md = st + en >> 1;
			int p = 0;
			for (int i = 1; i <= m; i ++) if (f[i] > md) p += f[i] - md;
			if (p <= md) en = md;
			else st = md;
		}
		printf("%d\n", ans + en);
	}
	return 0;
}
