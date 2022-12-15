#include <bits/stdc++.h>
using namespace std;

#define N 100100

typedef pair <int, int> pii;

int n, m, vis[N], prv[N], T;
vector <int> v[N];
vector <pii> cyc;

bool dfs(int x) {
	vis[x] = T + 1;
	for (int i = 0; i < v[x].size(); i ++) {
		int y = v[x][i];
		if (vis[y] == T + 1) {
			int xx = x;
			while (xx != y) {
				cyc.push_back(make_pair(prv[xx], xx));
				xx = prv[xx];
			}
			cyc.push_back(make_pair(x, y));
			reverse(cyc.begin(), cyc.end());
			return 1;
		}
		if (vis[y] && vis[y] < T) continue;
		prv[y] = x;
		if (dfs(y)) return 1;
	}
	vis[x] = T;
	return 0;
}

int d[N], flag[N];
priority_queue <pii> q;

bool bfs(int src) {
	while (!q.empty()) q.pop();
	d[src] = 0;
	flag[src] = T + 1;
	q.push(make_pair(-d[src], src));
	while (!q.empty()) {
		pii t = q.top(); q.pop();
		int x = t.second;
		flag[x] = T;
		if (d[x] != -t.first) continue;
		for (int i = 0; i < v[x].size(); i ++) {
			int y = v[x][i];
			if (y == src) {
				int xx = x;
				while (xx != y) {
					cyc.push_back(make_pair(prv[xx], xx));
					xx = prv[xx];
				}
				cyc.push_back(make_pair(x, y));
				reverse(cyc.begin(), cyc.end());
				return 1;
			}
			if (flag[y] && flag[y] < T) continue;
			if (!flag[y] || flag[y] && d[y] > d[x] + 1) {
				d[y] = d[x] + 1;
				prv[y] = x;
				flag[y] = T + 1;
				q.push(make_pair(-d[y], y));
			}
		}
	}
	return 0;
}

bool incycle[N];

void divide() {
	memset(incycle, 0, sizeof incycle);
	for (int i = 0; i < cyc.size(); i ++) incycle[cyc[i].first] = 1;
	vector <pii> tmp;
	int sz = cyc.size();
	bool update = false;
	for (int i = 0; i < sz && !update; i ++) {
		int x = cyc[i].first, y = 0;
		for (int j = 0; j < v[x].size() && !y; j ++) {
			y = v[x][j];
			if (!incycle[y] || y == cyc[i].second) {
				y = 0; continue;
			}
		}
		if (!y) continue;
		int j = i;
		while (cyc[j%sz].second != y) j ++;
		j ++;
		while (1) {
			tmp.push_back(cyc[j%sz]);
			if (cyc[j%sz].second == x) break;
			j ++;
		}
		tmp.push_back(make_pair(x, y));
		update = true;
	}
	if (!update) return;
	cyc = tmp;
	divide();
}

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i ++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
	}
	vector <pii> ans;
	T = 1;
	for (int i = 1; i <= n; i ++) if (!vis[i]) {
		T += 2;
		if (dfs(i)) {
		//	divide();
			cyc.clear();
			T += 2;
			memset(vis, 0, sizeof vis);
			bfs(i);
			if (ans.size() == 0 || ans.size() > cyc.size()) ans = cyc;
			break;
		}
	}
	if (ans.size() > 0) {
		printf("%d\n", ans.size());
		for (int i = 0; i < ans.size(); i ++) {
			printf("%d %d\n", ans[i].first, ans[i].second);
		}
	}
	else puts("-1");
	return 0;
}
