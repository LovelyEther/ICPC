#include <bits/stdc++.h>
using namespace std;

int t, n;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= i; j ++) printf("%d%c", (j == 1 || j == i) ? 1 : 0, j < i ? ' ' : '\n');
		}
	}
	return 0;
}
