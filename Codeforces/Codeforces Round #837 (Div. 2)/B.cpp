#include <bits/stdc++.h>
using namespace std;

#define N 100100

int t, n, m, f[N];
pair <int, int> p[N];

void add(int x, int val) {
	while (x <= n) f[x] = max(f[x], val), x += x & -x;
}

int calc(int x) {
	int rlt = 0;
	while (x) rlt = max(rlt, f[x]), x -= x & -x;
	return rlt;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= m; i ++) {
			int x, y;
			scanf("%d %d", &x, &y);
			if (x < y) swap(x, y);
			p[i] = make_pair(x, y);
		}
		sort(p + 1, p + m + 1);
		for (int i = 1; i <= n; i ++) f[i] = 0;
		long long ans = 0;
		for (int i = 1, j = 1; i <= n; i ++) {
			while (j <= m && p[j].first <= i) {
				add(i, p[j].second);
				j ++;
			}
			ans += i - calc(i);
		}
		printf("%I64d\n", ans);
	}
	return 0;
}
