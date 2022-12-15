#include <bits/stdc++.h>
using namespace std;

#define N 200200

int t, n, a[N], b[N];

int get(int *a, int val) {
	int i = lower_bound(a + 1, a + n + 1, val) - a;
	int rlt = 2e9;
	if (i <= n) rlt = a[i] - val;
	i --;
	if (i) rlt = min(rlt, val - a[i]);
	return rlt;
}

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
		for (int i = 1; i <= n; i ++) scanf("%d", &b[i]);
		long long ans = min(abs(a[1] - b[1]) + abs(a[n] - b[n]), abs(a[1] - b[n]) + abs(a[n] - b[1]));
		int a1 = a[1], an = a[n];
		int b1 = b[1], bn = b[n];
		sort(a + 1, a + n + 1);
		sort(b + 1, b + n + 1);
		int x1 = get(b, a1), xn = get(b, an);
		int y1 = get(a, b1), yn = get(a, bn);
		ans = min(ans, 0ll + abs(a1 - b1) + xn + yn);
		ans = min(ans, 0ll + abs(a1 - bn) + xn + y1);
		ans = min(ans, 0ll + abs(an - b1) + x1 + yn);
		ans = min(ans, 0ll + abs(an - bn) + x1 + y1);
		ans = min(ans, 0ll + x1 + xn + y1 + yn);
		printf("%I64d\n", ans);
	}
	return 0;
}
