#include <bits/stdc++.h>
using namespace std;

int t, n, k, x;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &n, &k);
		int ans = 0;
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &x);
			if (i <= k && x > k) ans ++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
