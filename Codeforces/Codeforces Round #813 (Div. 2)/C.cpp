#include <bits/stdc++.h>
using namespace std;

#define N 100100

int t, n, a[N], f[N], first[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), first[i] = f[i] = 0;
		for (int i = 1; i <= n; i ++) {
			f[i] = f[i-1];
			if (!first[a[i]]) first[a[i]] = i, f[i] ++;
		}
		int ans = f[n];
		int p = n;
		for (int i = n; i >= 1; i --) {
			if (i < n && a[i] > a[i+1]) break;
			p = min(p, first[a[i]]);
			if (p >= i) ans = min(ans, f[i-1]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
