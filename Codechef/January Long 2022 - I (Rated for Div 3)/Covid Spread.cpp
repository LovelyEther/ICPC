#include <bits/stdc++.h>
using namespace std;

int t, n, d;

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &n, &d);
		int ans = 1;
		for (int i = 1; i <= d; i ++) {
			ans *= (i <= 10) ? 2 : 3;
			if (ans >= n) {
				ans = n; break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
