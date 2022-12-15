#include <bits/stdc++.h>
using namespace std;

#define N 200200

int t, n, k, a[N], f[N];

bool valid(int cnt) {
	return cnt - (n - cnt) >= k;
}

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &n, &k);
		for (int i = 1; i <= n; i ++) f[i] = 0;
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), f[a[i]] ++;
		for (int i = 1; i <= n; i ++) f[i] += f[i-1];
		int x = 0, y = n;
		for (int i = 1; i <= n; i ++) {
			if (!valid(f[n] - f[i-1])) break;
			if (valid(f[i] - f[i-1])) {
				x = y = i; break;
			}
			int st = i, en = n;
			while (en - st > 1) {
				int md = st + en >> 1;
				if (valid(f[md] - f[i-1])) en = md;
				else st = md;
			}
			if (y - x > en - i) {
				x = i, y = en;
			}
		}
		printf("%d %d\n", x, y);
		int st = 1, en = 0;
		for (int i = 1; i < k; i ++) {
			en = st - 1;
			int cnt = 0;
			while (cnt <= 0) {
				en ++;
				if (x <= a[en] && a[en] <= y) cnt ++;
				else cnt --;
			}
			printf("%d %d\n", st, en);
			st = en + 1;
		}
		printf("%d %d\n", st, n);
	}
	return 0;
}
