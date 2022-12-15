#include <bits/stdc++.h>
using namespace std;

int t, n, a[100100];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
		int mn = 1e9 + 1;
		int mx = 0;
		for (int i = 1; i <= n; i ++) {
			if (mn > a[i]) mn = a[i];
			if (mx < a[i]) mx = a[i];
		}
		if (mn == mx) {
			printf("%I64d\n", 1ll * n * (n - 1)); continue;
		}
		int mx_cnt = 0, mn_cnt = 0;
		for (int i = 1; i <= n; i ++) {
			if (a[i] == mn) mn_cnt ++;
			if (a[i] == mx) mx_cnt ++;
		}
		printf("%I64d\n", 2ll * mn_cnt * mx_cnt);
	}
	return 0;
}
