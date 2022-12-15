#include <bits/stdc++.h>
using namespace std;

#define N 3030

int t, n, d[N], a[N][N], b[N], c[N], mx[N], vis[N];
vector <int> v[N];

void dfs(int x, int p = 0) {
	d[x] = d[p] + 1;
	for (int i = 0; i < v[x].size(); i ++) if (v[x][i] != p) dfs(v[x][i], x);
}

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) v[i].clear();
		memset(c, 0, sizeof c);
		memset(mx, 0, sizeof mx);
		memset(vis, 0, sizeof vis);
		for (int i = 1; i < n; i ++) {
			int x, y;
			scanf("%d %d", &x, &y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		d[0] = -1;
		for (int i = 1; i <= n; i ++) {
			dfs(i);
			for (int j = 1; j <= n; j ++) a[i][j] = d[j];
		}
		for (int i = 1; i <= n; i ++) b[i] = a[1][i];
		sort(b + 1, b + n + 1);
		for (int i = n; i >= 1; i --) {
			for (int j = 1; j <= n; j ++) if (!vis[j] && a[1][j] == b[i]) {
				vis[j] = 1;
				for (int k = 2; k <= n; k ++) mx[k] = max(mx[k], a[k][j]);
			}
			c[i] = n;
			for (int k = 2; k <= n; k ++) c[i] = min(c[i], mx[k]);
		}
	//	for (int i = 1; i <= n; i ++) printf("%d ", c[i]); puts("");
		for (int x = 1; x <= n; x ++) {
			int st = 0, en = n;
			while (en - st > 1) {
				int mid = st + en >> 1;
				int i = lower_bound(b + 1, b + n + 1, mid + 1) - b;
			//	printf("%d : %d\n", x, i);
				if (i > n || c[i] + x <= mid) en = mid;
				else st = mid;
			}
			printf("%d%c", en, x < n ? ' ' : '\n');
		}
	}
	return 0;
}
