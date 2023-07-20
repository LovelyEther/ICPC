#include <bits/stdc++.h>
using namespace std;

#define N 200200

int t, n, m, x[N], w[N], id[N];

bool cmp1(int i, int j) {
	return w[i] < w[j];
}

bool cmp2(int i, int j) {
	return x[i] < x[j];
}

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= m; i ++) scanf("%d %d", &x[i], &w[i]);
		for (int i = 1; i <= m; i ++) id[i] = i;
		sort(id + 1, id + m + 1, cmp1);
		sort(id + 1, id + 2 * n + 1, cmp2);
		long long ans = 0;
		for (int i = 1; i <= 2 * n; i ++) ans += w[id[i]];
		printf("%d\n", ans);
		for (int i = 1; i <= n; i ++) printf("%d %d\n", id[i], id[2*n-i+1]);
		puts("");
	}
	return 0;
}
