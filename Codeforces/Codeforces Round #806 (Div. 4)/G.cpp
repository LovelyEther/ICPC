#include <bits/stdc++.h>
using namespace std;

#define N 100100

const long long inf = 1ll << 60;

int t, n, k, a[N];
long long f[N][33];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &n, &k);
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
		for (int i = 0; i <= n; i ++) {
			for (int j = 0; j <= 30; j ++) f[i][j] = -inf;
		}
		f[0][0] = 0;
		for (int i = 1; i <= n; i ++) {
			for (int j = 0; j <= 30; j ++) {
				f[i][j] = max(f[i][j], f[i-1][j] + (a[i] >> j) - k);
				int jj = min(30, j + 1);
				f[i][jj] = max(f[i][jj], f[i-1][j] + (a[i] >> jj));
			}
		}
		long long ans = 0;
		for (int j = 0; j <= 30; j ++) ans = max(ans, f[n][j]);
		printf("%I64d\n", ans);
	}
	return 0;
}
