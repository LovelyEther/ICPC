#include <bits/stdc++.h>
using namespace std;

#define N 200200

const int mod = 1e9 + 7;

int n, m, a[N], c, x, d, z;
vector <int> v[N], w[N];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	for (int i = 1; i <= m; i ++) {
		scanf("%d %d", &c, &x);
		for (int j = 0; j < x; j ++) {
			scanf("%d %d", &z, &d);
			v[c].push_back(d);
			w[c].push_back(z);
		}
	}
	for (int i = 1; i <= n; i ++) {
		if (v[i].size() == 0) continue;
		for (int j = 0; j < v[i].size(); j ++) a[v[i][j]] = (a[v[i][j]] + 1ll * a[i] * w[i][j]) % mod;
		a[i] = 0;
	}
	for (int i = 1; i <= n; i ++) printf("%d\n", a[i]);
	return 0;
}
