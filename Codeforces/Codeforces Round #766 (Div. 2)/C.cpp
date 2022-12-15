#include <bits/stdc++.h>
using namespace std;

#define N 100100

int t, n, deg[N], ans[N];
vector <int> v[N], w[N];

void dfs(int x, int p = 0, int dp = 0) {
	for (int i = 0; i < v[x].size(); i ++) {
		int y = v[x][i], z = w[x][i];
		if (y == p) continue;
		ans[z] = (dp & 1) ? 2 : 3;
		dfs(y, x, dp ^ 1);
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) v[i].clear(), w[i].clear(), deg[i] = 0;
		for (int i = 1; i < n; i ++) {
			int a, b;
			scanf("%d %d", &a, &b);
			v[a].push_back(b); w[a].push_back(i);
			v[b].push_back(a); w[b].push_back(i);
			deg[a] ++, deg[b] ++;
		}
		bool valid = true;
		for (int i = 1; i <= n; i ++) if (deg[i] >= 3) valid = false;
		if (!valid) {
			puts("-1"); continue;
		}
		for (int i = 1; i <= n; i ++) if (deg[i] == 1) {
			dfs(i); break;
		}
		for (int i = 1; i < n; i ++) printf("%d%c", ans[i], i < n - 1 ? ' ' : '\n');
	}
	return 0;
}
