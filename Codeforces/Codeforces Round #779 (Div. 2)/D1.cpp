#include <bits/stdc++.h>
using namespace std;

int t, l, r, n, k, a[1<<20];

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &l, &r);
		n = r + 1 - l;
		for (int i = l; i <= r; i ++) scanf("%d", &a[i]);
		k = 31 - __builtin_clz(r);
		int ans = a[l] >> k + 1 << k + 1;
		for (int i = l; i <= r; i ++) a[i] ^= ans;
		for (int j = k; j >= 0; j --) {
			if (n % (1 << j + 1) == 0) break;
			int cnt = 0;
			for (int i = l; i <= r; i ++) if (a[i] & (1 << j)) cnt ++;
			if (cnt > n - cnt) ans ^= 1 << j;
		}
		printf("%d\n", ans);
	}
	return 0;
}
