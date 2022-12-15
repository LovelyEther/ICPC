#include <bits/stdc++.h>
using namespace std;

int t, n, x, y, ans;

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &n, &x);
		ans = 0;
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &y);
			if (y < x) ans = i;
		}
		printf("%d\n", ans);
	}
	return 0;
}
