#include <bits/stdc++.h>
using namespace std;

#define N 100100

int t, n, a[N], b[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		int sa = 0, sb = 0;
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), sa += a[i];
		for (int i = 1; i <= n; i ++) scanf("%d", &b[i]), sb += b[i];
		int dif_cnt = 0, non_match = 0;
		for (int i = 1; i <= n; i ++) {
			if (a[i] != b[i]) non_match ++;
		}
		dif_cnt = abs(sa - sb);
		if (!non_match) puts("0");
		else printf("%d\n", min(non_match, dif_cnt + 1));
	}
	return 0;
}
