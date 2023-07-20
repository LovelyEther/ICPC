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
		int mn = 1e9;
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), mn = min(mn, a[i]);
		if (mn == a[1]) puts("Yes");
		else puts("No");
	}
	return 0;
}
