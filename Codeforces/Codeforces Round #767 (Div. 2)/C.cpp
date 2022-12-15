#include <bits/stdc++.h>
using namespace std;

#define N 200200

int t, n, m, a[N], b[N];
set <int> s[N];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 0; i <= n; i ++) s[i].clear();
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &a[i]);
			s[a[i]].insert(i);
		}
		m = 0;
		int last = 0;
		while (1) {
			int x = 0, mx = last + 1;
			for (int i = 0; i <= n; i ++) {
				if (s[i].empty()) {
					x = i; break;
				}
				else mx = max(mx, *s[i].begin());
			}
			b[++m] = x;
			for (int i = last + 1; i <= mx; i ++) s[a[i]].erase(i);
			last = mx;
			if (last == n) break;
		}
		printf("%d\n", m);
		for (int i = 1; i <= m; i ++) printf("%d%c", b[i], i < m ? ' ' : '\n');
	}
	return 0;
}
