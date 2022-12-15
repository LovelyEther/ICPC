#include <bits/stdc++.h>
using namespace std;

#define N 100100

int t, n, k, f[N][33], a[N];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &n, &k);
		for (int i = 1; i <= n; i ++) f[i][0] = (i & 1) ? (i + 1) / 2 : n / 2 + i / 2;
		for (int j = 1; (1 << j) <= k; j ++) {
			for (int i = 1; i <= n; i ++) f[i][j] = f[f[i][j-1]][j-1];
		}
		for (int i = 1; i <= n; i ++) {
			int x = i;
			for (int j = 0; (1 << j) <= k; j ++) if ((1 << j) & k) x = f[x][j];
			a[x] = i;
		}
		for (int i = 1; i <= n; i ++) printf("%d%c", a[i], i < n ? ' ' : '\n');
	}
	return 0;
}
