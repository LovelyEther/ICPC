#include <bits/stdc++.h>
using namespace std;

int t, n, r[3], c[3], x, y, tx, ty;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 0; i < 3; i ++) {
			scanf("%d %d", &r[i], &c[i]);
		}
		x = (r[0] == r[1] || r[0] == r[2]) ? r[0] : r[1];
		y = (c[0] == c[1] || c[0] == c[2]) ? c[0] : c[1];
		scanf("%d %d", &tx, &ty);
		if (x == 1 && y == 1) {
			if (tx == 1 || ty == 1) puts("YES");
			else puts("NO");
		}
		else if (x == 1 && y == n) {
			if (tx == 1 || ty == n) puts("YES");
			else puts("NO");
		}
		else if (x == n && y == 1) {
			if (tx == n || ty == 1) puts("YES");
			else puts("NO");
		}
		else if (x == n && y == n) {
			if (tx == n || ty == n) puts("YES");
			else puts("NO");
		}
		else {
			puts((x & 1) != (tx & 1) && (y & 1) != (ty & 1) ? "NO" : "YES");
		}
	}
	return 0;
}
