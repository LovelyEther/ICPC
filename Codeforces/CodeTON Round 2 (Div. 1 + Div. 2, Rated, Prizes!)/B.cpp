#include <bits/stdc++.h>
using namespace std;

#define N 200200
#define M 22

int t, n, m, x, a[N], mn[N][M], mx[N][M];

int get_min(int i, int j) {
	int d = 31 - __builtin_clz(j - i + 1);
	return min(mn[i][d], mn[j-(1<<d)+1][d]);
}

int get_max(int i, int j) {
	int d = 31 - __builtin_clz(j - i + 1);
	return max(mx[i][d], mx[j-(1<<d)+1][d]);
}

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &n, &x);
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), mn[i][0] = mx[i][0] = a[i];
		for (int j = 1; (1 << j) <= n; j ++) {
			for (int i = 1; i + (1 << j) - 1 <= n; i ++) {
				mn[i][j] = min(mn[i][j-1], mn[i+(1<<j-1)][j-1]);
				mx[i][j] = max(mx[i][j-1], mx[i+(1<<j-1)][j-1]);
			}
		}
		int ans = 0;
		int last = 0;
		while (last < n) {
			if (get_max(last + 1, n) - get_min(last + 1, n) <= 2 * x) break;
			int st = last + 1, en = n + 1;
			while (en - st > 1) {
				int md = st + en >> 1;
				if (get_max(last + 1, md) - get_min(last + 1, md) <= 2 * x) st = md;
				else en = md;
			}
			ans ++;
			last = st;
		}
		printf("%d\n", ans);
	}
	return 0;
}
