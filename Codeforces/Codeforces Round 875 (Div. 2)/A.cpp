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
		for (int i = 1; i <= n; i ++) printf("%d%c", n + 1 - a[i], i == n ? ' ' : '\n');
	}
	return 0;
}
