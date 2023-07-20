#include <bits/stdc++.h>
using namespace std;

#define N 505

const long long inf = 1ll << 60;

int n, l, k, d[N], a[N];
long long f[N][N];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d %d %d", &n, &l, &k);
	for (int i = 1; i <= n; i ++) scanf("%d", &d[i]);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	d[++n] = l;
	for (int i = 1; i <= n; i ++) {
		for (int j = 0; j <= k; j ++) f[i][j] = inf;
		if (i == 1) {
			f[i][0] = 0; continue;
		}
		for (int j = 1; j < i; j ++) {
			for (int r = 0; r < j; r ++) {
				if (r + i - j - 1 <= k) {
					f[i][r+i-j-1] = min(f[i][r+i-j-1], f[j][r] + 1ll * (d[i] - d[j]) * a[j]);
				}
			}
		}
	}
	long long ans = inf;
	for (int j = 0; j <= k; j ++) ans = min(ans, f[n][j]);
	printf("%I64d\n", ans);
	return 0;
}
