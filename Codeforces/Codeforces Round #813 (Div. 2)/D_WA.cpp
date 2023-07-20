#include <bits/stdc++.h>
using namespace std;

#define N 100100

const int inf = 1e9;

int t, n, k, a[N], id[N], f[N], g[N];

bool cmp(int i, int j) { return a[i] < a[j]; }

int calc() {
	for (int i = 0; i <= n + 1; i ++) f[i] = g[i] = inf;
	for (int i = 1; i <= n; i ++) f[i] = min(f[i-1], a[i]);
	for (int i = n; i >= 1; i --) g[i] = min(g[i+1], a[i]);
	int rlt = 0;
	for (int i = 1; i < n; i ++) {
		int tmp = min(a[i], a[i+1]);
		tmp = min(tmp, 2 * f[i-1]);
		tmp = min(tmp, 2 * g[i+2]);
		rlt = max(rlt, tmp);
	}
	return min(rlt, inf);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &n, &k);
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), id[i] = i;
		if (k == n) {
			printf("%d\n", inf); continue;
		}
		sort(id + 1, id + n + 1, cmp);
		int ans = a[id[k+1]];
		for (int i = 1; i <= k - 1; i ++) a[id[i]] = inf;
		int prv = a[id[k]];
		a[id[k]] = inf;
		ans = max(ans, calc());
		a[id[k]] = prv;
		prv = a[id[k+1]];
		a[id[k+1]] = inf;
		ans = max(ans, calc());
		a[id[k+1]] = prv;
		printf("%d\n", ans);
	}
	return 0;
}
