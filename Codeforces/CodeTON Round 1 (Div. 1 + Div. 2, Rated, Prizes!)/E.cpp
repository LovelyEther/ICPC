#include <bits/stdc++.h>
using namespace std;

#define N 100100

int t, n, x, y, a[N];
vector <int> v[N];

void dfs(int x, int p, int sum1, int sum2) {
	int cnt = 0;
	for (int i = 0; i < v[x].size(); i ++) {
		int y = v[x][i];
		if (y == p) continue;
		cnt ++;
	}
	a[x] = sum1 - sum2 * cnt;
	for (int i = 0; i < v[x].size(); i ++) {
		int y = v[x][i];
		if (y == p) continue;
		dfs(y, x, sum2, -sum2);
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) v[i].clear();
		for (int i = 1; i < n; i ++) {
			scanf("%d %d", &x, &y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dfs(1, 0, 0, 1);
		for (int i = 1; i <= n; i ++) printf("%d%c", a[i], i < n ? ' ' : '\n');
	}
	return 0;
}
