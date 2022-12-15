#include <bits/stdc++.h>
using namespace std;

int n, m, q;

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	long long ans = 0;
	for (int i = 1; i <= n; i ++) {
		int x;
		scanf("%d", &x);
		ans += x;
	}
	ans -= 1ll * n * (n - 1) / 2;
	while (m --) {
		int x, y;
		scanf("%d %d", &x, &y);
		ans += 2;
	}
	scanf("%d", &q);
	while (q --) {
		char type[7];
		int x, y;
		scanf("%s", type);
		if (type[0] == '?') {
			printf("%lld\n", ans);
		}
		else {
			scanf("%d %d", &x, &y);
			if (type[0] == '+') ans += 2;
			else ans -= 2;
		}
	}
	return 0;
}
