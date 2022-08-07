#include <bits/stdc++.h>
using namespace std;

#define N 1010

int n, m, x[N], y[N], root[N];
pair <int, pair <int, int> > p[N*N];

int find_root(int x) {
	return x == root[x] ? x : root[x] = find_root(root[x]);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d %d", &x[i], &y[i]), root[i] = i;
	for (int i = 1; i <= n; i ++) {
		for (int j = i + 1; j <= n; j ++) {
			p[++m] = make_pair((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]), make_pair(i, j));
		}
	}
	sort(p + 1, p + m + 1);
	int ans = 0;
	for (int i = 1; i <= m; i ++) {
		int x = p[i].second.first, y = p[i].second.second;
		int xx = find_root(x), yy = find_root(y);
		if (xx == yy) continue;
		ans += p[i].first;
		root[xx] = yy;
	}
	printf("%d\n", ans);
	return 0;
}