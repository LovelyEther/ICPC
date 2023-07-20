#include <bits/stdc++.h>
using namespace std;

#define N 300300

const int inf = 1e9;

int t, n, m, a[N], b[N], c[N], f[N][11], g[N][11];
char s[N], A[N], B[N];

bool solve() {
	for (int i = 0; i <= m + 1; i ++) {
		for (int j = 0; j < 10; j ++) f[i][j] = inf;
	}
	for (int i = m; i >= 1; i --) {
		for (int j = 0; j < 10; j ++) f[i][j] = f[i+1][j];
		f[i][c[i]] = i;
	}
	for (int j = 0; j < 10; j ++) g[0][j] = 0;
	for (int i = 1; i <= n; i ++) {
		for (int j = 0; j < 10; j ++) g[i][j] = inf;
		for (int j = a[i]; j <= b[i]; j ++) {
			int mx = 0;
			for (int jj = 0; jj < 10; jj ++) if (g[i-1][jj] != inf) {
				mx = max(mx, g[i-1][jj]);
			}
			assert(mx != inf);
			g[i][j] = f[mx+1][j];
			if (g[i][j] == inf) return true;
		}
	}
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%s %d %s %s", s + 1, &n, A + 1, B + 1);
		m = strlen(s + 1);
		for (int i = 1; i <= m; i ++) {
			c[i] = s[i] - '0';
		}
		for (int i = 1; i <= n; i ++) {
			a[i] = A[i] - '0';
			b[i] = B[i] - '0';
		}
		if (solve()) puts("YES");
		else puts("NO");
	}
	return 0;
}
