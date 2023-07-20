#include <bits/stdc++.h>
using namespace std;

int t, n, x;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		bool yes = false;
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &x);
			if (x <= i) yes = true;
		}
		puts(yes ? "YES" : "NO");
	}
	return 0;
}
