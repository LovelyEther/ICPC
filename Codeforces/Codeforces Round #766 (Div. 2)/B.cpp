#include <bits/stdc++.h>
using namespace std;

int t, n, m;
vector <int> v;

int dist(int i, int j, int x, int y) {
	return abs(i - x) + abs(j - y);
}

int calc(int i, int j) {
	int rlt = 0;
	rlt = max(rlt, dist(i, j, 1, 1));
	rlt = max(rlt, dist(i, j, 1, m));
	rlt = max(rlt, dist(i, j, n, 1));
	rlt = max(rlt, dist(i, j, n, m));
	return rlt;
}

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &n, &m);
		v.clear();
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= m; j ++) {
				v.push_back(calc(i, j));
			}
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < v.size(); i ++) printf("%d%c", v[i], i < v.size() - 1 ? ' ' : '\n');
	}
	return 0;
}
