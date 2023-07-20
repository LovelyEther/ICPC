#include <bits/stdc++.h>
using namespace std;

#define N 200200

int t, n, x, m, a[N], b[N], c[N];
map <int, int> mp;

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &n, &x);
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
		sort(a + 1, a + n + 1);
		mp.clear();
		m = 0;
		for (int i = 1; i <= n; i ++) {
			if (!mp.count(a[i])) {
				mp[a[i]] = ++ m;
				b[m] = a[i];
				c[m] = 0;
			}
			c[mp[a[i]]] ++;
		}
		int ans = 0;
		for (int i = m; i >= 1; i --) if (c[i]) {
			if (b[i] % x) {
				ans += c[i]; continue;
			}
			int p = b[i] / x;
			if (!mp.count(p)) {
				ans += c[i]; continue;
			}
			int j = mp[p];
			int d = min(c[i], c[j]);
			c[i] -= d, c[j] -= d;
			ans += c[i];
		}
		printf("%d\n", ans);
	}
	return 0;
}
