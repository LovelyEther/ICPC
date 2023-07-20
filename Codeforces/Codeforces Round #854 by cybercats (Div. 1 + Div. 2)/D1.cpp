#include <bits/stdc++.h>
using namespace std;

const long long inf = 1ll << 62;

#define N 5050

int t, n, k, a[N], hot[N], cold[N];
long long f[N][N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &n, &k);
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
		for (int i = 1; i <= k; i ++) scanf("%d", &cold[i]);
		for (int i = 1; i <= k; i ++) scanf("%d", &hot[i]);
		for (int i = 1; i <= n; i ++) {
			for (int j = 0; j < i - 1; j ++) {
				f[i][j] = f[i-1][j] + (a[i] == a[i-1] ? hot[a[i]] : cold[a[i]]);
			}
			f[i][i-1] = i == 1 ? cold[a[i]] : inf;
			for (int j = 0; j < i - 1; j ++) {
				f[i][i-1] = min(f[i][i-1], f[i-1][j] + (a[j] == a[i] ? hot[a[i]] : cold[a[i]]));
			}
		}
		long long ans = inf;
		for (int j = 0; j < n; j ++) ans = min(ans, f[n][j]);
		printf("%I64d\n", ans);
	}
	return 0;
}
