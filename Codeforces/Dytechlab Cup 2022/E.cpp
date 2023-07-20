#include <bits/stdc++.h>
using namespace std;

#define N 1001001

const int mod = 1e9 + 7;

int t, n, f[N], r, ans[N];

int expmod(int a, int b) {
	int rlt = 1;
	while (b) {
		if (b & 1) rlt = 1ll * rlt * a % mod;
		a = 1ll * a * a % mod, b >>= 1;
	}
	return rlt;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	r = expmod(2, mod - 2);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		if (n == 1) {
			puts("1");
			continue;
		}
		if (n == 2) {
			puts("0");
			puts("1");
			continue;
		}
		f[n+1] = 1;
		for (int i = n; i > 1; i --) {
			if (i > n / 2) {
				f[i] = 1;
			}
			else if (i == n / 2) {
				int tmp = 0;
				for (int j = 1; j <= i - 1; j ++) {
					tmp = (tmp + 1ll * expmod(r, j) * f[i+j]) % mod;
				}
				f[i] = tmp;
			}
			else {
				int tmp = f[i+1];
				if (2 * i <= n) tmp = (tmp - 1ll * expmod(r, i - 1) * f[2*i]) % mod;
				if (2 * i + 1 <= n) tmp = (tmp - 1ll * expmod(r, i) * f[2*i+1]) % mod;
				tmp = (tmp + mod) % mod;
				tmp = 1ll * r * tmp % mod;
				if (i > 1) tmp = (1ll * r * f[i+1] + tmp) % mod;
				f[i] = tmp;
			}
			ans[i] = (1ll * expmod(r, i - i / 2 - (i == n)) * f[i] % mod + mod) % mod;
		}
		for (int i = 1; i <= n; i ++) printf("%d\n", ans[i]);
	}
	return 0;
}
