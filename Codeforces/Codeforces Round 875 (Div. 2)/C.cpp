#include <bits/stdc++.h>
using namespace std;

#define N 400400

int t, n, head[N], nxt[N], to[N], id[N], dt[N], cnt, w[N];

void add_edge(int x, int y, int id) {
	nxt[id] = head[x];
	to[id] = y;
	head[x] = id;
}

void dfs(int x, int p, int prv_id) {
	for (int id = head[x]; id; id = nxt[id]) {
		int y = to[id];
		if (y == p) continue;
		w[y] = w[x];
		if (id < prv_id) w[y] ++;
		dfs(y, x, id);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		cnt = 0;
		for (int i = 1; i <= n; i ++) head[i] = 0;
		for (int i = 1; i < n; i ++) {
			int x, y;
			scanf("%d %d", &x, &y);
			add_edge(x, y, 2 * i);
			add_edge(y, x, 2 * i + 1);
		}
		dt[0] = 1e9;
		w[1] = 1;
		dfs(1, 0, 0);
		int ans = 0;
		for (int i = 1; i <= n; i ++) ans = max(ans, w[i]);
		printf("%d\n", ans);
	}
	return 0;
}
