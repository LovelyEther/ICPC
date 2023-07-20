#include <bits/stdc++.h>
using namespace std;

#define N 400400

int t, n, a[N], b[N];
map <int, int> mpa, mpb;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
		for (int i = 1; i <= n; i ++) scanf("%d", &b[i]);
		mpa.clear();
		mpb.clear();
		for (int i = 1, j = 0; i <= n; i ++) {
			if (a[i] != a[i-1]) j = i - 1;
			int tmp = mpa[a[i]];
			tmp = max(tmp, i - j);
			mpa[a[i]] = tmp;
		}
		for (int i = 1, j = 0; i <= n; i ++) {
			if (b[i] != b[i-1]) j = i - 1;
			int tmp = mpb[b[i]];
			tmp = max(tmp, i - j);
			mpb[b[i]] = tmp;
		}
		int ans = 0;
		for (int i = 1; i <= n; i ++) ans = max(ans, mpa[a[i]] + mpb[a[i]]);
		for (int i = 1; i <= n; i ++) ans = max(ans, mpa[b[i]] + mpb[b[i]]);
		printf("%d\n", ans);
	}
	return 0;
}
