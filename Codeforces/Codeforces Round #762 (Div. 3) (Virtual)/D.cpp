#include <bits/stdc++.h>
using namespace std;

int t, m, n, vis[100100];
vector <int> v[100100];

bool ok(int val) {
	for (int j = 0; j < n; j ++) vis[j] = 0;
	bool multi = 0;
	for (int i = 0; i < m; i ++) {
		int cnt = 0;
		for (int j = 0; j < n; j ++) if (v[i][j] >= val) cnt ++, vis[j] = 1;
		if (cnt > 1) multi = 1;
	}
	for (int j = 0; j < n; j ++) if (!vis[j]) multi = 0;
	return multi;
}

int main() {
	//freopen("d.in", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &m, &n);
		for (int i = 0; i < m; i ++) {
			v[i].clear();
			for (int j = 0, x; j < n; j ++) scanf("%d", &x), v[i].push_back(x);
		}
		int st = 0, en = 1e9 + 1;
		while (en - st > 1) {
			int mid = st + en >> 1;
			if (ok(mid)) st = mid;
			else en = mid;
		}
		printf("%d\n", st);
	}
	return 0;
}
