#include <bits/stdc++.h>
using namespace std;

#define N 1010

const int mod = 1e9 + 7;

int t, m, f[60][N][N], g[60][N];
long long n;


void prepare() {
	for (int j = 1; j <= 1000; j ++) {
		for (int k = 1; k <= j; k ++) f[0][j][k] = 1;
		g[0][j] = j;
	}
	for (int i = 1; i < 59; i ++) {
		for (int j = 1; j <= 1000; j ++) {
			for (int k = 1; k <= j; k ++) {
				f[i][j][k] = 1ll * g[i-1][j-k] * g[i-1][j-k] % mod;
				if (i == 2 && j == 2 && k == 1) {
					printf("%d\n", g[i-1][j-k]); puts("");
				}
			}
		}
		for (int j = 1; j <= 1000; j ++) {
			for (int k = 1; k <= j; k ++) g[i][j] = (g[i][j] + f[i][j][k]) % mod;
		}
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	prepare();
	cin >> t;
	while (t -- ) {
		cin >> n >> m;
		n = 31 - __builtin_clz(n);
		printf("%d\n", g[n][m]);
	}
	return 0;
}
