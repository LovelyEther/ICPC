#include <bits/stdc++.h>
using namespace std;

#define N 200200

const int mod = 998244353;

int t, n, m, k, q, row[N], col[N], x[N], y[N];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d %d %d", &n, &m, &k, &q);
		for (int i = 1; i <= q; i ++) scanf("%d %d", &x[i], &y[i]);
		for (int i = 1; i <= n; i ++) row[i] = 0;
		for (int j = 1; j <= m; j ++) col[j] = 0;
		int rows = 0, cols = 0;
		int ans = 1;
		for (int _ = q; _; _ --) {
			int I = x[_], J = y[_];
			if (row[I] && col[J]) continue;
			ans = 1ll * ans * k % mod;
			if (!row[I]) row[I] = 1, rows ++;
			if (!col[J]) col[J] = 1, cols ++;
			if (rows == n) {
				for (int j = 1; j <= m; j ++) col[j] = 1;
			}
			if (cols == m) {
				for (int i = 1; i <= n; i ++) row[i] = 1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
