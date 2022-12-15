#include <bits/stdc++.h>
using namespace std;

#define N 200200

const int mod = 998244353;

int t, n, m, a[N], vis[N], cnt, p[N], x[N];

int calc(int n, int k) {
	if (k == 1) return n;
	int l = 0;
	for (int i = 1; i <= cnt && 1ll * p[i] * p[i] <= k; i ++) {
		if (k % p[i] == 0) {
			while (k % p[i] == 0) k /= p[i];
			x[l++] = p[i];
		}
	}
	if (k > 1) x[l++] = k;
	int rlt = 0;
	for (int i = 0; i < (1 << l); i ++) {
		int y = 1, bt = 0;
		for (int j = 0; j < l; j ++) if (i & (1 << j)) y *= x[j], bt ++;
		if (bt % 2 == 0) rlt += n / y;
		else rlt -= n / y;
	}
	return rlt;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	for (int i = 2; i < N; i ++) {
		if (!vis[i]) p[++cnt] = i;
		if (1ll * i * i >= N) continue;
		for (int j = i * i; j < N; j += i) vis[j] = 1;
	}
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &n, &m);
		int ans = 1;
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &a[i]);
			if (i > 1 && a[i-1] % a[i]) {
				ans = 0;
			}
			if (i == 1) continue;
			ans = 1ll * ans * calc(m / a[i], a[i-1] / a[i]) % mod;
		}
		printf("%d\n", ans);
	}
	return 0;
}
