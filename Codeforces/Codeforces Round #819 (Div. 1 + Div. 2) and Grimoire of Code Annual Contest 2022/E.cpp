#include <bits/stdc++.h>
using namespace std;

#define N 300300

const int mod = 998244353;

int t, n, fact[N], rfact[N], ofact[N], ex[N], f[N];

int expmod(int a, int b) {
	int rlt = 1;
	while (b) {
		if (b & 1) rlt = 1ll * rlt * a % mod;
		a = 1ll * a * a % mod;
		b >>= 1;
	}
	return rlt;
}

int C(int n, int k) {
	return 1ll * fact[n] * rfact[k] % mod * rfact[n-k] % mod;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	fact[0] = 1;
	ofact[0] = 1;
	ex[0] = 1;
	for (int i = 1; i < N; i ++) {
		fact[i] = 1ll * fact[i-1] * i % mod;
		ofact[i] = ofact[i-1];
		if (i & 1) ofact[i] = 1ll * ofact[i] * i % mod;
		ex[i] = ex[i-1] * 2 % mod;
	}
	for (int i = 0; i < N; i ++) rfact[i] = expmod(fact[i], mod - 2);
	f[0] = 1;
	f[1] = 1;
	for (int i = 2; i < N; i ++) {
		f[i] = (f[i-1] + 1ll * f[i-2] * (i - 1)) % mod;
	}
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		int ans = 0;
		for (int k = 0; k * 4 <= n; k ++) {
			int tmp = C(n - 2 * k, 2 * k);
			tmp = 1ll * tmp * ofact[2*k] % mod;
			tmp = 1ll * tmp * ex[k] % mod;
			tmp = 1ll * tmp * f[n-4*k] % mod;
			ans = (ans + tmp) % mod;
		}
		printf("%d\n", ans);
	}
	return 0;
}
