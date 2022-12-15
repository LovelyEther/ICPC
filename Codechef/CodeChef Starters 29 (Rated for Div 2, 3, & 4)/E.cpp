#include <bits/stdc++.h>
using namespace std;

const int inf = 2e9;

int t, n, x, mx, mn;
long long sum[2];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		mn = inf, mx = -inf;
		sum[0] = sum[1] = 0;
		for (int i = 0; i < n; i ++) {
			scanf("%d", &x);
			x = abs(x);
			sum[i&1] += x;
			if (i & 1) mx = max(mx, x);
			else mn = min(mn, x);
		}
		if (mx > mn) {
			sum[0] = sum[0] - mn + mx;
			sum[1] = sum[1] - mx + mn;
		}
		printf("%lld\n", sum[0] - sum[1]);
	}
	return 0;
}
