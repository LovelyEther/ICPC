#include <bits/stdc++.h>
using namespace std;

#define N 100100

const int mod = 1e9 + 7;
const int r = (mod + 1) / 2;

int t, n, fact[N], f[N];

int expmod(int x, int y) {
	int rlt = 1;
	while (y) {
		if (y & 1) rlt = 1ll * rlt * x % mod;
		x = 1ll * x * x % mod; y >>= 1;
	}
	return rlt;
}

int c(int x, int y) {
	return 1ll * fact[x] * expmod(fact[y], mod - 2) % mod * expmod(fact[x-y], mod - 2) % mod;
}

int calc(int x) {
	return (1ll * x * expmod(r, x) % mod * f[x] % mod + mod) % mod;
}

int main() {
//	freopen("in.txt", "r", stdin);
	fact[0] = 1;
	for (int i = 1; i < N; i ++) fact[i] = 1ll * fact[i-1] * i % mod;
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		f[n] = 1;
		for (int i = n; i > 1; i --) {
			f[i-1] = (1ll * (1 - r) * f[i] + 1ll * expmod(r, n - i + 1) * c(n + 1, n - i + 1)) % mod;
		}
		for (int i = 1; i <= n; i ++) printf("%d%c", (calc(i) + calc(n + 1 - i)) % mod, i < n ? ' ' : '\n');
	}
	return 0;
}
