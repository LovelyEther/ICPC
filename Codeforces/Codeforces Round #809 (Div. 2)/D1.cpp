#include <bits/stdc++.h>
using namespace std;

#define N 100100

int t, n, k, a[N];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &n, &k);
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
		int ans = a[n];
		for (int m = 0; m <= a[1]; m ++) {
			int mx = 0;
			for (int i = 1; i <= n; i ++) {
				if (m == 0) {
					mx = max(mx, a[i] / k); continue;
				}
				int x = a[i] / m;
				x = min(x, k);
				mx = max(mx, a[i] / x);
			}
			ans = min(ans, mx - m);
		}
		printf("%d\n", ans);
	}
	return 0;
}
