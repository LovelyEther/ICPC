#include <bits/stdc++.h>
using namespace std;

#define N 200200

const int inf = 2e9;
const int mod = 1e9 + 7;

int t, n, m, src, dst, a[N], b[N], f[N], g[N];
vector <int> v[N];
int Q[N];

void calc(int src, int* d, int* f) {
	for (int i = 1; i <= n; i ++) d[i] = inf, f[i] = 0;
	d[src] = 0, f[src] = 1;
	int head = 0, tail = 0;
	Q[tail++] = src;
	while (head < tail) {
		int x = Q[head++];
		for (int i = 0; i < v[x].size(); i ++) {
			int y = v[x][i];
			if (d[y] > d[x] + 1) {
				Q[tail++] = y;
				d[y] = d[x] + 1;
				f[y] = f[x];
			}
			else if (d[y] == d[x] + 1) {
				f[y] = (f[y] + f[x]) % mod;
			}
		}
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d %d %d", &n, &m, &src, &dst);
		for (int i = 1; i <= n; i ++) v[i].clear();
		while (m --) {
			int x, y;
			scanf("%d %d", &x, &y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		calc(src, a, f);
		calc(dst, b, g);
		int ans = f[dst], len = a[dst];
		for (int i = 1; i <= n; i ++) {
			for (int j = 0; j < v[i].size(); j ++) {
				int x = i, y = v[i][j];
				if (a[x] + b[x] == len && a[x] + b[y] == len) {
					ans = (ans + 1ll * f[x] * g[y]) % mod;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
