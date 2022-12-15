#include <bits/stdc++.h>
using namespace std;

#define N 200200

int t, n, f[N], g[N], ic[N], dc[N], eq[N];

void add_lower(int x, int val) {
	while (x <= n) f[x] = max(f[x], val), x += x & -x;
}

void add_upper(int x, int val) {
	x = n + 1 - x;
	while (x <= n) g[x] = max(g[x], val), x += x & -x;
}

int get_lower(int x) {
	int rlt = 0;
	while (x) rlt = max(rlt, f[x]), x -= x & -x;
	return rlt;
}

int get_upper(int x) {
	int rlt = 0;
	x = n + 1 - x;
	while (x) rlt = max(rlt, g[x]), x -= x & -x;
	return rlt;
}

int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) f[i] = g[i] = eq[i] = ic[i] = dc[i] = 0;
		int ans = 0;
		for (int i = 1; i <= n; i ++) {
			int x;
			scanf("%d", &x);
			int tmp = max(eq[x], max(ic[x], dc[x])) + 1;
			ic[x] = max(ic[x], get_lower(x) + 1);
			dc[x] = max(dc[x], get_upper(x) + 1);
			eq[x] = tmp;
			add_lower(x, max(eq[x], ic[x]));
			add_upper(x, max(eq[x], dc[x]));
			ans = max(ans, eq[x]);
			ans = max(ans, ic[x]);
			ans = max(ans, dc[x]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
