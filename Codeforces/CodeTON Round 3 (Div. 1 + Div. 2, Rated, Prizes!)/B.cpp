#include <bits/stdc++.h>
using namespace std;

int t, n;
char s[200200];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%d %s", &n, s);
		long long ans = 0;
		int zero = 0, one = 0, cnt = 0;
		for (int i = 0; i < n; i ++) {
			if (s[i] == '0') zero ++;
			else one ++;
			if (i == 0 || i > 0 && s[i] == s[i-1]) cnt ++;
			else cnt = 1;
			ans = max(ans, 1ll * cnt * cnt);
		}
		ans = max(ans, 1ll * zero * one);
		printf("%I64d\n", ans);
	}
	return 0;
}
