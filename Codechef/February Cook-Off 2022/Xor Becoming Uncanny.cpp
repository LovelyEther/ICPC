#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int expmod(int a, int b) {
	int rlt = 1;
	while (b) {
		if (b & 1) rlt = 1ll * rlt * a % mod;
		a = 1ll * a * a % mod;
		b >>= 1;
	}
	return rlt;
}

int t, n;

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		int ans = 2ll * (expmod(2, n - 1) - 1) % mod;
		ans = (ans + 3ll * expmod(2, n - 1) % mod) % mod;
		int pal = 1;
		n -= 2;
		if (n >= 0) {
			pal += 1;
			pal = (pal + 2ll * (expmod(2, n / 2 + 1) - 2)) % mod;
			if (n & 1) pal = (pal + expmod(2, (n + 1) / 2)) % mod;
		}
		ans = (ans - 2ll * pal) % mod;
		ans = (ans + mod) % mod;
		printf("%d\n", ans);
	}
	return 0;
}
