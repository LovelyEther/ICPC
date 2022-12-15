#include <bits/stdc++.h>
using namespace std;

#define N 111

int t, n, f[N][N][2];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	f[0][0][0] = 1;
	for (int i = 0; i < N; i ++) {
		for (int j = 0; j < N; j ++) {
			for (int k = 0; k < 2; k ++) {
				if (i > 0 && !f[i-1][j][(k^j^1)&1]) f[i][j][k] = 1;
				if (j > 0 && !f[i][j-1][(k^j^1)&1]) f[i][j][k] = 1;
			}
		}
	}
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		int a = 0, b = 0, x;
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &x);
			x = (x + (1 << 30)) & 1;
			if (x) b ++;
			else a ++;
		}
		if (f[a][b][0]) puts("Alice");
		else puts("Bob");
	}
	return 0;
}
