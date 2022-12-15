#include <bits/stdc++.h>
using namespace std;

#define N 2020

const int mod = 1e9 + 7;
const int r = (mod + 1) / 2;

int t, n, m, k, f[N][N];

void prepare() {
	for (int i = 1; i <= 2000; i ++) {
		f[i][0] = 0;
		f[i][i] = i;
		for (int j = 1; j < i; j ++) f[i][j] = 1ll * (f[i-1][j-1] + f[i-1][j]) * r % mod;
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
	prepare();
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d %d", &n, &m, &k);
		printf("%d\n", (int)(1ll * f[n][m] * k % mod));
	}
	return 0;
}
