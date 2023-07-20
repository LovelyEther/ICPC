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
		int mx = 0, id = 0;
		for (int i = 1; i <= n; i ++) {
			int x;
			scanf("%d", &x);
			if (mx < x) mx = x, id = i;
		}
		printf("%d\n", id);
	}
	return 0;
}
