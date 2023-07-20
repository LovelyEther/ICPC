#include <bits/stdc++.h>
using namespace std;

int t, n, a[200200];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
		if (n == 1) {
			puts("0"); continue;
		}
		sort(a + 1, a + n + 1);
		int mx = 1;
		a[0] = 1e9 + 7;
		for (int i = 1, j = 1; i <= n; i ++) {
			if (a[i] == a[i-1]) mx = max(mx, i - j + 1);
			else j = i;
		}
		int ans = 0;
	//	if (mx == 1) ans = (n - 2) / 2 * 3 + (n - 2) % 2 * 2 + 2;
	//	else ans = (n - mx) / 2 * 3 + (n - mx) % 2 * 2;
		while (mx < n) {
			ans += 1 + min(mx, n - mx);
			mx *= 2;
		}
		printf("%d\n", ans);
	}
	return 0;
}
