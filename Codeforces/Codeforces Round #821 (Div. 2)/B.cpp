#include <bits/stdc++.h>
using namespace std;

int t, n, x, y;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d %d", &n, &x, &y);
		if (x && y || !x && !y) {
			puts("-1"); continue;
		}
		if (!x) swap(x, y);
		if ((n - 1) % x) {
			puts("-1"); continue;
		}
		for (int i = 1; i < n; i ++) printf("%d ", (i - 1) / x * x + 2); puts("");
	}
	return 0;
}
