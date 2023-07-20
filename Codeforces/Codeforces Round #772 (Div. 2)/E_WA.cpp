#include <bits/stdc++.h>
using namespace std;

#define N 200200

int n, m, wdeg[N], bdeg[N], col[N], vis[N], pos[N];
vector <int> v[N], w[N];
set <pair <int, int> > W, B;
set <pair <int, int> > :: iterator it;

bool dfs(int x) {
	for (int i = 0; i < v[x].size(); i ++) {
		int y = v[x][i];
		if (col[y] == col[x]) return true;
		if (col[y] != -1) continue;
		col[y] = col[x] ^ 1;
		if (dfs(y)) return true;
	}
	return false;
}

int main() {
	freopen("in.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i ++) {
		int type, x, y;
		scanf("%d %d %d", &type, &x, &y);
		if (type == 1) {
			w[x].push_back(y);
			w[y].push_back(x);
		}
		else {
			v[x].push_back(y);
			v[y].push_back(x);
		}
	}
	memset(col, -1, sizeof col);
	for (int i = 1; i <= n; i ++) if (col[i] == -1) {
		col[i] = 0;
		if (dfs(i)) {
			puts("NO"); return 0;
		}
	}
	for (int i = 1; i <= n; i ++) {
		W.insert(make_pair(wdeg[i] = w[i].size(), i));
		B.insert(make_pair(bdeg[i] = v[i].size(), i));
	}
	int L = 1, R = n;
	for (int step = n; step; step --) {
		it = W.begin();
		int x = (*it).second;
		if (wdeg[x] == 0) {
			if (col[x] == 0) pos[x] = L ++;
			else pos[x] = R --;
			vis[x] = 1;
			W.erase(make_pair(wdeg[x], x));
			B.erase(make_pair(bdeg[x], x));
			for (int i = 0; i < w[x].size(); i ++) {
				int y = w[x][i];
				if (vis[y]) continue;
				W.erase(make_pair(wdeg[y], y));
				wdeg[y] --;
				W.insert(make_pair(wdeg[y], y));
			}
			for (int i = 0; i < v[x].size(); i ++) {
				int y = v[x][i];
				if (vis[y]) continue;
				B.erase(make_pair(bdeg[y], y));
				bdeg[y] --;
				B.insert(make_pair(bdeg[y], y));
			}
			continue;
		}
		it = B.begin();
		x = (*it).second;
		if (bdeg[x] == 0) {
			if (col[x] == 0) pos[x] = R --;
			else pos[x] = L ++;
			vis[x] = 1;
			W.erase(make_pair(wdeg[x], x));
			B.erase(make_pair(bdeg[x], x));
			for (int i = 0; i < w[x].size(); i ++) {
				int y = w[x][i];
				if (vis[y]) continue;
				W.erase(make_pair(wdeg[y], y));
				wdeg[y] --;
				W.insert(make_pair(wdeg[y], y));
			}
			for (int i = 0; i < v[x].size(); i ++) {
				int y = v[x][i];
				if (vis[y]) continue;
				B.erase(make_pair(bdeg[y], y));
				bdeg[y] --;
				B.insert(make_pair(bdeg[y], y));
			}
			continue;
		}
		puts("NO"); return 0;
	}
	puts("YES");
	for (int i = 1; i <= n; i ++) printf("%c %d\n", col[i] == 0 ? 'R' : 'L', pos[i]);
	return 0;
}
