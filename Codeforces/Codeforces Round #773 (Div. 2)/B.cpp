#include <bits/stdc++.h>
using namespace std;

int t, n, m, x;
set <int> s;

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		s.clear();
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &x);
			s.insert(x);
		}
		m = s.size();
		for (int i = 1; i <= n; i ++) printf("%d%c", i <= m ? m : i, i < n ? ' ' : '\n');
	}
	return 0;
}
