#include <bits/stdc++.h>
using namespace std;

#define N 100100

const int mod = 1e9 + 7;

int t, n, k, fact[N], rfact[N];
char s[N];

inline int smallers(char c) { return c - 'a'; }

int expmod(int a, int b) {
	int rlt = 1;
	while (b) {
		if (b & 1) rlt = 1ll * rlt * a % mod;
		a = 1ll * a * a % mod, b >>= 1;
	}
	return rlt;
}

int C(int n, int k) {
	return 1ll * fact[n] * rfact[k] % mod * rfact[n-k] % mod;
}

int main() {
	fact[0] = rfact[0] = 1;
	for (int i = 1; i < N; i ++) {
		fact[i] = 1ll * fact[i-1] * i % mod;
		rfact[i] = expmod(fact[i], mod - 2);
	}
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d %s", &n, &k, s);
		int ans = 0;
		for (int i = 0; i <= n - k; i ++) {
			ans = (ans + 1ll * smallers(s[i]) * C(n - 1 - i, k - 1) % mod * expmod(25, k - 1)) % mod;
		}
		printf("%d\n", ans);
	}
	return 0;
}