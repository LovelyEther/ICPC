#include <bits/stdc++.h>
using namespace std;

#define N 100100

int t, n, a[N];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
		int mx = 0;
		for (int i = 2; i < n; i ++) mx = max(mx, a[i]);
		if (mx <= 1) {
			puts("-1"); continue;
		}
		long long ans = 0;
		int odd = 0;
		for (int i = 2; i < n; i ++) ans += (a[i] + 1) / 2, odd += a[i] & 1;
		if ((odd & 1) && n == 3) {
			puts("-1"); continue;
		}
		printf("%I64d\n", ans);
	}
	return 0;
}
