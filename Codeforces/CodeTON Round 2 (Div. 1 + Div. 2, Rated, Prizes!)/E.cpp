#include <bits/stdc++.h>
using namespace std;

#define N 1010

const int mod = 998244353;

int t, n, m, a[N], b[N], x[N], y[N], flag[N];
long long f[N];

vector <int> v[N], rv[N];
vector <bool> visited;
vector <int> ids;

void dfs(int x) {
    visited[x] = true;
    for (int y : v[x]) {
        if (!visited[y]) dfs(y);
    }
    ids.push_back(x);
}

void topological_sort() {
    visited.assign(n + 1, false);
    ids.clear();
    for (int i = 1; i <= n; i ++) {
        if (!visited[i]) dfs(i);
    }
    reverse(ids.begin(), ids.end());
}

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), v[i].clear(), rv[i].clear(), f[i] = 0;
		for (int i = 1; i <= m; i ++) {
			scanf("%d %d", &x[i], &y[i]);
			v[x[i]].push_back(y[i]);
			rv[y[i]].push_back(x[i]);
		}
		topological_sort();
	//	for (int i = 1; i <= n; i ++) printf("%d ", ids[i-1]); puts("");
		int ans = 0;
		while (1) {
			bool valid = true;
			for (int i = 1; i <= m; i ++) if (a[x[i]] && !a[y[i]]) valid = false;
			if (valid) break;
			for (int i = 1; i <= n; i ++) b[i] = a[i];
			for (int i = 1; i <= n; i ++) if (b[i] > 0) {
				a[i] --;
				for (auto j: v[i]) a[j] ++;
			}
			ans ++;
		}
	//	for (int i = 1; i <= n; i ++) printf("%d ", a[i]); puts("");
		for (int i = 0; i < n; i ++) {
			int x = ids[i];
			f[x] = a[x];
			for (auto y: rv[x]) {
				f[x] = (f[x] + f[y]) % mod;
			}
		}
		ans = (ans + f[ids[n-1]]) % mod;
		printf("%d\n", ans);
	}
	return 0;
}
