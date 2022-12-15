#include <bits/stdc++.h>
using namespace std;

#define N 200200

int t, n, m, x[N], y[N], z[N];

bool valid(int k) {
	if (n - m < m - k + 1) return false;
	for (int i = m; i >= k; i --) {
		if (z[i] + z[n+k-i] < 0) return false;
	}
	return true;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) scanf("%d", &x[i]);
		for (int i = 1; i <= n; i ++) scanf("%d", &y[i]), z[i] = y[i] - x[i];
		sort(z + 1, z + n + 1);
		m = 0;
		while (m + 1 <= n && z[m+1] < 0) m ++;
		if (m == 0) {
			printf("%d\n", n / 2); continue;
		}
		if (m == n) {
			puts("0"); continue;
		}
		int st = 0, en = m + 1;
		while (en - st > 1) {
			int md = st + en >> 1;
			if (valid(md)) en = md;
			else st = md;
		}
		printf("%d\n", (n - en + 1) / 2);
	}
	return 0;
}
