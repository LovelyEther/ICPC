#include <bits/stdc++.h>
using namespace std;

#define N 5050

int t, n, x, a[N], g[N];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &n, &x);
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
		for (int i = 1; i <= n; i ++) {
			int sum = 0;
			for (int j = 1; j <= i; j ++) sum += a[j];
			g[i] = sum;
			for (int j = i + 1; j <= n; j ++) {
				sum += a[j];
				sum -= a[j-i];
				g[i] = max(g[i], sum);
			}
		}
		for (int k = 0; k <= n; k ++) {
			int ans = -1e9;
			for (int i = 0; i <= n; i ++) ans = max(ans, g[i] + min(i, k) * x);
			printf("%d ", ans);
		}
		puts("");
	}
	return 0;
}
