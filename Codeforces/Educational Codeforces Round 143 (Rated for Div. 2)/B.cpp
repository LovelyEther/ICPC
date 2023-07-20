#include <bits/stdc++.h>
using namespace std;

int t, n, x, l, r, cnt[55];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &n, &x);
		for (int i = 1; i <= 50; i ++) cnt[i] = 0;
		for (int i = 1; i <= n; i ++) {
			scanf("%d %d", &l, &r);
			if (l <= x && x <= r) {
				for (int j = l; j <= r; j ++) cnt[j] ++;
			}
		}
		bool good = true;
		for (int i = 1; i <= 50; i ++) if (i != x && cnt[i] >= cnt[x]) good = false;
		puts(good ? "YES" : "NO");
	}
	return 0;
}
