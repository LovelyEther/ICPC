#include <bits/stdc++.h>
using namespace std;

#define N 500500

int t, n, x, vis[N];
vector <int> v;

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	for (int T = 1; T <= t; T ++) {
		scanf("%d %d", &n, &x);
		int m = n % 4;
		if (!m) m = 4;
		v.clear();
		if (__builtin_popcount(x) >= m) {
			int xx = x;
			for (int i = 1; i < m; i ++) v.push_back(xx & -xx), xx -= xx & -xx;
			v.push_back(xx);
		}
		else {
			int p = -1, q = -1;
			for (int i = 0; ; i ++) if (!((x >> i) & 1)) {
				if (p == -1) p = i;
				else if (q == -1) q = i;
				else break;
			}
			if (m <= 2) {
				v.push_back(x);
				if (m == 2) v.push_back(0);
			}
			if (m > 2) {
				v.push_back(x ^ (1 << p));
				v.push_back(x ^ (1 << q));
				v.push_back(x ^ (1 << p) ^ (1 << q));
				if (m == 4) v.push_back(0);
			}
		}
		for (int i = 0; i < v.size(); i ++) vis[v[i]>>2] = T;
		int step = n - m >> 2, i = 0;
		while (step --) {
			if (vis[i] == T) {
				step ++; i ++; continue;
			}
			for (int j = 0; j < 4; j ++) v.push_back(i << 2 ^ j);
			i ++;
		}
		for (int i = 0; i < v.size(); i ++) printf("%d%c", v[i], i < v.size() - 1 ? ' ' : '\n');
	}
	return 0;
}
