#include <bits/stdc++.h>
using namespace std;

#define N 200200

const int mod = 1e9 + 7;

int n, p, a[N], f[N], g[N];
map <int, int> mp;

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d %d", &n, &p);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), mp[a[i]] = i;
	f[0] = f[1] = 1;
	for (int i = 2; i <= p; i ++) f[i] = (f[i-1] + f[i-2]) % mod;
	g[0] = f[1];
	for (int i = 1; i <= p; i ++) g[i] = (g[i-1] + f[i]) % mod;
	int ans = 0;
	for (int i = 1; i <= n; i ++) {
		bool bad = false;
		int x = a[i];
		while (x > 1) {
			if (x & 1) x >>= 1;
			else if (x % 4 == 0) x >>= 2;
			else break;
			if (mp[x]) {
				bad = true; break;
			}
		}
		if (bad) continue;
		int k = p - 1 - (31 - __builtin_clz(a[i]));
		if (k < 0) continue;
		ans = (ans + g[k]) % mod;
	}
	printf("%d\n", ans);
	return 0;
}
