#include <bits/stdc++.h>
using namespace std;

#define N 2020
#define M 12

int t, n, m, fa[N][M], dp[N], d[N][N], f[N][N];
char s[N];
pair <int, int> p[N*N];
vector <int> v[N], son[N];

void dfs(int x, int p = 0) {
	dp[x] = dp[p] + 1;
	son[x].clear();
	son[x].push_back(x);
	fa[x][0] = p;
	for (int i = 1; (1 << i) <= dp[x]; i ++) fa[x][i] = fa[fa[x][i-1]][i-1];
	for (int i = 0; i < v[x].size(); i ++) {
		int y = v[x][i];
		if (y == p) continue;
		dfs(y, x);
		for (int j = 0; j < son[y].size(); j ++) {
			int z = son[y][j];
			for (int k = 0; k < son[x].size(); k ++) {
				int w = son[x][k];
				d[z][w] = d[w][z] = dp[w] + dp[z] - 2 * dp[x];
			}
		}
		for (int j = 0; j < son[y].size(); j ++) {
			son[x].push_back(son[y][j]);
		}
	}
}

bool cmp(pair <int, int> x, pair <int, int> y) {
	return d[x.first][x.second] < d[y.first][y.second];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		scanf("%s", s + 1);
		for (int i = 1; i <= n; i ++) v[i].clear();
		for (int i = 1; i < n; i ++) {
			int x, y;
			scanf("%d %d", &x, &y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		for (int i = 1; i <= n; i ++) {
			for (int j = i + 1; j <= n; j ++) d[i][j] = d[j][i] = 0;
			f[i][i] = 1;
		}
		dfs(1);
		int cnt = 0;
		for (int i = 1; i <= n; i ++) {
			for (int j = i + 1; j <= n; j ++) p[++cnt] = make_pair(i, j);
		}
		sort(p + 1, p + cnt + 1, cmp);
		int ans = 1;
		for (int i = 1; i <= cnt; i ++) {
			int x = p[i].first, y = p[i].second;
			if (d[x][y] == 1) {
				if (s[x] == s[y]) f[x][y] = f[y][x] = 2;
				else f[x][y] = f[y][x] = 1;
				ans = max(ans, f[x][y]);
				continue;
			}
			if (dp[x] < dp[y]) swap(x, y);
			int delta = dp[x] - dp[y];
			int xx = fa[x][0], yy = fa[y][0];
			int z = x;
			for (int j = 0; (1 << j) <= delta; j ++) if ((1 << j) & delta) z = fa[z][j];
			if (z == y) {
				delta --;
				z = x;
				for (int j = 0; (1 << j) <= delta; j ++) if ((1 << j) & delta) z = fa[z][j];
				yy = z;
			}
			f[x][y] = max(f[x][yy], f[xx][y]);
			if (s[x] == s[y]) f[x][y] = max(f[x][y], 2 + f[xx][yy]);
			f[y][x] = f[x][y];
			ans = max(ans, f[x][y]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
