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
		sort(a + 1, a + n + 1);
		printf("%d\n", a[n] + a[n-1] - a[2] - a[1]);
	}
	return 0;
}
