#include <bits/stdc++.h>
using namespace std;

int t, n, a[200200];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
		printf("%d %d\n", 1, n);
	}
	return 0;
}
