#include <bits/stdc++.h>
using namespace std;

int t, a, b, c, d;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		long long x = 1ll * a * d, y = 1ll * b * c;
		if (x == y) puts("0");
		else if (x == 0 || y == 0 || x % y == 0 || y % x == 0) puts("1");
		else puts("2");
	}
	return 0;
}
