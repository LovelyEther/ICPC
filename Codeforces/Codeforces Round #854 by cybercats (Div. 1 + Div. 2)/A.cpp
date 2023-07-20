#include <bits/stdc++.h>
using namespace std;

#define N 200200

int t, n, m, x, f[N];
set <int> s;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &n, &m);
		s.clear();
		for (int i = 1; i <= n; i ++) f[i] = -1;
		for (int i = 1; i <= m; i ++) {
			scanf("%d", &x);
			int sz = s.size();
			s.insert(x);
			if (s.size() > sz) f[sz+1] = i;
		}
		for (int i = 1; i <= n; i ++) printf("%d%c", f[n+1-i], i < n ? ' ' : '\n');
	}
	return 0;
}
