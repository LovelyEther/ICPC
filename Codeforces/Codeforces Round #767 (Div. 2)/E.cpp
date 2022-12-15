#include <bits/stdc++.h>
using namespace std;

#define N 2020

int t, n, a[N][N], b[N][N];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= n; j ++) scanf("%d", &b[i][j]);
		}
		for (int j = 1; j <= n; j ++) a[1][j] = 0;
		for (int i = 2; i <= n; i ++) {
			for (int j = 1; j <= n; j ++) {
				a[i][j] = b[i-1][j];
				if (j > 1) a[i][j] ^= a[i-1][j-1];
				if (j < n) a[i][j] ^= a[i-1][j+1];
				if (i > 2) a[i][j] ^= a[i-2][j];
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= n; j ++) ans ^= a[i][j];
		}
		printf("%d\n", ans);
	}
	return 0;
}
