#include <bits/stdc++.h>
using namespace std;

#define N 300300

const long long inf = 1e18;

int t, n, a[N];
long long s[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), s[i] = s[i-1] + a[i];
		long long mn = inf;
		long long profit = 0;
		long long ans = 0;
		for (int i = n; i >= 0; i --) {
			mn = min(mn, s[i]);
			if (s[i] - mn > profit) {
				profit = s[i] - mn;
				ans = s[i];
			}
		}
		printf("%I64d\n", ans);
	}
	return 0;
}
