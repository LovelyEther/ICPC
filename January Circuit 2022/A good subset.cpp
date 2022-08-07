#include <bits/stdc++.h>
using namespace std;

#define N 5050

int t, n, k, a[N], v[N], w[N];
bool f[N][N], g[N][N];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &n, &k);
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
		memset(f, 0, sizeof f);
		memset(g, 0, sizeof g);
		f[0][0] = 1;
		for (int i = 1; i <= n; i ++) {
			for (int j = 0; j <= k; j ++) f[i][j] = f[i-1][j];
			for (int j = 0; j + a[i] <= k; j ++) if (f[i-1][j]) f[i][j+a[i]] = 1;
		}
		g[n+1][0] = 1;
		for (int i = n; i >= 1; i --) {
			for (int j = 0; j <= k; j ++) g[i][j] = g[i+1][j];
			for (int j = 0; j + a[i] <= k; j ++) if (g[i+1][j]) g[i][j+a[i]] = 1;
		}
		int ans = n;
		for (int i = 1; i <= n; i ++) {
			int nv = 0, nw = 0;
			for (int j = 0; j <= k; j ++) {
				if (f[i-1][j]) v[nv++] = j;
				if (g[i+1][j]) w[nw++] = j;
			}
			bool valid = false;
			for (int j = 0; j < nv && !valid; j ++) {
				int jj = lower_bound(w, w + nw, k - a[i] - v[j]) - w;
				if (jj < nw && v[j] + w[jj] < k) valid = true;
			}
			if (valid) ans --;
		}
		printf("%d\n", ans);
	}
	return 0;
}
