#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int expmod(int a, int b) {
	int rlt = 1;
	while (b) {
		if (b & 1) rlt = 1ll * rlt * a % mod;
		a = 1ll * a * a % mod, b >>= 1;
	}
	return rlt;
}

int n, a, b, c, d;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &n);
	int ans = 1;
	for (int i = 1; i <= n / 3; i ++) ans = 1ll * ans * i % mod;
	int x = 1;
	for (int i = 1; i <= n / 6; i ++) x = 1ll * x * i % mod;
	ans = 1ll * ans * expmod(x, mod - 3) % mod;
	for (int i = 0; i < n; i += 3) {
		scanf("%d %d %d", &a, &b, &c);
		d = min(a, min(b, c));
		int cnt = (a == d) + (b == d) + (c == d);
		ans = 1ll * ans * cnt % mod;
	}
	printf("%d\n", ans);
	return 0;
}
