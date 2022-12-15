#include <bits/stdc++.h>
using namespace std;

#define N 200200

int t, n, m, a[N], b[N];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= m; i ++) scanf("%d", &a[i]);
		sort(a + 1, a + m + 1);
		for (int i = 1; i < m; i ++) b[i] = a[i+1] - a[i] - 1;
		b[m] = a[1] + n - a[m] - 1;
		sort(b + 1, b + m + 1);
		reverse(b + 1, b + m + 1);
		if (b[1] <= 1) {
			printf("%d\n", n - b[1]); continue;
		}
		int saved = 0, days = 0;
		for (int k = 1; k <= m; k ++) {
			if (b[k] - days * 2 <= 0) break;
			saved += max(b[k] - days * 2 - 1, 1);
			days += 2;
		}
		printf("%d\n", n - saved);
	}
	return 0;
}
