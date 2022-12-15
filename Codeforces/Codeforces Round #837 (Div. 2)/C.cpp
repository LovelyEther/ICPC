#include <bits/stdc++.h>
using namespace std;

#define N 100100

int t, n, x, cnt, p[N], vis[N];
map <int, int> mp;

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
		scanf("%d", &n);
		bool good = false;
		mp.clear();
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &x);
			for (int j = 1; j <= cnt && 1ll * p[j] * p[j] <= x; j ++) if (x % p[j] == 0) {
				while (x % p[j] == 0) x /= p[j];
				if (mp.count(p[j])) good = true;
				mp[p[j]] = 1;
			}
			if (x > 1) {
				if (mp.count(x)) good = true;
				mp[x] = 1;
			}
		}
		puts(good ? "YES" : "NO");
	}
	return 0;
}
