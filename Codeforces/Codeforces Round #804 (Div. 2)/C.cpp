#include <bits/stdc++.h>
using namespace std;

#define N 100100

const int mod = 1e9 + 7;

int t, n, p[N], fact[N], rfact[N];

int expmod(int a, int b) {
	int rlt = 1;
	while (b) {
		if (b & 1) rlt = 1ll * rlt * a % mod;
		a = 1ll * a * a % mod, b >>= 1;
	}
	return rlt;
}

int F(int n, int k) {
	return 1ll * fact[n] * rfact[n-k] % mod;
}

int main() {
//	freopen("in.txt", "r", stdin);
	fact[0] = 1;
	for (int i = 1; i < N; i ++) fact[i] = 1ll * fact[i-1] * i % mod;
	for (int i = 0; i < N; i ++) rfact[i] = expmod(fact[i], mod - 2);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 0; i < n; i ++) {
			int x;
			scanf("%d", &x);
			p[x] = i;
		}
		if (n == 1) {
			puts("1"); continue;
		}
		int mn = min(p[0], p[1]);
		int mx = max(p[0], p[1]);
		int last = 1;
		int r = mx - mn - 1;
		int ans = 1;
		for (int i = 2; i < n; i ++) {
			if (mn < p[i] && p[i] < mx) continue;
			ans = 1ll * ans * F(r, i - last - 1) % mod;
			r -= i - last - 1;
			if (p[i] < mn) r += mn - p[i] - 1, mn = p[i];
			else r += p[i] - mx - 1, mx = p[i];
			last = i;
		}
		ans = 1ll * ans * fact[r] % mod;
		printf("%d\n", ans);
	}
	return 0;
}
