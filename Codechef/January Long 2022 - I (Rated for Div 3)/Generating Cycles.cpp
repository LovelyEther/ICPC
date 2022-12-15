#include <bits/stdc++.h>
using namespace std;

#define N 1010

int t, n, m, col[N][N], use[N][N], vis[N], prv[N], deg[N];
vector <int> v;
vector < vector <int> > w;
vector <int> z;

void dfs(int x) {
	vis[x] = 1;
	for (int y = 1; y <= n; y ++) if (!use[x][y] && col[x][y] == 1) {
		use[x][y] = use[y][x] = 1;
		if (vis[y]) {
			v.clear();
			v.push_back(y);
			int xx = x;
			while (xx != y) {
				vis[xx] = 0;
				v.push_back(xx);
				xx = prv[xx];
			}
			w.push_back(v);
		}
		else {
			prv[y] = x;
		}
		dfs(y);
		vis[x] = 1;
	}
	vis[x] = 0;
}

vector <int> A, B;

bool divide(vector <int> t) {
	vector < vector <int> > rlt;
	int sz = t.size();
	for (int i = 0; i < sz; i ++) {
		for (int j = i + 2; j < sz + i - 1; j ++) {
			int ii = j % sz;
			if (col[t[i]][t[ii]] != -1) {
				A.clear(), B.clear();
				if (ii < i) swap(i, ii);
				for (int k = i; k <= ii; k ++) A.push_back(t[k]);
				for (int k = ii; k <= sz + i; k ++) B.push_back(t[k%sz]);
				return 1;
			}
		}
	}
	return 0;
}

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i ++) {
			deg[i] = 0;
			for (int j = 1; j <= n; j ++) col[i][j] = -1;
		}
		for (int i = 1; i <= m; i ++) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			col[a][b] = col[b][a] = c;
			if (c == 1) deg[a] ++, deg[b] ++;
		}
		bool invalid = false;
		for (int i = 1; i <= n; i ++) if (deg[i] & 1) invalid = true;
		if (invalid) {
			puts("-1"); continue;
		}
		for (int i = 1; i <= n; i ++) {
			vis[i] = 0;
			for (int j = 1; j <= n; j ++) use[i][j] = 0;
		}
		w.clear();
		for (int i = 1; i <= n; i ++) dfs(i);
		z.clear();
		int bad = 0;
		for (int i = 0; i < w.size(); i ++) {
			if (divide(w[i])) w.push_back(A), w.push_back(B), z.push_back(0), bad ++;
			else z.push_back(1);
		}
		printf("%d\n", w.size() - bad);
		for (int i = 0; i < w.size(); i ++) if (z[i]) {
			printf("%d", w[i].size());
			for (int j = 0; j < w[i].size(); j ++) printf(" %d", w[i][j]); puts("");
		}
	}
	return 0;
}
