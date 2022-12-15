#include <bits/stdc++.h>
using namespace std;

int t, n, k, x, y, ans;

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d %d %d", &n, &k, &x, &y);
		if (x <= y) ans = x * n;
		else ans = x * k + y * (n - k);
		printf("%d\n", ans);
	}
	return 0;
}
