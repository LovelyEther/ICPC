#include <bits/stdc++.h>
using namespace std;

#define N 200200

int t, n, m, root[N], col[N], a[N], b[N], vis[N];
vector <int> v[N], w[N];
vector <int> path;

bool dfs(int x, int target) {
	vis[x] = 1;
	if (x == target) return 1;
	for (int i = 0; i < v[x].size(); i ++) {
		int y = v[x][i], z = w[x][i];
		if (vis[y]) continue;
		path.push_back(z);
		if (dfs(y, target)) return 1;
		path.pop_back();
	}
	return 0;
}

int find_root(int x) {
	return root[x] == x ? x : root[x] = find_root(root[x]);
}

bool bad(vector <int> &red) {
	if (red.size() != 3) return 0;
	set <int> s;
	for (int i = 0; i < 3; i ++) {
		s.insert(a[red[i]]);
		s.insert(b[red[i]]);
	}
	return s.size() == 3;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i ++) root[i] = i;
		vector <int> red;
		for (int i = 1; i <= m; i ++) {
			scanf("%d %d", &a[i], &b[i]);
			int x = find_root(a[i]);
			int y = find_root(b[i]);
			if (x != y) {
				col[i] = 0;
				root[x] = y;
			}
			else {
				col[i] = 1;
				red.push_back(i);
			}
		}
		if (bad(red)) {
			for (int i = 1; i <= n; i ++) v[i].clear(), w[i].clear(), vis[i] = 0;
			for (int i = 1; i <= m; i ++) if (col[i] == 0) {
				v[a[i]].push_back(b[i]), w[a[i]].push_back(i);
				v[b[i]].push_back(a[i]), w[b[i]].push_back(i);
			}
			path.clear();
			int i = red[0];
			dfs(a[i], b[i]);
			int j = path[0];
			col[i] = 0;
			col[j] = 1;
		}
		for (int i = 1; i <= m; i ++) printf("%d", col[i]); puts("");
	}
	return 0;
}
